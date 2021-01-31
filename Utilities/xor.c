/*
 *  xor.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "xor.h"

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

u8 XOR_Caculator(uint8_t* buffer, uint8_t ofset, uint16_t length)
{
    u8 result = 0;
		u8 i = 0;
    for(i = ofset; i < length; i++)
    {
        result ^= buffer[i];
    }
    return result;
}