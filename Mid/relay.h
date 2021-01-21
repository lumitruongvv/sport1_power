
/*
 *  relay.h
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef _RELAY_H_
#define _RELAY_H_
/******************************************************************************/
/*                              DEFINE                                      */
/******************************************************************************/
#define DEFRELAYCONFIG_H

#define ON                  1
#define OFF                 0
#define RELAY_AC_PORT       P1
#define RELAY_UPDOWN_PORT   P0   
#define RELAY_AC_PIN        5
#define RELAY_UP_PIN        0   
#define RELAY_DOWN_PIN      1
#define RELAYAC_Init()      P15_PushPull_Mode
#define RELAYUP_Init()      P00_PushPull_Mode
#define RELAYDOWN_Init()    P01_PushPull_Mode
/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

void RELAY_Config (void);
void RELAY_AC(unsigned char state);
void RELAY_Up(void);
void RELAY_UpReset(void);
void RELAY_Down(void);
void RELAY_DownReset(void);

#endif /* _RELAY_H_/