/*
Autores: 		Ahisahar Pretel Rodriguez
	 		David Fernando Guerrero Cardona

Ultima modificación: 	24-03-2017

Licencia:		GNU

*/


//#include "my_io.h"
#include "my_io.c"


const static BYTE COLOR_DEFECTO = 0x0F;
const static BYTE COLOR_CAMBIADO = 0x05;
BYTE aux;
void nuevaLinea(){
  gotoXY(0,whereY()+1);
}

void siguiente(){
  cputs("Presiona una tecla pra continuar");
	nuevaLinea();
  read();
}

int main(){
  clrscr(COLOR_DEFECTO);
  gotoXY(0,0);
  cputs("Primera funcion kbhit(). Presiona una tecla");
  aux = kbhit();
  siguiente();
  printf("Codigo de la tecla pulsada %i\n",aux);
  cputs("Prueba de gotoXY, nos pasamos a la coordenada 10,10");
  gotoXY(10,10);
  printf("Prueba de whereX y whereY, estamos en la coordenada (%i,%i)\n",whereX(),whereY());
  siguiente();
  cputs("Probamos cursortype, en modo grueso");
  setcursortype(1);
  nuevaLinea();
  siguiente();
  cputs("Prueba de clrscr()");
  nuevaLinea();
  nuevaLinea();
  siguiente();
  clrscr(COLOR_DEFECTO);
  cputs("Prueba de clreol(). Borramos Primera Linea");
  nuevaLinea();
  cputs("A Excepcion de las 3 primeras letras!");
  nuevaLinea();
  siguiente();
  gotoXY(3,0); /*Hasta aqui*/
  clreol();
  gotoXY(0,4);
  siguiente();
  cputs("Prueba de scrollup(). Subimos una linea..");
  nuevaLinea();
  siguiente();
  scrollup();
  siguiente();
  cputs("Prueba de scrolldown(). Bajamos una linea");
  nuevaLinea();
  siguiente();
  scrolldown();
  siguiente();
  settextcolor(COLOR_CAMBIADO);
  clrscr(COLOR_CAMBIADO);
  cputs("Prueba de getche(). Introduce un caracter ");
  nuevaLinea();
  cputs("ahora se muestra en la esquina inferior derecha de la pantalla");
  gotoXY(79,24);
  getche();
  gotoXY(0,20);
  cputs("Wubba Lubba Dub Dub");
  nuevaLinea();
  //siguiente();
  clrscr(COLOR_DEFECTO);
  return(0);
}
