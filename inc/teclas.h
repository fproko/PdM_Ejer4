/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/28
 * Version: v1.0
 *===========================================================================*/
#include "sapi.h"

//FSM Antirebote
typedef enum{
   BtN_UP,       //Mientras el botón está liberado.
   BtN_FALLING,  //Mientras está ocurriendo el flanco descendente, hace anti_rebote
   BtN_RISING,   //Mientras está ocurriendo el flanco ascendente, hace anti_rebote
   BtN_DOWN      //Mientras el botón está presionado.
} ButtonState_t;

void ButtonInit(void);
void ButtonUpdate( gpioMap_t tecla );
void ButtonError( void );

void buttonPressed( gpioMap_t tecla);
void buttonReleased( gpioMap_t tecla);



