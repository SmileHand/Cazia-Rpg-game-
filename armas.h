#ifndef ARMAS_H
#define ARMAS_H
#include <SFML/Graphics.hpp>
#include <iostream>

class armas
{
    public:
        bool item = false;
        sf::Texture itemm;
        sf::Sprite itemm_;
        sf::Texture lansallamas;
        sf::Sprite lansallamas_;
        sf::Texture fuego;
        sf::Sprite fuego_;
        sf::Texture proyectil;
        sf::Sprite protectil_;
        int x=500,y=500;
        int w=59;
        int i =0,e=0,o =0 ,fps =12,fotograma,fotograma2,estela=0;
        bool fuee = false;
        static const int maxx=100;
        bool izquierda = false;
        bool abajo = false;
        bool arriba = false;
        struct disparo {
            sf::Texture disparo;
            sf::Sprite disparo_;
            bool iz;
            bool ab;
            bool ar;
            int x_,y_,h=50,w=50,fotograma=0,indicador=0,limite=4,fps=15,dsx,dsy;
            float velocidad = 5;
            bool ddd= false;
            bool sss= false;
            void disparar(int x,int y,int dx, int dy,bool c1,bool c2,bool c3,int indice);
            void recorte(int angulo);
        };


        disparo shoot[maxx];
        disparo recurso;


        float LansallamasPosX,LansallamasPosY,fx,fy,velocidad=20,dx,dy,dpx,dpy;
        void inicio();
        void item_suelto();
        void imprimir_arma(bool pos1,bool pos2,bool pos3,bool pos4,float x,float y);
        void animacion_fuego(int limite_de_fotogramas);

        void fuego_lansado(int x, int y,int dx, int dy);


        armas();
        virtual ~armas();

    protected:

    private:
};

#endif // ARMAS_H
