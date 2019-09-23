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
void Circulo::setVelocidade(GLfloat& velocidade){
	this->velocidade = velocidade;
}

void Circulo::desenha(){
	glPushMatrix();
	desenhaCirculo(this->raio, this->x, this->y, this->corR, this->corG, this->corB);
	glPopMatrix();
}

void Circulo::desenhaCirculo(GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB){
	float theta, px, py;
    glTranslatef(x, y, 0);
	glColor3f(this->getCorR(), this->getCorG(), this->getCorB());
	glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			theta = (i * M_PI) / 180.0;
			px = cos(theta) * this->getRaio();
			py = sin(theta) * this->getRaio();
			glVertex2f(px, py);
		}
	glEnd();
}	
void Circulo::moveX(GLfloat x){
    this->x += x;
}
void Circulo::moveY(GLfloat y){
    this->y += y;
}
void Circulo::decola(Linha* linha){
	std::cout << this->x << endl;
	this->moveX(1.0);
	this->desenhaCirculo(this->raio, this->x, this->y, this->corR, this->corG, this->corB);
}