#ifndef PANTALLA_DE_INICIO_H
#define PANTALLA_DE_INICIO_H
#include <SFML/Graphics.hpp>


class pantalla_de_inicio
{
    public:
        sf::Font fuente;
        sf::Font fuente2;

        sf::Text Titulo;
        sf::Text Jugar;

        void iniciar ();
        void texto();
        void partida(bool& inicio);

        pantalla_de_inicio();
        virtual ~pantalla_de_inicio();

    protected:

    private:
};

#endif // PANTALLA_DE_INICIO_H
