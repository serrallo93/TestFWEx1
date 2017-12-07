/*************************************************************************//**
 * @file typedef.h
 *
 * @brief Basic typedef
 *
 * @author Albert Serrallo
 *
 * @date 07/12/2017
 *
 ****************************************************************************/


#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__


#include "stdint.h"

typedef char char_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;


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



#endif /* __TYPEDEF_H__ */
