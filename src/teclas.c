/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/28
 * Version: v1.0
 *===========================================================================*/
#include "sapi.h"
#include "teclas.h"
#include "semaforo.h"

//Función leerTecla
bool_t leerTecla(gpioMap_t tecla)
{
	bool_t estado_tecla;
	estado_tecla = gpioRead(tecla);
	return estado_tecla;
}

// Variable de estado actual (global), de tipo ButtonState_t
static ButtonState_t ButtonState;

//FSM Anti-rebote Init
void buttonDBInit( void )
{
   ButtonState = BtN_UP; //Se inicializa FSM de Anti-rebote
}

//FSM Anti-rebote Error
void buttonDBError( void )
{
   ButtonState = BtN_UP;
}

void buttonPressed( gpioMap_t tecla )
{
   static uint8_t tec2pressed = 0;
   if (tecla == TEC2)
   {
      tec2pressed++;
   }   
}

void buttonReleased( gpioMap_t tecla )
{
   if (tecla == TEC2)
   {
      modeUpdate(); //Se cambia de modo
   }
}   

//FSM Anti-rebote Update
void buttonDBUpdate(gpioMap_t tecla)
{
   static delay_t delayDB; //declaración de estructura tipo delay_t

   switch (ButtonState)
   {
   case BtN_UP:
      //Si está en estado UP y presionan el pulsador pasa al estado FALLING.
      if (leerTecla(tecla) == 0)
      {
         ButtonState = BtN_FALLING;
         delayWrite(&delayDB, 40); //setea el delay
      }
      break;

   case BtN_FALLING:
      //Resuelve las acciones correspondientes al flanco descendente.
      if (delayRead(&delayDB)) //si se cumple el delay seteado ingresa
      {
         if (leerTecla(tecla) == 0) //Si tecla sigue presionada
         {
            ButtonState = BtN_DOWN; //Pasa al estado DOWN
            buttonPressed(tecla);
         }
         else
         {
            ButtonState = BtN_UP; //Vuelve al estado UP
         }
      }
      break;

   case BtN_DOWN:
      //Si está en estado DOWN y liberan el botón pasa al estado RISING.
      if (!(leerTecla(tecla) == 0))
      {
         ButtonState = BtN_RISING;
         delayWrite(&delayDB, 40); //setea el delay
      }
      break;

   case BtN_RISING:
      //Resuelve las acciones correspondientes al flanco ascendente.
      if (delayRead(&delayDB)) //si se cumple el delay seteado ingresa
      {
         if (!(leerTecla(tecla) == 0)) //Si la tecla sigue no presionada
         {
            ButtonState = BtN_UP; //Pasa al estado UP
            buttonReleased(tecla);
         }
         else
         {
            ButtonState = BtN_DOWN; //Vuelve al estado DOWN
         }
      }
      break;

   default:
      buttonDBError();
      break;
   }
}
