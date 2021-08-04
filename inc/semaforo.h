/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/28
 * Version: v1.0
 *===========================================================================*/
#include "sapi.h"

//! Enumeración de Semaphore state names
typedef enum
{
   S_RED,        //!<LED Rojo Prendido.
   S_RED_YELLOW, //!<LED Rojo y LED Amarillo Prendidos.
   S_GREEN,      //!<LED Verde Prendido.
   S_YELLOW,     //!<LED Amarillo Prendido.
   S_OFF         //!<LEDs Apagados.
} SemaphoreState_t;

//! Enumeración de Semaphore Mode state names
typedef enum
{
   NORMAL_MODE,       //!<Secuencia de LEDs: Rojo 3 s, Rojo y Amarillo 500 ms, Verde 1s, Amarillo 500 ms y Rojo nuevamente.
   DISCONNECTED_MODE, //!<Led Amarillo intermitente cada 500 mS.
   ALARM_MODE         //!<Led Rojo intermitente cada 1000 mS.
} ModeState_t;

/**
 * @brief Inicializa FSM Semaforo.
 * 
 */
void semaphoreInit( void );

/**
 * @brief Actualiza FSM Semaforo.
 * 
 */
void semaphoreUpdate( void );

/**
 * @brief Realiza tratamiento de un error en FSM Semaforo.
 * 
 */
void semaphoreError( void );

/**
 * @brief Inicializa FSM Modo de Semaforo.
 * 
 */
void modeInit( void );

/**
 * @brief Actualiza FSM Modo de Semaforo.
 * 
 */
void modeUpdate( void );

/**
 * @brief Realiza tratamiento de un error en FSM Modo de Semaforo.
 * 
 */
void modeError( void );

