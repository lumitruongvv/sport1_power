/*
 * Copyright (c) 2021
 * Team, JSC.
 * All Rights Reserved
 *
 *
 * Description:
 *
 * Author: Truongvv
 *
 * Last Changed By:  $Author: Truongvv $
 * Revision:         $Revision: 1.0 $
 * Last Changed:     $Date: x/x/xxxx $
 */

#ifndef UART_H_

#define UART_H_


/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/


/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/

#define UART_BAUDRATE           1200
typedef void (*type_UartCallBackFnc)(void);

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

void UART_Init (u32 baudRate);
void UART_Enable(void);
void UART_Disable(void);
void UART_SendByte (u8 byte);
void UART_SendData (u8* buff, u8 length);
u8 UART_RevData (void);
void MODIFY_Hirc166(void);
void UART_CallBackInit(type_UartCallBackFnc uartCallBackFnc);

#endif	/* UART_H_ */