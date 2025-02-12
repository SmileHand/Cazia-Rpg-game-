#include "pantalla_de_inicio.h"

void pantalla_de_inicio::iniciar(){
    fuente.loadFromFile("recursos/fuentes/Leander.ttf");
    fuente2.loadFromFile("recursos/fuentes/kirsty.otf");
    Titulo.setFont(fuente);
    Jugar.setFont(fuente2);
}

void pantalla_de_inicio::texto(){
    Jugar.setString("Presiona espacio para jugar");
    Jugar.setCharacterSize(20);
    Jugar.setPosition(210,300);
    Jugar.setFillColor(sf::Color::Red);

    Titulo.setString("Cazia");
    Titulo.setCharacterSize(100);
    Titulo.setPosition(200,100);
    Titulo.setFillColor(sf::Color::Red);
}

void pantalla_de_inicio::partida(bool& inicio){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        inicio = true;
    }
}

pantalla_de_inicio::pantalla_de_inicio()
{
    //ctor
}

pantalla_de_inicio::~pantalla_de_inicio()
{
    //dtor
}
