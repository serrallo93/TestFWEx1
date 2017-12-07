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
#include "typedef.h"
#include "main.h"
#include "TestAPI.h"

/****************************************************************************
 *    DEFINES
 ****************************************************************************/


/****************************************************************************
 *    PUBLIC VARIABLE
 ****************************************************************************/
tBool robotTaskEnable;
tBool isSpiReady;

/****************************************************************************
 *    PRIVATE FUNCTIONS
 ****************************************************************************/
static tError getNextTaskFromEEPROM( uint8_t* command );
static tBool checkSensorDetected( void );


/*************************************************************************//**
 * @brief   Embedded application start routine.
 * @param	None
 * @return  0
 ****************************************************************************/
int main()
{
	uint8_t command;
	robotTaskEnable = TRUE;
	isSpiReady = TRUE;

	/* Timer and SPI Initialization
	 * TimerInit expend 5ms and SPIInit expends 7ms, but is not problem
	 * because there are in the Initialization phase.
	 */
	TimerInit();
	SPIInit();

    while (TRUE)
    {
    	/* If the robotTask is enabled, we execute as fast as possible the next
    	 * robot task, so we put in the infinite loop
    	 */
    	if (robotTaskEnable == TRUE)
    	{
			if (getNextTaskFromEEPROM(&command) == RET_OK)
			{
				RobotTask(command);
			}
    	}
    	else
    	{
    		// System Stop state. Nothing to execute
    	}
    }

    return 0;
}


/*************************************************************************//**
* @brief   Interrupt Timer callback. It is executed every 1 ms. Its read
*          and check the sensor. In case that object is detected, we execute
*          Robot Stop functionality and disable robotTaskEnable to entry in a
*          system stop state
******************************************************************************/
void TimerISR(void)
{
	if (robotTaskEnable == TRUE)
	{
		if( checkSensorDetected()== TRUE)
		{
			RobotStop();
			robotTaskEnable = FALSE;
		}
	}
}



/*************************************************************************//**
* @brief   get the next command task from the EEPROM SPI memory
* @return  Command
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
* @return  TRUE (Object is detected) or FALSE (Object is NOT detected)
******************************************************************************/
static tBool checkSensorDetected( void )
{
	tBool detection = FALSE;
	uint8_t val;

	/* Is the SPI is Busy for the EEPROM, Disable
	 * in order to give priority to the Sensor communication.
	 */
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
