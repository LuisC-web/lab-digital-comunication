/*******************************************************************************
* File Name: Q.h  
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

#if !defined(CY_PINS_Q_H) /* Pins Q_H */
#define CY_PINS_Q_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Q_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Q__PORT == 15 && ((Q__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Q_Write(uint8 value);
void    Q_SetDriveMode(uint8 mode);
uint8   Q_ReadDataReg(void);
uint8   Q_Read(void);
void    Q_SetInterruptMode(uint16 position, uint16 mode);
uint8   Q_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Q_SetDriveMode() function.
     *  @{
     */
        #define Q_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Q_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Q_DM_RES_UP          PIN_DM_RES_UP
        #define Q_DM_RES_DWN         PIN_DM_RES_DWN
        #define Q_DM_OD_LO           PIN_DM_OD_LO
        #define Q_DM_OD_HI           PIN_DM_OD_HI
        #define Q_DM_STRONG          PIN_DM_STRONG
        #define Q_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Q_MASK               Q__MASK
#define Q_SHIFT              Q__SHIFT
#define Q_WIDTH              1u

/* Interrupt constants */
#if defined(Q__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Q_SetInterruptMode() function.
     *  @{
     */
        #define Q_INTR_NONE      (uint16)(0x0000u)
        #define Q_INTR_RISING    (uint16)(0x0001u)
        #define Q_INTR_FALLING   (uint16)(0x0002u)
        #define Q_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Q_INTR_MASK      (0x01u) 
#endif /* (Q__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Q_PS                     (* (reg8 *) Q__PS)
/* Data Register */
#define Q_DR                     (* (reg8 *) Q__DR)
/* Port Number */
#define Q_PRT_NUM                (* (reg8 *) Q__PRT) 
/* Connect to Analog Globals */                                                  
#define Q_AG                     (* (reg8 *) Q__AG)                       
/* Analog MUX bux enable */
#define Q_AMUX                   (* (reg8 *) Q__AMUX) 
/* Bidirectional Enable */                                                        
#define Q_BIE                    (* (reg8 *) Q__BIE)
/* Bit-mask for Aliased Register Access */
#define Q_BIT_MASK               (* (reg8 *) Q__BIT_MASK)
/* Bypass Enable */
#define Q_BYP                    (* (reg8 *) Q__BYP)
/* Port wide control signals */                                                   
#define Q_CTL                    (* (reg8 *) Q__CTL)
/* Drive Modes */
#define Q_DM0                    (* (reg8 *) Q__DM0) 
#define Q_DM1                    (* (reg8 *) Q__DM1)
#define Q_DM2                    (* (reg8 *) Q__DM2) 
/* Input Buffer Disable Override */
#define Q_INP_DIS                (* (reg8 *) Q__INP_DIS)
/* LCD Common or Segment Drive */
#define Q_LCD_COM_SEG            (* (reg8 *) Q__LCD_COM_SEG)
/* Enable Segment LCD */
#define Q_LCD_EN                 (* (reg8 *) Q__LCD_EN)
/* Slew Rate Control */
#define Q_SLW                    (* (reg8 *) Q__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Q_PRTDSI__CAPS_SEL       (* (reg8 *) Q__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Q_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Q__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Q_PRTDSI__OE_SEL0        (* (reg8 *) Q__PRTDSI__OE_SEL0) 
#define Q_PRTDSI__OE_SEL1        (* (reg8 *) Q__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Q_PRTDSI__OUT_SEL0       (* (reg8 *) Q__PRTDSI__OUT_SEL0) 
#define Q_PRTDSI__OUT_SEL1       (* (reg8 *) Q__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Q_PRTDSI__SYNC_OUT       (* (reg8 *) Q__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Q__SIO_CFG)
    #define Q_SIO_HYST_EN        (* (reg8 *) Q__SIO_HYST_EN)
    #define Q_SIO_REG_HIFREQ     (* (reg8 *) Q__SIO_REG_HIFREQ)
    #define Q_SIO_CFG            (* (reg8 *) Q__SIO_CFG)
    #define Q_SIO_DIFF           (* (reg8 *) Q__SIO_DIFF)
#endif /* (Q__SIO_CFG) */

/* Interrupt Registers */
#if defined(Q__INTSTAT)
    #define Q_INTSTAT            (* (reg8 *) Q__INTSTAT)
    #define Q_SNAP               (* (reg8 *) Q__SNAP)
    
	#define Q_0_INTTYPE_REG 		(* (reg8 *) Q__0__INTTYPE)
#endif /* (Q__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Q_H */


/* [] END OF FILE */
