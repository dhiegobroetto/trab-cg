#ifndef JOGADOR_H
#define JOGADOR_H

#include <GL/glut.h>
#include "math.h"
#include "linha.h"
#include <iostream>
#include <string>

using namespace std;

class Jogador
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
        GLfloat tempoMultiplicador;

    public:
    	// ------------ Construtor ------------ //
        Jogador(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB);

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
        GLfloat getTempoMultiplicador();
        void setTempoMultiplicador(GLfloat& tempoMultiplicador);
        GLfloat getVelocidade();
        void setVelocidade(GLfloat velocidade);
        void desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaJogador();
        void moveX(GLfloat x);
        void moveY(GLfloat y);
        void decola(Linha* linha);

};

#endif /* JOGADOR_H */

