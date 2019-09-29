#ifndef ARENA_H
#define ARENA_H

#include <GL/glut.h>
#include "math.h"
#include "linha.h"
#include "jogador.h"
#include "circulo.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Jogador;

class Arena
{
    private:
        GLint id;
        GLfloat raio;
        GLfloat x;
        GLfloat y;
        GLfloat corR;
        GLfloat corG;
        GLfloat corB;
        GLfloat velocidade;
        Jogador* jogador;
        Linha* linha;
        list<Circulo*> inimigosAereos;
        list<Circulo*> inimigosTerrestres;

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
        GLfloat getCorR();
        void setCorR(GLfloat& corR);
        GLfloat getCorG();
        void setCorG(GLfloat& corG);
        GLfloat getCorB();
        void setCorB(GLfloat& corB);
        Jogador* getJogador();
        void setJogador(Jogador* jogador);
        Linha* getLinha();
        void setLinha(Linha* linha);
        list<Circulo*> getInimigosAereos();
        list<Circulo*> getInimigosTerrestres();
        void desenhaArena();
        void criaInimigosAereos(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b);
        void criaInimigosTerrestres(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b);
};

#endif /* ARENA_H */

