/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/28
 * Version: v1.0
 *===========================================================================*/
#include "sapi.h"
#define LED_OFF 50

/**
 * @brief Enciende el led que recibe como parámetro .
 * 
 * @param  led		Led que se busca encender
 * @return bool_t	"1" -> Se completó el encendido del LEDX
 */
bool_t encenderLed(gpioMap_t led);

/**
 * @brief Apaga todos los Leds
 * 
 * @return bool_t "1" -> Se completó el apagado de Leds
 */
bool_t apagarLeds();
