/*************************************************************************//**
 * @file IngeniaAPI.h
 *
 * @brief Basic set of functions
 *
 * @author Albert Serrallo
 *
 * @date 07/12/2017
 *
 ****************************************************************************/


#ifndef __TEST_API_H__
#define __TEST_API_H__


/****************************************************************************
*  INCLUDES
****************************************************************************/
#include "typedef.h"

/****************************************************************************
 *    PUBLIC FUNCTIONS
 ****************************************************************************/
void RobotTask(uint8_t u8Command);
void RobotStop (void);
void TimerInit(void);
void TimerISR(void);
uint32_t TimetGetus(void);
void SPIInit(void);
void SPIEepromEnable(void);
void SPIEepromDisable(void);
void SPISensorEnable(void);
void SPISensorDisable(void);
uint8_t SPIRead(void);



#endif /* __TEST_API_H__ */
