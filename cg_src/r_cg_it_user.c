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
* File Name    : r_cg_it_user.c
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
#pragma interrupt r_it_interrupt(vect=INTIT)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
volatile unsigned int	Timer_service_count1;
volatile unsigned int	Timer_service_count2;
volatile unsigned char	Timer_service_flag1;
volatile unsigned char	Timer_service_flag2;
volatile unsigned char	Wakeup_flag;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_it_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_it_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */

    
    /* INTP0 processing */
    if ( PIF0 == 1 )
    	Wakeup_flag = 1;
    else
    	Wakeup_flag = 0;

    PIF0 = 0;


    /* Timer service_count */
    if( Timer_service_count1 != 0 ){
	if( Timer_service_count1 == 1 ){
		Timer_service_count1 = 0;	
		Timer_service_flag1 = 1;
	}else{
		Timer_service_count1--;
    	}
    }
	
    if( Timer_service_count2 != 0 ){
	if( Timer_service_count2 == 1 ){
		Timer_service_count2 = 0;
		Timer_service_flag2 = 1;
	}else{
		Timer_service_count2--;
    	}
    }
	
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */



/* End user code. Do not edit comment generated here */
