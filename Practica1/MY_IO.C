#include <dos.h>
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
return outregs.x.cflag;
}

void setcursortype(int type){
  union REGS inregs, outregs;
  inregs.h.ah = 0x01;
  //inregs.h.ch =
  //inregs.x.cx =
  // ch y cl
  switch (type) {
    case 0: inregs.x.cx = 0x0607; break; //Cursor NORMAL

    case 1: inregs.x.cx = 0x0007; break; //Cursor Relleno

    case 2: inregs.x.cx = 0x2607; break; //INVISIBLE
  }
  int86(0x10,&inregs,&outregs);
}

#define BYTE unsigned char

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

void clreol(){
  union REGS inregs, outregs;
  inregs.h.ah = 0x06;
    inregs.h.al = 0x00;
    inregs.h.bh = 15; //color
    inregs.h.ch = whereY();
    inregs.h.cl = whereX();
    inregs.h.dh = whereY();
    inregs.h.dl = 79;
    int86(0x10,&inregs,&outregs);
}

/*

81 Caracter por linea

*/

void scrollup(){
  union REGS inregs, outregs;
  inregs.h.ah = 0x06;
  inregs.h.al = 0x01;
  inregs.h.bh = 15; //15 = WHITE
  inregs.h.ch = 0;    // Linea esquina superior izquierda
  inregs.h.cl = 0;    // Columna de la esquina superior izquierda
  inregs.h.dh = 480;       // Linea de la esquina superior inferior derecha
  inregs.h.dl = 640;  //Columna de la esquina inferior derecha
  int86(0x10,&inregs,&outregs);
  //gotoxy(whereX,whereY-1); //Nos desplazamos una fila hacia arriba
}

void scrolldown(){
  union REGS inregs, outregs;
  inregs.h.ah = 0x07;
  inregs.h.al = 0x01;
  inregs.h.bh = 15; //15 = WHITE
  inregs.h.ch = 0;    // Linea esquina superior izquierda
  inregs.h.cl = 0;    // Columna de la esquina superior izquierda
  inregs.h.dh = 480;       // Linea de la esquina superior inferior derecha
  inregs.h.dl = 640;  //Columna de la esquina inferior derecha
  int86(0x10,&inregs,&outregs);
  //gotoxy(whereX,whereY+1); //Nos desplazamos una fila hacia abajo
}

void cputchar(char p){
  union REGS inregs, outregs;
  inregs.h.ah = 0x09;
  inregs.h.al = p;
  inregs.h.bh = 0;
  inregs.h.bl = 15; // WHITE
  inregs.x.cx = 1;
  int86(0x10,&inregs,&outregs);
  //gotoxy(whereX+1,whereY); //Nos desplazamos a la derecha de lo escrito
}



void getche(){
  /*Obtiene un carácter del teclado y lo muestra
    en pantalla.
  */
  union REGS inregs, outregs;
  inregs.h.ah = 0x00;
  int86(0x16,&inregs,&outregs);
  if(outregs.h.al != 0){
    cputchar(outregs.h.al);
    //gotoxy(whereX+1,whereY); //Nos desplazamos a la derecha de lo escrito
  }

}


int main(){
  char * p;
  int i=0;int count = 0;
  while(i<45){
		printf("%d\n",i);i++;
    if(i<10){
      count++;}
      else{
        count = count+2;
      }

	}
  /*scrolldown();
  printf("\nPepe estuvo aqui\n" );
  scanf("%s\n",p );
	/*scrollup();
	scrollup();
  scrollup();*/
  getche();
	/*printf("La cuenta es %d\n",count );/*
  printf("Pepe estuvo aqui pero ya se fue\n" );
  scanf("%s\n",p );
  char a = 'a';
	printf("Pepe estuvo aqui\n" );
  cputchar(a);*/


}
