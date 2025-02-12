#include "mpapas.h"

mpapas::mpapas()
{
    piedra.loadFromFile("recursos/texturas/pisos.png");
    piedra_.setTexture(piedra);
    /*for (int i=0; i<w;i ++){
        for(int f=0; f<h; f++){
            mapaaa[i][f]= cual;
        }
    }*/
    tamano = piedra.getSize();
    cuantas = tamano.x/50;
}

mpapas::~mpapas()
{
    //dtor
}


void mpapas::cambio(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        if (!press[0]){
            press[0] =true;
            if (cual<cuantas-1){
            cual++;
            ss();
            }
            //if(cual==cuantas-1)cual = 0;

        }

    }
    else{
        press[0]=false;
    }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        if (!press[1]){
            press[1]=true;
            if (cual>0){
            cual--;
            ss();
            }
        }
        //if (cual==0) cual= cuantas-1;

    }else press[1]=false;
}

void mpapas::ss(){
    /*piedra_.setTexture(piedra);
    for (int i=0; i<w;i ++){
        for(int f=0; f<h; f++){
            mapaaa[i][f]= cual;
        }
    }*/




}
