#ifndef COLISIONMAPA_H
#define COLISIONMAPA_H
#include <iostream>
#include <cmath>

class colisionmapa
{
    public:
        float x,y,w,h;
        float xl,yl,wl,hl;
        float coliderx=15,colidery=60;
        bool co;
        void colision_pared(float& jx, float& jy, float jw, float jh,float aceleracion0,float aceleracion1);
        colisionmapa();
        virtual ~colisionmapa();

    protected:

    private:
};

#endif // COLISIONMAPA_H
