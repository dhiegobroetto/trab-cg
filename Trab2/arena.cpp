#include "arena.h"

Arena::Arena(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB){
	this->id = id;
    this->raio = raio;
    this->x = x;
    this->y = y;
    this->corR = corR;
    this->corG = corG;
    this->corB = corB;
}

GLint Arena::getId(){
	return this->id;
}
void Arena::setId(GLint& id){
	this->id = id;
}

GLfloat Arena::getRaio() {
    return this->raio;
}

void Arena::setRaio(GLfloat& raio) {
    this->raio = raio;
}

GLfloat Arena::getX(){
	return this->x;
}
void Arena::setX(GLfloat& x){
	this->x = x;
}
GLfloat Arena::getY(){
	return this->y;
}
void Arena::setY(GLfloat& y){
	this->y = y;
}
GLfloat Arena::getCorR(){
	return this->corR;
}
void Arena::setCorR(GLfloat& corR){
	this->corR = corR;
}
GLfloat Arena::getCorG(){
	return this->corG;
}
void Arena::setCorG(GLfloat& corG){
	this->corG = corG;
}
GLfloat Arena::getCorB(){
	return this->corB;
}
void Arena::setCorB(GLfloat& corB){
	this->corB = corB;
}
GLfloat Arena::getVelocidade(){
	return this->velocidade;
}
void Arena::setVelocidade(GLfloat velocidade){
	this->velocidade = velocidade;
}

void Arena::desenhaArena(){
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
void Arena::moveX(GLfloat x){
    this->x += x;
}
void Arena::moveY(GLfloat y){
    this->y += y;
}
void Arena::decola(Linha* linha){
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
		this->desenhaArena();
	}
}