/*****************************************************************************\
*              efs - General purpose Embedded Filesystem library              *
*          ---------------------------------------------------------          *
*                                                                             *
* Filename :  linuxfile.h                                                     *
* Revision :  Initial developement                                            *
* Description : Headerfile for linuxfile.c                                    *
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
*                                                    (c)2004 Lennart Yseboodt *
*                                                    (c)2005 Michael De Nil   *
\*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "helper.h"
#include "../debug.h"
#include "../types.h"
#include "config.h"

#ifndef __LINUXFILE_H_
#define __LINUXFILE_H_

#define _LARGEFILE_SOURCE 
#define _GNU_SOURCE 
#define _FILE_OFFSET_BITS 64

/*************************************************************\
              hwInterface
               ----------
* FILE* 	imagefile		File emulation of hw interface.
* long		sectorCount		Number of sectors on the file.
\*************************************************************/
struct hwInterface{
	FILE 	*imageFile; 
	eint32  	sectorCount;
};
typedef struct hwInterface hwInterface;

eint16 if_initInterface(hwInterface* file,eint8* fileName);
esint8 if_readBuf(hwInterface* file,euint32 address,euint8* buf);
esint8 if_writeBuf(hwInterface* file,euint32 address,euint8* buf);
eint16 if_setPos(hwInterface* file,euint32 address);

#endif
