#include <dos.h>
#define BYTE unsigned char
/* Selecciona el modo de video deseado */
void selecciona_modo_video(BYTE modo)
{
union REGS inregs, outregs;
inregs.h.ah = 0x00;
inregs.h.al = modo;
int86(0x10,&inregs,&outregs);
return;
}

char

int main(){
int mode;
scanf("%d",&mode);
selecciona_modo_video(mode);
scanf("%d",&mode);
if(mode==3)	selecciona_modo_video(mode);
return 0;
}
