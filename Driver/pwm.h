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

#ifndef PWM_H_

#define PWM_H_


/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/


/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

void PWM_Init (void);
void PWM_CreatedPeriodDuty (uint16_t pwmDuty);
void PWM_Stop(uint16_t pwmDuty);
void PWM_Start(uint16_t pwmDuty);


#endif	/* PWM_H_*/