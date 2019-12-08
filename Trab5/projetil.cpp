#include "projetil.h"

Projetil::Projetil(GLfloat x, GLfloat y, GLfloat z, GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB, GLfloat velocidade, GLfloat anguloProjetil, GLfloat anguloJogadorBase, GLfloat anguloProjetilVertical, GLfloat alturaCanhao, GLfloat baseCanhao){
    this->x = x;
    this->y = y;
    this->z = z;
    this->raio = raio;
    this->corR = corR;
    this->corG = corG;
    this->corB = corB;
	this->velocidade = velocidade;
    this->anguloProjetil = anguloProjetil;
    this->anguloProjetilVertical = anguloProjetilVertical;
	this->anguloJogadorBase = anguloJogadorBase;
	this->alturaCanhao = alturaCanhao;
	this->baseCanhao = baseCanhao;
}

GLfloat Projetil::getX(){
	return this->x;
}

void Projetil::setX(GLfloat x){
	this->x = x;
}

GLfloat Projetil::getRaio(){
	return this->raio;
}

void Projetil::setRaio(GLfloat raio){
	this->raio = raio;
}

GLfloat Projetil::getY(){
	return this->y;
}

void Projetil::setY(GLfloat y){
	this->y = y;
}

GLfloat Projetil::getZ(){
	return this->z;
}

void Projetil::setZ(GLfloat z){
	this->z = z;
}

GLfloat Projetil::getCorR(){
	return this->corR;
}

void Projetil::setCorR(GLfloat corR){
	this->corR = corR;
}

GLfloat Projetil::getCorG(){
	return this->corG;
}

void Projetil::setCorG(GLfloat corG){
	this->corG = corG;
}

GLfloat Projetil::getCorB(){
	return this->corB;
}

void Projetil::setCorB(GLfloat corB){
	this->corB = corB;
}

GLfloat Projetil::getVelocidade(){
	return this->velocidade;
}

void Projetil::setVelocidade(GLfloat velocidade){
	this->velocidade = velocidade;
}

GLfloat Projetil::getAnguloProjetil(){
    return this->anguloProjetil;
}

void Projetil::setAnguloProjetil(GLfloat anguloProjetil){
    this->anguloProjetil = anguloProjetil;
}

GLfloat Projetil::getAnguloProjetilVertical(){
    return this->anguloProjetilVertical;
}

void Projetil::setAnguloProjetilVertical(GLfloat anguloProjetilVertical){
    this->anguloProjetilVertical = anguloProjetilVertical;
}

GLfloat Projetil::getAnguloJogadorBase(){
    return this->anguloJogadorBase - 90;
}

void Projetil::setAnguloJogadorBase(GLfloat anguloJogadorBase){
    this->anguloJogadorBase = anguloJogadorBase;
}

GLfloat Projetil::getAnguloFinal(){
    return this->getAnguloJogadorBase() + this->getAnguloProjetil() + 90;
}

GLfloat Projetil::getBaseCanhao(){
	return this->baseCanhao;
}
GLfloat Projetil::getAlturaCanhao(){
	return this->alturaCanhao;
}

void Projetil::desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB){
    float theta, px, py;
    defineCor(corR, corG, corB);

    glutSolidSphere(raio, 30, 30);

	defineCor(1.0, 1.0, 1.0);
	glPointSize(0.5);
	glBegin(GL_POINTS);
        for (int i = 0; i < 360; i++) {
			theta = (i * M_PI) / 180.0;
			px = cos(theta) * raio;
			py = sin(theta) * raio;
			glVertex3f(px, 0, py);
		}
	glEnd();
}

void Projetil::desenhaProjetil(GLfloat corR, GLfloat corG, GLfloat corB){
	glPushMatrix();
		glTranslatef(this->x, this->y, this->z);
		glRotatef(this->anguloProjetil, 0.0, 0.0, 1.0);
		desenhaCirculo(this->raio, corR, corG, corB);
	glPopMatrix();
}

void Projetil::voa(GLfloat tempoAjustador){
	GLfloat cx = this->getX() + (cos(this->getAnguloProjetilVertical() * (M_PI / 180)) * cos(((this->getAnguloFinal()) * (M_PI / 180))) * this->velocidade * tempoAjustador);
  GLfloat cy = this->getY() + (cos(this->getAnguloProjetilVertical() * (M_PI / 180)) * sin(((this->getAnguloFinal()) * (M_PI / 180))) * this->velocidade * tempoAjustador);
  GLfloat cz = this->getZ() + (sin(this->getAnguloProjetilVertical() * (M_PI / 180)) * this->velocidade * tempoAjustador);
	this->setX(cx);
	this->setY(cy);
  this->setZ(cz);
}
