/*************************************************************************//**
 * @file Exercise1_main.c
 *
 * @brief For this test exercise I suppose that the SPI is working as Polling
 * 		  mode.
 *
 * @author Albert Serrallo
 *
 * @date 06/12/2017
 *
 ****************************************************************************/

/****************************************************************************
*  INCLUDES
****************************************************************************/
#include "stdint.h"
#include "main.h"
#include "TestAPI.h"

/****************************************************************************
 *    DEFINES
 ****************************************************************************/
#define PERIODIC_TIME_SENSOR_TASK 1000
#define PERIODIC_TIME_ROBOT_TASK 100000

/****************************************************************************
 *    PUBLIC VARIABLE
 ****************************************************************************/
tBool robotTaskEnable;
tBool isSpiReady;
uint32_t timeProcessRobotTask;
uint32_t timeProcessSensorTask;

/****************************************************************************
 *    PRIVATE FUNCTIONS
 ****************************************************************************/
static tError getNextTaskFromEEPROM( uint8_t* command );
static tBool checkSensorDetected( void );


/*************************************************************************//**
 * @brief   Embedded application start routine.
 * @param	None
 * @return  None
 ****************************************************************************/
int main()
{
	uint8_t command;
	robotTaskEnable = TRUE;
	isSpiReady = TRUE;

	/* Timer and SPI Initialization */
	TimerInit();
	SPIInit();

    while (TRUE)
    {
    	/* If the robotTask is Enable, we execute as fast as possible, so we
    	 * put in the infinite loop.
    	 */
    	if (robotTaskEnable == TRUE)
    	{
			if (getNextTaskFromEEPROM(&command) == RET_OK)
			{
				RobotTask(command);
			}
    	}
    }

    return 0;
}


/*************************************************************************//**
* @brief   Interrupt Timer callback. It is executed every 1 ms. Its read
*          and check the sensor. It is not the best
*          way, but we don't know how RobotTask is implemented, so its supposed
*          that is polling mode and the only way to execute another functionality
*          is in an interrupt.
******************************************************************************/
void TimerISR(void)
{
	if (robotTaskEnable == TRUE && checkSensorDetected())
	{
		RobotStop();
		robotTaskEnable = FALSE;
	}
}


/*************************************************************************//**
* @brief   Check if the sensor detects presence, in affirmative case Stops
*          the Robot and disable the robotTask.
*
******************************************************************************/
void callSensorTask(void)
{
	if (checkSensorDetected() == TRUE && robotTaskEnable == TRUE)
	{
		RobotStop();
		robotTaskEnable = FALSE;
	}
}


/*************************************************************************//**
* @brief   get the next command task from the EEPROM SPI memory
*
* @return  Command
*
******************************************************************************/
static tError getNextTaskFromEEPROM( uint8_t* command )
{
	tError ret;

	if (isSpiReady == TRUE)
	{
		SPIEepromEnable();
		*command = SPIRead();
		SPIEepromDisable();
		ret = RET_OK;
	}
	else
	{
		ret = RET_BUSY;
	}

	return ret;
}


/*************************************************************************//**
* @brief   Check if the sensor detects collision
*
* @return  TRUE or FALSE
*
******************************************************************************/
static tBool checkSensorDetected( void )
{
	tBool detection = FALSE;
	uint8_t val;

	if (isSpiReady == FALSE)
	{
		SPIEepromDisable();
	}

	SPISensorEnable();
	val = SPIRead();
	SPISensorDisable();

	if (val > 128)
	{
		detection = TRUE;
	}

	return detection;
}

/****************************************************************************
 *    End of file
 ***************************************************************************/
