/*
 *      irfapp_main.c
 *
 *      Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "irfapp_main.h"


volatile uint8_t deviceAnnounceFlag = 0;
volatile uint8_t checkConnectFlag = 0;
volatile uint8_t startRunFlag = 0;
volatile uint8_t stopRunFlag = 0;
volatile uint8_t updownFloorFlag = 0;
volatile uint8_t getStateMotorFlag = 0;
volatile uint8_t getStateFloorFlag = 0;
volatile uint8_t setSpeedMotorFlag = 0;
volatile uint8_t getAllStateFlag = 0;
volatile uint8_t resetDeviceFlag = 0;
volatile uint8_t speedValue = 0;


/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
static void APP_DeviceAnnounce(u8 type,u8 *buff, u8 length);

static void APP_CheckConnect(u8 type,u8 *buff, u8 length);

static void APP_StartRun(u8 type,u8 *buff, u8 length);

static void APP_StopRun(u8 type, u8 *buff, u8 length);

static void APP_UpDownFloor(u8 type, u8 *buff, u8 length);

static void APP_GetStateMotor(u8 type, u8 *buff, u8 length);

static void APP_GetStateFloor(u8 type, u8 *buff, u8 length);

static void APP_SetSpeedMotor(u8 type, u8 *buff, u8 length);

static void APP_GetAllState(u8 type, u8 *buff, u8 length);

static void APP_ResetDevice(u8 type, u8 *buff, u8 length);


/**
 * @func   APP_CheckCommandExistAndExecutes
 * @brief  None
 * @param  
 * @retval None
 */
void APP_CheckCommandExistAndExecutes(u8 command, u8 type, u8* buff, u8 length)
{
    switch (command)
    {
    case DEVICE_ANNOUNCE:
        APP_DeviceAnnounce(type, buff, length);
        break;
    case CHECK_CONNECT:
        APP_CheckConnect(type, buff, length);
        break;
    case START_RUN:
        APP_StartRun(type, buff, length);
        break;
    case STOP_RUN:
        APP_StopRun(type, buff, length);
        break;
    case UP_DOW_FLOOR:
        APP_UpDownFloor(type, buff, length);
        break;
    case GET_STATE_MOTOR:
        APP_GetStateMotor(type, buff, length);
        break;
    case GET_STATE_FLOOR:
        APP_GetStateFloor(type, buff, length);
        break;
    case SET_SPEED_MOTOR:
        APP_SetSpeedMotor(type, buff, length);
        break;
    case GET_ALL_STATE:
        APP_GetAllState(type, buff, length);
        break;
    case RESET_DEVICE:
        APP_ResetDevice(type, buff, length);
        break;
    default:
        break;
    }
}


/**
 * @func   APP_DeviceAnnounce
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_DeviceAnnounce(u8 type,u8 *buff, u8 length)
{
    deviceAnnounceFlag = 1;
}

/**
 * @func   APP_CheckConnect
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_CheckConnect(u8 type,u8 *buff, u8 length)
{
	checkConnectFlag = 1;
}

/**
 * @func   APP_StartRun
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_StartRun(u8 type,u8 *buff, u8 length)
{
    startRunFlag = 1;
}

/**
 * @func   APP_StopRun
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_StopRun(u8 type, u8 *buff, u8 length)
{
    stopRunFlag = 1;
}

/**
 * @func   APP_UpDownFloor
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_UpDownFloor(u8 type, u8 *buff, u8 length)
{
    updownFloorFlag = 1;
}

/**
 * @func   APP_GetStateMotor
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_GetStateMotor(u8 type, u8 *buff, u8 length)
{
    getStateMotorFlag = 1;

}

/**
 * @func   APP_GetStateFloor
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_GetStateFloor(u8 type, u8 *buff, u8 length)
{
    getStateFloorFlag = 1;
}

/**
 * @func   APP_SetSpeedMotor
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_SetSpeedMotor(u8 type, u8 *buff, u8 length)
{
    setSpeedMotorFlag = 1;
    speedValue = buff[0];
}

/**
 * @func   APP_GetAllState
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_GetAllState(u8 type, u8 *buff, u8 length)
{
    getAllStateFlag = 1;
}   

/**
 * @func   APP_ResetDevice
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_ResetDevice(u8 type, u8 *buff, u8 length)
{
    resetDeviceFlag = 1;
}