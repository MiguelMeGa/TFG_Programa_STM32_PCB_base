////////////////////////////////////////////
//
// Definición de constantes del sistema
//
// Nombre: definiciones.h
// Autor: Miguel Méndez Gayol
// Fecha: 03/05/2025
//
/////////////////////////////////////////////

//--------------------------------------------
//
//  		Configuraciones del sistema
//
//---------------------------------------------

#define CARGA_1KHZ    8000


//--------------------------------------------
//
//  				Pines del sistema 
//
//---------------------------------------------

////////////////////////////////////////////////
// 			Salidas digitales
////////////////////////////////////////////////

#define PIN_ACT_OUT_DIG_V_1  GPIO_PIN_9   
#define PORT_ACT_OUT_DIG_V_1 GPIOB
#define PIN_ACT_OUT_DIG_V_2  GPIO_PIN_10  
#define PORT_ACT_OUT_DIG_V_2 GPIOB
#define PIN_ACT_OUT_DIG_V_3  GPIO_PIN_11  
#define PORT_ACT_OUT_DIG_V_3 GPIOB
#define PIN_ACT_OUT_DIG_C_1  GPIO_PIN_12   
#define PORT_ACT_OUT_DIG_C_1 GPIOB
#define PIN_ACT_OUT_DIG_C_2  GPIO_PIN_13   
#define PORT_ACT_OUT_DIG_C_2 GPIOB
#define PIN_ACT_OUT_DIG_C_3  GPIO_PIN_14   
#define PORT_ACT_OUT_DIG_C_3 GPIOB

//////////////////////////////////////////////////
//  Entradas digitales
//////////////////////////////////////////////////

#define PIN_ACT_IN_DIG_1  GPIO_PIN_2   
#define PORT_ACT_IN_DIG_1 GPIOB
#define ADC_IN_DIG_1      ADC_CHANNEL_0  //PA0
#define PIN_ACT_IN_DIG_2  GPIO_PIN_3   
#define PORT_ACT_IN_DIG_2 GPIOB
#define ADC_IN_DIG_2      ADC_CHANNEL_1  //PA1
#define PIN_ACT_IN_DIG_3  GPIO_PIN_4   
#define PORT_ACT_IN_DIG_3 GPIOB
#define ADC_IN_DIG_3      ADC_CHANNEL_2  //PA2      

//////////////////////////////////////////////////
//  			Salidas analógicas
//////////////////////////////////////////////////

#define PIN_OUT_ANA_1_I  GPIO_PIN_6   
#define PORT_OUT_ANA_1_I GPIOA
#define PWM_OUT_ANA_1_I  TIM_CHANNEL_1

#define PIN_OUT_ANA_2_I  GPIO_PIN_7   
#define PORT_OUT_ANA_2_I GPIOA
#define PWM_OUT_ANA_2_I  TIM_CHANNEL_2

#define PIN_OUT_ANA_3_I  GPIO_PIN_8   
#define PORT_OUT_ANA_3_I GPIOA
#define PWM_OUT_ANA_3_I  TIM_CHANNEL_1

#define PIN_OUT_ANA_1_V  GPIO_PIN_9   
#define PORT_OUT_ANA_1_V GPIOA
#define PWM_OUT_ANA_1_V  TIM_CHANNEL_2

#define PIN_OUT_ANA_2_V  GPIO_PIN_10  
#define PORT_OUT_ANA_2_V GPIOA
#define PWM_OUT_ANA_2_V  TIM_CHANNEL_3

#define PIN_OUT_ANA_3_V  GPIO_PIN_11  
#define PORT_OUT_ANA_3_V GPIOA
#define PWM_OUT_ANA_3_V  TIM_CHANNEL_4

//////////////////////////////////////////////////
//  			Entradas analógicas
//////////////////////////////////////////////////

#define PIN_IN_ANA_V_1  ADC_CHANNEL_3  //PA3 
#define PIN_IN_ANA_V_2  ADC_CHANNEL_4  //PA4 
#define PIN_IN_ANA_V_3  ADC_CHANNEL_5  //PA5
#define PIN_IN_ANA_I_1  ADC_CHANNEL_8  //PB0
#define PIN_IN_ANA_I_2  ADC_CHANNEL_9  //PB1
#define PIN_IN_ANA_I_3  ADC_CHANNEL_9  //PB2 (Modificar está mal)

#define PIN_ACT_IN_ANA_1  GPIO_PIN_13   
#define PORT_ACT_IN_ANA_1 GPIOA
#define PIN_ACT_IN_ANA_2  GPIO_PIN_14   
#define PORT_ACT_IN_ANA_2 GPIOB
#define PIN_ACT_IN_ANA_3  GPIO_PIN_15   
#define PORT_ACT_IN_ANA_3 GPIOB

//--------------------------------------------
//
//   Tamaño matriz IO y posiciones 
//
//--------------------------------------------

#define NUM_IO     12
#define NUM_COLUM   3  //Columna 1 configuración / Columna 2 parte referente a las entradas/ Columna 3 cambio de configuración

#define COL_CONFIG  0  //Posición en la matriz de entradas salidas de la configuración implementada
#define COL_VALOR   1  //Posición del valor implementado (en entradas lo que se lea y en salidas el valor implementado)
#define COL_CAMBIO  2  //Si la entrada/salida ha experimentado un cambio toma un valor distinto a 0

#define POS_ENTRADA_DIG_1     0
#define POS_ENTRADA_DIG_2     1
#define POS_ENTRADA_DIG_3     2
#define POS_SALIDA_DIG_1      3
#define POS_SALIDA_DIG_2      4
#define POS_SALIDA_DIG_3      5
#define POS_ENTRADA_ANA_1     6
#define POS_ENTRADA_ANA_2     7
#define POS_ENTRADA_ANA_3     8
#define POS_SALIDA_ANA_1      9
#define POS_SALIDA_ANA_2     10
#define POS_SALIDA_ANA_3     11

//--------------------------------------------
//
//    Configuraciones IO 
//
//--------------------------------------------
#define CFG_IDLE                 0  //Configuración común a todas las entradas 
#define CFG_ENTRADA_TENSION      1
#define CFG_ENTRADA_CONTACTO     2

#define CFG_ENTRADA_020MA        1
#define CFG_ENTRADA_420MA        2
#define CFG_ENTRADA_010V         3

#define CFG_SALIDA_TENSION       1
#define CFG_SALIDA_CONTACTO      2

#define CFG_SALIDA_020MA         1
#define CFG_SALIDA_420MA         2
#define CFG_SALIDA_010V          3


//--------------------------------------------
//
//  	Turno en la INTERRUPCIÓN DE TIEMPO
//
//---------------------------------------------

#define TURNO_RECEPCION     1  //100ms -> //Se refiere a la recepción  y decodificación de la información 
#define TURNO_CONFIG_IO     2  //200ms -> //Especifica el turno en el que se vuelcan las configuraciones de las entradas y salidas 
#define TURNO_LECTESC_IO    3  //300ms -> //Establece la lectura escritura de las entradas  o salidas del sistema para comunicación del elemento
#define TURNO_TRANSMISION   4  //400 ms -> Turno de comunicación de la pantalla


//--------------------------------------------
//
//  LIMITES DE NIVEL ENTRADAS DIGITALES
//
//---------------------------------------------

//Entradas digitales
#define LIMITE_ON_ENTRADA_TENSION   2000  //Por encima de 16V aprox
#define LIMITE_NA_ENTRADA_CONTACTO   300  //Por encima de 0,3V aprox

//Entradas analógicas
#define  TENSION_VCC   3.3    //Tensión de alimentación de 3V3
#define  RANGO_AD      4095.0    //Límite superior en la medida NOTA: 255 será el límite de 
#define  RANGO_DESTINO 255.0   

//--------------------------------------------
//
// 				 TAMAÑO BUFFERS COMUNICACION
//
//---------------------------------------------

#define 	TAMANIO_RECEPCION        6    //Se especifica el tamaño en la recepción 
#define   TAMANIO_TRANSMISION      6    //Se especifica el tamaño en la transmisión 
#define   TAMANIO_RESP_TRANSMISION 2     //Marca el buffer auxiliar que nos indica lo que tenemos que leer en el bufer
//---------------------------------------------
//
//			IDENTIFICACION PLACA_BASE Y MAESTRO
//
//----------------------------------------------

#define 	ID_PCB_BASE 	5
#define 	ID_MAESTRO    0


//-------------------------------------------------
//
//  			PALABRAS EN COMUNICACIONES
//
//-------------------------------------------------

#define CABECERA   			 33
#define LECTURA_CONFIG    1     //Lectura de la configuración del sistema
#define LECTURA_VALOR     2     //Lectura del valor de una entrada/salida
#define ESCRITURA_CONFIG 129    //Escritura de la configuración
#define ESCRITURA_VALOR  130    //Escritura del valor 