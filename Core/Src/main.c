/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include "definiciones.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;

I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim14;
TIM_HandleTypeDef htim16;
TIM_HandleTypeDef htim17;

/* USER CODE BEGIN PV */


 bool _timer_14_interrupt_done = false;
 bool _recepcion_pendiente = false;
 bool _transmision_pendiente = false;
 
 uint8_t _cuenta_turno = 0;
 uint8_t aux = 0;
 uint8_t  _matriz_io[NUM_IO][NUM_COLUM]; //Mapeado de salidas para configuración 
 uint8_t  _respuesta_transm[TAMANIO_RESP_TRANSMISION]; //Marca la respuesta a transmitir en la recepción
 
 uint8_t  _buffer_rx[TAMANIO_RECEPCION];
 uint8_t  _buffer_tx[TAMANIO_TRANSMISION];
 
 //uint8_t i2c_rx_buffer[6];  // Buffer de recepción

// Inicia la recepción en modo interrupción



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  
	
  /* USER CODE BEGIN 2 */

	
	MX_GPIO_Init();
	//HAL_Delay(10000);
  MX_ADC_Init(&hadc);
	//HAL_I2C_EnableListen_IT(&hi2c1);
  
  MX_TIM1_Init(&htim1);
  MX_TIM3_Init(&htim3);
  MX_TIM14_Init(&htim14);
  MX_TIM16_Init(&htim16);
  MX_TIM17_Init(&htim17);
	
  MX_I2C1_Init(&hi2c1);

	HAL_I2C_EnableListen_IT(&hi2c1);
		
		
	HAL_TIM_Base_Start_IT(&htim14); 	
	
	 
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
		
		if(_timer_14_interrupt_done == true)
		{
			_cuenta_turno ++;
			
			if(_cuenta_turno == TURNO_RECEPCION)
			{
				recepcion_comunicaciones(_matriz_io, _buffer_rx, _respuesta_transm, _recepcion_pendiente,&_transmision_pendiente);  //Decodificación de la función en caso de requerirse
				_recepcion_pendiente = false;
			}
			else if(_cuenta_turno == TURNO_CONFIG_IO)
			{
				actualizacion_configuracion_io(_matriz_io);
			}
			else if(_cuenta_turno == TURNO_LECTESC_IO)
			{
				actualizacion_estados_io(_matriz_io);  //Lectura y escritura en la matriz de 
			}
			else if(_cuenta_turno == TURNO_TRANSMISION)
			{
				transmision_comunicaciones(_matriz_io,_buffer_tx,_respuesta_transm,_transmision_pendiente);//se llama a las funciones para comunicaciones con la pantalla
				_transmision_pendiente = 0;  //Transmisión en la trama de comunicaciones
			}
			
			
			_timer_14_interrupt_done = false;
		}
     aux=1;
		
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}


void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c1, uint8_t TransferDirection, uint16_t AddrMatchCode)
{
	
	//HAL_I2C_DisableListen_IT(hi2c1);                    //Se deja de escuchar comunicaciones
	if (TransferDirection == I2C_DIRECTION_TRANSMIT)  // if the master wants to transmit the data
	{
		//RxData[0] = 0;  // reset the RxData[0] to clear any residue address from previous call
		//rxcount =0;
		aux=2;
		//HAL_I2C_Slave_Seq_Receive_IT(hi2c, RxData+rxcount, 1, I2C_FIRST_FRAME);
	}
 // HAL_I2C_EnableListen_IT(hi2c1);																//Se habilita la escucha del I2C
//	HAL_I2C_EV_IRQHandler(hi2c1);
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
