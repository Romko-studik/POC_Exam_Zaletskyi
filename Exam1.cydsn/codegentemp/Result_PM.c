/*******************************************************************************
* File Name: Result.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Result.h"

static Result_BACKUP_STRUCT  Result_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Result_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Result_SUT.c usage_Result_Sleep_Wakeup
*******************************************************************************/
void Result_Sleep(void)
{
    #if defined(Result__PC)
        Result_backup.pcState = Result_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Result_backup.usbState = Result_CR1_REG;
            Result_USB_POWER_REG |= Result_USBIO_ENTER_SLEEP;
            Result_CR1_REG &= Result_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Result__SIO)
        Result_backup.sioState = Result_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Result_SIO_REG &= (uint32)(~Result_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Result_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Result_Sleep() for an example usage.
*******************************************************************************/
void Result_Wakeup(void)
{
    #if defined(Result__PC)
        Result_PC = Result_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Result_USB_POWER_REG &= Result_USBIO_EXIT_SLEEP_PH1;
            Result_CR1_REG = Result_backup.usbState;
            Result_USB_POWER_REG &= Result_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Result__SIO)
        Result_SIO_REG = Result_backup.sioState;
    #endif
}


/* [] END OF FILE */
