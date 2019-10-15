#include "projetil.h"

Projetil::Projetil(GLfloat x, GLfloat y, GLfloat base, GLfloat altura, GLfloat corR, GLfloat corG, GLfloat corB, GLfloat velocidade, GLfloat anguloProjetil, GLfloat anguloJogadorBase, GLfloat alturaCanhao, GLfloat baseCanhao){
    this->x = x;
    this->y = y;
    this->base = base;
    this->altura = altura;
    this->corR = corR;
    this->corG = corG;
    this->corB = corB;
	this->velocidade = velocidade;
    this->anguloProjetil = anguloProjetil;
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

GLfloat Projetil::getBase(){
	return this->base;
}

void Projetil::setBase(GLfloat base){
	this->base = base;
}

GLfloat Projetil::getAltura(){
	return this->altura;
}

void Projetil::setAltura(GLfloat altura){
	this->altura = altura;
}

GLfloat Projetil::getY(){
	return this->y;
}

void Projetil::setY(GLfloat y){
	this->y = y;
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

void Projetil::desenhaQuadrado(GLfloat base, GLfloat altura, GLfloat corR, GLfloat corG, GLfloat corB){
    float theta, px, py;
    glColor3f(corR, corG, corB);
	glBegin(GL_POLYGON);
        glVertex3f(base/2, -altura/2, 0.0);
        glVertex3f(base/2, altura/2, 0.0);
        glVertex3f(-base/2, altura/2, 0.0);
        glVertex3f(-base/2, -altura/2, 0.0);
    glEnd();
}

void Projetil::desenhaProjetil(){
	glPushMatrix();
		glTranslatef(this->x, this->y, 0);
		// glRotatef(this->getAnguloJogadorBase(), 0.0, 0.0, 1.0);
		// glTranslatef(0.0, this->baseCanhao, 0);
		glRotatef(this->anguloProjetil, 0.0, 0.0, 1.0);
		// glTranslatef(0.0, this->alturaCanhao, 0);
		desenhaQuadrado(this->base, this->altura, this->corR, this->corG, this->corB);
	glPopMatrix();
}

void Projetil::voa(){
	GLfloat cx = this->getX() + (cos(((this->getAnguloFinal()) * (M_PI / 180))) * this->velocidade);
    GLfloat cy = this->getY() + (sin(((this->getAnguloFinal()) * (M_PI / 180))) * this->velocidade);
	this->setX(cx);
	this->setY(cy);
}