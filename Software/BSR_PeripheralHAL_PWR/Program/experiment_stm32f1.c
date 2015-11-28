/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f1_system.h"

#include "experiment_stm32f1.h"
/*====================================================================================================*/
/*====================================================================================================*/
void PWR_StandbyMode( void );
/*====================================================================================================*/
/*====================================================================================================*/
void System_Init( void )
{
  HAL_Init();
  GPIO_Config();
}

int main( void )
{
  System_Init();

  while(1) {
    LED_R_Toggle();
    Delay_100ms(1);
    if(KEY_BO_Read()) {
      LED_B_Reset();
      PWR_StandbyMode();   // Use KEY_WU to WakeUp
    }
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void PWR_StandbyMode( void )
{
  __HAL_RCC_PWR_CLK_ENABLE();

  if(__HAL_PWR_GET_FLAG(PWR_FLAG_SB) != RESET)
    __HAL_PWR_CLEAR_FLAG(PWR_FLAG_SB);

  Delay_100ms(50);

  HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);
  __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
  HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
  HAL_PWR_EnterSTANDBYMode();
}
/*====================================================================================================*/
/*====================================================================================================*/
