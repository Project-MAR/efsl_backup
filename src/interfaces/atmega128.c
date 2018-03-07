/*****************************************************************************\
*              efs - General purpose Embedded Filesystem library              *
*          --------------------- -----------------------------------          *
*                                                                             *
* Filename : atmega128.c                                                      *
* Revision : Initial developement                                             *
* Description : This file contains the functions needed to use efs for        *
*               accessing files on an SD-card connected to an ATMega128.      *
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
\*****************************************************************************/

/*****************************************************************************/
#include "interfaces/atmega128.h"
#include "interfaces/sd.h"
/*****************************************************************************/

esint16 if_initInterface(hwInterface* file, eint8* opts)
{
	if_spiInit();
	if(sd_Init()<0)
	{
		DBG((TXT("Card failed to init, breaking up...\n")));
		return(-1);
	}
	if(sd_State()<0)
	{
		DBG((TXT("Card didn't return the ready state, breaking up...\n")));
		return(-2);
	}
	file->sectorCount=4; /*FIX!!*/
	DBG((TXT("Init done...\n")));
	return(1);
}
/*****************************************************************************/ 

esint8 if_readBuf(hwInterface* file,euint32 address,euint8* buf)
{
	return(sd_readSector(address,buf,512));
}
/*****************************************************************************/

esint8 if_writeBuf(hwInterface* file,euint32 address,euint8* buf)
{
	return(sd_writeSector(address, buf));
}
/*****************************************************************************/ 

euint16 if_setPos(hwInterface* file,euint32 address)
{
	return(0);
}
/*****************************************************************************/ 

void if_spiInit(void)
{
	euint8 i;
	
	/* Unselect card */
	PORTB |= 0x01;
	
	/* Set as master, clock and chip select output */
	DDR_SPI = (1<<DD_MOSI) | (1<<DD_SCK) | 1;

	/* Enable SPI, master, set clock rate to fck/2 */
	SPCR = (1<<SPE) | (1<<MSTR); /* fsck / 4 */
	SPSR = 1; /* fsck / 2 */

	/* Send 10 spi commands with card not selected */
	for(i=0;i<10;i++)
		if_spiSend(0xff);

	/* Select card */
	PORTB &= 0xFE;
}
/*****************************************************************************/

euint8 if_spiSend(euint8 outgoing)
{
	euint8 incoming=0;
	
	PORTB &= 0xFE;
	SPDR = outgoing;
	while(!(SPSR & (1<<SPIF)))
		incoming = SPDR;
	PORTB |= 0x01;

	return(incoming);
}
/*****************************************************************************/

