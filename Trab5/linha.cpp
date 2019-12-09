#include "linha.h"

Linha::Linha(GLint& id, GLfloat& x1, GLfloat& y1, GLfloat& x2, GLfloat& y2, GLfloat& corR, GLfloat& corG, GLfloat& corB){
	this->id = id;
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
	this->z1 = 0;
	this->z2 = 0;
    this->corR = corR;
    this->corG = corG;
    this->corB = corB;
}

GLint Linha::getId(){
	return this->id;
}

void Linha::setId(GLint& id){
	this->id = id;
}

GLfloat Linha::getX1() {
    return this->x1;
}

void Linha::setX1(GLfloat& x1) {
    this->x1 = x1;
}

GLfloat Linha::getX2(){
	return this->x2;
}

void Linha::setX2(GLfloat& x2){
	this->x2 = x2;
}

GLfloat Linha::getY1(){
	return this->y1;
}

void Linha::setY1(GLfloat& y1){
	this->y1 = y1;
}

GLfloat Linha::getY2(){
	return this->y2;
}

void Linha::setY2(GLfloat& y2){
	this->y2 = y2;
}

GLfloat Linha::getZ1(){
	return this->z1;
}

void Linha::setZ1(GLfloat& z1){
	this->z1 = z1;
}

GLfloat Linha::getZ2(){
	return this->z2;
}

void Linha::setZ2(GLfloat& z2){
	this->z2 = z2;
}

GLfloat Linha::getCorR(){
	return this->corR;
}

void Linha::setCorR(GLfloat& corR){
	this->corR = corR;
}

GLfloat Linha::getCorG(){
	return this->corG;
}

void Linha::setCorG(GLfloat& corG){
	this->corG = corG;
}

GLfloat Linha::getCorB(){
	return this->corB;
}

void Linha::setCorB(GLfloat& corB){
	this->corB = corB;
}

void Linha::desenhaLinha(GLuint texturaPista){
	GLfloat dist = getDistanciaX();
    GLfloat angulo = (180 / M_PI) * atan2(y2 - y1, x2 - x1);
    
    glEnable(GL_TEXTURE_2D);
        glPushMatrix();
            glTranslatef(x1, y1, 0.0);
            glRotatef(angulo, 0.0, 0.0, 1.0);
            
            glMatrixMode(GL_TEXTURE);
            glPushMatrix();
                glScalef(0.1, 1.0, 1.0);

                glBindTexture(GL_TEXTURE_2D, texturaPista);
                glColor3f(1.0, 1.0, 1.0);

                glBegin(GL_QUAD_STRIP);
                    glNormal3f(0.0, 0.0, 1.0);
                    glTexCoord2f(0.0, 0.0);
                    glVertex3f(-6 * dist / 50, -30.0, 0.1);
                    
                    glNormal3f(0.0, 0.0, 1.0);
                    glTexCoord2f(0.0, 1.0);
                    glVertex3f(-6 * dist / 50, 30.0, 0.1);
                        
                    int textura = 0;
                        
                    for (int i = -5 * dist / 50; i <= dist; i += dist / 50) {
                    	// Ponto direita
                        glNormal3f(0.0, 0.0, 1.0);
                        glTexCoord2f(1.0 + textura, 0.0);
                        glVertex3f(i, -30.0, 0.1);
                        
                        // Ponto esquerda
                        glNormal3f(0.0, 0.0, 1.0);
                        glTexCoord2f(textura + 1.0, 1.0);
                        glVertex3f(i, 30.0, 0.1);
                        
                        textura++;
                    }
                glEnd();
            glPopMatrix();
            glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

GLfloat Linha::getDistanciaX(){
	return this->x2 - this->x1;
}


GLfloat Linha::getDistanciaY(){
	return this->y2 - this->y1;
}
