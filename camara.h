#ifndef CAMARA_H
#define CAMARA_H
#include <SFML/Graphics.hpp>
#include "personaje.h"
#include <iostream>
#include <cmath>

class camara
{
    public:
        personaje jugador;

        sf::View view1;
        float tolerancia_x = 600;
        float tolerancia_y = 300;
        float posicion_x = 640;
        float posicion_y = 360;
        float dx,dy,distancia, acelera[2],vzz=1;
        bool camara_moviendose = true;
        bool choque = true;
        float cuadro_x = posicion_x-tolerancia_x/2;
        float cuadro_w = posicion_x+tolerancia_x/2;
        float cuadro_y = posicion_y-tolerancia_y/2;
        float cuadro_h = posicion_y+tolerancia_y/2;
        void seguimiento_de_camara(int x,int y,float acelera1,float acelera2,float acelera3,float acelera4);

        camara();
        virtual ~camara();

    protected:

    private:
};

#endif // CAMARA_H
