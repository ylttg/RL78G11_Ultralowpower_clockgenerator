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
* File Name    : r_cg_intp.h
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1054A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for INTP module.
* Creation Date: 2024/07/24
***********************************************************************************************************************/
#ifndef INTP_H
#define INTP_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Specify the valid edge for INTP0 to INTP7 (EGP0) 
*/
/* Valid edge selection (EGP7) */
#define _00_INTP7_EDGE_FALLING_DISABLE           (0x00U) /* edge detection disabled or falling edge */
#define _80_INTP7_EDGE_RISING_BOTH               (0x80U) /* rising or both edge */
/* Valid edge selection (EGP6) */
#define _00_INTP6_EDGE_FALLING_DISABLE           (0x00U) /* edge detection disabled or falling edge */
#define _40_INTP6_EDGE_RISING_BOTH               (0x40U) /* rising or both edge */
/* Valid edge selection (EGP5) */
#define _00_INTP5_EDGE_FALLING_DISABLE           (0x00U) /* edge detection disabled or falling edge */
#define _20_INTP5_EDGE_RISING_BOTH               (0x20U) /* rising or both edge */
/* Valid edge selection (EGP4) */
#define _00_INTP4_EDGE_FALLING_DISABLE           (0x00U) /* edge detection disabled or falling edge */
#define _10_INTP4_EDGE_RISING_BOTH               (0x10U) /* rising or both edge */
/* Valid edge selection (EGP3) */
#define _00_INTP3_EDGE_FALLING_DISABLE           (0x00U) /* edge detection disabled or falling edge */
#define _08_INTP3_EDGE_RISING_BOTH               (0x08U) /* rising or both edge */
/* Valid edge selection (EGP2) */
#define _00_INTP2_EDGE_FALLING_DISABLE           (0x00U) /* edge detection disabled or falling edge */
#define _04_INTP2_EDGE_RISING_BOTH               (0x04U) /* rising or both edge */
/* Valid edge selection (EGP1) */
#define _00_INTP1_EDGE_FALLING_DISABLE           (0x00U) /* edge detection disabled or falling edge */
#define _02_INTP1_EDGE_RISING_BOTH               (0x02U) /* rising or both edge */
/* Valid edge selection (EGP0) */
#define _00_INTP0_EDGE_FALLING_DISABLE           (0x00U) /* edge detection disabled or falling edge */
#define _01_INTP0_EDGE_RISING_BOTH               (0x01U) /* rising or both edge */

/*
    Specify the valid edge for INTP0 to INTP7 (EGN0) 
*/
/* Valid edge selection (EGN7) */
#define _00_INTP7_EDGE_RISING_DISABLE            (0x00U) /* edge detection disabled or rising edge */
#define _80_INTP7_EDGE_FALLING_BOTH              (0x80U) /* falling or both edge */
/* Valid edge selection (EGN6) */
#define _00_INTP6_EDGE_RISING_DISABLE            (0x00U) /* edge detection disabled or rising edge */
#define _40_INTP6_EDGE_FALLING_BOTH              (0x40U) /* falling or both edge */
/* Valid edge selection (EGN5) */
#define _00_INTP5_EDGE_RISING_DISABLE            (0x00U) /* edge detection disabled or rising edge */
#define _20_INTP5_EDGE_FALLING_BOTH              (0x20U) /* falling or both edge */
/* Valid edge selection (EGN4) */
#define _00_INTP4_EDGE_RISING_DISABLE            (0x00U) /* edge detection disabled or rising edge */
#define _10_INTP4_EDGE_FALLING_BOTH              (0x10U) /* falling or both edge */
/* Valid edge selection (EGN3) */
#define _00_INTP3_EDGE_RISING_DISABLE            (0x00U) /* edge detection disabled or rising edge */
#define _08_INTP3_EDGE_FALLING_BOTH              (0x08U) /* falling or both edge */
/* Valid edge selection (EGN2) */
#define _00_INTP2_EDGE_RISING_DISABLE            (0x00U) /* edge detection disabled or rising edge */
#define _04_INTP2_EDGE_FALLING_BOTH              (0x04U) /* falling or both edge */
/* Valid edge selection (EGN1) */
#define _00_INTP1_EDGE_RISING_DISABLE            (0x00U) /* edge detection disabled or rising edge */
#define _02_INTP1_EDGE_FALLING_BOTH              (0x02U) /* falling or both edge */
/* Valid edge selection (EGN0) */
#define _00_INTP0_EDGE_RISING_DISABLE            (0x00U) /* edge detection disabled or rising edge */
#define _01_INTP0_EDGE_FALLING_BOTH              (0x01U) /* falling or both edge */

/*
    Specify the valid edge for INTP8 to INTP11 (EGP1) 
*/
/* Valid edge selection (EGP11) */
#define _00_INTP11_EDGE_FALLING_DISABLE          (0x00U) /* edge detection disabled or falling edge */
#define _08_INTP11_EDGE_RISING_BOTH              (0x08U) /* rising or both edge */
/* Valid edge selection (EGP10) */
#define _00_INTP10_EDGE_FALLING_DISABLE          (0x00U) /* edge detection disabled or falling edge */
#define _04_INTP10_EDGE_RISING_BOTH              (0x04U) /* rising or both edge */
/* Valid edge selection (EGP9) */
#define _00_INTP9_EDGE_FALLING_DISABLE           (0x00U) /* edge detection disabled or falling edge */
#define _02_INTP9_EDGE_RISING_BOTH               (0x02U) /* rising or both edge */
/* Valid edge selection (EGP8) */
#define _00_INTP8_EDGE_FALLING_DISABLE           (0x00U) /* edge detection disabled or falling edge */
#define _01_INTP8_EDGE_RISING_BOTH               (0x01U) /* rising or both edge */

/*
    Specify the valid edge for INTP8 to INTP11 (EGN1) 
*/
/* Valid edge selection (EGN11) */
#define _00_INTP11_EDGE_RISING_DISABLE           (0x00U) /* edge detection disabled or rising edge */
#define _08_INTP11_EDGE_FALLING_BOTH             (0x08U) /* falling or both edge */
/* Valid edge selection (EGN10) */
#define _00_INTP10_EDGE_RISING_DISABLE           (0x00U) /* edge detection disabled or rising edge */
#define _04_INTP10_EDGE_FALLING_BOTH             (0x04U) /* falling or both edge */
/* Valid edge selection (EGN9) */
#define _00_INTP9_EDGE_RISING_DISABLE            (0x00U) /* edge detection disabled or rising edge */
#define _02_INTP9_EDGE_FALLING_BOTH              (0x02U) /* falling or both edge */
/* Valid edge selection (EGN8) */
#define _00_INTP8_EDGE_RISING_DISABLE            (0x00U) /* edge detection disabled or rising edge */
#define _01_INTP8_EDGE_FALLING_BOTH              (0x01U) /* falling or both edge */

/*
    Interrupt flag enable register (INTFE) 
*/
/*  The changing interrupt request flag of comparator 1 (INTCMP1FE) */
#define _00_CMP1_FLAG_DISABLE                    (0x00U) /* disable the changing interrupt request flag */
#define _80_CMP1_FLAG_ENABLE                     (0x80U) /* enable the changing interrupt request flag */
/* The changing interrupt request flag of comparator 0 (INTCMP0FE) */
#define _00_CMP0_FLAG_DISABLE                    (0x00U) /* disable the changing interrupt request flag */
#define _40_CMP0_FLAG_ENABLE                     (0x40U) /* enable the changing interrupt request flag */
/* The changing interrupt request flag of DOC (INTDOCFE) */
#define _00_DOC_FLAG_DISABLE                     (0x00U) /* disable the changing interrupt request flag */
#define _20_DOC_FLAG_ENABLE                      (0x20U) /* enable the changing interrupt request flag */
/* The changing interrupt request flag of timer KB (INTTMKB0FE) */
#define _00_TMKB0_FLAG_DISABLE                   (0x00U) /* disable the changing interrupt request flag */
#define _10_TMKB0_FLAG_ENABLE                    (0x10U) /* enable the changing interrupt request flag */
/* The changing interrupt request flag of 8-bit interval timer 01 (INTIT01FE) */
#define _00_IT01_FLAG_DISABLE                    (0x00U) /* disable the changing interrupt request flag */
#define _08_IT01_FLAG_ENABLE                     (0x08U) /* enable the changing interrupt request flag */
/* The changing interrupt request flag of 8-bit interval timer 00 (INTIT00FE) */
#define _00_IT00_FLAG_DISABLE                    (0x00U) /* disable the changing interrupt request flag */
#define _04_IT00_FLAG_ENABLE                     (0x04U) /* enable the changing interrupt request flag */
/* The changing interrupt request flag of 12-bit interval timer (INTITFE) */
#define _00_IT_FLAG_DISABLE                      (0x00U) /* disable the changing interrupt request flag */
#define _02_IT_FLAG_ENABLE                       (0x02U) /* enable the changing interrupt request flag */
/* The changing interrupt request flag of A/D converter (INTADFE) */
#define _00_AD_FLAG_DISABLE                      (0x00U) /* disable the changing interrupt request flag */
#define _01_AD_FLAG_ENABLE                       (0x01U) /* enable the changing interrupt request flag */

/*
    Peripheral function switch register (PFSEL0) 
*/
/* Invert setting of INTP11 signal (INTPINV1) */
#define _00_INTP11_OUTPUT_NORMAL                 (0x00U) /* do not invert INTP11 signal */
#define _20_INTP11_OUTPUT_INVERTED               (0x20U) /* invert INTP11 signal */
/* Invert setting of INTP10 signal (INTPINV0) */
#define _00_INTP10_OUTPUT_NORMAL                 (0x00U) /* do not invert INTP10 signal */
#define _10_INTP10_OUTPUT_INVERTED               (0x10U) /* invert INTP10 signal */
/* Noise filter setting of external interrupt INTP11 (PNFEN1) */
#define _00_INTP11_NOISE_FILTER_ENABLED          (0x00U) /* noise filter enable */
#define _08_INTP11_NOISE_FILTER_DISABLE          (0x08U) /* noise filter disable */
/* Noise filter setting of external interrupt INTP10 (PNFEN0) */
#define _00_INTP10_NOISE_FILTER_ENABLED          (0x00U) /* noise filter enable */
#define _04_INTP10_NOISE_FILTER_DISABLE          (0x04U) /* noise filter disable */
/* Switch of external interrupt INTP11 (TMRSTEN1) */
#define _00_INTP11_CLEAR_STOP                    (0x00U) /* external interrupt function is selected */
#define _02_INTP11_TIMER_RESTART                 (0x02U) /* timer restart function/forced output stop */
/* Switch of external interrupt INTP10 (TMRSTEN0) */
#define _00_INTP10_CLEAR_STOP                    (0x00U) /* external interrupt function is selected */
#define _01_INTP10_TIMER_RESTART                 (0x01U) /* timer restart function/forced output stop */

/*
    Interrupt flag output control register 0 (INTFOCTL0) 
*/
/* The output of statuses of interrupt request flags (INTFOEN) */
#define _00_OUTPUT_STATUSES_DISABLE              (0x00U) /* disable the output statuses */
#define _04_OUTPUT_STATUSES_ENABLE               (0x04U) /* enable the output statuses */
/* Select the logic of output status of interrupt request flags (INTFINV) */
#define _00_POSITIVE_LOGIC                       (0x00U) /* outputs with positive logic */
#define _02_NEGATIVE_LOGIC                       (0x02U) /* outputs with negative logic */
/* Select the output mode of status of interrupt request flags (INTFM) */
#define _00_HARDWARE_CLEAR_MODE                  (0x00U) /* hardware clear mode */
#define _01_SOFTWARE_CLEAR_MODE                  (0x01U) /* software clear mode */

/*
    Interrupt flag output control register 1 (INTFOCTL1) 
*/
/* Select the output level of status of interrupt request flags (INTFRD) */
#define _00_HIGHT_LEVEL                          (0x00U) /* high level */
#define _02_LOW_LEVEL                            (0x02U) /* low level */
/* Control to clear the output of status of interrupt request flags (INTFCLR) */
#define _00_OUTPUT_NOT_CLEAR                     (0x00U) /* do not clear the output */
#define _01_OUTPUT_CLEAR                         (0x01U) /* clear the output when INTFM = 1 */


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_INTC_Create(void);
void R_INTC0_Start(void);
void R_INTC0_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
