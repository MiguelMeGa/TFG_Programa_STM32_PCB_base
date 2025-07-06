/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"
#include <stdbool.h>
#include "definiciones.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_ADC_Init(ADC_HandleTypeDef* hadc);
void MX_I2C1_Init(I2C_HandleTypeDef* hi2c);
void MX_TIM1_Init(TIM_HandleTypeDef* htim);
void MX_TIM3_Init(TIM_HandleTypeDef* htim);
void MX_TIM14_Init(TIM_HandleTypeDef* htim);
void MX_TIM16_Init(TIM_HandleTypeDef* htim);
void MX_TIM17_Init(TIM_HandleTypeDef* htim);

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

void actualizacion_configuracion_io(uint8_t mat_io[][NUM_COLUM]);
void actualizacion_estados_io(uint8_t mat_io[][NUM_COLUM]);

void recepcion_comunicaciones (uint8_t _matriz_io[][NUM_COLUM],uint8_t _buffer_rx[TAMANIO_RECEPCION], uint8_t respuesta_trans[TAMANIO_RESP_TRANSMISION] ,bool recepcion_pendiente, bool* requiere_transmision);
void transmision_comunicaciones(uint8_t _matriz_io[][NUM_COLUM],uint8_t _buffer_tx[TAMANIO_TRANSMISION],uint8_t respuesta_trans[TAMANIO_RESP_TRANSMISION],bool transmision_pendiente);


/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */
uint16_t get_ADC_conversion (unsigned int adc_channel);
void set_PWM_out_ana_1_i(uint8_t duty);
void set_PWM_out_ana_2_i(uint8_t duty);
void set_PWM_out_ana_3_i(uint8_t duty);
void set_PWM_out_ana_1_v(uint8_t duty);
void set_PWM_out_ana_2_v(uint8_t duty);
void set_PWM_out_ana_3_v(uint8_t duty);

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
