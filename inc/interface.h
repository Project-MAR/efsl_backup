/*****************************************************************************\
*              efs - General purpose Embedded Filesystem library              *
*          --------------------------------------------------------           *
*                                                                             *
* Filename : interface.h                                                      *
* Revision : Initial developement                                             *
* Description : This headerfile includes the right interface headerfile       *
*                                                                             *
* This library is free software; you can redistribute it and/or               *
* modify it under the terms of the GNU Lesser General Public                  *
* License as published by the Free Software Foundation; either                *
* version 2.1 of the License, or (at your option) any later version.          *
*                                                                             *
* This library is distributed in the hope that it will be useful,             *
* but WITHOUT ANY WARRANTY; without even the implied warranty of              *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU           *
* Lesser General Public License for more details.                             *
*                                                                             *
*                                                                             *
*                                                    (c)2004 Michael De Nil   *
\*****************************************************************************/

#ifndef __TYPES_H__
#define __TYPES_H__

/*****************************************************************************/
#include "types.h"
#include "config.h"
/*****************************************************************************/

#if defined(HW_ENDPOINT_LINUX)
	#include "interfaces/linuxfile.h"
#elif defined(HW_ENDPOINT_ATMEGA128_SD)
	#include "interfaces/atmega128.h"
#elif defined(HW_ENDPOINT_DSP_TI6713_SD)
	#include "interfaces/dsp67xx.h"
#else
	#error "NO INTERFACE DEFINED - see interface.h"
#endif

#endif

