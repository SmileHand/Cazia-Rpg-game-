#include "colisionmapa.h"


void colisionmapa::colision_pared(float& jx, float& jy, float jw, float jh,float aceleracion0,float aceleracion1){
    xl=jx+coliderx;
    yl=jy+colidery;
    wl=jw-coliderx*2;
    hl=jh-colidery;
    aceleracion0 = std::abs(aceleracion0);
    aceleracion1 = std::abs(aceleracion1);
    co = false;
    if (x<=xl+wl&&x+w>=xl&&y<=yl+hl&&y+h>=yl){
        co = true;
        if(xl<x){
            jx -= aceleracion0;
        }
        if (xl+wl>x+w){
            jx += aceleracion0;
        }
        if (yl<y){
            jy -= aceleracion1;
        }
        if (yl+hl>y+h){
            jy += aceleracion1;
        }
    }

    std::cout<<"jugador: "<<jx<<" colider: "<<xl<<std::endl;



//    if (co){
//        std::cout<<"si funciona la mierda esta"<<std::endl;
//    } else{
//        std::cout<<"No hay colision"<<std::endl;
//    }



}



colisionmapa::colisionmapa()
{
    //ctor
}

colisionmapa::~colisionmapa()
{
    //dtor
}
