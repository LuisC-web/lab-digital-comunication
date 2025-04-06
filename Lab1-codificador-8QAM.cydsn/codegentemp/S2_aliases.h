/*******************************************************************************
* File Name: S2.h  
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

#if !defined(CY_PINS_S2_ALIASES_H) /* Pins S2_ALIASES_H */
#define CY_PINS_S2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define S2_0			(S2__0__PC)
#define S2_0_INTR	((uint16)((uint16)0x0001u << S2__0__SHIFT))

#define S2_1			(S2__1__PC)
#define S2_1_INTR	((uint16)((uint16)0x0001u << S2__1__SHIFT))

#define S2_2			(S2__2__PC)
#define S2_2_INTR	((uint16)((uint16)0x0001u << S2__2__SHIFT))

#define S2_INTR_ALL	 ((uint16)(S2_0_INTR| S2_1_INTR| S2_2_INTR))

#endif /* End Pins S2_ALIASES_H */


/* [] END OF FILE */
