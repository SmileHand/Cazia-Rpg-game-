#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
#include <personaje.h>
#include <objetos_sobrepuestos.h>
#include <camara.h>
#include <pantalla_de_inicio.h>
#include <armas.h>
#include <colisiones.h>
#include <mpapas.h>
#include <colisionmapa.h>
#include <smiles.h>


class juego
{
    public:

        void ASIGNAR_TEXTURAS_ENTORNO ();
        void DIBUJADO_DE_TEXTURAS_DE_FONDO ();
        void DIBUJOS_DINAMICOS();// ESTO ES PARA LOS PERSONAJES, ENEMIGOS, ETC.
        void DIBUJADO_DE_TEXTURAS_SOBREPUESTAS ();// ESTO PARA PAREDES O DECORACION QUE ESTE FRENTE AL PERSONAJE
        void EVENTOS_DE_JUEGO ();
        void ACCIONES ();
        void inicio();

        int WITH = 1280;
        int HEIGHT =  720;
        int fps= 30;
        int espera_camara= 0;
        bool juego_iniciado = false;

        sf::RenderWindow app;
        sf::Texture texture;
        sf::Sprite sprite;

        smiles enemigo;
        personaje yo;
        objetos_sobrepuestos suelo;
        camara primera;
        pantalla_de_inicio pantalla1;
        armas armas1;
        colisiones coli;
        mpapas mapass;
        colisionmapa delmapa;


        sf::RectangleShape pared;




        /*hacer esto me tomo algo de tiempo, 2 dias aprox y pues honestamente estoy satisfecho con lo que hice,
        hace falta mucha optimizacion de variables y todo eso, hay errores con las texturas y eso significa que
        hay una mala gestion en las animaciones, si puedes ver que onda estaria perro*/

        void principal(){

            // Create the main window

            inicio();

            // Start the game loop
            while (app.isOpen()){
                // Process events
                sf::Event event;
                while (app.pollEvent(event)){
                    // Close window : exit
                    if (event.type == sf::Event::Closed)
                        app.close();
                }
                ACCIONES ();

                // Clear screen
                app.clear();


                // Draw the sprite

                DIBUJADO_DE_TEXTURAS_DE_FONDO();
                DIBUJOS_DINAMICOS();
                DIBUJADO_DE_TEXTURAS_SOBREPUESTAS();

                // Update the window
                app.display();
            }
        }

        juego();
        virtual ~juego();

    protected:

    private:
};

#endif // JUEGO_H
