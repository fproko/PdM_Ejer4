/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/28
 * Version: v1.0
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "main.h"
#include "sapi.h"
#include "teclas.h"
#include "semaforo.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main(void)
{
   // ----- Setup -----------------------------------
   boardInit();     // Se inicializa el Hardware
   buttonDBInit();  //Se inicializa FSM de Anti-rebote
   modeInit();      //Se inicializa FSM Mode
   semaphoreInit(); //Se inicializa FSM Semaforo

   // ----- Repeat for ever -------------------------
   while (true)
   {
      buttonDBUpdate(TEC2); //Se actualiza estado del Botón
      semaphoreUpdate();    //Se actualiza el estado del Semaforo
   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the
   // case of a PC program.
   return 0;
}
