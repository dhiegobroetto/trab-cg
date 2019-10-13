#ifndef BOMBA_H
#define BOMBA_H

#include <GL/glut.h>
#include "math.h"
#include "linha.h"
#include "circulo.h"
#include "arena.h"
#include <iostream>
#include <string>

using namespace std;


class Bomba
{
    private:
        GLfloat x;
        GLfloat y;
        GLfloat raio;
        GLfloat corR;
        GLfloat corG;
        GLfloat corB;
        GLfloat velocidade;
        GLfloat anguloJogadorBase;

    public:
    	// ------------ Construtor ------------ //
        Bomba(GLfloat x, GLfloat y, GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB, GLfloat velocidade, GLfloat anguloJogadorBase);

        // ------------ Getters e Setters ------------ //
        GLfloat getX();
        void setX(GLfloat x);
        GLfloat getY();
        void setY(GLfloat y);
        GLfloat getRaio();
        void setRaio(GLfloat raio);
        GLfloat getCorR();
        void setCorR(GLfloat corR);
        GLfloat getCorG();
        void setCorG(GLfloat corG);
        GLfloat getCorB();
        void setCorB(GLfloat corB);
        GLfloat getAnguloJogadorBase();
        GLfloat getVelocidade();
        void setVelocidade(GLfloat velocidade);
        void desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaBomba();
        void voa();
};

#endif /* BOMBA_H */

