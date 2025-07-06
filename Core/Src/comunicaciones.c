////////////////////////////////////////////
//
// Establece las comunicaciones con la placa base
//
// Nombre: comunicacion.c
// Autor: Miguel Méndez Gayol
// Fecha: 01/07/2025
//
/////////////////////////////////////////////

#include "main.h"
#include "definiciones.h"


////////////////////////////////////////////////////////////////
//
//			FUNCIÓN PARA LA RECEPCION DE COMUNICACIONES
//
/////////////////////////////////////////////////////////////////


void recepcion_comunicaciones (uint8_t _matriz_io[][NUM_COLUM],uint8_t _buffer_rx[TAMANIO_RECEPCION], uint8_t respuesta_trans[TAMANIO_RESP_TRANSMISION] ,bool recepcion_pendiente, bool* requiere_transmision)
{
	uint8_t checksum = 0;
  if( recepcion_pendiente == true)
	{
		//Se ha recibido la respuesta evaluación del checksum 
		for(uint8_t i=0; i<(TAMANIO_RECEPCION-1);i++)
		{
			checksum = checksum+_buffer_rx[i];
		}
		if(checksum == _buffer_rx[TAMANIO_RECEPCION-1])
		{
			//Aquí se evaluará si el mensaje es para el equipo
			if(_buffer_rx[0] == CABECERA && _buffer_rx[1] == ID_PCB_BASE)
			{
				////////////////////////////
				//			Escrituras
				////////////////////////////
				
				//Escritura configuracion
				
				if(_buffer_rx[2] == ESCRITURA_CONFIG)
				{
					_matriz_io[_buffer_rx[3]][COL_CONFIG]=_buffer_rx[4];
					_matriz_io[_buffer_rx[3]][COL_CAMBIO] = 1;
				}
				
				//Escritura de valor
				else if( _buffer_rx[2] == ESCRITURA_VALOR)
				{
					_matriz_io[_buffer_rx[3]][COL_VALOR]=_buffer_rx[4];
					_matriz_io[_buffer_rx[3]][COL_CAMBIO] = 1;
				}
				
			  ////////////////////////////
				//			Lecturas
				////////////////////////////
				
				//Lectura configuracion
				else if( _buffer_rx[2] == LECTURA_CONFIG)
				{
					   respuesta_trans[0] = LECTURA_CONFIG;
					   respuesta_trans[1] = _buffer_rx[3];
				     *requiere_transmision = 1;
				}
				
				//Lectura de valor
				else if( _buffer_rx[2] == LECTURA_VALOR)
				{
					  respuesta_trans[0] = LECTURA_CONFIG;
					  respuesta_trans[1] = _buffer_rx[3];
				    *requiere_transmision = 1;
				}
				
			}
		}
	}
	
}

////////////////////////////////////////////////////////////////
//
//			FUNCIÓN PARA LA TRANSMISION DE COMUNICACIONES
//
/////////////////////////////////////////////////////////////////


void transmision_comunicaciones(uint8_t _matriz_io[][NUM_COLUM],uint8_t _buffer_tx[TAMANIO_TRANSMISION],uint8_t respuesta_trans[TAMANIO_RESP_TRANSMISION],bool transmision_pendiente)
{
	
	uint8_t checksum = 0;
	
	if(transmision_pendiente == true)
	{
		//Lectura de configuración
		if(respuesta_trans[0] == LECTURA_CONFIG)
		{
			_buffer_tx[0] = CABECERA;
			_buffer_tx[1] = ID_MAESTRO;
			_buffer_tx[2] = LECTURA_CONFIG;
			_buffer_tx[3] = respuesta_trans[1];
			_buffer_tx[4] = _matriz_io[COL_CONFIG][respuesta_trans[1]];
			
			for(uint8_t i=0; i<(TAMANIO_TRANSMISION-1); i++)
			{
				checksum = checksum + _buffer_tx[i];
			}
			_buffer_tx[5] = checksum;
			
		}
		else if(respuesta_trans[1] == LECTURA_VALOR)
		{
			
			_buffer_tx[0] = CABECERA;
			_buffer_tx[1] = ID_MAESTRO;
			_buffer_tx[2] = LECTURA_VALOR;
			_buffer_tx[3] = respuesta_trans[1];
			_buffer_tx[4] = _matriz_io[COL_VALOR][respuesta_trans[1]];
			
			for(uint8_t i=0; i<(TAMANIO_TRANSMISION-1); i++)
			{
				checksum = checksum + _buffer_tx[i];
			}
			_buffer_tx[5] = checksum;
			
		}
	}
}