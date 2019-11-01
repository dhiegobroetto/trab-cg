#ifndef LINHA_H
#define LINHA_H

#include <GL/glut.h>
#include "math.h"

using namespace std;

class Linha
{
    private:
        GLint id;
        GLfloat x1;
        GLfloat y1;
        GLfloat x2;
        GLfloat y2;
        GLfloat corR;
        GLfloat corG;
        GLfloat corB;
    public:
    	// ------------ Construtor ------------ //
        Linha(GLint& id, GLfloat& x1, GLfloat& y1, GLfloat& x2, GLfloat& y2, GLfloat& corR, GLfloat& corG, GLfloat& corB);

        // ------------ Getters e Setters ------------ //
        GLint getId();
        void setId(GLint& id);
        GLfloat getX1();
        void setX1(GLfloat& x1);
        GLfloat getY1();
        void setY1(GLfloat& y1);
        GLfloat getX2();
        void setX2(GLfloat& x2);
        GLfloat getY2();
        void setY2(GLfloat& y2);
        GLfloat getCorR();
        void setCorR(GLfloat& corR);
        GLfloat getCorG();
        void setCorG(GLfloat& corG);
        GLfloat getCorB();
        void setCorB(GLfloat& corB);
        void desenhaLinha();
        GLfloat getDistanciaX();
        GLfloat getDistanciaY();
};

#endif /* LINHA_H */

