/*******************************************************************************
* File Name: I.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_I_H) /* Pins I_H */
#define CY_PINS_I_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "I_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 I__PORT == 15 && ((I__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    I_Write(uint8 value);
void    I_SetDriveMode(uint8 mode);
uint8   I_ReadDataReg(void);
uint8   I_Read(void);
void    I_SetInterruptMode(uint16 position, uint16 mode);
uint8   I_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the I_SetDriveMode() function.
     *  @{
     */
        #define I_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define I_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define I_DM_RES_UP          PIN_DM_RES_UP
        #define I_DM_RES_DWN         PIN_DM_RES_DWN
        #define I_DM_OD_LO           PIN_DM_OD_LO
        #define I_DM_OD_HI           PIN_DM_OD_HI
        #define I_DM_STRONG          PIN_DM_STRONG
        #define I_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define I_MASK               I__MASK
#define I_SHIFT              I__SHIFT
#define I_WIDTH              1u

/* Interrupt constants */
#if defined(I__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in I_SetInterruptMode() function.
     *  @{
     */
        #define I_INTR_NONE      (uint16)(0x0000u)
        #define I_INTR_RISING    (uint16)(0x0001u)
        #define I_INTR_FALLING   (uint16)(0x0002u)
        #define I_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define I_INTR_MASK      (0x01u) 
#endif /* (I__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define I_PS                     (* (reg8 *) I__PS)
/* Data Register */
#define I_DR                     (* (reg8 *) I__DR)
/* Port Number */
#define I_PRT_NUM                (* (reg8 *) I__PRT) 
/* Connect to Analog Globals */                                                  
#define I_AG                     (* (reg8 *) I__AG)                       
/* Analog MUX bux enable */
#define I_AMUX                   (* (reg8 *) I__AMUX) 
/* Bidirectional Enable */                                                        
#define I_BIE                    (* (reg8 *) I__BIE)
/* Bit-mask for Aliased Register Access */
#define I_BIT_MASK               (* (reg8 *) I__BIT_MASK)
/* Bypass Enable */
#define I_BYP                    (* (reg8 *) I__BYP)
/* Port wide control signals */                                                   
#define I_CTL                    (* (reg8 *) I__CTL)
/* Drive Modes */
#define I_DM0                    (* (reg8 *) I__DM0) 
#define I_DM1                    (* (reg8 *) I__DM1)
#define I_DM2                    (* (reg8 *) I__DM2) 
/* Input Buffer Disable Override */
#define I_INP_DIS                (* (reg8 *) I__INP_DIS)
/* LCD Common or Segment Drive */
#define I_LCD_COM_SEG            (* (reg8 *) I__LCD_COM_SEG)
/* Enable Segment LCD */
#define I_LCD_EN                 (* (reg8 *) I__LCD_EN)
/* Slew Rate Control */
#define I_SLW                    (* (reg8 *) I__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define I_PRTDSI__CAPS_SEL       (* (reg8 *) I__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define I_PRTDSI__DBL_SYNC_IN    (* (reg8 *) I__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define I_PRTDSI__OE_SEL0        (* (reg8 *) I__PRTDSI__OE_SEL0) 
#define I_PRTDSI__OE_SEL1        (* (reg8 *) I__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define I_PRTDSI__OUT_SEL0       (* (reg8 *) I__PRTDSI__OUT_SEL0) 
#define I_PRTDSI__OUT_SEL1       (* (reg8 *) I__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define I_PRTDSI__SYNC_OUT       (* (reg8 *) I__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(I__SIO_CFG)
    #define I_SIO_HYST_EN        (* (reg8 *) I__SIO_HYST_EN)
    #define I_SIO_REG_HIFREQ     (* (reg8 *) I__SIO_REG_HIFREQ)
    #define I_SIO_CFG            (* (reg8 *) I__SIO_CFG)
    #define I_SIO_DIFF           (* (reg8 *) I__SIO_DIFF)
#endif /* (I__SIO_CFG) */

/* Interrupt Registers */
#if defined(I__INTSTAT)
    #define I_INTSTAT            (* (reg8 *) I__INTSTAT)
    #define I_SNAP               (* (reg8 *) I__SNAP)
    
	#define I_0_INTTYPE_REG 		(* (reg8 *) I__0__INTTYPE)
#endif /* (I__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_I_H */


/* [] END OF FILE */
