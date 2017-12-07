/*************************************************************************//**
 * @file main.h
 *
 * @brief The main function is where a program starts execution.
 *
 * @author Albert Serrallo
 *
 * @date 06/12/2017
 *
 ****************************************************************************/

#ifndef __MAIN_H__
#define __MAIN_H__



typedef char char_t;
typedef signed char int8_t;
typedef signed short int16_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

typedef float float32_t;


/****************************************************************************
 *    PUBLIC TYPEDEFS
 ****************************************************************************/
typedef enum eBool
{
	FALSE,
	TRUE
} tBool;


typedef enum eError
{
	RET_OK,
	RET_FAIL,
	RET_BUSY,
} tError;


#endif

/* __MAIN_H__ */

