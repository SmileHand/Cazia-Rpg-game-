#include "juego.h"

 void juego::inicio(){
    app.setFramerateLimit(fps);
    yo.inicio();
    suelo.crear_nuevo("recursos/texturas/suelo.png",0,0);
    pantalla1.iniciar();
    armas1.inicio();

}

void juego::DIBUJADO_DE_TEXTURAS_DE_FONDO(){

    if (juego_iniciado){
        //app.draw(suelo.objeto_);
        for (int i=0; i<mapass.w; i++){
            for(int f=0; f<mapass.h; f++){
                mapass.piedra_.setTextureRect(sf::IntRect(mapass.mapaaa[i][f]*mapass.t,0,mapass.t,mapass.t));
                mapass.piedra_.setPosition(i*mapass.t,f*mapass.t);
                app.draw(mapass.piedra_);

            }
        }
        app.draw(pared);
    }

}

void juego::DIBUJADO_DE_TEXTURAS_SOBREPUESTAS(){
    if (juego_iniciado){

    }
    else{
        app.draw(pantalla1.Titulo);
        app.draw(pantalla1.Jugar);
    }
}


void juego::ACCIONES (){
    if (juego_iniciado){
        mapass.cambio();
        primera.seguimiento_de_camara(yo.pos_x+yo.textura_ancho/2,yo.pos_y+yo.textura_largo/2,yo.acelera[1],yo.acelera[2],yo.acelera[3],yo.acelera[4]);
        app.setView(primera.view1);
        coli.colision(yo.pos_x,yo.pos_y,yo.textura_ancho,yo.textura_largo,armas1.x,armas1.y,armas1.w,armas1.w,armas1.item);
        armas1.item_suelto();
        delmapa.colision_pared(yo.pos_x,yo.pos_y,yo.textura_ancho,yo.textura_largo,yo.acelera[1],yo.acelera[2]);
        yo.moverse();
        armas1.imprimir_arma(yo.moves[1],yo.moves[2],yo.moves[3],yo.moves[4],yo.pos_x,yo.pos_y);

        enemigo.accion_smile(yo.pos_x,yo.pos_y);

        if (!yo.sse_mueve/*&&primera.choque*/){
            if (espera_camara>0){
                espera_camara --;
            }
            else{
                primera.camara_moviendose = false;
                espera_camara = fps*4;
                primera.choque = false;
            }

        }

    }
    else{
        pantalla1.texto();
        pantalla1.partida(juego_iniciado);
    }
}
void juego::DIBUJOS_DINAMICOS(){
    if (juego_iniciado){
        //app.draw(enemigo.smile_);
        if (yo.pos_y+yo.textura_largo>enemigo.y+enemigo.largof){
            app.draw(enemigo.smile_);
        }
        if (/*!yo.moves[3]||*/!yo.abajo){
            app.draw(armas1.fuego_);
            for (int i=0; i<armas1.maxx-1;i++){
                app.draw(armas1.shoot[i].disparo_);
            }
        }
        if (yo.izquierda) app.draw(armas1.lansallamas_);
        app.draw(yo.personaje_parado_);
        if (!yo.izquierda) app.draw(armas1.lansallamas_);
        if (/*yo.moves[3]||*/yo.abajo){
            app.draw(armas1.fuego_);
            //int i=0; i<armas1.maxx;i++
            for (int i=armas1.maxx-1; i>0;i--){
                app.draw(armas1.shoot[i].disparo_);
            }
        }
        if (yo.pos_y+yo.textura_largo<enemigo.y+enemigo.largof){
            app.draw(enemigo.smile_);
        }

        app.draw(armas1.itemm_);
    }
}

juego::juego()
{
    app.create(sf::VideoMode(WITH, HEIGHT, 64), "Juego de smile", sf::Style::Default);
    delmapa.x = 800;
    delmapa.y = 40;
    delmapa.w = 500;
    delmapa.h = 600;
    pared.setSize(sf::Vector2f(delmapa.w,delmapa.h));
    pared.setPosition(delmapa.x,delmapa.y);
    pared.setFillColor(sf::Color::Red);
    //ctor
}

juego::~juego()
{
    //dtor
}
