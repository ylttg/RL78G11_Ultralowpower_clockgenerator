/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2016, 2021 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_it.c
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1054A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for IT module.
* Creation Date: 2024/07/24
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_it.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_IT_Create
* Description  : This function initializes the IT module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT_Create(void)
{
    TMKARES = 1U;   /* reset 12-bit interval timer */
    TMKARES = 0U;   /* reset release of 12-bit interval timer */
    TMKAEN = 1U;    /* enables input clock supply */
    ITMC = _0000_IT_OPERATION_DISABLE;
    TMKAMK = 1U;    /* disable INTIT interrupt */
    TMKAIF = 0U;    /* clear INTIT interrupt flag */
    /* Set INTIT low priority */
    TMKAPR1 = 1U;
    TMKAPR0 = 1U;
    TPS3 = _00_IT_CLOCK_FIL;
    ITMC = _05DB_ITCMP_VALUE;
}
/***********************************************************************************************************************
* Function Name: R_IT_Start
* Description  : This function starts IT module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT_Start(void)
{
    TMKAIF = 0U;    /* clear INTIT interrupt flag */
    TMKAMK = 0U;    /* enable INTIT interrupt */
    ITMC |= _8000_IT_OPERATION_ENABLE;
}
/***********************************************************************************************************************
* Function Name: R_IT_Stop
* Description  : This function stops IT module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT_Stop(void)
{
    TMKAMK = 1U;    /* disable INTIT interrupt */
    TMKAIF = 0U;    /* clear INTIT interrupt flag */
    ITMC &= (uint16_t)~_8000_IT_OPERATION_ENABLE;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
