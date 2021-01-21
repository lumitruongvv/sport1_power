/*
 *      motor.h
 *
 *      Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef MOTOR_H
#define MOTOR_H
/*****************************************************************************/
/*                              DEFINE                                      */
/******************************************************************************/
#define DEFAULTDUTY    15000
#define DEFAULTSPEEP    13500
/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

void MOTOR_Config(void);
void MOTOR_Init(uint16_t defaultDuty);
uint16_t MOTOR_GetCurrentSpeed(uint8_t revSpeed);
void MOTOR_SetSpeed(uint16_t currentDuty, uint16_t desireDuty);

#endif /* MOTOR_H */