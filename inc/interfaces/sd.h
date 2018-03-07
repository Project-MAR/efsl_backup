/*****************************************************************************\
*              efs - General purpose Embedded Filesystem library              *
*          ---------------------------------------------------------          *
*                                                                             *
* Filename :  sd.h                                                            *
* Revision :  Initial developement                                            *
* Description : Headerfile for sd.c                                           *
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

#ifndef __SD_H_ 
#define __SD_H_ 

#include "config.h"
#include "types.h"
#include "../debug.h"

#define	CMDREAD		17
#define	CMDWRITE	24

esint8  sd_Init(void);
void sd_Command(euint8 cmd, euint16 paramx, euint16 paramy);
euint8 sd_Resp8b(void);
void sd_Resp8bError(euint8 value);
euint16 sd_Resp16b(void);
esint8 sd_State(void);

esint8 sd_readSector(euint32 address,euint8* buf, euint16 len);
esint8 sd_writeSector(euint32 address, euint8* buf);

#endif
