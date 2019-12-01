#ifndef PROJETIL_H
#define PROJETIL_H

#include <GL/glut.h>
#include "math.h"
#include "linha.h"
#include "circulo.h"
#include "arena.h"
#include "config.h"
#include <iostream>
#include <string>

class Projetil
{
    private:
        GLfloat x;
        GLfloat y;
        GLfloat z;
        GLfloat raio;
        GLfloat corR;
        GLfloat corG;
        GLfloat corB;
        GLfloat velocidade;
        GLfloat anguloProjetil;
        GLfloat anguloJogadorBase;
        GLfloat alturaCanhao;
        GLfloat baseCanhao;

    public:
    	// ------------ Construtor ------------ //
        Projetil(GLfloat x, GLfloat y, GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB, GLfloat velocidade, GLfloat anguloProjetil, GLfloat anguloJogadorBase, GLfloat baseCanhao, GLfloat alturaCanhao);

        // ------------ Getters e Setters ------------ //
        GLfloat getX();
        void setX(GLfloat x);
        GLfloat getY();
        void setY(GLfloat y);
        GLfloat getZ();
        void setZ(GLfloat z);
        GLfloat getRaio();
        void setRaio(GLfloat raio);
        GLfloat getCorR();
        void setCorR(GLfloat corR);
        GLfloat getCorG();
        void setCorG(GLfloat corG);
        GLfloat getCorB();
        void setCorB(GLfloat corB);
        GLfloat getVelocidade();
        void setVelocidade(GLfloat velocidade);
        GLfloat getAnguloProjetil();
        void setAnguloProjetil(GLfloat anguloProjetil);
        GLfloat getAnguloJogadorBase();
        void setAnguloJogadorBase(GLfloat anguloJogadorBase);
        GLfloat getAnguloFinal();
        GLfloat getBaseCanhao();
        GLfloat getAlturaCanhao();
        void desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaProjetil(GLfloat corR, GLfloat corG, GLfloat corB);
        void voa(GLfloat tempoAjustador);
};

#endif /* PROJETIL_H */
