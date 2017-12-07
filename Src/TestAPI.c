/*************************************************************************//**
 * @file TestAPI.c
 *
 * @brief Basic set of functions
 *
 * @author Albert Serrallo
 *
 * @date 07/12/2017
 *
 ****************************************************************************/

#include "typedef.h"


void RobotTask(uint8_t u8Command)
{
	/* It is the function that executes the main task of the robot system. It needs the command
	 * obtained from EEPROM.
	 */
}

void RobotStop (void)
{
	/* Stops immediately the robot operation. */
}

void TimerInit(void)
{
	/* Initializes a timer and enables its interrupt. The ISR is called TimerISR */
}


uint32_t TimetGetus(void)
{
	/* Returns the number of us on the Timer since its initialization.
	 * To avoid warning in the compilation  we return 1
	 */
	return 1;
}


void SPIInit(void)
{

}

void SPIEepromEnable(void)
{
	/* Set to LOW the Chip select signal of the SPI protocol to allow communication with EEPROM. */
}

void SPIEepromDisable(void)
{
	/* Set to HIGH the Chip select signal of the SPI protocol to disable communication with EEPROM */
}

void SPISensorEnable(void)
{
	/* Set to LOW the Chip select signal of the SPI protocol to allow communication with Sensor. */
}

void SPISensorDisable(void)
{
	/* Set to HIGH the Chip select signal of the SPI protocol to disable communication with Sensor */
}

uint8_t SPIRead(void)
{
	/* Returns the value read from the SPI bus. To avoid warning in the compilation  we return 1 */
	return 1;
}

