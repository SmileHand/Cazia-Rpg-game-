#ifndef OBJETOS_SOBREPUESTOS_H
#define OBJETOS_SOBREPUESTOS_H
#include <SFML/Graphics.hpp>
#include <iostream>



class objetos_sobrepuestos
{
    public:
        objetos_sobrepuestos();
        virtual ~objetos_sobrepuestos();
        sf::Texture objeto;
        sf::Sprite objeto_;
        int pos_x = 0;
        int pos_y = 500;


        void crear_nuevo(std::string textura_imagen, /*int with, int height,*/ int pos_x, int pos_y/*, bool animado ,int fotogramas, int fps*/);


    protected:

    private:
};

#endif // OBJETOS_SOBREPUESTOS_H
