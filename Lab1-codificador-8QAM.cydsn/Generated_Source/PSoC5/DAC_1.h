/*******************************************************************************
* File Name: DAC_1.h  
* Version 1.90
*
*  Description:
*    This file contains the function prototypes and constants used in
*    the 8-bit Voltage DAC (vDAC8) User Module.
*
*   Note:
*     
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_VDAC8_DAC_1_H) 
#define CY_VDAC8_DAC_1_H

#include "cytypes.h"
#include "cyfitter.h"

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component VDAC8_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/***************************************
*       Type defines
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState; 
    uint8 data_value;
}DAC_1_backupStruct;

/* component init state */
extern uint8 DAC_1_initVar;


/***************************************
*        Function Prototypes 
***************************************/

void DAC_1_Start(void)           ;
void DAC_1_Stop(void)            ;
void DAC_1_SetSpeed(uint8 speed) ;
void DAC_1_SetRange(uint8 range) ;
void DAC_1_SetValue(uint8 value) ;
void DAC_1_DacTrim(void)         ;
void DAC_1_Init(void)            ;
void DAC_1_Enable(void)          ;
void DAC_1_SaveConfig(void)      ;
void DAC_1_RestoreConfig(void)   ;
void DAC_1_Sleep(void)           ;
void DAC_1_Wakeup(void)          ;


/***************************************
*            API Constants
***************************************/

/* SetRange constants */

#define DAC_1_RANGE_1V       0x00u
#define DAC_1_RANGE_4V       0x04u


/* Power setting for Start API  */
#define DAC_1_LOWSPEED       0x00u
#define DAC_1_HIGHSPEED      0x02u


/***************************************
*  Initialization Parameter Constants
***************************************/

 /* Default DAC range */
#define DAC_1_DEFAULT_RANGE    4u
 /* Default DAC speed */
#define DAC_1_DEFAULT_SPEED    0u
 /* Default Control */
#define DAC_1_DEFAULT_CNTL      0x00u
/* Default Strobe mode */
#define DAC_1_DEFAULT_STRB     1u
 /* Initial DAC value */
#define DAC_1_DEFAULT_DATA     100u
 /* Default Data Source */
#define DAC_1_DEFAULT_DATA_SRC 0u


/***************************************
*              Registers        
***************************************/
#define DAC_1_CR0_REG            (* (reg8 *) DAC_1_viDAC8__CR0 )
#define DAC_1_CR0_PTR            (  (reg8 *) DAC_1_viDAC8__CR0 )
#define DAC_1_CR1_REG            (* (reg8 *) DAC_1_viDAC8__CR1 )
#define DAC_1_CR1_PTR            (  (reg8 *) DAC_1_viDAC8__CR1 )
#define DAC_1_Data_REG           (* (reg8 *) DAC_1_viDAC8__D )
#define DAC_1_Data_PTR           (  (reg8 *) DAC_1_viDAC8__D )
#define DAC_1_Strobe_REG         (* (reg8 *) DAC_1_viDAC8__STROBE )
#define DAC_1_Strobe_PTR         (  (reg8 *) DAC_1_viDAC8__STROBE )
#define DAC_1_SW0_REG            (* (reg8 *) DAC_1_viDAC8__SW0 )
#define DAC_1_SW0_PTR            (  (reg8 *) DAC_1_viDAC8__SW0 )
#define DAC_1_SW2_REG            (* (reg8 *) DAC_1_viDAC8__SW2 )
#define DAC_1_SW2_PTR            (  (reg8 *) DAC_1_viDAC8__SW2 )
#define DAC_1_SW3_REG            (* (reg8 *) DAC_1_viDAC8__SW3 )
#define DAC_1_SW3_PTR            (  (reg8 *) DAC_1_viDAC8__SW3 )
#define DAC_1_SW4_REG            (* (reg8 *) DAC_1_viDAC8__SW4 )
#define DAC_1_SW4_PTR            (  (reg8 *) DAC_1_viDAC8__SW4 )
#define DAC_1_TR_REG             (* (reg8 *) DAC_1_viDAC8__TR )
#define DAC_1_TR_PTR             (  (reg8 *) DAC_1_viDAC8__TR )
/* Power manager */
#define DAC_1_PWRMGR_REG         (* (reg8 *) DAC_1_viDAC8__PM_ACT_CFG )
#define DAC_1_PWRMGR_PTR         (  (reg8 *) DAC_1_viDAC8__PM_ACT_CFG )
  /* Standby Power manager */
#define DAC_1_STBY_PWRMGR_REG    (* (reg8 *) DAC_1_viDAC8__PM_STBY_CFG )
#define DAC_1_STBY_PWRMGR_PTR    (  (reg8 *) DAC_1_viDAC8__PM_STBY_CFG )

/***************************************
*  Registers definitions
* for backward capability        
***************************************/
#define DAC_1_CR0         (* (reg8 *) DAC_1_viDAC8__CR0 )
#define DAC_1_CR1         (* (reg8 *) DAC_1_viDAC8__CR1 )
#define DAC_1_Data        (* (reg8 *) DAC_1_viDAC8__D )
#define DAC_1_Data_PTR    (  (reg8 *) DAC_1_viDAC8__D )
#define DAC_1_Strobe      (* (reg8 *) DAC_1_viDAC8__STROBE )
#define DAC_1_SW0         (* (reg8 *) DAC_1_viDAC8__SW0 )
#define DAC_1_SW2         (* (reg8 *) DAC_1_viDAC8__SW2 )
#define DAC_1_SW3         (* (reg8 *) DAC_1_viDAC8__SW3 )
#define DAC_1_SW4         (* (reg8 *) DAC_1_viDAC8__SW4 )
#define DAC_1_TR          (* (reg8 *) DAC_1_viDAC8__TR )
/* Power manager */
#define DAC_1_PWRMGR      (* (reg8 *) DAC_1_viDAC8__PM_ACT_CFG )
  /* Standby Power manager */
#define DAC_1_STBY_PWRMGR (* (reg8 *) DAC_1_viDAC8__PM_STBY_CFG )


/***************************************
*         Register Constants       
***************************************/

/* CR0 vDac Control Register 0 definitions */

/* Bit Field  DAC_HS_MODE                  */
#define DAC_1_HS_MASK        0x02u
#define DAC_1_HS_LOWPOWER    0x00u
#define DAC_1_HS_HIGHSPEED   0x02u

/* Bit Field  DAC_MODE                  */
#define DAC_1_MODE_MASK      0x10u
#define DAC_1_MODE_V         0x00u
#define DAC_1_MODE_I         0x10u

/* Bit Field  DAC_RANGE                  */
#define DAC_1_RANGE_MASK     0x0Cu
#define DAC_1_RANGE_0        0x00u
#define DAC_1_RANGE_1        0x04u

/* CR1 iDac Control Register 1 definitions */

/* Bit Field  DAC_MX_DATA                  */
#define DAC_1_SRC_MASK       0x20u
#define DAC_1_SRC_REG        0x00u
#define DAC_1_SRC_UDB        0x20u

/* This bit enable reset from UDB array      */
#define DAC_1_RESET_MASK     0x10u
#define DAC_1_RESET_ENABLE   0x10u
#define DAC_1_RESET_DISABLE  0x00u

/* This bit enables data from DAC bus      */
#define DAC_1_DACBUS_MASK     0x20u
#define DAC_1_DACBUS_ENABLE   0x20u
#define DAC_1_DACBUS_DISABLE  0x00u

/* DAC STROBE Strobe Control Register definitions */

/* Bit Field  DAC_MX_STROBE                  */
#define DAC_1_STRB_MASK     0x08u
#define DAC_1_STRB_EN       0x08u
#define DAC_1_STRB_DIS      0x00u

/* PM_ACT_CFG (Active Power Mode CFG Register)     */ 
#define DAC_1_ACT_PWR_EN   DAC_1_viDAC8__PM_ACT_MSK
  /* Standby Power enable mask */
#define DAC_1_STBY_PWR_EN  DAC_1_viDAC8__PM_STBY_MSK


/*******************************************************************************
*              Trim    
* Note - VDAC trim values are stored in the "Customer Table" area in * Row 1 of
*the Hidden Flash.  There are 8 bytes of trim data for each VDAC block.
* The values are:
*       I Gain offset, min range, Sourcing
*       I Gain offset, min range, Sinking
*       I Gain offset, med range, Sourcing
*       I Gain offset, med range, Sinking
*       I Gain offset, max range, Sourcing
*       I Gain offset, max range, Sinking
*       V Gain offset, 1V range
*       V Gain offset, 4V range
*
* The data set for the 4 VDACs are arranged using a left side/right side
* approach:
*   Left 0, Left 1, Right 0, Right 1.
* When mapped to the VDAC0 thru VDAC3 as:
*   VDAC 0, VDAC 2, VDAC 1, VDAC 3
*******************************************************************************/
#define DAC_1_TRIM_M7_1V_RNG_OFFSET  0x06u
#define DAC_1_TRIM_M8_4V_RNG_OFFSET  0x07u
/*Constatnt to set DAC in current mode and turnoff output */
#define DAC_1_CUR_MODE_OUT_OFF       0x1Eu 
#define DAC_1_DAC_TRIM_BASE          (DAC_1_viDAC8__TRIM__M1)

#endif /* CY_VDAC8_DAC_1_H  */


/* [] END OF FILE */


