#include <dos.h>

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
