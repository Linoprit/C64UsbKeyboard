/*
 * MasterSerialTask.h
 *
 *  Created on: 02.02.2019
 *      Author: harald
 */

#pragma once

#define	 PACKED	__attribute__ ((packed))

#define NUM_ROWS 9
#define NUM_COLS 9
#define NUM_RAW_KEYS 6

// C interface
#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif


EXTERNC void applicationTask(void const * argument);


#undef EXTERNC
#ifdef __cplusplus

// cpp classes and includes go here


#endif // C interface
