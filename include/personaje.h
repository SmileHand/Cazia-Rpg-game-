#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include<cmath>



class personaje
{
    public:
        personaje();
        virtual ~personaje();
        int vida = 10;
        int ataque = 3;
        float pos_x = 640;
        float pos_y = 360,dx,dy,magnitud;
        int textura_ancho = 59;
        int textura_largo = 84;
        int fotograma = 0;
        int i = 0;
        int fps = 12;
        int lfoto;
        bool izquierda = true;
        bool abajo = false;
        float velocidad = 5;
        bool moves[5] = {false};
        bool sse_mueve = false;
        float acelera[5];
        float w,h;
        float aceleracion = 0;
        float friccion = .92f,suavizado = 0.08f;
        struct direcciones {
            int arriba=1,abajo=3,izquierda=2,derecha=4;

        };

        direcciones dir;


        sf::Clock tiempo;
        sf::Texture personaje_parado;
        sf::Sprite personaje_parado_;

        void inicio();
        void detener_animacion();
        void DANO (int DANO_RECIBIDO);
        void cual_animacion ();
        void animacion_de_personaje(int limite_de_fotogramas,std::string animacion);
        void moverse ();
        void direccion (sf::Sprite& personaje_parado_c,int textura_anchoc,int fotogramac,int textura_largoc, bool camina, bool camina_arriba );

    protected:

    private:
};

#endif // PERSONAJE_H
