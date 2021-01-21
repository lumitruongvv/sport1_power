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

#ifndef PWM_H

#define PWM_H


/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/


/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/

#define PWM_PinInit()           P10_PushPull_Mode
#define PWM_PORT                P1

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

void PWM_Init (void);
void PWM_CreatedPeriodDuty (uint16_t pwmDuty);
void PWM_Stop(uint16_t pwmDuty);
void PWM_Start(uint16_t pwmDuty);


#endif	/* PWM_H*/