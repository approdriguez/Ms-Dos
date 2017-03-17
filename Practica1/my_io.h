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
@param: x,y coordenadas
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
@description: obtiene el modo de video actual
@param: mode en el que se indica que modo queremos
@return: void
*/
BYTE getvideomode(BYTE mode);
