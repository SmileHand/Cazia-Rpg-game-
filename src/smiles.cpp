#include "smiles.h"




void smiles::accion_smile(float px,float py){
    /*if(px<x){
        if(acelera[0]<velocidad){
            acelera[0]+=empuje;
        }

    }
    else{
        if(acelera[0]>0){
            acelera[0]-=empuje;
        }
    }

    if (px>x){
        if(acelera[1]<velocidad){
            acelera[1]+=empuje;
        }

    }
    else{
        if(acelera[1]>0){
            acelera[1]-=empuje;
        }
    }
    if(py<y){
        if(acelera[2]<velocidad){
            acelera[2]+=empuje;
        }

    }
    else{
        if(acelera[2]>0){
            acelera[2]-=empuje;
        }
    }
    if (py>y){
            if(acelera[3]<velocidad){
            acelera[3]+=empuje;
        }

    }
    else{
        if(acelera[3]>0){
            acelera[3]-=empuje;
        }

    }
    x-=acelera[0];
    x+=acelera[1];
    y-=acelera[2];
    y+=acelera[3];
    smile_.setPosition(x,y);*/






    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)&&!press){
        press = true;
        if(movimiento_activo){
            movimiento_activo = false;
        }
        else{
            movimiento_activo = true;

        }
    }else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::M)) press = false;

    if(movimiento_activo){
        dx = px - x;
        dy = py - y;

        distancia = sqrt(dx * dx + dy * dy);

        if (distancia > 0) {
            dx /= distancia;
            dy /= distancia;
        }

        acelera[0] = acelera[0] * (1 - suavizado) + dx * velocidad * suavizado;
        acelera[1] = acelera[1] * (1 - suavizado) + dy * velocidad * suavizado;
        /*
        acelera[0] = dx * velocidad;
        acelera[1] = dy * velocidad;
        */


    }
    else{
        acelera[0] *= friccion;
        acelera[1] *= friccion;
    }
    x += acelera[0];
    y += acelera[1];
    smile_.setPosition(x, y);


}







smiles::smiles()
{
    smile.loadFromFile("recursos/texturas/smile/camina_frontal.png");
    smile_.setTexture(smile);
    smile_.setTextureRect(sf::IntRect(0,0,59,84));
    smile_.setPosition(x,y);
}

smiles::~smiles()
{
    //dtor
}
