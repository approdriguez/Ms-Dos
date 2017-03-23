#include <dos.h>
#include "mi_io.h"

BYTE TEXT_COLOR;
BYTE TEXT_BACKGROUND;

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

void settextcolor(BYTE color){
  TEXT_COLOR = color;
}

void settextbackground(BYTE color){
  TEXT_BACKGROUND = color;
}

void clrscr(const BYTE color){
    union REGS inregs, outregs;
    inregs.h.ah = 0x06;
    inregs.h.al = 0;
    inregs.h.bh = color;
    inregs.h.ch = 0;
    inregs.h.cl = 0;
    inregs.h.dh = 480;
    inregs.h.dl = 640;
    int86(0x10,&inregs,&outregs);
    gotoXY(0,0);
    return;
}

void cputs(const char * c, const BYTE color){
  int i = 0;
  while (c[i] != '\0'){
      cputchar(c[i],color,1);
      gotoXY(whereX()+1,whereY());
      i++;
  }
  return;
}
