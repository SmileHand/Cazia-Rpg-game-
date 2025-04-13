#include "camara.h"

void camara::seguimiento_de_camara(int x,int y,float acelera1,float acelera2,float acelera3,float acelera4){
    acelera1 = std::abs(acelera1);
    acelera2 = std::abs(acelera2);
    if (!camara_moviendose){
        /*if (x>cuadro_x+tolerancia_x/2){
        cuadro_w += .5f;
        cuadro_x += .5f;
        view1.move(.5f,0);
        //std::cout<<"derecha";
        }
        if (x<cuadro_x+tolerancia_x/2){
            cuadro_w -= .5f;
            cuadro_x -= .5f;
            view1.move(-.5f,0);
            //std::cout<<"izquierda";
        }
        if (y>cuadro_y+tolerancia_y/2){
            cuadro_h += .5f;
            cuadro_y += .5f;
            view1.move(0,.5f);
            //std::cout<<"derecha";
        }
        if (y<cuadro_y+tolerancia_y/2){
            cuadro_h -= .5f;
            cuadro_y -= .5f;
            view1.move(0,-.5f);
            //std::cout<<"derecha";
        }*/
        dx = x - (cuadro_x+tolerancia_x/2);
        dy = y - (cuadro_y+tolerancia_y/2);

        distancia = sqrt(dx*dx+dy*dy);

        if (distancia > 1) {
            dx /= distancia;
            dy /= distancia;
        }
        acelera[0] = dx * vzz;
        acelera[1] = dy * vzz;

        view1.move(acelera[0],acelera[1]);
        cuadro_x += acelera[0];
        cuadro_w += acelera[0];
        cuadro_y += acelera[1];
        cuadro_h += acelera[1];

    }


    if (x>cuadro_w){
        cuadro_w += acelera1;
        cuadro_x += acelera1;

        view1.move(acelera1,0);
        //std::cout<<"derecha";
        camara_moviendose = true;
    }
    if (x<cuadro_x){
        cuadro_w -= acelera1;
        cuadro_x -= acelera1;
        view1.move(-acelera1,0);
        //std::cout<<"izquierda";
        camara_moviendose = true;
    }
    if (y>cuadro_h){
        cuadro_h += acelera2;
        cuadro_y += acelera2;
        view1.move(0,acelera2);
        //std::cout<<"arriba";
        camara_moviendose = true;
    }
    if (y<cuadro_y){
        cuadro_h -= acelera2;
        cuadro_y -= acelera2;
        view1.move(0,-acelera2);
        //std::cout<<"abajo";
        camara_moviendose = true;
    }


    if (x>cuadro_w||x<cuadro_x||y>cuadro_h||y<cuadro_y){
        choque = true;
    }




}


camara::camara():view1(sf::FloatRect(0.f, 0.f, 1280.f, 720.f))

{
    //ctor

}

camara::~camara()
{
    //dtor
}
