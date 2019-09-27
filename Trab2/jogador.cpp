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
GLfloat Jogador::getTempoMultiplicador(){
	return this->tempoMultiplicador;
}
void Jogador::setTempoMultiplicador(GLfloat& tempoMultiplicador){
	this->tempoMultiplicador = tempoMultiplicador;
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
	// S = So + Vo * t + (a * t^2)/2
    GLfloat tempo = 4.0;

    GLfloat dy = linha->getY2() - linha->getY1();
    GLfloat y = 2 * dy / pow(tempo, 2);

    GLfloat dx = linha->getX2() - linha->getX1();
    GLfloat x = 2 * dx / pow(tempo, 2);

	GLfloat y1 = linha->getY1() + (y * pow(this->tempoMultiplicador / 1000.0, 2)) / 2;
	GLfloat x1 = linha->getX1() + (x * pow(this->tempoMultiplicador / 1000.0, 2)) / 2;
    this->setY(y1);
    this->setX(x1);
}