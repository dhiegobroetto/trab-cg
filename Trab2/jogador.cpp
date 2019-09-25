#include "jogador.h"

Jogador::Jogador(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB){
	this->id = id;
    this->raio = raio;
    this->x = x;
    this->y = y;
    this->corR = corR;
    this->corG = corG;
    this->corB = corB;
}

GLint Jogador::getId(){
	return this->id;
}
void Jogador::setId(GLint& id){
	this->id = id;
}

GLfloat Jogador::getRaio() {
    return this->raio;
}

void Jogador::setRaio(GLfloat& raio) {
    this->raio = raio;
}

GLfloat Jogador::getX(){
	return this->x;
}
void Jogador::setX(GLfloat& x){
	this->x = x;
}
GLfloat Jogador::getY(){
	return this->y;
}
void Jogador::setY(GLfloat& y){
	this->y = y;
}
GLfloat Jogador::getCorR(){
	return this->corR;
}
void Jogador::setCorR(GLfloat& corR){
	this->corR = corR;
}
GLfloat Jogador::getCorG(){
	return this->corG;
}
void Jogador::setCorG(GLfloat& corG){
	this->corG = corG;
}
GLfloat Jogador::getCorB(){
	return this->corB;
}
void Jogador::setCorB(GLfloat& corB){
	this->corB = corB;
}
GLfloat Jogador::getVelocidade(){
	return this->velocidade;
}
void Jogador::setVelocidade(GLfloat velocidade){
	this->velocidade = velocidade;
}

void Jogador::desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB){
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

void Jogador::desenhaJogador(){
	glPushMatrix();
    glTranslatef(this->x, this->y, 0);
	desenhaCirculo(this->getRaio(), this->getCorR(), this->getCorG(), this->getCorB());
	glPopMatrix();
}	
void Jogador::moveX(GLfloat x){
    this->x += x;
}
void Jogador::moveY(GLfloat y){
    this->y += y;
}
void Jogador::decola(Linha* linha){
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
		this->desenhaJogador();
	}
}