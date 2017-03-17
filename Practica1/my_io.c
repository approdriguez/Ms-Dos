#include <dos.h>
#include "mi_io.h"

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


void gotoXY(const BYTE x, const BYTE y){
  union REGS inregs, outregs;
  inregs.h.ah = 0x02;
  inregs.h.dh = y;
  inregs.h.dl = x;
  inregs.h.bh = 0x00;
  int86(0x10,&inregs,&outregs);
  return;
}

void setvideomode(BYTE mode){
  union REGS inregs, outregs;
  inregs.h.ah = 0x00;
  inregs.h.al = mode;
  int86(0x10,&inregs,&outregs);
  return;
}

BYTE getvideomode(BYTE void){
  union REGS inregs,outregs;
  inregs.h.ah = 0x0F;
  int86(0x10,&inregs,&outregs);
  return outregs.h.al;
}
