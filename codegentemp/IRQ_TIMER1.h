/*******************************************************************************
* File Name: IRQ_TIMER1.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_IRQ_TIMER1_H)
#define CY_ISR_IRQ_TIMER1_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void IRQ_TIMER1_Start(void);
void IRQ_TIMER1_StartEx(cyisraddress address);
void IRQ_TIMER1_Stop(void);

CY_ISR_PROTO(IRQ_TIMER1_Interrupt);

void IRQ_TIMER1_SetVector(cyisraddress address);
cyisraddress IRQ_TIMER1_GetVector(void);

void IRQ_TIMER1_SetPriority(uint8 priority);
uint8 IRQ_TIMER1_GetPriority(void);

void IRQ_TIMER1_Enable(void);
uint8 IRQ_TIMER1_GetState(void);
void IRQ_TIMER1_Disable(void);

void IRQ_TIMER1_SetPending(void);
void IRQ_TIMER1_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the IRQ_TIMER1 ISR. */
#define IRQ_TIMER1_INTC_VECTOR            ((reg32 *) IRQ_TIMER1__INTC_VECT)

/* Address of the IRQ_TIMER1 ISR priority. */
#define IRQ_TIMER1_INTC_PRIOR             ((reg8 *) IRQ_TIMER1__INTC_PRIOR_REG)

/* Priority of the IRQ_TIMER1 interrupt. */
#define IRQ_TIMER1_INTC_PRIOR_NUMBER      IRQ_TIMER1__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable IRQ_TIMER1 interrupt. */
#define IRQ_TIMER1_INTC_SET_EN            ((reg32 *) IRQ_TIMER1__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the IRQ_TIMER1 interrupt. */
#define IRQ_TIMER1_INTC_CLR_EN            ((reg32 *) IRQ_TIMER1__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the IRQ_TIMER1 interrupt state to pending. */
#define IRQ_TIMER1_INTC_SET_PD            ((reg32 *) IRQ_TIMER1__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the IRQ_TIMER1 interrupt. */
#define IRQ_TIMER1_INTC_CLR_PD            ((reg32 *) IRQ_TIMER1__INTC_CLR_PD_REG)


#endif /* CY_ISR_IRQ_TIMER1_H */


/* [] END OF FILE */
