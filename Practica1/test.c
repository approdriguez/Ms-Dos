#include <dos.h>
#define BYTE unsigned char
/* Selecciona el modo de video deseado */


int main(){
int mode;
scanf("%d",&mode);
selecciona_modo_video(mode);
scanf("%d",&mode);
if(mode==3)	selecciona_modo_video(mode);
return 0;
}
