/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/28
 * Version: v1.0
 *===========================================================================*/
#include "sapi.h"

//! Enumeración de FSM Antirebote
typedef enum{
   BtN_UP,       //!<Mientras el botón está liberado.
   BtN_FALLING,  //!<Mientras está ocurriendo el flanco descendente, hace anti_rebote
   BtN_RISING,   //!<Mientras está ocurriendo el flanco ascendente, hace anti_rebote
   BtN_DOWN      //!<Mientras el botón está presionado.
} ButtonState_t;

/**
 * @brief Inicializa FSM Anti-rebote.
 * 
 */
void buttonDBInit(void);

/**
 * @brief Actualiza FSM Anti-rebote.
 * 
 * @param tecla   Tecla a la cual se aplica Anti-Rebote.
 */
void buttonDBUpdate( gpioMap_t tecla );

/**
 * @brief Realiza tratamiento de un error en FSM Antirebote.
 * 
 */
void buttonDBError( void );

/**
 * @brief Resuelva las acciones correspondientes al flanco descendente.  
 * 
 * @param tecla Tecla presionada.
 */
void buttonPressed( gpioMap_t tecla);

/**
 * @brief Resuelva las acciones correspondientes al flanco descendente.
 * 
 * 
 * Cuando se libera la tecla TEC2 se llama a la función modeUpdate(), para indicar que la tecla
 * fue presionada.
 * @param tecla Tecla soltada.
 */
void buttonReleased( gpioMap_t tecla);



