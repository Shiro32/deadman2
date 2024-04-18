/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18857
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include <stdbool.h>

/*
                         Main application
 */

// -----------------------------------------------------------------------------
#define DEADMAN_TIMER_S             80     // デッドマンタイマー（秒）
#define DEADMAN_TIMER_INCREMENT_S   600     // １ボタンプッシュで増える時間（秒）
#define HUMAN_SENSOR_TIMER_s        30      // 人感センサーによってオフにする時間（秒）

#define SEG_DP                      0b10000000
#define HUMAN_SENSOR_CALIB_TERM     5


bool SSROutputStatus = false;
bool HumanSensorStatus = false;



// システムの動作状態
// MODE_START		: 電源ON、アライブボタンなどで再スタートするとき
// MODE_RESUME	: カウントダウン中にボタンを押された（増加）とき
// MODE_COUNT1	: 残り１分以上（分表示）
// MODE_COUNT2	: 残り１分未満（秒表示）
// MODE_STOP		: 0秒になり出力オフ
typedef enum { MODE_START, MODE_RESUME, MODE_COUNT1, MODE_COUNT2, MODE_STOP } SystemMode_t;
SystemMode_t SystemMode;

// デッドマンタイマーそのもの
uint16_t DeadmanTimer_s;
uint16_t HumanSensorTimer_s;


// -----------------------------------------------------------------------------
// セグメントのパターン（7seg+DPのON/OFFをバイナリで dp-a-b-c d-e-f-g）
uint8_t SegPattern[] = 
	{0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67,                // 0-9
     0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000};   // 回転（10-15）
// 現在表示中の２桁(DPも込み)→VRAMみたいなバッファ
uint8_t SegBuffer[2];

// -----------------------------------------------------------------------------
// 7セグメントLEDをダイナミック制御で点灯させる
// ・表示データはSegBuffer（0が１の桁、1が10の桁）
// ・タイマ２の割込みで1ms程度でずっと呼び出され続ける（2msだとちらつく）
// ・１回で１セグメントだけ付けるので、２桁で16回（8*2）コールして１周
void TMR2_Refresh7Seg( void ) {
	static uint8_t pos = 0;
	static uint8_t mask = 0b10000000;
    
	// 書き込み開始
	if( pos<=7 ) {      	// 10の桁（左セグメント）
		GPIO_SEG7_10_LAT = 1;
        GPIO_SEG7_1_LAT  = 0;
        LATB = ~(SegBuffer[1] & mask);
        // TODO: Bポートは名前つけられないんだっけ？
        // LATB = LATBitsだとは思うが、LAT自体なんとかならんのか・・・？
    }
	else {                  // 1の桁（右セグメント）
        GPIO_SEG7_10_LAT = 0;
		GPIO_SEG7_1_LAT	 = 1;
        LATB = ~(SegBuffer[0] & mask);
	}

	// マスクポジションを進める
	mask = mask>>1;
	if( mask==0 ) mask = 0x80;
	// 書き込みポジションも進める
	pos++;
	if( pos>=16 ) pos = 0;
}

// -----------------------------------------------------------------------------
// 7セグメントLEDに数字を表示する
// ・バッファをセットするだけで、実際に表示するのはTMR2_Refresh7Seg
// value: 表示数(0~99)
// dp   : 小数点表示するか（false=表示しない）
// zero : ゼロサプレスするか（false=サプレス市内）
void Draw7Seg( uint16_t value, bool dp, bool zero ) {
    // １の位（DPの処理）
    SegBuffer[0] = SegPattern[ value % 10 ] | (dp ? SEG_DP : 0);
    // 10の位（ゼロサプレスの処理）
    SegBuffer[1] = (zero && value<10) ? 0 : SegPattern[ value / 10 ];
}

// -----------------------------------------------------------------------------
// 7セグメントLEDを回転させる
void Circulate7Seg( void ) {
    uint8_t i, j;
    
    for( i=0; i<30; i++) {
        for( j=10; j<16; j++ ) {
            SegBuffer[0] = SegPattern[j];
            SegBuffer[1] = SegPattern[j];
            __delay_ms( 15 );
        }
    }
}

// -----------------------------------------------------------------------------
// 7セグメントLEDを数回点滅させる
// value : 表示する数字(0-99)
void Blink7Seg( uint16_t value ) {
    uint8_t i;
    
    for( i=0; i<3; i++ ) {
        Draw7Seg( value, false, false );
        __delay_ms( 200 );
        SegBuffer[0] = 0;
        SegBuffer[1] = 0;
        __delay_ms( 200 ) ;
    }
}

// 7セグメントLEDを消灯（全セル0x00）
void Clear7Seg( void ) {
    SegBuffer[0] = 0;
    SegBuffer[1] = 0;
}

// -----------------------------------------------------------------------------
// プッシュスイッチ（デッドマンスイッチ）を押された時の処理
// ・キー割り込み（INT）のハンドラー
// ・ポーリングだと反応が悪くなりそうなので、割り込みにした（けどメインが遅いので意味なし）
// ・押されたら10分増やす
void INT_PushSW( void ) {
    IOCAF2 = 0;
    IOCAF2_SetInterruptHandler(NULL);
    DeadmanTimer_s += DEADMAN_TIMER_INCREMENT_S;
    SystemMode = MODE_RESUME;
}

// -----------------------------------------------------------------------------
// SSRの制御
// ・SSR制御のもっともハードウェアよりの部分
// ・実際にGPIOから出力してフォトカプラを駆動する
void HandleSSR( void ) {
    GPIO_SSR_LAT = ( SSROutputStatus && HumanSensorStatus ) ? 1:0;    
}

// -----------------------------------------------------------------------------
// SSRのオン・オフ
// ・内部状態を設定するだけで、実際にはHandleSSRが処理する（GPIO）
inline void TurnOnSSR( void ) { SSROutputStatus = true; }
inline void TurnOffSSR( void ) { SSROutputStatus = false; }

// -----------------------------------------------------------------------------
// 人感センサーの処理
//　・センサー自体がノイズ（ONもOFFも）を持っているので意外と面倒
//　・過去５秒程度で平均化
//	・この結果をもって、さらに60秒程度無人が続けばOFF（なるべくON継続型）
bool AverageHumanSensor(void);

// 人感センサーチェック
// これがメインルーチンから１秒ごとに呼び出される
void CheckHumanSensor( void ) {
    static uint16_t lastTimer_s = 0;

    // 現在が人感ONの時
    if( HumanSensorStatus ) {
        // 人感センサーで「無人」を検出
        if( !AverageHumanSensor() ) {
            lastTimer_s ++;
            if( lastTimer_s > HUMAN_SENSOR_TIMER_s ) HumanSensorStatus = false;
        }

    } else {
        // 現在が人感OFFの時
        if( AverageHumanSensor() ) {
            HumanSensorStatus = true;
            lastTimer_s = 0;
        }
    }
}

// 人感センサーの平均化処理
// ・ノイズがとても多いので移動平均をとる
// ・一定回数ONにならないとONと見なさない
bool AverageHumanSensor() {
    static bool buf[ HUMAN_SENSOR_CALIB_TERM ]; // 移動平均用バッファ
    uint8_t i;
    int8_t sum=0;

    // 過去分をスクロールさせて、新データを１個読み込む
    for( i=HUMAN_SENSOR_CALIB_TERM-1; i>0; i-- ) {
        sum+=buf[i];
        buf[i] = buf[i-1];
    }

    // TODO: プルアップでよいのかどうか、実験で試してみる必要あり
    // TODO: 無人→VSS、有人→VDDのような気がする（プルアップ・ダウンともにしない）
    buf[0] = GPIO_PIR_PORT;
    sum+=buf[0];

    return ( (float)sum/HUMAN_SENSOR_CALIB_TERM > 0.1 ) ? true:false;
}


// -----------------------------------------------------------------------------
void main(void)
{
    // 表示初期化（なぜかちらつく？）
    GPIO_SEG7_10_LAT = 0;
    GPIO_SEG7_1_LAT  = 0;
	SegBuffer[0] = SegPattern[0];
	SegBuffer[1] = SegPattern[0];

    // initialize the device
    SYSTEM_Initialize();
    
    // 初期モード設定（これやらないと何も始まらない）
    SystemMode = MODE_START;
    
    TMR2_SetInterruptHandler( TMR2_Refresh7Seg );    // 7セグ表示の割り込み設定
//    INT_SetInterruptHandler( INT_PushSW );           // キー割り込み（デッドマンSW)
    IOCAF2_SetInterruptHandler( INT_PushSW );
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
	while(1) {
        //TODO: 1秒完全待機のために遅くなる。プリスケーラーで対応できないか？
        __delay_ms(1000);

        DeadmanTimer_s--;   // デッドマンタイマ・デクリメント       
        CheckHumanSensor(); // 人感センサーチェック
        HandleSSR();        // SSR出力制御
    
        // システム状態遷移
        switch( SystemMode ) {
        case MODE_START:
            DeadmanTimer_s = DEADMAN_TIMER_S;
            SystemMode = MODE_RESUME;
            Circulate7Seg();
            // break;

        case MODE_RESUME:   // TODO: RESUMEだけするのはいつか？
            TurnOnSSR();
            Blink7Seg( DeadmanTimer_s/60 );
            IOCAF2_SetInterruptHandler( INT_PushSW );
            SystemMode = MODE_COUNT1;
            // break;

        case MODE_COUNT1:
            // 分単位で表示する
            Draw7Seg( DeadmanTimer_s/60, DeadmanTimer_s%2, true );
            if( DeadmanTimer_s<60 ) SystemMode = MODE_COUNT2;
            break;

        case MODE_COUNT2:
            // 秒単位で表示する
            Draw7Seg( DeadmanTimer_s, false, false );
            if( DeadmanTimer_s<=0 ) SystemMode = MODE_STOP;
            break;

        case MODE_STOP:
            TurnOffSSR();   // 目玉機能であるSSRオフ！

            if( DeadmanTimer_s%2 )
                Draw7Seg( 0, false, false );
            else
                Clear7Seg();
            break;
        }
    }
}
