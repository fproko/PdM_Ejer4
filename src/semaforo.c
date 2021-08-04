/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Author: Armando Suhuán <suhuan.aj@pucp.edu.pe>
 * Date: 2021/07/28
 * Version: v1.0
 *===========================================================================*/
#include "semaforo.h"
#include "sapi.h"
#include "led.h"

//Variable de estado actual privada, de tipo SemaphoreState_t
static SemaphoreState_t SemaphoreState;
//Variable de estado actual privada, de tipo ModeState_t
static ModeState_t ModeState;
//Estructura privada de tipo delay_t utilizada para los retardos del Semaforo
static delay_t delayS;

//FSM Semaphore Mode Init
void modeInit( void )
{
   ModeState = NORMAL_MODE; //Se inicializa FSM de Modo en NORMAL_MODE
}

//FSM Semaphore Init
void semaphoreInit( void )
{
   SemaphoreState = S_RED; //Se inicializa FSM de Semaforo en el estado S_RED
}

// FSM Semaphore Mode Update
void modeUpdate( void )
{
	delayWrite(&delayS, 0);
    switch (ModeState)
    {
    case NORMAL_MODE:
        ModeState = DISCONNECTED_MODE;
        SemaphoreState = S_OFF;
        break;

    case DISCONNECTED_MODE:
        ModeState = ALARM_MODE;
        SemaphoreState = S_OFF;
        break;
    
    case ALARM_MODE:
        ModeState = NORMAL_MODE;
        SemaphoreState = S_RED;
        break;
        
    default:
        modeError();
        break;
    }
}

//FSM Semaphore Update
void semaphoreUpdate(void)
{
	//static delay_t delayS;
    if (delayRead(&delayS)) //si se cumple el delay seteado ingresa
    {
        if (ModeState == NORMAL_MODE)
        {
            switch (SemaphoreState)
            {
            case S_RED:
                apagarLeds();
                encenderLed(LED1);
                delayWrite(&delayS, 3000);
                SemaphoreState = S_RED_YELLOW;
                break;
            case S_RED_YELLOW:
                apagarLeds();
                encenderLed(LED1);
                encenderLed(LED2);
                delayWrite(&delayS, 500);
                SemaphoreState = S_GREEN;
                break;
            case S_GREEN:
                apagarLeds();
                encenderLed(LED3);
                delayWrite(&delayS, 1000);
                SemaphoreState = S_YELLOW;
                break;
            case S_YELLOW:
                apagarLeds();
                encenderLed(LED2);
                delayWrite(&delayS, 500);
                SemaphoreState = S_RED;
                break;
            default:
                semaphoreError();
                break;
            }
        }
        else if (ModeState == DISCONNECTED_MODE)
        {
            switch (SemaphoreState)
            {
            case S_OFF:
                SemaphoreState = S_YELLOW;
                apagarLeds();
                delayInit(&delayS, 500);
                break;
            case S_YELLOW:
                apagarLeds();
                encenderLed(LED2);
                delayWrite(&delayS, 500);
                SemaphoreState = S_OFF;
                break;
            default:
                semaphoreError();
                break;
            }
        }
        else if (ModeState == ALARM_MODE)
        {
            switch (SemaphoreState)
            {
            case S_OFF:
                SemaphoreState = S_RED;
                apagarLeds();
                delayInit(&delayS, 1000);
                break;
            case S_RED:
                apagarLeds();
                encenderLed(LED1);
                delayWrite(&delayS, 1000);
                SemaphoreState = S_OFF;
                break;
            default:
                semaphoreError();
                break;
            }
        }
    }
}

void semaphoreError( void )
{
    SemaphoreState = S_RED;
}

void modeError( void )
{
    ModeState = NORMAL_MODE;
}
