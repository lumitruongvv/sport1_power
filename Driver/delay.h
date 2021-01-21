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

#ifndef DELAY_H_

#define DELAY_H_


/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/


/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/

#define F_CPU 		    16000000
#define dly_const       (F_CPU / 16000000.0) 
/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/
void delay_us(uint16_t  value);
void delay_ms(uint16_t  value);


#endif	/* DELAY_H_ */