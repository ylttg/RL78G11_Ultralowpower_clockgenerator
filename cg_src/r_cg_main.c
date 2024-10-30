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
* File Name    : r_cg_main.c
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1054A
* Tool-Chain   : CCRL
* Description  : This file implements main function.
* Creation Date: 2024/07/24
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_tau.h"
#include "r_cg_it.h"
#include "r_cg_tmkb.h"
#include "r_cg_sau.h"
#include "r_cg_adc.h"
#include "r_cg_elc.h"
#include "r_cg_intp.h"
/* Start user code for include. Do not edit comment generated here */
#include "clockgene.h"
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
unsigned char	wakeup_flag;
unsigned int	switch_read( void );
void		beep( unsigned char );
void		wait_100ms( unsigned time );
void	wait_1us( void );

extern volatile unsigned int	Timer_service_count1;
extern volatile unsigned int	Timer_service_count2;
extern volatile unsigned char	Timer_service_flag1;
extern volatile unsigned char	Timer_service_flag2;
extern volatile unsigned char	Wakeup_flag;

/* End user code. Do not edit comment generated here */

static void R_MAIN_UserInit(void);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    unsigned int switch_state;
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
    HIOSTOP = 1;				/* hoco stop */
    /* if removed, restore unsigned int switch_state; statement above R_MAIN_UserInit */
    Wakeup_flag = 0;
    while (1U)
    {
	/* INTP0 wake up disable */
	PIF0 = 0;
	PMK0 = 1;
 
	/* uart interrupt enable */
	R_UART0_Start();			/* RXD0 start */
    	R_UART1_Start();			/* TXD1 start */


	/* enable 12bit it */
	R_IT_Start();

	switch_state = switch_read();

	/* output clock setting */
	switch( switch_state ){
	case 3:
		/* Max. */
		LED1 = LED_ON;
		LED2 = LED_ON;
		CKS0 = 0;		/* main clock is out */
		PCLOE0 = 1;		/* output start */
		break;
	case 2:
		/* Double */
		LED1 = LED_OFF;
		LED2 = LED_ON;
		CKS0 = 1;		/* main clock/2 is out */
		PCLOE0 = 1;		/* output start */	
		break;
	case 1:
	default :
		switch_state = 1;
		/* Normal */
		LED1 = LED_ON;
		LED2 = LED_OFF;
		CKS0 = 2;		/* main clock/4 is out */
		PCLOE0 = 1;		/* output start */
		break;
	}

	
	/* beep */
	beep( switch_state );
	
	/* LED OFF */
	LED1 = LED_OFF;
	LED2 = LED_OFF;
	
	/* standby */	
	Wakeup_flag = 1;
	do{
			
		__halt();

	}while( Wakeup_flag == 1 );

	/* goto stop */
	
	/* need to check uart buffer before going to stop */
	
	
	R_UART0_Stop();		/* RXD0 Stop */
	R_UART1_Stop();		/* TXD1 Stop */
	PCLOE0 = 0;		/* output stop */
	P3_bit.no0 = 1;		/* clock out set to high */
	wait_100ms( 1 );	/* 100ms wait */
	R_IT_Stop();		/* interval timer stop */
	PIF0 = 0;		/* INTP enable */ 
	PMK0 = 0;		/* Mask clear */
	__stop();		/* goto stop */	
	
	P3_bit.no0 = 0;		/* clock out set to low ( enable clock out side ) */
	
	/* wake up */

    }
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    R_ADC_Set_OperationOff();		/* A/D Comparator off */
    
    /* INTP0 IF clear, MK set = polling mode */
    PIF0 = 0;				
    PMK0 = 1;
    /* Pull up RXD terminal P3.1 */
    PU3_bit.no1 = 1;    
    
    EI();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */

unsigned int switch_read( void )
{

    unsigned int buffer;
	
    R_ADC_Set_OperationOn();		/* A/D Comparator ON */
    AD_POWER = AD_POWER_ON;					/* Port high */ 
    
	/* Wait */
    wait_1us();
    ADIF = 0;
    R_ADC_Start();
    do{
	    __nop();
    }while( ADIF == 0 );    
    R_ADC_Get_Result( &buffer );
    R_ADC_Stop();
    ADIF = 0;
    
    AD_POWER = AD_POWER_OFF;					/* Port low */ 

    R_ADC_Set_OperationOff();		/* A/D Comparator OFF */

    
    if ( buffer < switch_ad_th1 ){
	    return 1;
    }else{
	    if( buffer < switch_ad_th2 ){
		    return 2;
	    }else{
		if( buffer < switch_ad_th3 ){
			return 3;
		}else{
			return 4;
		}
	    }
    }
	
}

void		beep( unsigned char mode )
{

	volatile unsigned char time;
	
	if( mode == 1 )
		time = beep_low;
	else
		if( mode == 2 )
			time = beep_mid;
		else
			time = beep_high;

	
	/* Pi 2KHz */
	TOE0 |= 0x0008;			/* Timer output start */
	TDR03 = SOUND_PI;
	R_TAU0_Channel3_Start();
	wait_100ms( time );
	R_TAU0_Channel3_Stop();
	
	
	/* Po 1KHz */
	TDR03 = SOUND_PO;
	R_TAU0_Channel3_Start();
	wait_100ms( time );
	R_TAU0_Channel3_Stop();
	TOE0 &= 0xFFF7;			/* Timer output stop */
	
	return;
	
}

void	wait_100ms( unsigned time )
{
	Timer_service_count1 = time;
	Timer_service_flag1 = 0;
	while ( !Timer_service_flag1 ){
	};

	return;
}

void	wait_1us( void )
{
	
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();
	__nop();

	return;
	
}




/* End user code. Do not edit comment generated here */
