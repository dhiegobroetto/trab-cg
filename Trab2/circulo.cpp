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
GLfloat Circulo::getVelocidade(){
	return this->velocidade;
}
void Circulo::setVelocidade(GLfloat velocidade){
	this->velocidade = velocidade;
}

void Circulo::desenhaCirculo(){
	glPushMatrix();
	float theta, px, py;
    glTranslatef(this->x, this->y, 0);
	glColor3f(this->getCorR(), this->getCorG(), this->getCorB());
	glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			theta = (i * M_PI) / 180.0;
			px = cos(theta) * this->getRaio();
			py = sin(theta) * this->getRaio();
			glVertex2f(px, py);
		}
	glEnd();
	glPopMatrix();
}	
void Circulo::moveX(GLfloat x){
    this->x += x;
}
void Circulo::moveY(GLfloat y){
    this->y += y;
}
void Circulo::decola(Linha* linha){
	GLfloat x, y;
	if(this->x >= linha->getX2()){
		x = 1;
	}else{
		x = -1;
	}
	if(this->y >= linha->getY2()){
		y = 1;
	}else{
		y = -1;
	}
	while(this->x <= linha->getX2()){
		this->x += 0.01;
		this->desenhaCirculo();
	}
}