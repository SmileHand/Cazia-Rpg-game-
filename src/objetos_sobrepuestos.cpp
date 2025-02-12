#include "objetos_sobrepuestos.h"

void objetos_sobrepuestos::crear_nuevo(std::string textura_imagen, /*int with, int height,*/ int pos_x, int pos_y/*, bool animado ,int fotogramas, int fps*/){
    this -> objeto.loadFromFile(textura_imagen);
    this -> objeto_.setTexture(objeto);
    objeto_.setPosition(pos_x,pos_y);
}

objetos_sobrepuestos::objetos_sobrepuestos()
{
    //ctor
}

objetos_sobrepuestos::~objetos_sobrepuestos()
{
    //dtor
}
