#include "personaje.h"




void personaje::inicio(){
    this->personaje_parado.loadFromFile("recursos/texturas/personaje/Cazia.png");
    this->personaje_parado_.setTexture(personaje_parado);
    personaje_parado_.setPosition(pos_x,pos_y);
}
void personaje::detener_animacion(){
    if (!abajo){
        fotograma=0;
    }else{

        animacion_de_personaje(0,"recursos/texturas/personaje/Cazia.png");
    }
}

void personaje::DANO(int DANO_RECIBIDO){
    this->vida -= DANO_RECIBIDO;
}

void personaje::animacion_de_personaje(int limite_de_fotogramas,std::string animacion){

    this->personaje_parado.loadFromFile(animacion);
    this->personaje_parado_.setTexture(personaje_parado);
    lfoto = limite_de_fotogramas - 1;

    if (i >= 30/fps){
        i = 0;
        if (fotograma >= lfoto){
        fotograma = 0;
        }
        else{
            fotograma ++;
        }
    }
    else i ++;
    direccion(this->personaje_parado_,this->textura_ancho,this->fotograma,this->textura_largo, izquierda, abajo);
}

void personaje::moverse(){
    /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&& moves[dir.abajo] == false){
        if (acelera[1]<velocidad){
            acelera [1] +=.5f;
        }
        pos_y -=acelera[1] ;
        //izquierda = false;
        moves[dir.arriba] = true;
        //abajo = false;

    }
    else{
        moves[dir.arriba] = false;
        if (acelera[1] >0){
            acelera[1] -=.5f;
        }
        pos_y -=acelera[1];

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& moves[dir.arriba]== false){
        if (acelera[2]<velocidad){
            acelera [2] +=.5f;
        }
        pos_y +=acelera[2] ;
        //izquierda = false;
        //abajo = true;
        moves[dir.abajo]=true;
    }
    else{
        if (acelera[2] >0){
            acelera[2] -=.5f;
        }
        pos_y +=acelera[2];
        moves[dir.abajo]=false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && moves[dir.derecha]==false){
        if (acelera[2]<0||acelera[1]<0){
                velocidad = 5;
            }else{
                velocidad = 10;
            }
        if (acelera[3]<velocidad){

            acelera [3] +=.5f;
        }
        pos_x -=acelera[3] ;
        moves[dir.izquierda]= true;
        //if (!moves[dir.arriba]&&!moves[dir.abajo]) izquierda = true;
        //abajo = false;
    }
    else{
        if (acelera[3]>0){
            acelera [3] -=.5f;
        }
        pos_x -=acelera[3];

        moves[dir.izquierda]=false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& moves[dir.izquierda]==false){
         if (acelera[2]<0||acelera[1]<0){
                velocidad = 5;
            }else{
                velocidad = 10;
            }
        if (acelera[4]<velocidad){
            acelera [4] +=.5f;
        }
        pos_x +=acelera[4];
        //izquierda = false;
        moves[dir.derecha]=true;
        //abajo = false;
    }
    else{
        if (acelera[4]>0){
            acelera [4] -=.5f;
        }
        pos_x +=acelera[4];
        moves[dir.derecha]=false;
    }
    */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
        velocidad = 10;
        fps = 12;
    } else {
        velocidad = 5;
        fps = 8;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !moves[dir.abajo]) {
        dy -= 1.0f;
        moves[dir.arriba] = true;
    } else {
        moves[dir.arriba] = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !moves[dir.arriba]) {
        dy += 1.0f;
        moves[dir.abajo] = true;
    } else {
        moves[dir.abajo] = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !moves[dir.derecha]) {
        dx -= 1.0f;
        moves[dir.izquierda] = true;
    } else {
        moves[dir.izquierda] = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !moves[dir.izquierda]) {
        dx += 1.0f;
        moves[dir.derecha] = true;
    } else {
        moves[dir.derecha] = false;
    }

    /*
    if(moves[dir.abajo]==false&&moves[dir.arriba]==false&&moves[dir.izquierda]==false&&moves[dir.derecha]==false){
        dx = 0;
        dy = 0;
    }*/
    if (sse_mueve){
        magnitud = sqrt(dx * dx + dy * dy);

        if (magnitud > 0.0f) {
            dx /= magnitud;
            dy /= magnitud;
        }
        acelera[1] = acelera[1] * (1 - suavizado) + dx * velocidad * suavizado;
        acelera[2] = acelera[2] * (1 - suavizado) + dy * velocidad * suavizado;
    }
    else{
        acelera[1] *= friccion;
        acelera[2] *= friccion;
    }



    pos_x += acelera[1];
    pos_y += acelera[2];


    cual_animacion();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
        dir.arriba=3;
        dir.abajo=1;
        dir.izquierda=4;
        dir.derecha=2;
    }
    else{
        dir.arriba=1;
        dir.abajo=3;
        dir.izquierda=2;
        dir.derecha=4;

    }
    if (!moves[1]&&!moves[3]&& !moves[4] &&moves[2]) izquierda = true;
    else if(moves[1]||moves[3]||moves[4]) izquierda = false;

    w = pos_x+textura_ancho;
    h = pos_y+textura_largo;

    if (!moves[4]&&!moves[2]&&!moves[1]&&moves[3]) abajo = true;
    else if(moves[4]||moves[2]||moves[1]) abajo = false;
    direccion(this->personaje_parado_,this->textura_ancho,this->fotograma,this->textura_largo, izquierda, abajo);
    personaje_parado_.setPosition(pos_x,pos_y);
}

void personaje::direccion(sf::Sprite& personaje_parado_c,int textura_anchoc,int fotogramac,int textura_largoc, bool camina, bool camina_arriba){

    if (izquierda){
        personaje_parado_c.setTextureRect(sf::IntRect(textura_anchoc*fotogramac+textura_anchoc,0,-textura_anchoc,textura_largoc));
    }
    else{
        personaje_parado_c.setTextureRect(sf::IntRect(textura_anchoc*fotogramac,0,textura_anchoc,textura_largoc));

    }
}

void personaje::cual_animacion(){
    if (moves[1]) {
        animacion_de_personaje(4,"recursos/texturas/personaje/camina_trasera_4.png");
    }

    else if (moves[3]){
        animacion_de_personaje(4,"recursos/texturas/personaje/camina_frontal_4.png");
    }

    else if (moves[2]==true||moves[4]==true){
        animacion_de_personaje(2,"recursos/texturas/personaje/camina_lado_2.png");
    }


    if (moves[1]==false && moves[2]==false && moves[4]==false && moves[3]==false){
        detener_animacion();
        sse_mueve = false;
    }
    else{
        sse_mueve = true;
    }



}

personaje::personaje()
{
    //ctor
}

personaje::~personaje()
{
    //dtor
}
