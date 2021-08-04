/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/28
 * Version: v1.0
 *===========================================================================*/
#include "led.h"
#include "sapi.h"

//Función encenderLed
bool_t encenderLed(gpioMap_t led){
	if(led!=LED_OFF)
	{
		gpioWrite( led, ON );
	}
	return 1;
}

//Función apagarLeds
bool_t apagarLeds(){
	gpioWrite( LEDR, OFF );
	gpioWrite( LEDG, OFF );
	gpioWrite( LEDB, OFF );
	gpioWrite( LED1, OFF );
	gpioWrite( LED2, OFF );
	gpioWrite( LED3, OFF );
	return 1;
}
