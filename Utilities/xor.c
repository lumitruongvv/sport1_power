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

u8 XOR_Caculator(uint8_t* data, uint8_t ofset, uint16_t length)
{
    u8 result = 0;
    for(u8 i = ofset; i < length; i++)
    {
        result ^= data[i];
    }
    return result;
}