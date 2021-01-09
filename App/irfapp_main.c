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

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
static void APP_SendFirstTime(u8 type,u8 *buff, u8 len);

static void APP_SendFirstTime1(u8 type,u8 *buff, u8 len);

static void APP_SendFirstTime2(u8 type,u8 *buff, u8 len);

static void APP_DeviceAnnounce(u8 type,u8 *buff, u8 len);

static void APP_CheckConnect(u8 type,u8 *buff, u8 len);

static void APP_StartRun(u8 type,u8 *buff, u8 len);

static void APP_StopRun(u8 type, u8 *buff, u8 len);

static void APP_UpDownFloor(u8 type, u8 *buff, u8 len);

static void APP_GetStateMotor(u8 type, u8 *buff, u8 len);

static void APP_GetStateFloor(u8 type, u8 *buff, u8 len);

static void APP_SetSpeedMotor(u8 type, u8 *buff, u8 len);

static void APP_GetAllState(u8 type, u8 *buff, u8 len);

static const App_ComandInfo_t appListCommand[]=
{
    {SEND_FIRST_TIME        ,APP_SendFirstTime},
    {SEND_FIRST_TIME_1      ,APP_SendFirstTime1},
    {SEND_FIRST_TIME_2      ,APP_SendFirstTime2},
    {DEVICE_ANNOUNCE        ,APP_DeviceAnnounce},
    {CHECK_CONNECT          ,APP_CheckConnect},
    {START_RUN              ,APP_StartRun},
    {STOP_RUN               ,APP_StopRun},
    {UP_DOW_FLOOR           ,APP_UpDownFloor},
    {GET_STATE_MOTOR        ,APP_GetStateMotor},
    {GET_STATE_FLOOR        ,APP_GetStateFloor},
    {SET_SPEED_MOTOR        ,APP_SetSpeedMotor},
    {GET_ALL_STATE          ,APP_GetAllState}
};

/**
 * @func   APP_CheckCommandExistAndExecutes
 * @brief  None
 * @param  
 * @retval None
 */
void APP_CheckCommandExistAndExecutes(u8 command, u8 type, u8* buff, u8 length)
{
    for(int i = 0; i<sizeof(appListCommand)/sizeof(App_ComandInfo_t);i++)
    {
        if(command == appListCommand[i].cmdId)
        {
            if(appListCommand[i].cmdHandle != NULL)
            {
                appListCommand[i].cmdHandle(type, buff, length);
            }
        }
    }
}


/**
 * @func   APP_SendFirstTime
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_SendFirstTime(u8 type,u8 *buff, u8 len)
{

}

/**
 * @func   APP_SendFirstTime1
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_SendFirstTime1(u8 type,u8 *buff, u8 len)
{

}

/**
 * @func   APP_SendFirstTime2
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_SendFirstTime2(u8 type,u8 *buff, u8 len)
{

}

/**
 * @func   APP_DeviceAnnounce
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_DeviceAnnounce(u8 type,u8 *buff, u8 len)
{

}

/**
 * @func   APP_CheckConnect
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_CheckConnect(u8 type,u8 *buff, u8 len)
{

}

/**
 * @func   APP_StartRun
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_StartRun(u8 type,u8 *buff, u8 len)
{

}

/**
 * @func   APP_StopRun
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_StopRun(u8 type, u8 *buff, u8 len)
{

}

/**
 * @func   APP_UpDownFloor
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_UpDownFloor(u8 type, u8 *buff, u8 len)
{

}

/**
 * @func   APP_GetStateMotor
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_GetStateMotor(u8 type, u8 *buff, u8 len)
{

}

/**
 * @func   APP_GetStateFloor
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_GetStateFloor(u8 type, u8 *buff, u8 len)
{

}

/**
 * @func   APP_SetSpeedMotor
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_SetSpeedMotor(u8 type, u8 *buff, u8 len)
{

}

/**
 * @func   APP_GetAllState
 * @brief  None
 * @param  
 * @retval None
 */
static void APP_GetAllState(u8 type, u8 *buff, u8 len)
{

}