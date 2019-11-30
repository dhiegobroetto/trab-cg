#ifndef CIRCULO_H
#define CIRCULO_H

#include <GL/glut.h>
#include "math.h"
#include "linha.h"
#include <iostream>
#include <string>

using namespace std;

class Circulo
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
        GLfloat velocidade;

    public:
    	// ------------ Construtor ------------ //
        Circulo(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB);

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
        GLfloat getVelocidade();
        void setVelocidade(GLfloat& velocidade);
        void desenha();
        void desenhaQuadrado(GLfloat base, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaQuadradoLinha(GLfloat base, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaCruz(GLfloat base, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaCirculo(GLfloat raio, GLfloat x, GLfloat y, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaCirculoLinha(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB);
        void moveX(GLfloat x);
        void moveY(GLfloat y);
        void decola(Linha* linha);

};

#endif /* CIRCULO_H */
