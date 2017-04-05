/*
Autores: 		Ahisahar Pretel Rodriguez
	 		David Fernando Guerrero Cardona

Ultima modificación: 	24-03-2017

Licencia:		GNU




*/

#include "my_io.h"




/***************************************
*
* int86(Numero de interrupcion,
*              copia inregs en los registros internos,
*              copia registros internos en outregs)
*
* interrupcion: 16 teclado
*               10 video
*
* Numero de funcion: .ah
****************************************/

BYTE read(){
    BYTE resultado;
    union REGS inregs, outregs;

    inregs.h.ah = 0x00;	//Funcion 0: Leer valor de tecla
    int86(0x16,&inregs,&outregs); //Interrupcion de teclado
    resultado = outregs.h.al; //scan-code de la tecla pulsada
    if(resultado == 0)
        resultado = outregs.h.ah; //caracter ascii pulsado
    return resultado;
}

BYTE whereX(void){
  union REGS inregs, outregs;
  inregs.h.ah = 0x03;
  inregs.h.bh = 0x00;
  int86(0x10,&inregs,&outregs);
    //salida dl: posicion/columna(00 es la izq del todo)
  return outregs.h.dl;
}

BYTE whereY(void){
  union REGS inregs, outregs;
  inregs.h.ah = 0x03;
  inregs.h.bh = 0x00;
  int86(0x10,&inregs,&outregs);
  //salida dl: posicion/columna(00 es arriba del todo)
  return outregs.h.dh;
}

void gotoXY(const BYTE x, const BYTE y){
  union REGS inregs, outregs;
  inregs.h.ah = 0x02;
  inregs.h.dh = y;
  inregs.h.dl = x;
  inregs.h.bh = 0x00;
  int86(0x10,&inregs,&outregs);
  //No tiene salida modificamos valores donde debe ir el cursor
  return;
}

void setvideomode(BYTE mode){
  union REGS inregs, outregs;
  inregs.h.ah = 0x00;
  //Cambiamos el modo de video espeficicado en mode
  inregs.h.al = mode;
  int86(0x10,&inregs,&outregs);
  return;
}

BYTE getvideomode(){
  union REGS inregs,outregs;
  inregs.h.ah = 0x0F;
  int86(0x10,&inregs,&outregs);
  // devuelve .al que es el modo actual
  return outregs.h.al;
}


void settextcolor(BYTE color){
  TEXT_COLOR = color;
  //Ponemos la variable global TEXT_COLOR = color
}

void settextbackground(BYTE color){
  TEXT_BACKGROUND = color;
  //Ajustamos la variable global TEXT_BACKGROUND = color
}

void clrscr(const BYTE color){
    union REGS inregs, outregs;
    inregs.h.ah = 0x06;
    inregs.h.al = 0; //El registro a 0 para borrar toda la pantalla    
    inregs.h.bh = color; // cambiamos el color de la pantalla
    inregs.h.ch = 0;
    inregs.h.cl = 0;
    inregs.h.dh = 480;
    inregs.h.dl = 640;
    int86(0x10,&inregs,&outregs);
    gotoXY(0,0);
    return;
    //Al borrar toda la pantalla no devolvemos nada
}

void cputs(const char * c){
  int i = 0;
  //Recorremos cadena, imprimimos.
  //Reposicionamos el cursor  
  while (c[i] != '\0'){
      cputchar(c[i]);
      gotoXY(whereX(),whereY());
      i++;
  }
  gotoXY(0,whereY()+1);//Nos desplazamos a la siguiente línea
  return;
}

BYTE khbit()
{
  union REGS inregs, outregs;
  inregs.h.ah = 0x01;
  int86(0x16,&inregs,&outregs); //Interrupcion de teclado
  return (outregs.x.cflag>>6)&0x01;// Devolvemos el bit número 6
  //Teniendo en cuenta que el primer bit es el 0
  }

void setcursortype(int type){
  union REGS inregs, outregs;
  inregs.h.ah = 0x01;
  switch (type) {
    case 0: inregs.x.cx = 0x0607; break; //Cursor NORMAL

    case 1: inregs.x.cx = 0x0007; break; //Cursor Relleno

    case 2: inregs.x.cx = 0x2607; break; //INVISIBLE
  }
  int86(0x10,&inregs,&outregs);
}


void clreol(){
  union REGS inregs, outregs;
  inregs.h.ah = 0x06;
  inregs.h.al = 0x00; //lineas a scroll
  inregs.h.bh = 15; //color
  inregs.h.ch = whereY(); //Borramos desde la posicion del cursor
  inregs.h.cl = whereX();
  inregs.h.dh = whereY(); //Hasta el final de la línea
  inregs.h.dl = 79;
  int86(0x10,&inregs,&outregs);
}


void scrollup(){
  union REGS inregs, outregs;
  inregs.h.ah = 0x06;
  inregs.h.al = 0x01; //Numero de lineas
  inregs.h.bh = 15;   //15 = WHITE
  inregs.h.ch = 0;    // Linea esquina superior izquierda
  inregs.h.cl = 0;    // Columna de la esquina superior izquierda
  inregs.h.dh = 20;       // Linea de la esquina superior inferior derecha
  inregs.h.dl = 70;  //Columna de la esquina inferior derecha
  int86(0x10,&inregs,&outregs);
  gotoXY(whereX(),whereY()-1); //Nos desplazamos una fila hacia arriba
}

void scrolldown(){
  union REGS inregs, outregs;
  inregs.h.ah = 0x07;
  inregs.h.al = 0x01; //Numero de lineas
  inregs.h.bh = 15; //15 = WHITE
  inregs.h.ch = 0;    // Linea esquina superior izquierda
  inregs.h.cl = 0;    // Columna de la esquina superior izquierda
  inregs.h.dh = 20;       // Linea de la esquina superior inferior derecha
  inregs.h.dl = 70;  //Columna de la esquina inferior derecha
  int86(0x10,&inregs,&outregs);
  gotoXY(whereX(),whereY()+1); //Nos desplazamos una fila hacia abajo
}

void cputchar(char p){
  union REGS inregs, outregs;
  inregs.h.ah = 0x09;
  inregs.h.al = p; //Caracter a escribir
  inregs.h.bh = 0; //Numero de pagina
  inregs.h.bl = TEXT_COLOR; // 15=WHITE
  inregs.x.cx = 1; //Numero de veces a escribir
  int86(0x10,&inregs,&outregs);
  gotoXY(whereX()+1,whereY()); //Nos desplazamos a la derecha de lo escrito
}



void getche(){
  /*Obtiene un carácter del teclado y lo muestra
    en pantalla.
  */
  union REGS inregs, outregs;
  inregs.h.ah = 0x00;
  int86(0x16,&inregs,&outregs);
  if(outregs.h.al != 0){ //Si el valor del caracter es distinto de 0 lo pintamos
    cputchar(outregs.h.al);
    gotoXY(whereX()+1,whereY()); //Nos desplazamos a la derecha de lo escrito
  }

}


