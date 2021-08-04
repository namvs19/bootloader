// Viet 1 thu vien timer, su dung 1 ngat HW timer (PIT/SysTick). Chu ky cua ngat là 1ms
// Ung dung: Viet chuong trinh su dung thu vien Timer de nhay 2 LED voi chu ky là 1S và 1.3S

//9 API
/*
   1. Configuration
   2. update parameters
      2.1 Callback
      2.2 Timeout
   3. Start/stop
   4. Information
      4.1 time elapsed
      4.2 time remaining
      4.3 status
   5. Deinit.
*/
//SysTick_Config();
// Timer_Config(Id,TimeOut,Mode...)
// Mode: OneShot, Coninuous
// Timer_InstallCallback(Id, callBackFunction);
// start timer : Timer_StartChannel(Id);
// Stop timer : Timer_StopChannel(Id);
// yêu cau thay doi time out luc timer dang chay: Timer_UpdateTimeout(Id, NewTimeout)
// Thoi gian dã qua: Timer_GetTimeElapsed(TimerID)
// Thoi gian còn lai: Timer_GetTimeRemain(TimerID)
// Xoá timer: Timer_Remove(Id)

// Dùng SysTick/PIT cho ngat chu ky 1ms
// so luong kenh: #define TIMER_MAX_CHANNEL    10U
// su dung mang, moi phan tu la 1 timer, size = TIMER_MAX_CHANNEL
/* môi timer là 1 struct:
                - uint8_t ChannelId
                - uint32 TimeOut
                - CallBackType CallbackFunction
                - eModeType Mode // OneShot, Continuous
                - TimerStatusType Status // STOPPED, RUNNING, EXPIRED
    */
//Vi du su dung
// void main()
// cai dat timer 1 co chu ky 1000 = 1s: Timer_Config(1,1000,Continuous)
// install callBack1 vào timer 1: Timer_InstallCallback(1, callBack1);
// start timer 1: Timer_StartChannel(1);

// cai dat timer 2 co chu ky 1300= 1.3s: Timer_Config(2,1300,...)
// install callBack1 vào timer 1: Timer_InstallCallback(2, callBackLedRed);
// start timer 1: Timer_StartChannel(2);
// while(1)

#ifndef _TIMER_H_
#define _TIMER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "PIT.h"
#include "Timer_config.h"
#include "std_type.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum
{
   ONESHOT = 0,
   CONTINUOUS = 1
} Timer_eSwMode_Type;

typedef enum
{
   STOPPED = 0,
   RUNNING = 1,
   EXPIRED = 2,
   UNINIT = 3,
} Timer_eSwStatus_Type;

typedef void (*CallBack_Type)(void);

typedef struct
{
   uint32_t u32TimeOut;
   uint32_t u32NextTimeOut;
   volatile uint32_t u32CurrentTime;
   CallBack_Type CallBackFunc;
   Timer_eSwMode_Type eMode;
   volatile Timer_eSwStatus_Type eStatus;
} Timer_SwChannel_Type;

/*******************************************************************************
 * API
 ******************************************************************************/

/* ----------------------------------------------------------------------------
   -- Initialize
   ---------------------------------------------------------------------------- */
void Timer_InitSWTimer(void);
void Timer_InitChannel(uint8_t u8ChannelID,
                       CallBack_Type CallBackFunc,
                       Timer_eSwMode_Type eMode);

/* ----------------------------------------------------------------------------
   -- Update Parameter
   ---------------------------------------------------------------------------- */
void Timer_UpdateCallback(uint8_t u8ChannelID, CallBack_Type CallBackFunc);
void Timer_UpdateNextTimeOut(uint8_t u8ChannelID, uint32_t u32NextTimeOut);

/* ----------------------------------------------------------------------------
   -- Start/ Stop Timer
   ---------------------------------------------------------------------------- */
void Timer_StartChannel(uint8_t u8ChannelID, uint32_t u32TimeOut);
void Timer_StopChannel(uint8_t u8ChannelID);

/* ----------------------------------------------------------------------------
   -- Get Information's Channel
   ---------------------------------------------------------------------------- */
uint32_t Timer_GetTimeElapsed(uint8_t u8ChannelID);
uint32_t Timer_GetTimeRemain(uint8_t u8ChannelID);

/*  */
Timer_eSwStatus_Type Timer_GetChannelStatus(uint8_t u8ChannelID);
/* uint8_t Timer_GetActiveTimer(void); */

/* ----------------------------------------------------------------------------
   -- Deinitialize
   ---------------------------------------------------------------------------- */
void Timer_DeinitChannel(uint8_t u8ChannelID);
void Timer_Deinit(void);

#endif /* _TIMER_H_ */
