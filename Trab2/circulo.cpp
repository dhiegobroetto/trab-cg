#include "circulo.h"

Circulo::Circulo(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB){
	this->id = id;
    this->raio = raio;
    this->x = x;
    this->y = y;
    this->corR = corR;
    this->corG = corG;
    this->corB = corB;
}

GLint Circulo::getId(){
	return this->id;
}
void Circulo::setId(GLint& id){
	this->id = id;
}

GLfloat Circulo::getRaio() {
    return this->raio;
}

void Circulo::setRaio(GLfloat& raio) {
    this->raio = raio;
}

GLfloat Circulo::getX(){
	return this->x;
}
void Circulo::setX(GLfloat& x){
	this->x = x;
}
GLfloat Circulo::getY(){
	return this->y;
}
void Circulo::setY(GLfloat& y){
	this->y = y;
}
GLfloat Circulo::getCorR(){
	return this->corR;
}
void Circulo::setCorR(GLfloat& corR){
	this->corR = corR;
}
GLfloat Circulo::getCorG(){
	return this->corG;
}
void Circulo::setCorG(GLfloat& corG){
	this->corG = corG;
}
GLfloat Circulo::getCorB(){
	return this->corB;
}
void Circulo::setCorB(GLfloat& corB){
	this->corB = corB;
}
