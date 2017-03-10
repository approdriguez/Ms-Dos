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

















void selecciona_modo_video(BYTE modo)
{
union REGS inregs, outregs;
inregs.h.ah = 0x00;
inregs.h.al = modo;
int86(0x10,&inregs,&outregs);
return;
}

main(){
int mode;
scanf("%d",&mode);
selecciona_modo_video(mode);
scanf("%d",&mode);
if(mode==3)	selecciona_modo_video(mode);
return 0;
}
