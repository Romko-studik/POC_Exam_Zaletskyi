/*******************************************************************************
* File Name: Result.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Result_H) /* Pins Result_H */
#define CY_PINS_Result_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Result_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Result_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Result_Read(void);
void    Result_Write(uint8 value);
uint8   Result_ReadDataReg(void);
#if defined(Result__PC) || (CY_PSOC4_4200L) 
    void    Result_SetDriveMode(uint8 mode);
#endif
void    Result_SetInterruptMode(uint16 position, uint16 mode);
uint8   Result_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Result_Sleep(void); 
void Result_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Result__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Result_DRIVE_MODE_BITS        (3)
    #define Result_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Result_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Result_SetDriveMode() function.
         *  @{
         */
        #define Result_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Result_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Result_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Result_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Result_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Result_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Result_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Result_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Result_MASK               Result__MASK
#define Result_SHIFT              Result__SHIFT
#define Result_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Result_SetInterruptMode() function.
     *  @{
     */
        #define Result_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Result_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Result_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Result_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Result__SIO)
    #define Result_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Result__PC) && (CY_PSOC4_4200L)
    #define Result_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Result_USBIO_DISABLE              ((uint32)(~Result_USBIO_ENABLE))
    #define Result_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Result_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Result_USBIO_ENTER_SLEEP          ((uint32)((1u << Result_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Result_USBIO_SUSPEND_DEL_SHIFT)))
    #define Result_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Result_USBIO_SUSPEND_SHIFT)))
    #define Result_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Result_USBIO_SUSPEND_DEL_SHIFT)))
    #define Result_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Result__PC)
    /* Port Configuration */
    #define Result_PC                 (* (reg32 *) Result__PC)
#endif
/* Pin State */
#define Result_PS                     (* (reg32 *) Result__PS)
/* Data Register */
#define Result_DR                     (* (reg32 *) Result__DR)
/* Input Buffer Disable Override */
#define Result_INP_DIS                (* (reg32 *) Result__PC2)

/* Interrupt configuration Registers */
#define Result_INTCFG                 (* (reg32 *) Result__INTCFG)
#define Result_INTSTAT                (* (reg32 *) Result__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Result_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Result__SIO)
    #define Result_SIO_REG            (* (reg32 *) Result__SIO)
#endif /* (Result__SIO_CFG) */

/* USBIO registers */
#if !defined(Result__PC) && (CY_PSOC4_4200L)
    #define Result_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Result_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Result_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Result_DRIVE_MODE_SHIFT       (0x00u)
#define Result_DRIVE_MODE_MASK        (0x07u << Result_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Result_H */


/* [] END OF FILE */
