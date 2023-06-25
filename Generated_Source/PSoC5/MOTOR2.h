/*******************************************************************************
* File Name: MOTOR2.h  
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

#if !defined(CY_PINS_MOTOR2_H) /* Pins MOTOR2_H */
#define CY_PINS_MOTOR2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MOTOR2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MOTOR2__PORT == 15 && ((MOTOR2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MOTOR2_Write(uint8 value);
void    MOTOR2_SetDriveMode(uint8 mode);
uint8   MOTOR2_ReadDataReg(void);
uint8   MOTOR2_Read(void);
void    MOTOR2_SetInterruptMode(uint16 position, uint16 mode);
uint8   MOTOR2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MOTOR2_SetDriveMode() function.
     *  @{
     */
        #define MOTOR2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MOTOR2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MOTOR2_DM_RES_UP          PIN_DM_RES_UP
        #define MOTOR2_DM_RES_DWN         PIN_DM_RES_DWN
        #define MOTOR2_DM_OD_LO           PIN_DM_OD_LO
        #define MOTOR2_DM_OD_HI           PIN_DM_OD_HI
        #define MOTOR2_DM_STRONG          PIN_DM_STRONG
        #define MOTOR2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MOTOR2_MASK               MOTOR2__MASK
#define MOTOR2_SHIFT              MOTOR2__SHIFT
#define MOTOR2_WIDTH              1u

/* Interrupt constants */
#if defined(MOTOR2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MOTOR2_SetInterruptMode() function.
     *  @{
     */
        #define MOTOR2_INTR_NONE      (uint16)(0x0000u)
        #define MOTOR2_INTR_RISING    (uint16)(0x0001u)
        #define MOTOR2_INTR_FALLING   (uint16)(0x0002u)
        #define MOTOR2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MOTOR2_INTR_MASK      (0x01u) 
#endif /* (MOTOR2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOTOR2_PS                     (* (reg8 *) MOTOR2__PS)
/* Data Register */
#define MOTOR2_DR                     (* (reg8 *) MOTOR2__DR)
/* Port Number */
#define MOTOR2_PRT_NUM                (* (reg8 *) MOTOR2__PRT) 
/* Connect to Analog Globals */                                                  
#define MOTOR2_AG                     (* (reg8 *) MOTOR2__AG)                       
/* Analog MUX bux enable */
#define MOTOR2_AMUX                   (* (reg8 *) MOTOR2__AMUX) 
/* Bidirectional Enable */                                                        
#define MOTOR2_BIE                    (* (reg8 *) MOTOR2__BIE)
/* Bit-mask for Aliased Register Access */
#define MOTOR2_BIT_MASK               (* (reg8 *) MOTOR2__BIT_MASK)
/* Bypass Enable */
#define MOTOR2_BYP                    (* (reg8 *) MOTOR2__BYP)
/* Port wide control signals */                                                   
#define MOTOR2_CTL                    (* (reg8 *) MOTOR2__CTL)
/* Drive Modes */
#define MOTOR2_DM0                    (* (reg8 *) MOTOR2__DM0) 
#define MOTOR2_DM1                    (* (reg8 *) MOTOR2__DM1)
#define MOTOR2_DM2                    (* (reg8 *) MOTOR2__DM2) 
/* Input Buffer Disable Override */
#define MOTOR2_INP_DIS                (* (reg8 *) MOTOR2__INP_DIS)
/* LCD Common or Segment Drive */
#define MOTOR2_LCD_COM_SEG            (* (reg8 *) MOTOR2__LCD_COM_SEG)
/* Enable Segment LCD */
#define MOTOR2_LCD_EN                 (* (reg8 *) MOTOR2__LCD_EN)
/* Slew Rate Control */
#define MOTOR2_SLW                    (* (reg8 *) MOTOR2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MOTOR2_PRTDSI__CAPS_SEL       (* (reg8 *) MOTOR2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MOTOR2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MOTOR2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MOTOR2_PRTDSI__OE_SEL0        (* (reg8 *) MOTOR2__PRTDSI__OE_SEL0) 
#define MOTOR2_PRTDSI__OE_SEL1        (* (reg8 *) MOTOR2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MOTOR2_PRTDSI__OUT_SEL0       (* (reg8 *) MOTOR2__PRTDSI__OUT_SEL0) 
#define MOTOR2_PRTDSI__OUT_SEL1       (* (reg8 *) MOTOR2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MOTOR2_PRTDSI__SYNC_OUT       (* (reg8 *) MOTOR2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MOTOR2__SIO_CFG)
    #define MOTOR2_SIO_HYST_EN        (* (reg8 *) MOTOR2__SIO_HYST_EN)
    #define MOTOR2_SIO_REG_HIFREQ     (* (reg8 *) MOTOR2__SIO_REG_HIFREQ)
    #define MOTOR2_SIO_CFG            (* (reg8 *) MOTOR2__SIO_CFG)
    #define MOTOR2_SIO_DIFF           (* (reg8 *) MOTOR2__SIO_DIFF)
#endif /* (MOTOR2__SIO_CFG) */

/* Interrupt Registers */
#if defined(MOTOR2__INTSTAT)
    #define MOTOR2_INTSTAT            (* (reg8 *) MOTOR2__INTSTAT)
    #define MOTOR2_SNAP               (* (reg8 *) MOTOR2__SNAP)
    
	#define MOTOR2_0_INTTYPE_REG 		(* (reg8 *) MOTOR2__0__INTTYPE)
#endif /* (MOTOR2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MOTOR2_H */


/* [] END OF FILE */
