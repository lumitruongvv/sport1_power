/*
 *      mainfunclist.c
 *
 *      Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "irfapp_main.h"
#include "mainfunclist.h"
#include "Irf.h"
#include "motor.h"
#include "relay.h"
#include "xor.h"

/******************************************************************************/
/*                              DECLARE                                      */
/******************************************************************************/

uint8_t checkConnect[]  = {0x20, 0xA1, 0x00, 0x01, 0x0A, 0x8A};
uint8_t startRun[]      = {0x30, 0xA1, 0x00, 0x01, 0x0A, 0x9A};
uint8_t stopRun[]       = {0x40, 0xA1, 0x00, 0x01, 0x0A, 0xEA};
uint8_t updownFloor[]   = {0x50, 0xA1, 0x00, 0x01, 0x0A, 0xFA};
uint8_t getStateMotor[] = {0x70, 0xA1, 0x00, 0x01, 0x72, 0xA2};
uint8_t getStateFloor[] = {0x73, 0xA1, 0x00, 0x01, 0x75, 0xA6};
uint8_t setSpeedMotor[] = {0x80, 0xA1, 0x00, 0x01, 0x0A, 0x2A};
uint8_t getAllState[]   = {0x90, 0xA1, 0x00, 0x02, 0x21, 0x71, 0x63};
uint8_t resetDevice[]   = {0x0F, 0xA1, 0x00, 0x01, 0x0A, 0xA5};

extern volatile uint8_t deviceAnnounceFlag;
extern volatile uint8_t checkConnectFlag;
extern volatile uint8_t startRunFlag;
extern volatile uint8_t stopRunFlag;
extern volatile uint8_t updownFloorFlag;
extern volatile uint8_t getStateMotorFlag;
extern volatile uint8_t getStateFloorFlag;
extern volatile uint8_t setSpeedMotorFlag;
extern volatile uint8_t getAllStateFlag;
extern volatile uint8_t resetDeviceFlag = 0;
extern volatile uint8_t speedValue;

uint16_t currentDuty;
uint8_t stateConnectFlag;
uint8_t stateMotorFlag;
uint8_t stateFloorFlag;

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

/**
 * @func   funcHandle_AllFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_AllFlag(void)
{
    if(deviceAnnounceFlag==1||checkConnectFlag==1||startRunFlag==1||\
        stopRunFlag==1||updownFloorFlag==1||getStateMotorFlag==1||\
        getStateFloorFlag==1||setSpeedMotorFlag==1||getAllStateFlag==1)
    {
        if(deviceAnnounceFlag == 1)
        {
            funcHandle_DeviceAnnounceFlag();

        }else if(checkConnectFlag == 1)
        {
            funcHandle_CheckConnectFlag();

        }else if(startRunFlag == 1)
        {   
            funcHandle_StartRunFlag();

        }else if(stopRunFlag == 1)
        {
            funcHandle_StopRunFlag();

        }else if(updownFloorFlag == 1)
        {
            funcHandle_UpdownFloorFlag();

        }else if(getStateMotorFlag == 1)
        {
            funcHandle_GetStateMotorFlag();

        }else if(getStateFloorFlag == 1)
        {
            funcHandle_GetStateFloorFlag();

        }else if(setSpeedMotorFlag == 1)
        {
            funcHandle_SetSpeedMotorFlag();

        }else if(getAllStateFlag == 1)
        {
            funcHandle_GetAllStateFlag();

        }
    }
}
/**
 * @func   funcHandle_DeviceAnnounceFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_DeviceAnnounceFlag(void)
{
    
}
/**
 * @func   funcHandle_CheckConnectFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_CheckConnectFlag(void)
{
    checkConnectFlag = 0;
    IRF_Send(checkConnect, sizeof(checkConnect));
    stateConnectFlag = 1;
}
/**
 * @func   funcHandle_StartRunFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_StartRunFlag(void)
{
    startRunFlag = 0;
    IRF_Send(startRun, sizeof(startRun));
    RELAY_AC(ON);
    MOTOR_SetSpeed(DEFAULTDUTY, DEFAULTSPEEP);
    currentDuty = DEFAULTSPEEP;
}
/**
 * @func   funcHandle_StopRunFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_StopRunFlag(void)
{

    stopRunFlag = 0;
    IRF_Send(stopRun, sizeof(stopRun));
    MOTOR_SetSpeed(currentDuty, DEFAULTDUTY);
    RELAY_AC(OFF);
}
/**
 * @func   funcHandle_UpdownFloorFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_UpdownFloorFlag(void)
{
    updownFloorFlag = 0;
    IRF_Send(updownFloor, sizeof(updownFloor));
}

/**
 * @func   funcHandle_GetStateMotorFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_GetStateMotorFlag(void)
{
    getStateMotorFlag = 0;
    IRF_Send(getStateMotor, sizeof(getStateMotor));
}
/**
 * @func   funcHandle_GetStateFloorFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_GetStateFloorFlag(void)
{
    getStateFloorFlag = 0;
    IRF_Send(getStateFloor, sizeof(getStateFloor));
}

/**
 * @func   funcHandle_SetSpeedMotorFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_SetSpeedMotorFlag(void)
{
    uint16_t desireDuty;
    setSpeedMotorFlag = 0;
    IRF_Send(setSpeedMotor, sizeof(setSpeedMotor));
    desireDuty = MOTOR_GetCurrentSpeed(speedValue);
    MOTOR_SetSpeed(currentDuty, desireDuty);
    currentDuty = desireDuty;
}

/**
 * @func   funcHandle_GetAllStateFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_GetAllStateFlag(void)
{
    getAllStateFlag = 0;
    /* kiem tra xem co motor hay khong */
    if(stateConnectFlag == 1)
    {
        getAllState[4] = CHECK_CONNECT_SUCCESS;
    }else
    {
        getAllState[4] = CHECK_CONNECT_NOTSUCCESS;
    }
    if(stateMotorFlag == 1)
    {
        getAllState[5] = IS_HAVEMOTOR;
    }else
    {
        getAllState[5] = IS_NOTMOTOR;
    }
    getAllState[6] = XOR_Caculator(getAllState, 0, sizeof(getAllState)-1);
    IRF_Send(getAllState, sizeof(getAllState));
}

/**
 * @func   funcHandle_ResetDeviceFlag
 * @brief  None
 * @param  
 * @retval None
 */
void funcHandle_ResetDeviceFlag(void)
{
    resetDeviceFlag = 0;
    IRF_Send(resetDevice, sizeof(resetDevice));

}