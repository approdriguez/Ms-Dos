#include "my_io.cpp"
#define BYTE unsigned char;


main(){
  int mode;
  scanf("%d",&mode);
  selecciona_modo_video(mode);
  scanf("%d",&mode);
  if(mode==3)	selecciona_modo_video(mode);
  return 0;
}
