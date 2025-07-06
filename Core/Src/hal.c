////////////////////////////////////////////
//
// Funciones auxiliares: PWM,AD ...
//
// Nombre: hal.c
// Autor: Miguel Méndez Gayol
// Fecha: 04/05/2025
//
/////////////////////////////////////////////
#include "main.h"

extern ADC_HandleTypeDef hadc;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;


///////////////////////////////////////////////////
// Función que toma la converión AD de un elemento
///////////////////////////////////////////////////


uint16_t get_ADC_conversion (unsigned int adc_channel)
{
	uint16_t adcVal =0;
	ADC1->CHSELR=adc_channel;
	if (HAL_ADC_Start(&hadc) != HAL_OK)
	{
	/* Start Conversation Error */
	// Error_Handler();
		adcVal=0;
	}
	if (HAL_ADC_PollForConversion(&hadc, 500) != HAL_OK)
	{
		/* End Of Conversion flag not set on time */
		// Error_Handler();
		adcVal=0;
	}
	else
	{
	/* ADC conversion completed */
	/*##-5- Get the converted value of regular channel ########################*/
		adcVal = HAL_ADC_GetValue(&hadc);
	}
	
	HAL_ADC_Stop(&hadc);
	return adcVal;	
}




////////////////////////////////////
// Salida analógica de corriente 2
////////////////////////////////////

void set_PWM_out_ana_1_i(uint8_t duty)
{

  uint8_t aux_duty = duty;
	uint16_t frec_pwm = CARGA_1KHZ;
	uint16_t carga_duty_pwm =0;
	
	if(duty>255)
	{
		aux_duty = 255;
	}
	
	carga_duty_pwm = (uint16_t)((aux_duty/255.0)*frec_pwm);
	
	__HAL_TIM_SET_COMPARE(&htim3, PWM_OUT_ANA_1_I, carga_duty_pwm);
	
}


////////////////////////////////////
// Salida analógica de corriente 2
////////////////////////////////////

void set_PWM_out_ana_2_i(uint8_t duty)
{

  uint8_t aux_duty = duty;
	uint16_t frec_pwm = CARGA_1KHZ;
	uint16_t carga_duty_pwm =0;
	
	if(duty>255)
	{
		aux_duty = 255;
	}
	
	carga_duty_pwm = (uint16_t)((aux_duty/255.0)*frec_pwm);
	
	__HAL_TIM_SET_COMPARE(&htim3, PWM_OUT_ANA_2_I, carga_duty_pwm);
	
}



////////////////////////////////////
// Salida analógica de corriente 3
////////////////////////////////////

void set_PWM_out_ana_3_i(uint8_t duty)
{

  uint8_t aux_duty = duty;
	uint16_t frec_pwm = CARGA_1KHZ;
	uint16_t carga_duty_pwm =0;
	
	if(duty>255)
	{
		aux_duty = 255;
	}
	
	carga_duty_pwm = (uint16_t)((aux_duty/255.0)*frec_pwm);
	
	__HAL_TIM_SET_COMPARE(&htim1, PWM_OUT_ANA_3_I, carga_duty_pwm);
	
}



////////////////////////////////////
// Salida analógica de tensión 1
////////////////////////////////////

void set_PWM_out_ana_1_v(uint8_t duty)
{

  uint8_t aux_duty = duty;
	uint16_t frec_pwm = CARGA_1KHZ;
	uint16_t carga_duty_pwm =0;
	
	if(duty>255)
	{
		aux_duty = 255;
	}
	
	carga_duty_pwm = (uint16_t)((aux_duty/255.0)*frec_pwm);
	
	__HAL_TIM_SET_COMPARE(&htim1, PWM_OUT_ANA_1_V, carga_duty_pwm);
	
}

////////////////////////////////////
// Salida analógica de tensión 2
////////////////////////////////////

void set_PWM_out_ana_2_v(uint8_t duty)
{

  uint8_t aux_duty = duty;
	uint16_t frec_pwm = CARGA_1KHZ;
	uint16_t carga_duty_pwm =0;
	
	if(duty>255)
	{
		aux_duty = 255;
	}
	
	carga_duty_pwm = (uint16_t)((aux_duty/255.0)*frec_pwm);
	
	__HAL_TIM_SET_COMPARE(&htim1, PWM_OUT_ANA_2_V, carga_duty_pwm);
	
}


////////////////////////////////////
// Salida analógica de tensión 3
////////////////////////////////////

void set_PWM_out_ana_3_v(uint8_t duty)
{

  uint8_t aux_duty = duty;
	uint16_t frec_pwm = CARGA_1KHZ;
	uint16_t carga_duty_pwm =0;
	
	if(duty>255)
	{
		aux_duty = 255;
	}
	
	carga_duty_pwm = (uint16_t)((aux_duty/255.0)*frec_pwm);
	
	__HAL_TIM_SET_COMPARE(&htim1, PWM_OUT_ANA_3_V, carga_duty_pwm);
	
}