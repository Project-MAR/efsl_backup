/*****************************************************************************\
*              efs - General purpose Embedded Filesystem library              *
*          --------------------- -----------------------------------          *
*                                                                             *
* Filename : dsp67xx.c                                                        *
* Revision : Initial developement                                             *
* Description : This file contains the functions needed to use efs for        *
*               accessing files on an SD-card connected to a TI 67            *
*               series DSP.                                                   *
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

/*****************************************************************************/
#include "interfaces/dsp67xx.h"
#include "interfaces/sd.h"
/*****************************************************************************/

short if_initInterface(hwInterface* file, char* opts)
{
	volatile unsigned char *bspmux    = (volatile unsigned char *)0x90080006;
	(*bspmux)|=0x01;
    *(unsigned volatile int *)McBSP0_SPCR = 0;
    *(unsigned volatile int *)McBSP0_XCR  = 0x00010000;           	
    *(unsigned volatile int *)McBSP0_RCR  = 0x00010000;        
    *(unsigned volatile int *)McBSP0_SRGR = 0x2000006B;              
    *(unsigned volatile int *)McBSP0_PCR  = 0x00000A0C;              
    *(unsigned volatile int *)McBSP0_SPCR =  0x00001800;	
    *(unsigned volatile int *)McBSP0_SPCR |= 0x00410001;
    
    return(if_spiInit());
}
/*****************************************************************************/ 

short if_writeBuf(hwInterface* file,unsigned long address,unsigned char* buf)
{
	return(0);
}
/*****************************************************************************/ 

short if_setPos(hwInterface* file,unsigned long address)
{
	return(0);
}
/*****************************************************************************/ 

signed char if_spiInit()
{
	return(sd_Init());
}
/*****************************************************************************/

unsigned char if_spiSend(unsigned char outgoing)
{
	unsigned char r;

	while((*(unsigned volatile long*)McBSP0_SPCR & 0x20000)==0);
	*(unsigned volatile char*)McBSP0_DXR=outgoing;
	while(((*(unsigned volatile long*)McBSP0_SPCR & 0x2)==0));
	r=*(unsigned volatile char*)McBSP0_DRR;
	return(r);
}
/*****************************************************************************/

short if_readBuf(hwInterface* file,unsigned long address,unsigned char* buf)
{
	short r;
	r=sd_readSector(address,buf,512);
	if(r!=0)printf("ERROR READING SECTOR %i\n",address);
	return(r);
}
/*****************************************************************************/

