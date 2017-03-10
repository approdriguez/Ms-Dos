#include <dos.h>
#define BYTE unsigned char
int kbith()
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
printf(" el cflag es %d\n",outregs.x.cflag);
return (outregs.x.cflag)&0x01;
}

int main(){
while(!kbith()){printf("Esperando\n");}
printf("Perdio su vida en el loooooool\n");
exit(0);
}
