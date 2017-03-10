#include <dos.h>
#include "mi_io.h"

#define BYTE unsigned char
int khbit()
/*
@description: indica si se ha pulsado alguna tecla
@args:
@return: devuelve 0 si no se ha registrado una tecla pulsada
          si hay una disponible el valor retornado es distinto de 0.
*/
{
union REGS inregs, outregs;
inregs.h.ah = 0x01;
int86(0x16,&inregs,&outregs);
return (outregs.x.cflag)&0x01;
}

BYTE whereX(void){
  union REGS inregs, outregs;
  inregs.h.ah = 0x03;
  inregs.h.bh = 0x00;
  int86(0x10,&inregs,&outregs);
  return outregs.h.dl;

}

BYTE whereY(void){
  union REGS inregs, outregs;
  inregs.h.ah = 0x03;
  inregs.h.bh = 0x00;
  int86(0x10,&inregs,&outregs);
  return outregs.h.dh;
}

