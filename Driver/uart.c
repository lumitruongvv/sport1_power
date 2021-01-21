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
#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "uart.h"

type_UartCallBackFnc    p_uartCallBack = NULL;

/**
 * @func   UART_Init
 * @brief  None
 * @param  
 * @retval None
 */
void UART_Init (u32 baudRate) //use timer3 as Baudrate generator
{
    P06_Quasi_Mode;		//Setting UART pin as Quasi mode for transmit
    P07_Quasi_Mode;		//Setting UART pin as Quasi mode for transmit	

    #ifdef FOSC_160000
        RH3    = HIBYTE(65536 - (1000000/baudRate)-1);  		/*16 MHz */
        RL3    = LOBYTE(65536 - (1000000/baudRate)-1);			/*16 MHz */
    #endif
    #ifdef FOSC_166000
        RH3    = HIBYTE(65536 - (1037500/baudRate));  			/*16.6 MHz */
        RL3    = LOBYTE(65536 - (1037500/baudRate));				/*16.6 MHz */
    #endif

    SCON = 0x70;     //UART0 Mode1
    set_SMOD;        //UART0 Double Rate Enable
    T3CON &= 0xF8;   //T3PS2=0,T3PS1=0,T3PS0=0(Prescale=1)
    set_BRCK;        //UART0 baud rate clock source = Timer3
    set_TR3;         //Trigger Timer3
    UART_Disable();
}

/**
 * @func   UART_Enable
 * @brief  None
 * @param  
 * @retval None
 */
void UART_Enable(void)
{
    set_ES;
}

/**
 * @func   UART_Disable
 * @brief  None
 * @param  
 * @retval None
 */
void UART_Disable(void)
{
    clr_ES;
}


/**
 * @func   UART_SendByte
 * @brief  None
 * @param  
 * @retval None
 */
void UART_SendByte (u8 byte)
{
    TI = 0;
    SBUF = byte;
    while(TI==0);
}

/**
 * @func   UART_SendData
 * @brief  None
 * @param  
 * @retval None
 */
void UART_SendData (u8* buff, u8 length)
{
    uint8_t i;
	for(i = 0; i < length; i++)
    {
        UART_SendByte (buff[i]);
    }
}

/**
 * @func   UART_RevData
 * @brief  None
 * @param  
 * @retval None
 */
u8 UART_RevData (void)
{
	u8 dataRx;
	dataRx = SBUF;
	return dataRx;
}

/**
 * @func   MODIFY_Hirc166
 * @brief  None
 * @param  
 * @retval None
 */
void MODIFY_Hirc166(void)
{
    UINT8 xdata hircmap0,hircmap1;
    UINT16 xdata trimvalue16bit;
    // Check if power on reset, modify HIRC 
    if ((PCON&SET_BIT4)==SET_BIT4)				
    {
        hircmap0 = RCTRIM0;
        hircmap1 = RCTRIM1;
        trimvalue16bit = ((hircmap0<<1)+(hircmap1&0x01));
        trimvalue16bit = trimvalue16bit - 15;
        hircmap1 = trimvalue16bit&0x01;
        hircmap0 = trimvalue16bit>>1;
        TA=0XAA;
        TA=0X55;
        RCTRIM0 = hircmap0;
        TA=0XAA;
        TA=0X55;
        RCTRIM1 = hircmap1;
        // Clear power on flag 
        PCON &= CLR_BIT4;
    }
}

/**
 * @func   UART_CallBackInit
 * @brief  None
 * @param  
 * @retval None
 */
void UART_CallBackInit(type_UartCallBackFnc uartCallBackFnc)
{
    p_uartCallBack = uartCallBackFnc;
}

/**
 * @func   SerialPort0_ISR
 * @brief  None
 * @param  
 * @retval None
 */
void SerialPort0_ISR(void) interrupt 4
{
    if(RI == SET)
    {
        clr_RI;
        if(p_uartCallBack != NULL)
        {
            p_uartCallBack();
        }
    }
}