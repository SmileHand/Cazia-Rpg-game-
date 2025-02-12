#include "colisiones.h"

void colisiones::colision(int x1, int y1,int w1, int h1,int x2, int y2,int w2, int h2, bool& colii){
    if (x1 > x2+w2 || x1+w1 < x2|| y1 > y2+h2 ||y1+h1 < y2 ){}
    else{
        colii = true;
    }
}


colisiones::colisiones()
{
    //ctor
}

colisiones::~colisiones()
{
    //dtor
}
