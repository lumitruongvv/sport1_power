/*
 *  irfapp_main.h
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef IRFAPP_MAIN_H_
#define IRFAPP_MAIN_H_

/******************************************************************************/
/*                              DEFINE                                      */
/******************************************************************************/

/* Command type */
#define MASTER_REQUEST_TYPE              0xB0
#define MASTER_REPONSE_TYE               0xB1
#define SLAVE_REQUEST_TYPE               0xA0
#define SLAVE_REPONSE_TYPE               0xA1

/* Command */
/* INFORMATION */
#define DEVICE_ANNOUNCE                 0x10

/* Connect */
#define CHECK_CONNECT                   0x20
#define CHECK_CONNECT_SUCCESS           0x21
#define CHECK_CONNECT_NOTSUCCESS        0x22
#define CHECK_CONNECT_STATE             0x23


/* Start */
#define START_RUN                       0x30
#define START_RUN_NORMAL                0x31
#define START_RUN_4KMH                  0x32
#define START_RUN_6KMH                  0x33
#define START_RUN_8KHM                  0x34
#define START_RUN_10KM                  0x35

/* Stop */
#define STOP_RUN                        0x40
#define STOP_RUN_BY_TIMEOUT             0x41
#define STOP_RUN_BY_USER                0x42
#define STOP_RUN_BY_ERROR_MOTOR         0x43
#define STOP_RUN_BY_ERROR_SYSTEM        0x44

/* CHANGE UP DOWN FLOOR */
#define UP_DOW_FLOOR                    0x50
#define FLOOR_MAX                       0x51
#define FLOOR_MIN                       0x52
#define FLOOR_NORMAL                    0x53


/* GET STATE MOTOR */
#define GET_STATE_MOTOR                 0x70
#define IS_HAVEMOTOR                    0x71
#define IS_NOTMOTOR                     0x72

/* SET STATE FLOOR  */  
#define GET_STATE_FLOOR                 0x73
#define IS_HAVEFLOOR                    0x74
#define IS_NOTFLOOR                     0x75

/* SET SPEED MOTOR */
#define SET_SPEED_MOTOR                 0x80
#define SET_SPEED_MOTOR_NORMAL          0x81
#define SET_SPEED_MOTOR_MAX             0x82
#define SET_SPEED_MOTOR_MIN             0x83

/* LOG STATE */
#define GET_ALL_STATE                   0x90
#define GET_ALL_REQUEST                 0x91  

/* RESET */
#define RESET_DEVICE                    0x0F

/* REPLY CONTENT */
#define YES                             0x0A
#define NO                              0x0B

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
void APP_CheckCommandExistAndExecutes(u8 command, u8 type, u8* buff, u8 length);

#endif /*IRFAPP_MAIN_H_*/