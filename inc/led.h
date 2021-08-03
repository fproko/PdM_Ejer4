/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/28
 * Version: v1.0
 *===========================================================================*/
#include "sapi.h"
#define LED_OFF 50
/*=============================================================================
 * Function: encenderLed 
 * Description: Enciende un led en particular (LEDX) -> LED1, LED2, LED3 o LEDB 
 * Inpunt: Led que se busca encender
 * Output: Valor booleano que indica el encendido exitoso del LEDX
	"1" -> Se completó el encendido del LEDX
 *===========================================================================*/
bool_t encenderLed(gpioMap_t led);

/*=============================================================================
 * Function: apagarLeds 
 * Description: Apaga todos los Leds
 * Inpunt: No recibe entradas
 * Output: Valor booleano
	"1" -> Se completó el apagado de Leds
 *===========================================================================*/
bool_t apagarLeds();
