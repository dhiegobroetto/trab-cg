#ifndef BOMBA_H
#define BOMBA_H

#include <GL/glut.h>
#include "math.h"
#include "linha.h"
#include "circulo.h"
#include "arena.h"
#include "config.h"
#include <iostream>
#include <string>

class Arena;

class Bomba
{
    private:
        GLfloat x;
        GLfloat y;
        GLfloat z;
        GLfloat raio;
        GLfloat raioInicial;
        GLfloat corR;
        GLfloat corG;
        GLfloat corB;
        GLfloat velocidade;
        GLfloat velocidadeVertical;
        GLfloat anguloJogadorBase;
        GLfloat tempoInicial;
        bool explode;
        Arena *arena;
        bool camera;

    public:
    	// ------------ Construtor ------------ //
        Bomba(GLfloat x, GLfloat y, GLfloat z, GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB, GLfloat velocidade, GLfloat anguloJogadorBase, Arena *arena);

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
        GLfloat getAnguloJogadorBase();
        GLfloat getVelocidade();
        void setVelocidade(GLfloat velocidade);
        void desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaBomba();
        void voa(GLfloat tempoAjustador);
        void cai(GLfloat tempoAjustador);
        void explodeBomba();
        bool explodiu();
        void setCamera(bool status);
        bool hasCamera();
};

#endif /* BOMBA_H */
