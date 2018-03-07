/*****************************************************************************\
*              efs - General purpose Embedded Filesystem library              *
*          --------------------- -----------------------------------          *
*                                                                             *
* Filename :  atmega128.h                                                     *
* Revision :  Initial developement                                            *
* Description : Headerfile for atmega128.c                                    *
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
*                                                    (c)2005 Michael De Nil   *
\*****************************************************************************/

#ifndef __ATMEGA128_SD_H_ 
#define __ATMEGA128_SD_H_ 

#define __AVR_ATmega128__ 1
#define FALSE	0X00
#define TRUE	0x01

#define DDR_SPI DDRB
#define DD_MOSI DDB2
#define DD_SCK  DDB1

#include <avr/io.h>
#include <compat/ina90.h>
#include "../debug.h"
#include "config.h"


/*************************************************************\
              hwInterface
               ----------
* FILE* 	imagefile		File emulation of hw interface.
* long		sectorCount		Number of sectors on the file.
\*************************************************************/
struct  hwInterface{
	/*FILE 	*imageFile;*/
	eint32  	sectorCount;
};
typedef struct hwInterface hwInterface;

esint16 if_initInterface(hwInterface* file,eint8* opts);
esint8 if_readBuf(hwInterface* file,euint32 address,euint8* buf);
esint8 if_writeBuf(hwInterface* file,euint32 address,euint8* buf);
euint16 if_setPos(hwInterface* file,euint32 address);

void if_spiInit(void);
euint8 if_spiSend(euint8 outgoing);

#endif
