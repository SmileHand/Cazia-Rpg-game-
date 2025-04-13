#ifndef SMILES_H
#define SMILES_H
#include <SFML/Graphics.hpp>
#include<cmath>


class smiles
{
    public:
    sf::Texture smile;
    sf::Sprite smile_;
    float x=10,y=10,velocidad =11,acelera[4],empuje =.25,dx,dy,distancia,suavizado = 0.07f;
    float friccion = .95f;
    bool movimiento_activo = false,press = false;
    int largof = 84;



    bool se_mueve = false;

    void accion_smile(float px, float py);

        smiles();
        virtual ~smiles();

    protected:

    private:
};

#endif // SMILES_H
