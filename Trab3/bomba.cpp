#include "bomba.h"

Bomba::Bomba(GLfloat x, GLfloat y, GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB, GLfloat velocidade, GLfloat anguloJogadorBase){
    this->x = x;
    this->y = y;
    this->raio = raio;
    this->corR = corR;
    this->corG = corG;
    this->corB = corB;
	this->velocidade = velocidade;
    this->anguloJogadorBase = anguloJogadorBase;
}

GLfloat Bomba::getX(){
	return this->x;
}

void Bomba::setX(GLfloat x){
	this->x = x;
}

GLfloat Bomba::getY(){
	return this->y;
}

void Bomba::setY(GLfloat y){
	this->y = y;
}

GLfloat Bomba::getRaio(){
	return this->raio;
}

void Bomba::setRaio(GLfloat raio){
	this->raio = raio;
}

GLfloat Bomba::getCorR(){
	return this->corR;
}

void Bomba::setCorR(GLfloat corR){
	this->corR = corR;
}

GLfloat Bomba::getCorG(){
	return this->corG;
}

void Bomba::setCorG(GLfloat corG){
	this->corG = corG;
}

GLfloat Bomba::getCorB(){
	return this->corB;
}

void Bomba::setCorB(GLfloat corB){
	this->corB = corB;
}

GLfloat Bomba::getVelocidade(){
	return this->velocidade;
}

void Bomba::setVelocidade(GLfloat velocidade){
	this->velocidade = velocidade;
}

GLfloat Bomba::getAnguloJogadorBase(){
    return this->anguloJogadorBase - 90;
}

void Bomba::desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB){
    float theta, px, py;
    glColor3f(corR, corG, corB);
	glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			theta = (i * M_PI) / 180.0;
			px = cos(theta) * raio;
			py = sin(theta) * raio;
			glVertex2f(px, py);
		}
	glEnd();
}

void Bomba::desenhaBomba(){
	glPushMatrix();
		glTranslatef(this->x, this->y, 0);
        glRotatef(this->getAnguloJogadorBase(), 0.0, 0.0, 1.0);
		desenhaCirculo(this->raio, this->corR, this->corG, this->corB);
	glPopMatrix();
}

void Bomba::voa(){
	GLfloat cx = this->getX() + (cos(((this->getAnguloJogadorBase() + 90) * (M_PI / 180))) * this->velocidade);
    GLfloat cy = this->getY() + (sin(((this->getAnguloJogadorBase() + 90) * (M_PI / 180))) * this->velocidade);
	this->setX(cx);
	this->setY(cy);
}