#ifndef PROJETIL_H
#define PROJETIL_H

#include <GL/glut.h>
#include "math.h"
#include "linha.h"
#include "circulo.h"
#include "arena.h"
#include <iostream>
#include <string>

using namespace std;


class Projetil
{
    private:
        GLfloat x;
        GLfloat y;
        GLfloat projetilY;
        GLfloat base;
        GLfloat altura;
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
        Projetil(GLfloat x, GLfloat y, GLfloat base, GLfloat altura, GLfloat corR, GLfloat corG, GLfloat corB, GLfloat velocidade, GLfloat anguloProjetil, GLfloat anguloJogadorBase, GLfloat baseCanhao, GLfloat alturaCanhao);

        // ------------ Getters e Setters ------------ //
        GLfloat getX();
        void setX(GLfloat x);
        GLfloat getY();
        void setY(GLfloat y);
        GLfloat getBase();
        void setBase(GLfloat base);
        GLfloat getAltura();
        void setAltura(GLfloat altura);
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
        void desenhaQuadrado(GLfloat base, GLfloat altura, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaProjetil();
        void moveX(GLfloat x);
        void moveY(GLfloat y);
        bool verificaColisao(GLfloat x, GLfloat y);
        void voa();
};

#endif /* PROJETIL_H */

