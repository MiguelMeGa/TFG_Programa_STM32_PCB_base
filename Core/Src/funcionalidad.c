////////////////////////////////////////////
//
// Establece las funcionalidades de la placa base
//
// Nombre: funcionalidad.c
// Autor: Miguel Méndez Gayol
// Fecha: 04/05/2025
//
/////////////////////////////////////////////

#include "main.h"
#include "definiciones.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;


/////////////////////////////////////////////////
//
//			Función para configuración de IOs 
//
/////////////////////////////////////////////////

void actualizacion_configuracion_io(uint8_t mat_io[][NUM_COLUM])
{
	
	// ENTRADAS DIGITALES
	
	//Entrada 1
	if(mat_io[POS_ENTRADA_DIG_1][COL_CAMBIO]!=0)
	{
		 if(mat_io[POS_ENTRADA_DIG_1][COL_CONFIG] == CFG_ENTRADA_TENSION)
		 {
				HAL_GPIO_WritePin(PORT_ACT_IN_DIG_1, PIN_ACT_IN_DIG_1, GPIO_PIN_RESET);  //Por defecto entrada de tensión
			}
			else if(mat_io[POS_ENTRADA_DIG_1][COL_CONFIG] == CFG_ENTRADA_CONTACTO)
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_DIG_1, PIN_ACT_IN_DIG_1, GPIO_PIN_SET);   //Activado entrada por contacto
			}
			else
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_DIG_1, PIN_ACT_IN_DIG_1, GPIO_PIN_RESET);  //Valor idle 	
			}
			mat_io[POS_ENTRADA_DIG_1][COL_CAMBIO] = 0;
	}
	
	
	//Entrada 2
	if(mat_io[POS_ENTRADA_DIG_2][COL_CAMBIO]!=0)
	{
			if(mat_io[POS_ENTRADA_DIG_2][COL_CONFIG] == CFG_ENTRADA_TENSION)
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_DIG_2, PIN_ACT_IN_DIG_2, GPIO_PIN_RESET);  //Por defecto entrada de tensión 
		
			}
			else if(mat_io[POS_ENTRADA_DIG_2][COL_CONFIG] == CFG_ENTRADA_CONTACTO)
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_DIG_2, PIN_ACT_IN_DIG_2, GPIO_PIN_SET);   //Activado entrada por contacto
				
			}
			else
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_DIG_2, PIN_ACT_IN_DIG_2, GPIO_PIN_RESET);  //Valor idle 
				
			}
			mat_io[POS_ENTRADA_DIG_2][COL_CAMBIO] = 0;
	}
	
	
	//Entrada 3
	if(mat_io[POS_ENTRADA_DIG_3][COL_CAMBIO]!=0)
	{
			if(mat_io[POS_ENTRADA_DIG_3][COL_CONFIG] == CFG_ENTRADA_TENSION)
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_DIG_3, PIN_ACT_IN_DIG_3, GPIO_PIN_RESET);  //Por defecto entrada de tensión 
				
			}
			else if(mat_io[POS_ENTRADA_DIG_3][COL_CONFIG] == CFG_ENTRADA_CONTACTO)
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_DIG_3, PIN_ACT_IN_DIG_3, GPIO_PIN_SET);   //Activado entrada por contacto
			}
			else
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_DIG_3, PIN_ACT_IN_DIG_3, GPIO_PIN_RESET);  //Valor idle 
			}
			mat_io[POS_ENTRADA_DIG_3][COL_CAMBIO] = 0;
	}
	
  //-------------------------
	
	// SALIDAS DIGITALES
	
	//Salida digital 1
	
	if(mat_io[POS_SALIDA_DIG_1][COL_CAMBIO]!=0)
	{
			if(mat_io[POS_SALIDA_DIG_1][COL_CONFIG] == CFG_SALIDA_TENSION)
			{
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_1, PIN_ACT_OUT_DIG_C_1, GPIO_PIN_RESET);  //Primero se retira el contacto 
				//Pequeña temporización entre medias
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_1, PIN_ACT_OUT_DIG_V_1, GPIO_PIN_RESET);    //Salida de tensión si no hay contacto
				
			}
			else if(mat_io[POS_SALIDA_DIG_1][COL_CONFIG] == CFG_SALIDA_CONTACTO)
			{
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_1, PIN_ACT_OUT_DIG_V_1, GPIO_PIN_RESET);  //Salida de tensión si no hay contacto
				//Imagino que se necesite meter un pequeño retardo para quitar la tensión
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_1, PIN_ACT_OUT_DIG_C_1, GPIO_PIN_RESET);  //Primero se retira el contacto 
			}
			else
			{
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_1, PIN_ACT_OUT_DIG_C_1, GPIO_PIN_RESET);  //Primero se retira el contacto 
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_1, PIN_ACT_OUT_DIG_V_1, GPIO_PIN_RESET);  //Segundo se retira la tensión
			}
			mat_io[POS_SALIDA_DIG_1][COL_CAMBIO] = 0;
	}
	
	
	// Salida digital 2
	
	if(mat_io[POS_SALIDA_DIG_2][COL_CAMBIO]!=0)
	{
			if(mat_io[POS_SALIDA_DIG_2][COL_CONFIG] == CFG_SALIDA_TENSION)
			{
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_2, PIN_ACT_OUT_DIG_C_2, GPIO_PIN_RESET);  //Primero se retira el contacto 
				//Pequeña temporización entre medias
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_2, PIN_ACT_OUT_DIG_V_2, GPIO_PIN_RESET);    //Salida de tensión si no hay contacto
				
			}
			else if(mat_io[POS_SALIDA_DIG_2][COL_CONFIG] == CFG_SALIDA_CONTACTO)
			{
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_2, PIN_ACT_OUT_DIG_V_2, GPIO_PIN_RESET);  //Salida de tensión si no hay contacto
				//Imagino que se necesite meter un pequeño retardo para quitar la tensión
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_2, PIN_ACT_OUT_DIG_C_2, GPIO_PIN_RESET);  //Primero se retira el contacto 
			}
			else
			{
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_2, PIN_ACT_OUT_DIG_C_2, GPIO_PIN_RESET);  //Primero se retira el contacto 
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_2, PIN_ACT_OUT_DIG_V_2, GPIO_PIN_RESET);  //Segundo se retira la tensión
			}
			mat_io[POS_SALIDA_DIG_2][COL_CAMBIO] = 0;
	}
	
	//Salida digital 3
	
	if(mat_io[POS_SALIDA_DIG_3][COL_CAMBIO]!=0)
	{
			if(mat_io[POS_SALIDA_DIG_3][COL_CONFIG] == CFG_SALIDA_TENSION)
			{
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_3, PIN_ACT_OUT_DIG_C_3, GPIO_PIN_RESET);  //Primero se retira el contacto 
				//Pequeña temporización entre medias
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_3, PIN_ACT_OUT_DIG_V_3, GPIO_PIN_RESET);    //Salida de tensión si no hay contacto
				
			}
			else if(mat_io[POS_SALIDA_DIG_3][COL_CONFIG] == CFG_SALIDA_CONTACTO)
			{
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_3, PIN_ACT_OUT_DIG_V_3, GPIO_PIN_RESET);  //Salida de tensión si no hay contacto
				//Imagino que se necesite meter un pequeño retardo para quitar la tensión
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_3, PIN_ACT_OUT_DIG_C_3, GPIO_PIN_RESET);  //Primero se retira el contacto 
			}
			else
			{
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_3, PIN_ACT_OUT_DIG_C_3, GPIO_PIN_RESET);  //Primero se retira el contacto 
				HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_3, PIN_ACT_OUT_DIG_V_3, GPIO_PIN_RESET);  //Segundo se retira la tensión
			}
			mat_io[POS_SALIDA_DIG_3][COL_CAMBIO] = 0;
	}
	
	
	//-------------------------
	
	//ENTRADAS ANALÓGICAS
	
	//Entrada analógica 1
	if(mat_io[POS_ENTRADA_ANA_1][COL_CAMBIO]!=0)
	{
			if(mat_io[POS_ENTRADA_ANA_1][COL_CONFIG] == CFG_ENTRADA_020MA || mat_io[POS_ENTRADA_ANA_1][COL_CONFIG] == CFG_ENTRADA_420MA)
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_ANA_1, PIN_ACT_IN_ANA_1, GPIO_PIN_SET);  //Al activar el pin se mide la corriente 
			}
			else if (mat_io[POS_ENTRADA_ANA_1][COL_CONFIG] == CFG_ENTRADA_010V)
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_ANA_1, PIN_ACT_IN_ANA_1, GPIO_PIN_RESET);  //Por defecto se habilita la medida de tensión 
			}
			else
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_ANA_1, PIN_ACT_IN_ANA_1, GPIO_PIN_RESET);  //Por defecto se habilita la medida de tensión  
			}
			mat_io[POS_ENTRADA_ANA_1][COL_CAMBIO] = 0;
	}
	
	
	//Entrada analógica 2
	
	if(mat_io[POS_ENTRADA_ANA_2][COL_CAMBIO]!=0)
	{
			if(mat_io[POS_ENTRADA_ANA_2][COL_CONFIG] == CFG_ENTRADA_020MA || mat_io[POS_ENTRADA_ANA_2][COL_CONFIG] == CFG_ENTRADA_420MA)
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_ANA_2, PIN_ACT_IN_ANA_2, GPIO_PIN_SET);  //Al activar el pin se mide la corriente 
			}
			else if (mat_io[POS_ENTRADA_ANA_2][COL_CONFIG] == CFG_ENTRADA_010V)
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_ANA_2, PIN_ACT_IN_ANA_2, GPIO_PIN_RESET);  //Por defecto se habilita la medida de tensión 
			}
			else
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_ANA_2, PIN_ACT_IN_ANA_2, GPIO_PIN_RESET);  //Por defecto se habilita la medida de tensión  
			}
			mat_io[POS_ENTRADA_ANA_2][COL_CAMBIO] = 0;
	}
	
	//Entrada analógica 3
	
	if(mat_io[POS_ENTRADA_ANA_3][COL_CAMBIO]!=0)
	{
			if(mat_io[POS_ENTRADA_ANA_3][COL_CONFIG] == CFG_ENTRADA_020MA || mat_io[POS_ENTRADA_ANA_3][COL_CONFIG] == CFG_ENTRADA_420MA)
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_ANA_3, PIN_ACT_IN_ANA_3, GPIO_PIN_SET);  //Al activar el pin se mide la corriente 
			}
			else if (mat_io[POS_ENTRADA_ANA_3][COL_CONFIG] == CFG_ENTRADA_010V)
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_ANA_3, PIN_ACT_IN_ANA_3, GPIO_PIN_RESET);  //Por defecto se habilita la medida de tensión 
			}
			else
			{
				HAL_GPIO_WritePin(PORT_ACT_IN_ANA_3, PIN_ACT_IN_ANA_3, GPIO_PIN_RESET);  //Por defecto se habilita la medida de tensión  
			}
			mat_io[POS_ENTRADA_ANA_3][COL_CAMBIO] = 0;
	}
	
	
	//-------------------------
	
	//SALIDAS ANALOGICAS

	//Salida analógica 1
	
	if(mat_io[POS_SALIDA_ANA_1][COL_CAMBIO]!=0)
	{
		//Se procede a habilitar el PWM 
		if(mat_io[POS_SALIDA_ANA_1][COL_CONFIG] == CFG_SALIDA_020MA || mat_io[POS_SALIDA_ANA_1][COL_CONFIG] == CFG_SALIDA_420MA)
		{
       
			HAL_TIM_PWM_Stop(&htim1,PWM_OUT_ANA_1_V);   //Parar la señal PWM de tensión
			HAL_TIM_PWM_Start(&htim3,PWM_OUT_ANA_1_I);  //Habilitar la señal PWM de corriente
			
		}
		else if(mat_io[POS_SALIDA_ANA_1][COL_CONFIG] == CFG_SALIDA_010V)
		{
			HAL_TIM_PWM_Stop(&htim3,PWM_OUT_ANA_1_I);   //Parar la señal PWM de corriente
			HAL_TIM_PWM_Start(&htim1,PWM_OUT_ANA_1_V);  //Habilitar la señal PWM de tension
		}
		else
		{
			//Deshabilitar los dos pwm
			HAL_TIM_PWM_Stop(&htim3,PWM_OUT_ANA_1_I);   //Parar la señal PWM de corriente
			HAL_TIM_PWM_Stop(&htim1,PWM_OUT_ANA_1_V);   //Parar la señal PWM de tension
		}
		
		mat_io[POS_SALIDA_ANA_1][COL_CAMBIO] = 0; 
	}
	
	
	//Salida digital 2
	
	if(mat_io[POS_SALIDA_ANA_2][COL_CAMBIO]!=0)
	{
		//Se procede a habilitar el PWM 
		if(mat_io[POS_SALIDA_ANA_2][COL_CONFIG] == CFG_SALIDA_020MA || mat_io[POS_SALIDA_ANA_2][COL_CONFIG] == CFG_SALIDA_420MA)
		{
			HAL_TIM_PWM_Stop(&htim1,PWM_OUT_ANA_2_V);   //Parar la señal PWM de tensión
			HAL_TIM_PWM_Start(&htim3,PWM_OUT_ANA_2_I);  //Habilitar la señal PWM de corriente
		}
		else if(mat_io[POS_SALIDA_ANA_2][COL_CONFIG] == CFG_SALIDA_010V)
		{
			HAL_TIM_PWM_Stop(&htim3,PWM_OUT_ANA_2_I);   //Parar la señal PWM de corriente
			HAL_TIM_PWM_Start(&htim1,PWM_OUT_ANA_2_V);  //Habilitar la señal PWM de tension
		}
		else
		{
			//Deshabilitar los dos pwm
			HAL_TIM_PWM_Stop(&htim3,PWM_OUT_ANA_2_I);   //Parar la señal PWM de corriente
			HAL_TIM_PWM_Stop(&htim1,PWM_OUT_ANA_2_V);   //Parar la señal PWM de tension
		}
		
		mat_io[POS_SALIDA_ANA_2][COL_CAMBIO] = 0; 
	}
	
	
	
	//Salida digital 3
	
	if(mat_io[POS_SALIDA_ANA_3][COL_CAMBIO]!=0)
	{
		//Se procede a habilitar el PWM 
		if(mat_io[POS_SALIDA_ANA_3][COL_CONFIG] == CFG_SALIDA_020MA || mat_io[POS_SALIDA_ANA_3][COL_CONFIG] == CFG_SALIDA_420MA)
		{
			HAL_TIM_PWM_Stop(&htim1,PWM_OUT_ANA_3_V);   //Parar la señal PWM de tensión
			HAL_TIM_PWM_Start(&htim1,PWM_OUT_ANA_3_I);  //Habilitar la señal PWM de corriente
		}
		else if(mat_io[POS_SALIDA_ANA_3][COL_CONFIG] == CFG_SALIDA_010V)
		{
			HAL_TIM_PWM_Stop(&htim1,PWM_OUT_ANA_3_I);   //Parar la señal PWM de corriente
			HAL_TIM_PWM_Start(&htim1,PWM_OUT_ANA_3_V);  //Habilitar la señal PWM de tension
		}
		else
		{
			//Deshabilitar los dos pwm
			HAL_TIM_PWM_Stop(&htim1,PWM_OUT_ANA_3_I);   //Parar la señal PWM de corriente
			HAL_TIM_PWM_Stop(&htim1,PWM_OUT_ANA_3_V);   //Parar la señal PWM de tension
		}
		
		mat_io[POS_SALIDA_ANA_3][COL_CAMBIO] = 0; 
	}
	
	//-------------------------
	
}








/////////////////////////////////////////////////
//
//	 Función para actualización de estados IOs 
//
/////////////////////////////////////////////////

void actualizacion_estados_io(uint8_t mat_io[][NUM_COLUM])
{
	//Nota: si existe un cambio pendiente se opta en salidas por la seguridad (poner a 0 o NA)
	
	 uint16_t aux_ad_dig_in_1 = 0;
	 uint16_t aux_ad_dig_in_2 = 0;
	 uint16_t aux_ad_dig_in_3 = 0;
	
	 uint16_t aux_ad_ana_in_1 = 0;
	 uint16_t aux_ad_ana_in_2 = 0;
	 uint16_t aux_ad_ana_in_3 = 0;
	
	 uint8_t aux_duty_sal_ana_1 = 0;
	 uint8_t aux_duty_sal_ana_2 = 0;
	 uint8_t aux_duty_sal_ana_3 = 0;
	
	// ENTRADAS DIGITALES
	
	float aux_resol_ad_ana = RANGO_AD;
	float aux_resol_salida_ana = RANGO_DESTINO;
	
	//Entrada 1
	if(mat_io[POS_ENTRADA_DIG_1][COL_CAMBIO] == 0)
	{
			aux_ad_dig_in_1 = get_ADC_conversion(ADC_IN_DIG_1);
			
			if(mat_io[POS_ENTRADA_DIG_1][COL_CONFIG] == CFG_ENTRADA_TENSION)
			{
					if(aux_ad_dig_in_1 > LIMITE_ON_ENTRADA_TENSION  )
					{
						mat_io[POS_ENTRADA_DIG_1][COL_VALOR] = 1;
					}
					else
					{
						mat_io[POS_ENTRADA_DIG_1][COL_VALOR] = 0;
					}
			}
			else if(mat_io[POS_ENTRADA_DIG_1][COL_CONFIG] == CFG_ENTRADA_CONTACTO)
			{
				
					if(aux_ad_dig_in_1 > LIMITE_NA_ENTRADA_CONTACTO  )
					{
						mat_io[POS_ENTRADA_DIG_1][COL_VALOR] = 1;
					}
					else
					{
						mat_io[POS_ENTRADA_DIG_1][COL_VALOR] = 0;
					}
				
			}			
			else
			{
				 mat_io[POS_ENTRADA_DIG_1][COL_VALOR] = 0;
			}
	}
	else
	{
			mat_io[POS_ENTRADA_DIG_1][COL_VALOR] = 0;// En estado anterior 
	}
	
	
	//Entrada 2
	if(mat_io[POS_ENTRADA_DIG_2][COL_CAMBIO] == 0)
	{
			aux_ad_dig_in_2 = get_ADC_conversion(ADC_IN_DIG_2);
			
			if(mat_io[POS_ENTRADA_DIG_2][COL_CONFIG] == CFG_ENTRADA_TENSION)
			{
					if(aux_ad_dig_in_2 > LIMITE_ON_ENTRADA_TENSION  )
					{
						mat_io[POS_ENTRADA_DIG_2][COL_VALOR] = 1;
					}
					else
					{
						mat_io[POS_ENTRADA_DIG_2][COL_VALOR] = 0;
					}
			}
			else if(mat_io[POS_ENTRADA_DIG_2][COL_CONFIG] == CFG_ENTRADA_CONTACTO)
			{
				
					if(aux_ad_dig_in_2 > LIMITE_NA_ENTRADA_CONTACTO  )
					{
						mat_io[POS_ENTRADA_DIG_2][COL_VALOR] = 1;
					}
					else
					{
						mat_io[POS_ENTRADA_DIG_2][COL_VALOR] = 0;
					}
				
			}			
			else
			{
				 mat_io[POS_ENTRADA_DIG_2][COL_VALOR] = 0;
			}
	}
	else
	{
			mat_io[POS_ENTRADA_DIG_2][COL_VALOR] = 0;// En estado anterior 
	}
	
	
	//Entrada 3
	if(mat_io[POS_ENTRADA_DIG_3][COL_CAMBIO] == 0)
	{
			aux_ad_dig_in_3 = get_ADC_conversion(ADC_IN_DIG_3);
			
			if(mat_io[POS_ENTRADA_DIG_3][COL_CONFIG] == CFG_ENTRADA_TENSION)
			{
					if(aux_ad_dig_in_3 > LIMITE_ON_ENTRADA_TENSION  )
					{
						mat_io[POS_ENTRADA_DIG_3][COL_VALOR] = 1;
					}
					else
					{
						mat_io[POS_ENTRADA_DIG_3][COL_VALOR] = 0;
					}
			}
			else if(mat_io[POS_ENTRADA_DIG_3][COL_CONFIG] == CFG_ENTRADA_CONTACTO)
			{
				
					if(aux_ad_dig_in_3 > LIMITE_NA_ENTRADA_CONTACTO  )
					{
						mat_io[POS_ENTRADA_DIG_3][COL_VALOR] = 1;
					}
					else
					{
						mat_io[POS_ENTRADA_DIG_3][COL_VALOR] = 1;
					}
				
			}			
			else
			{
				 mat_io[POS_ENTRADA_DIG_3][COL_VALOR] = 0;
			}
	}
	else
	{
			mat_io[POS_ENTRADA_DIG_3][COL_VALOR] = 0;// En estado anterior 
	}
	
	
	//-------------------------
	
	// SALIDAS DIGITALES
	
	
	//Salida 1
	if(mat_io[POS_SALIDA_DIG_1][COL_CAMBIO] == 0)
	{
		
			if(mat_io[POS_SALIDA_DIG_1][COL_CONFIG] == CFG_SALIDA_TENSION)                      //SALIDA DE TENSIÓN 
			{
				  if(mat_io[POS_SALIDA_DIG_1][COL_VALOR] == 1)
					{
						HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_1, PIN_ACT_OUT_DIG_V_1, GPIO_PIN_SET);  //Salida de tensión a 1 -> se da tensión 
					}
					else
					{
						HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_1, PIN_ACT_OUT_DIG_V_1, GPIO_PIN_RESET); //Salida de tensión a 0 -> se quita tensión en la salida
					}
			}
			
			else if(mat_io[POS_SALIDA_DIG_1][COL_CONFIG] == CFG_SALIDA_CONTACTO)									//SALIDA DE CONTACTO
			{
				 if(mat_io[POS_SALIDA_DIG_1][COL_VALOR] == 1)
				 {
					 HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_1, PIN_ACT_OUT_DIG_C_1, GPIO_PIN_RESET);  //Salida de contacto a 1 -> NA
				 }
				 else
				 {
					 HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_1, PIN_ACT_OUT_DIG_C_1, GPIO_PIN_SET);    //Salida de contacto a 0 -> NC
				 }
			}
		
	}
	

	//Salida 2
	if(mat_io[POS_SALIDA_DIG_2][COL_CAMBIO] == 0)
	{
		
			if(mat_io[POS_SALIDA_DIG_2][COL_CONFIG] == CFG_SALIDA_TENSION)                      //SALIDA DE TENSIÓN 
			{
				  if(mat_io[POS_SALIDA_DIG_2][COL_VALOR] == 1)
					{
						HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_2, PIN_ACT_OUT_DIG_V_2, GPIO_PIN_SET);  //Salida de tensión a 1 -> se da tensión 
					}
					else
					{
						HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_2, PIN_ACT_OUT_DIG_V_2, GPIO_PIN_RESET); //Salida de tensión a 0 -> se quita tensión en la salida
					}
			}
			
			else if(mat_io[POS_SALIDA_DIG_2][COL_CONFIG] == CFG_SALIDA_CONTACTO)									//SALIDA DE CONTACTO
			{
				 if(mat_io[POS_SALIDA_DIG_2][COL_VALOR] == 1)
				 {
					 HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_2, PIN_ACT_OUT_DIG_C_2, GPIO_PIN_RESET);  //Salida de contacto a 1 -> NA
				 }
				 else
				 {
					 HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_2, PIN_ACT_OUT_DIG_C_2, GPIO_PIN_SET);    //Salida de contacto a 0 -> NC
				 }
			}
		
	}
	
	
	//Salida 3
	if(mat_io[POS_SALIDA_DIG_3][COL_CAMBIO] == 0)
	{
		
			if(mat_io[POS_SALIDA_DIG_3][COL_CONFIG] == CFG_SALIDA_TENSION)                      //SALIDA DE TENSIÓN 
			{
				  if(mat_io[POS_SALIDA_DIG_3][COL_VALOR] == 1)
					{
						HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_3, PIN_ACT_OUT_DIG_V_3, GPIO_PIN_SET);  //Salida de tensión a 1 -> se da tensión 
					}
					else
					{
						HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_V_3, PIN_ACT_OUT_DIG_V_3, GPIO_PIN_RESET); //Salida de tensión a 0 -> se quita tensión en la salida
					}
			}
			
			else if(mat_io[POS_SALIDA_DIG_3][COL_CONFIG] == CFG_SALIDA_CONTACTO)									//SALIDA DE CONTACTO
			{
				 if(mat_io[POS_SALIDA_DIG_3][COL_VALOR] == 1)
				 {
					 HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_3, PIN_ACT_OUT_DIG_C_3, GPIO_PIN_RESET);  //Salida de contacto a 1 -> NA
				 }
				 else
				 {
					 HAL_GPIO_WritePin(PORT_ACT_OUT_DIG_C_3, PIN_ACT_OUT_DIG_C_3, GPIO_PIN_SET);    //Salida de contacto a 0 -> NC
				 }
			}
		
	}
	
	
	//-------------------------
	
	// ENTRADAS ANALOGICAS
	
	//Entrada 1
	
	if(mat_io[POS_ENTRADA_ANA_1][COL_CAMBIO]==0)
	{
		
			if(mat_io[POS_ENTRADA_ANA_1][COL_CONFIG] == CFG_ENTRADA_020MA)
			{
				 aux_ad_ana_in_1 = get_ADC_conversion(PIN_IN_ANA_I_1);
				 mat_io[POS_ENTRADA_ANA_1][COL_VALOR] = (uint8_t)(aux_ad_ana_in_1*(aux_resol_salida_ana/aux_resol_ad_ana));
			}
			else if(mat_io[POS_ENTRADA_ANA_1][COL_CONFIG] == CFG_ENTRADA_420MA)
			{
				aux_ad_ana_in_1 = get_ADC_conversion(PIN_IN_ANA_I_1);
				mat_io[POS_ENTRADA_ANA_1][COL_VALOR] = (uint8_t)(aux_ad_ana_in_1*(aux_resol_salida_ana/aux_resol_ad_ana));
			}
			else if (mat_io[POS_ENTRADA_ANA_1][COL_CONFIG] == CFG_ENTRADA_010V)
			{
				aux_ad_ana_in_1 = get_ADC_conversion(PIN_IN_ANA_V_1);
				mat_io[POS_ENTRADA_ANA_1][COL_VALOR] = (uint8_t)(aux_ad_ana_in_1*(aux_resol_salida_ana/aux_resol_ad_ana));
			}
			else
			{
				mat_io[POS_ENTRADA_ANA_1][COL_VALOR] = 0;
			}	
	}
	else
	{
		mat_io[POS_ENTRADA_ANA_1][COL_VALOR] = 0;
	}
	
	
	//Entrada 2
	if(mat_io[POS_ENTRADA_ANA_2][COL_CAMBIO]==0)
	{
		
			if(mat_io[POS_ENTRADA_ANA_2][COL_CONFIG] == CFG_ENTRADA_020MA)
			{
				 aux_ad_ana_in_2 = get_ADC_conversion(PIN_IN_ANA_I_2);
				 mat_io[POS_ENTRADA_ANA_2][COL_VALOR] = (uint8_t)(aux_ad_ana_in_2*(aux_resol_salida_ana/aux_resol_ad_ana));
			}
			else if(mat_io[POS_ENTRADA_ANA_2][COL_CONFIG] == CFG_ENTRADA_420MA)
			{
				aux_ad_ana_in_2 = get_ADC_conversion(PIN_IN_ANA_I_2);
				mat_io[POS_ENTRADA_ANA_2][COL_VALOR] = (uint8_t)(aux_ad_ana_in_2*(aux_resol_salida_ana/aux_resol_ad_ana));
			}
			else if (mat_io[POS_ENTRADA_ANA_2][COL_CONFIG] == CFG_ENTRADA_010V)
			{
				aux_ad_ana_in_2 = get_ADC_conversion(PIN_IN_ANA_V_2);
				mat_io[POS_ENTRADA_ANA_2][COL_VALOR] = (uint8_t)(aux_ad_ana_in_2*(aux_resol_salida_ana/aux_resol_ad_ana));
			}
			else
			{
				mat_io[POS_ENTRADA_ANA_2][COL_VALOR] = 0;
			}	
	}
	else
	{
		mat_io[POS_ENTRADA_ANA_2][COL_VALOR] = 0;
	}
	
	
	//Entrada 3
	
	if(mat_io[POS_ENTRADA_ANA_3][COL_CAMBIO]==0)
	{
		
			if(mat_io[POS_ENTRADA_ANA_3][COL_CONFIG] == CFG_ENTRADA_020MA)
			{
				 aux_ad_ana_in_3 = get_ADC_conversion(PIN_IN_ANA_I_3);
				 mat_io[POS_ENTRADA_ANA_3][COL_VALOR] = (uint8_t)(aux_ad_ana_in_3*(aux_resol_salida_ana/aux_resol_ad_ana));
			}
			else if(mat_io[POS_ENTRADA_ANA_3][COL_CONFIG] == CFG_ENTRADA_420MA)
			{
				aux_ad_ana_in_3 = get_ADC_conversion(PIN_IN_ANA_I_3);
				mat_io[POS_ENTRADA_ANA_3][COL_VALOR] = (uint8_t)(aux_ad_ana_in_3*(aux_resol_salida_ana/aux_resol_ad_ana));
			}
			else if (mat_io[POS_ENTRADA_ANA_3][COL_CONFIG] == CFG_ENTRADA_010V)
			{
				aux_ad_ana_in_3 = get_ADC_conversion(PIN_IN_ANA_V_3);
				mat_io[POS_ENTRADA_ANA_3][COL_VALOR] = (uint8_t)(aux_ad_ana_in_3*(aux_resol_salida_ana/aux_resol_ad_ana));
			}
			else
			{
				mat_io[POS_ENTRADA_ANA_3][COL_VALOR] = 0;
			}	
	}
	else
	{
		mat_io[POS_ENTRADA_ANA_3][COL_VALOR] = 0;
	}
	
	//-------------------------
	
	// SALIDAS ANALOGICAS
	
	
	//Salida 1
	if(mat_io[POS_SALIDA_ANA_1][COL_CAMBIO]==0)
	{
		if(mat_io[POS_SALIDA_ANA_1][COL_CONFIG] == CFG_SALIDA_020MA)
		{
			aux_duty_sal_ana_1 = mat_io[POS_ENTRADA_ANA_1][COL_VALOR];
			set_PWM_out_ana_1_i(aux_duty_sal_ana_1);
			
		}
		else if(mat_io[POS_SALIDA_ANA_1][COL_CONFIG] == CFG_ENTRADA_420MA)
		{
			aux_duty_sal_ana_1 = mat_io[POS_ENTRADA_ANA_1][COL_VALOR];  //Revisar en base al nivel base que se tendrá 0 será 4 mA y 20 será 20 mA
			//Cálculo para incrementar fijando la base de 4mA
			set_PWM_out_ana_1_i(aux_duty_sal_ana_1);
		}
		else if(mat_io[POS_SALIDA_ANA_1][COL_CONFIG] == CFG_ENTRADA_010V)
		{
			aux_duty_sal_ana_1 = mat_io[POS_ENTRADA_ANA_1][COL_VALOR]; 
			set_PWM_out_ana_1_v(aux_duty_sal_ana_1);
		}
		else
		{
			set_PWM_out_ana_1_v(0);
		  set_PWM_out_ana_1_i(0);
		}
	}
	else
	{
		set_PWM_out_ana_1_v(0);
		set_PWM_out_ana_1_i(0);
	}
	
	
	//Salida 2
	if(mat_io[POS_SALIDA_ANA_2][COL_CAMBIO]==0)
	{
		if(mat_io[POS_SALIDA_ANA_2][COL_CONFIG] == CFG_SALIDA_020MA)
		{
			aux_duty_sal_ana_2 = mat_io[POS_ENTRADA_ANA_2][COL_VALOR];
			set_PWM_out_ana_2_i(aux_duty_sal_ana_2);
			
		}
		else if(mat_io[POS_SALIDA_ANA_2][COL_CONFIG] == CFG_ENTRADA_420MA)
		{
			aux_duty_sal_ana_2 = mat_io[POS_ENTRADA_ANA_2][COL_VALOR];  //Revisar en base al nivel base que se tendrá 0 será 4 mA y 20 será 20 mA
			//Cálculo para incrementar fijando la base de 4mA
			set_PWM_out_ana_2_i(aux_duty_sal_ana_2);
		}
		else if(mat_io[POS_SALIDA_ANA_2][COL_CONFIG] == CFG_ENTRADA_010V)
		{
			aux_duty_sal_ana_2 = mat_io[POS_ENTRADA_ANA_2][COL_VALOR]; 
			set_PWM_out_ana_2_v(aux_duty_sal_ana_2);
		}
		else
		{
			set_PWM_out_ana_2_v(0);
		  set_PWM_out_ana_2_i(0);
		}
	}
	else
	{
		set_PWM_out_ana_2_v(0);
		set_PWM_out_ana_2_i(0);
	}
	
	
	
	//Salida 3
	if(mat_io[POS_SALIDA_ANA_3][COL_CAMBIO]==0)
	{
		if(mat_io[POS_SALIDA_ANA_3][COL_CONFIG] == CFG_SALIDA_020MA)
		{
			aux_duty_sal_ana_3 = mat_io[POS_ENTRADA_ANA_3][COL_VALOR];
			set_PWM_out_ana_3_i(aux_duty_sal_ana_3);
			
		}
		else if(mat_io[POS_SALIDA_ANA_3][COL_CONFIG] == CFG_ENTRADA_420MA)
		{
			aux_duty_sal_ana_3 = mat_io[POS_ENTRADA_ANA_3][COL_VALOR];  //Revisar en base al nivel base que se tendrá 0 será 4 mA y 20 será 20 mA
			//Cálculo para incrementar fijando la base de 4mA
			set_PWM_out_ana_3_i(aux_duty_sal_ana_3);
		}
		else if(mat_io[POS_SALIDA_ANA_3][COL_CONFIG] == CFG_ENTRADA_010V)
		{
			aux_duty_sal_ana_3 = mat_io[POS_ENTRADA_ANA_3][COL_VALOR]; 
			set_PWM_out_ana_3_v(aux_duty_sal_ana_3);
		}
		else
		{
			set_PWM_out_ana_3_v(0);
		  set_PWM_out_ana_3_i(0);
		}
	}
	else
	{
		set_PWM_out_ana_3_v(0);
		set_PWM_out_ana_3_i(0);
	}
	
	//-------------------------
	
	
}

