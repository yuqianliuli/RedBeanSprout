/* #include "stm32f1_wdg.h" */

#ifndef __STM32F1_WDG_H
#define __STM32F1_WDG_H
/*=====================================================================================================*/
/*=====================================================================================================*/
void IWDG_Config( u8 Prescaler, u16 Reload );
void IWDG_FeedDog( void );
void WWDG_Config( u32 Prescaler, u8 WindowValue );
void WWDG_FeedDog( u8 CounterValue );
/*=====================================================================================================*/
/*=====================================================================================================*/
#endif	 