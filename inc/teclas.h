/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/28
 * Version: v1.0
 *===========================================================================*/
#include "sapi.h"

// FSM state names
typedef enum{
   STATE_INIT,
   STATE_1,
   STATE_2,
   // ...
   STATE_N
} fsmState_t;

// FSM functions
void fsmError( void );
void fsmInit( void );
void fsmUpdate( void );
