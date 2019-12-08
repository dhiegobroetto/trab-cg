#ifndef ARENA_H
#define ARENA_H

#include <GL/glut.h>
#include "math.h"
#include "config.h"
#include "linha.h"
#include "jogador.h"
#include "inimigo.h"
#include "circulo.h"
#include <iostream>
#include <string>
#include <list>

class Jogador;
class Inimigo;
class Linha;
class Circulo;

class Arena
{
    private:
        GLint id;
        GLfloat raio;
        GLfloat x;
        GLfloat y;
        GLfloat z;
        GLfloat corR;
        GLfloat corG;
        GLfloat corB;
        bool iluminacao;
        GLfloat velocidade;
        Jogador* jogador;
        Linha* linha;
        std::list<Inimigo*> inimigosAereos;
        std::list<Inimigo*> inimigosAereosMortos;
        std::list<Circulo*> inimigosTerrestres;
        std::list<Circulo*> inimigosTerrestresMortos;
        GLuint texturaMar;
        GLuint texturaCeu;
        GLfloat maiorRaioTerrestre;

    public:
    	// ------------ Construtor ------------ //
        Arena(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB);

        // ------------ Getters e Setters ------------ //
        GLint getId();
        void setId(GLint& id);
        GLfloat getRaio();
        void setRaio(GLfloat& raio);
        GLfloat getX();
        void setX(GLfloat& x);
        GLfloat getY();
        void setY(GLfloat& y);
        GLfloat getZ();
        void setZ(GLfloat& z);
        GLfloat getCorR();
        void setCorR(GLfloat& corR);
        GLfloat getCorG();
        void setCorG(GLfloat& corG);
        GLfloat getCorB();
        void setCorB(GLfloat& corB);
        GLfloat getMaiorRaioTerrestre();
        void setMaiorRaioTerrestre(GLfloat& maiorRaioTerrestre);
        Jogador* getJogador();
        void setJogador(Jogador* jogador);
        Linha* getLinha();
        bool getIluminacao();
        void trocaIluminacao();
        void setLinha(Linha* linha);
        GLuint getTexturaMar();
        void setTexturaMar(GLuint texturaMar);
        GLuint getTexturaCeu();
        void setTexturaCeu(GLuint texturaCeu);
        std::list<Inimigo*> getInimigosAereos();
        void mataInimigoAereo(Inimigo* inimigo);
        void mataInimigoTerrestre(Circulo* inimigo);
        std::list<Circulo*> getInimigosTerrestres();
        std::list<Circulo*> getInimigosTerrestresMortos();
        void desenhaArena();
        void desenhaCirculoBorda(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB);
        void criaInimigosAereos(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b, Arena* arena, GLfloat vel, GLfloat velTiro, GLfloat freqTiro);
        void criaInimigosTerrestres(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b);
        void voaInimigosAereos(GLfloat curva, GLfloat tempoMultiplicador);
        void reseta();
        void desenhaMinimapa(GLfloat raio);
};

#endif /* ARENA_H */
