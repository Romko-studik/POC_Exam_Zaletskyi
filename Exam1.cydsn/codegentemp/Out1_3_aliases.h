/*******************************************************************************
* File Name: Out1_3.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Out1_3_ALIASES_H) /* Pins Out1_3_ALIASES_H */
#define CY_PINS_Out1_3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Out1_3_0			(Out1_3__0__PC)
#define Out1_3_0_PS		(Out1_3__0__PS)
#define Out1_3_0_PC		(Out1_3__0__PC)
#define Out1_3_0_DR		(Out1_3__0__DR)
#define Out1_3_0_SHIFT	(Out1_3__0__SHIFT)
#define Out1_3_0_INTR	((uint16)((uint16)0x0003u << (Out1_3__0__SHIFT*2u)))

#define Out1_3_INTR_ALL	 ((uint16)(Out1_3_0_INTR))


#endif /* End Pins Out1_3_ALIASES_H */


/* [] END OF FILE */
