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
* File Name    : r_cg_it.h
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1054A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for IT module.
* Creation Date: 2024/07/24
***********************************************************************************************************************/
#ifndef IT_H
#define IT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    12-bit Interval Timer Control Register (ITMC) 
*/
/* 12-bit Interval timer operation control (RINTE) */
#define _0000_IT_OPERATION_DISABLE             (0x0000U) /* Count operation stopped */
#define _8000_IT_OPERATION_ENABLE              (0x8000U) /* Count operation started */

/*
    Timer clock select register 3 (TPS3) 
*/
/* Selection of count clock (TPS302 - TPS300) */
#define _00_IT_CLOCK_FIL                       (0x00U) /* fIL */
#define _01_IT_CLOCK_FCLK                      (0x01U) /* fCLK */
#define _02_IT_CLOCK_FCLK_2                    (0x02U) /* fCLK/2 */
#define _03_IT_CLOCK_FCLK_4                    (0x03U) /* fCLK/2^2 */
#define _04_IT_CLOCK_FCLK_8                    (0x04U) /* fCLK/2^3 */
#define _05_IT_CLOCK_FCLK_16                   (0x05U) /* fCLK/2^4 */
#define _06_IT_CLOCK_FCLK_32                   (0x06U) /* fCLK/2^5 */


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _05DB_ITCMP_VALUE                      (0x05DBU) /* Specification of the 12-bit interval timer compare value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_IT_Create(void);
void R_IT_Start(void);
void R_IT_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
