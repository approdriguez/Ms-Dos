#define BYTE unsigned char

/*
@description: indica la posicion x del cursor actual
@param: void
@return: Constante BYTE donde esta la posicion x
*/
BYTE whereX(void);

/*
@description: indica la posicion y del cursor actual
@param: void
@return: Constante BYTE donde esta la posicion y
*/
BYTE whereY(void);

/*
@description: mueve el cursor segun las coordenadas especificas por los
argumentos x e y
@param: BYTE x,y coordenadas
@return: void
*/
void gotoXY(const BYTE x, const BYTE y);

/*
@description: fija el modo de video deseado
@param: mode en el que se indica que modo queremos
@return: void
*/
void setvideomode(BYTE mode);

/*
@description: definimos el color de texto
@param: BYTE color a cambiar
@return: void
*/
void settextcolor(BYTE color);

/*
@description: definimos el color de fondo
@param: BYTE color a cambiar
@return: void
*/
void settextbackground(BYTE color);

/*
@description: Borra la pantalla,y la pinta del paramentro color
@param: BYTE color a pintar la pantalla
@return: void
*/
void clrscr(const BYTE color);

/*
@description: Imprime una cadena de caracteres por pantalla
@param: BYTE color para pintar cadena
@return: void
*/
void cputs(const char *c, const BYTE color);


int khbit();
/*
@description: indica si se ha pulsado alguna tecla
@args:
@return: devuelve 0 si no se ha registrado una tecla pulsada
          si hay una disponible el valor retornado es distinto de 0.
*/

void setcursortype(int type);
/*
@description: Ajusta el tipo del cursor a 3 valores:
              INVISIBLE, NORMAL y GRUESO.
@args: Un int que indicara si el cursor va a ser INVISIBLE
        NORMAL o GRUESO.
        1 - NORMAL
        2 - GRUESO
        3 - INVISIBLE
@return:
*/

void clreol();
/*
@description: borra una linea desde la posicion actal del cursor hasta el final de la misma
@ args:
@return:
*/

void scrollup();
/*
@description:desplazar toda la pantalla una línea hacia arriba
@ args: BYTE COLOR
@return:
*/

void scrolldown();
/*
@description:desplazar toda la pantalla una línea hacia abajo
@ args: BYTE COLOR
@return:
*/

void cputchar(char p);
/*
@description: escribe un carácter en pantalla con el color indicado actualmente
@args: BYTE char
@return:
*/

void getche();
/*
@description:  obtiene un carácter de teclado y lo muestra en pantalla
Para ello leemos desde el teclado y realiza una llamada a cputchar con los caracteres introducidos en el teclado
@args:
@return:
*/
