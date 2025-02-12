#include "armas.h"
#include <cstdlib>

void armas::inicio(){
    this ->itemm.loadFromFile("recursos/texturas/armas/lansallamas/item.png");
    this ->itemm_.setTexture(itemm);
    this ->lansallamas.loadFromFile("recursos/texturas/armas/lansallamas/lansallamas_lado.png");
    this ->lansallamas_.setTexture(lansallamas);
    this ->fuego.loadFromFile("recursos/texturas/armas/lansallamas/fuego.png");
    this ->fuego_.setTexture(fuego);
    this -> fuego_.setTextureRect(sf::IntRect(0,0,0,0));
    lansallamas_.setTextureRect(sf::IntRect(0,0,0,0));

    for (int i=0; i <maxx; i++){
        shoot[i].disparo.loadFromFile("recursos/texturas/armas/lansallamas/fuego_lansa2r.png");
        shoot[i].disparo_.setTexture(shoot[i].disparo);
        shoot[i].disparo_.setTextureRect(sf::IntRect(0,0,0,0));
        //shoot[i].disparo_.setColor(sf::Color(255, 255, 255, 128));
    }


    recurso.h =0;

    itemm_.setTextureRect(sf::IntRect(w,0,w,w));
    itemm_.setPosition(x,y);
}

void armas::item_suelto(){
    if (item){
        itemm_.setTextureRect(sf::IntRect(0,0,0,0));
        itemm_.setPosition(0,0);

    }
}

void armas::imprimir_arma(bool pos1,bool pos2,bool pos3,bool pos4,float x,float y){
    if (item){
            if (pos4){
                lansallamas.loadFromFile("recursos/texturas/armas/lansallamas/lansallamas_lado.png");
                lansallamas_.setTexture(lansallamas);
                lansallamas_.setTextureRect(sf::IntRect(0,0,78,30));

                LansallamasPosX = 0;
                LansallamasPosY = 50;
                fx=50;
                fy=40;
                dx =1;
                dy=0;
                dpx=10;
                dpy=25;
                abajo = false;
                izquierda = false;
                arriba = false;
            }
            if (pos2){
                lansallamas.loadFromFile("recursos/texturas/armas/lansallamas/lansallamas_lado.png");
                lansallamas_.setTexture(lansallamas);
                lansallamas_.setTextureRect(sf::IntRect(78,0,-78,30));

                LansallamasPosX = -15;
                LansallamasPosY = 50;
                fx=-35;
                fy=40;
                dx= -1;
                dy=0;
                dpx=35;
                dpy=28;
                abajo = false;
                izquierda = true;
                arriba = false;
            }
            if (pos1){
                lansallamas.loadFromFile("recursos/texturas/armas/lansallamas/lansallamas_trasera.png");
                lansallamas_.setTexture(lansallamas);
                lansallamas_.setTextureRect(sf::IntRect(0,0,34,36));

                LansallamasPosX = 15;
                LansallamasPosY = 50;
                fx=20;
                fy=0;
                dx=0;
                dy= -1;
                dpx=20;
                dpy=20;
                abajo = false;
                izquierda = false;
                arriba = true;
            }
            if (pos3){
                lansallamas.loadFromFile("recursos/texturas/armas/lansallamas/lansallamas_frontal.png");
                lansallamas_.setTexture(lansallamas);
                lansallamas_.setTextureRect(sf::IntRect(0,0,20,29));

                LansallamasPosX = 5;
                LansallamasPosY = 50;
                fx=-9;
                fy=40;
                dx=0;
                dy=1;
                dpx=25;
                dpy=20;
                abajo = true;
                izquierda = false;
                arriba = false;
            }
             for (int s=0;s<maxx;s++){
                if (shoot[s].ddd) shoot[s].disparar(x+fx+dpx,y+fy+dpy,dx,dy,izquierda,abajo,arriba,s);
                else shoot[s].disparo_.setPosition(fx+x+dpx,fy+y+dpy);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                if (e >= 30/maxx){
                    e=0;
                    /*if (o > maxx){
                        o=0;
                    }
                    else{*/

                        o = rand() % maxx;
                    //}
                }
                else{
                    e++;
                }
                shoot[o].ddd = true;
                //std::cout<<"fuego: "<< o <<std::endl;
            }else o =0;


            animacion_fuego(4);

            //fuego_lansado(1,0);
            /*else{

                protectil_.setTextureRect(sf::IntRect(0,0,0,0));
                e = 0;
                fotograma2 = 0;
                protectil_.setPosition(x,y);

            }*/

            lansallamas_.setPosition(x+LansallamasPosX,y+LansallamasPosY);
            fuego_.setPosition(x+fx,y+fy);
    }
}

void armas::animacion_fuego(int limite_de_fotogramas){

    if (i >= 30/fps){
        i = 0;
        if (fotograma >= limite_de_fotogramas){
        fotograma = 0;
        }
        else{
            fotograma ++;
        }
    }
    else i ++;
    fuego_.setTextureRect(sf::IntRect(50*fotograma,0,50,50));
}

void armas::disparo::disparar(int x,int y,int dx, int dy,bool c1,bool c2,bool c3,int indice){
    if (!sss){
        sss = true;

        ab = c2;
        ar = c3;
        iz = c1;
        dsx = dx;
        dsy = dy;
    }

    x_= x;
    y_=y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        limite = 4;
    }
    else{
        limite = 7;
    }
    if (iz){
        recorte(180);
    }
    else{
        recorte(0);
    }
    if (ar){
        recorte(270);
    }
    if (ab){
        recorte(90);
    }


    if (indicador >= 30/fps){
        indicador = 0;
        if (fotograma >= limite){
            disparo_.setTextureRect(sf::IntRect(0,0,0,0));
            fotograma = 0;
            disparo_.setPosition(x_,y_);
            ddd = false;
            sss = false;
            //disparo_.setRotation(0);
        }
        else{
            fotograma ++;
        }
    }
    else{
        indicador ++;
    }
    disparo_.move(dsx*velocidad,dsy*velocidad);

    //std::cout<<"Coordenadas de fuego "<< indice <<": "<<x<<","<<y <<std::endl;

}

void armas::disparo::recorte(int angulo){
    disparo_.setTextureRect(sf::IntRect(100*fotograma,0,100,50));
    disparo_.setOrigin(10,23);
    disparo_.setRotation(angulo);
}


armas::armas()
{
    //ctor
}

armas::~armas()
{
    //dtor
}
