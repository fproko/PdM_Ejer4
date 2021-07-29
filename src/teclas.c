/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/28
 * Version: v1.0
 *===========================================================================*/
#include "teclas.h"
#include "sapi.h"

// Variable that hold the current state
fsmState_t fsmState;

// FSM Error Handler Function
void fsmError( void )
{
   // Error handler, example, restart FSM:
   // fsmState = STATE_INIT;
}

// FSM Initialize Function
void fsmInit( void )
{
   // Example:
   // boardInit();          // Initialize hardwaree
   fsmState = STATE_INIT;   // Set initial state
}

// FSM Update Sate Function
void fsmUpdate( void )
{
   static bool_t flagStateInit = FALSE;
   static bool_t flagState1 = FALSE;
   // ...
   static bool_t flagStateN = FALSE;

   switch( fsmState ){

      case STATE_INIT:
         // ...
      break;

      // ...

      case STATE_N:
      
         /* ENTRY */
         if( flagStateN == FALSE ){
            flagStateN = TRUE;
            // Code for entry...    
         }
         
         /* UPDATE OUTPUTS */
         // Code for update outputs... 
         
         /* CHECK TRANSITION CONDITIONS */
         // Code for check transitions (some ifs)... 

         /* LEAVE */
         if( fsmState != STATE_N ){
            flagStateN = FALSE;
            // Code for leave...  
         }
      break;

      default:
         fsmError();
      break;
   }
}