#include "linha.h"

Linha::Linha(GLint& id, GLfloat& x1, GLfloat& y1, GLfloat& x2, GLfloat& y2, GLfloat& corR, GLfloat& corG, GLfloat& corB){
	this->id = id;
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
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

void Linha::desenhaLinha(){
	glColor3f(this->getCorR(), this->getCorG(), this->getCorB());
        glPointSize(3.0); 
        glBegin(GL_LINES);
        glVertex2d(this->getX1(), this->getY1());
        glVertex2d(this->getX2(), this->getY2());
    glEnd();
}
