/*****************************************************************************\
*              efs - General purpose Embedded Filesystem library              *
*          ---------------------------------------------------------          *
*                                                                             *
* Filename :  types.h                                                         *
* Revision :  Initial developement                                            *
* Description : This file contains the crossplatform data types               *
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
*                                                    (c)2005 Michael De Nil   *
*                                                    (c)2005 Lennart Yseboodt *
\*****************************************************************************/

#ifndef __EFS_TYPES_H__
#define __EFS_TYPES_H__

#include "config.h"

#if defined(HW_ENDPOINT_LINUX)
	typedef char eint8;
	typedef signed char esint8;
	typedef unsigned char euint8;
	typedef short eint16;
	typedef signed short esint16;
	typedef unsigned short euint16; 
	typedef long eint32; 
	typedef signed long esint32;
	typedef unsigned long euint32; 
#elif defined (HW_ENDPOINT_ATMEGA128_SD)
	typedef char eint8;
	typedef signed char esint8;
	typedef unsigned char euint8;
	typedef short eint16;
	typedef signed short esint16;
	typedef unsigned short euint16; 
	typedef long eint32; 
	typedef signed long esint32;
	typedef unsigned long euint32; 
#elif defined(HW_ENDPOINT_DSP_TI6713_SD)
	typedef char eint8;
	typedef signed char esint8;
	typedef unsigned char euint8;
	typedef short eint16;
	typedef signed short esint16;
	typedef unsigned short euint16; 
	typedef int eint32; 
	typedef signed int esint32;
	typedef unsigned int euint32; 
#else
	typedef char eint8;
	typedef signed char esint8;
	typedef unsigned char euint8;
	typedef short eint16;
	typedef signed short esint16;
	typedef unsigned short euint16; 
	typedef long eint32; 
	typedef signed long esint32;
	typedef unsigned long euint32; 
#endif

#endif
