#include "circulo.h"

Circulo::Circulo(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB){
	this->id = id;
    this->raio = raio;
    this->x = x;
    this->y = y;
	this->z = 0;
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
GLfloat Circulo::getZ(){
	return this->z;
}
void Circulo::setZ(GLfloat& z){
	this->z = z;
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

void Circulo::desenha(GLuint textura){
	glPushMatrix();
		GLfloat base = this->raio * 0.5;
		glColor3f(this->corR, this->corG, this->corB);
		// GLfloat tamanhoCilindro = base*0.6;
		glTranslatef(this->x, this->y, 0);
		// glTranslatef(base/2, base/2, 0);
		glEnable(GL_TEXTURE_2D);
			defineCor(1.0, 1.0, 1.0);
			glMatrixMode(GL_TEXTURE);
				glPushMatrix();
					glScalef(1.0, 2.0, 1.0);
					glBindTexture(GL_TEXTURE_2D, textura);
					// Base da arena
					GLUquadric* obj = gluNewQuadric();
				    gluQuadricOrientation(obj, GLU_OUTSIDE);
				    gluQuadricTexture(obj, GLU_TRUE);
				    gluQuadricDrawStyle(obj, GLU_FILL);
				    gluQuadricNormals(obj, GLU_SMOOTH);
					gluSphere(obj, this->raio, 30, 30);
					gluDeleteQuadric(obj);
				glPopMatrix();
    		glMatrixMode(GL_MODELVIEW);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Circulo::desenhaQuadrado(GLfloat base, GLfloat corR, GLfloat corG, GLfloat corB){
	defineCor(corR, corG, corB);
	glBegin(GL_POLYGON);
		glVertex3f(base, -base, 0.0);
		glVertex3f(base, base, 0.0);
		glVertex3f(-base, base, 0.0);
		glVertex3f(-base, -base, 0.0);
	glEnd();
}

void Circulo::desenhaQuadradoLinha(GLfloat base, GLfloat corR, GLfloat corG, GLfloat corB){
	defineCor(corR, corG, corB);
	glPointSize(1.0);
	glBegin(GL_LINES);
		glVertex3f(base, -base, 0.0);
		glVertex3f(base, base, 0.0);
		glVertex3f(base, base, 0.0);
		glVertex3f(-base, base, 0.0);
		glVertex3f(-base, base, 0.0);
		glVertex3f(-base, -base, 0.0);
		glVertex3f(-base, -base, 0.0);
		glVertex3f(base, -base, 0.0);
	glEnd();
}

void Circulo::desenhaCruz(GLfloat base, GLfloat corR, GLfloat corG, GLfloat corB){
	defineCor(corR, corG, corB);
	glPointSize(1.0);
	glBegin(GL_LINES);
		glVertex3f(0.0, -base, 0.0);
		glVertex3f(0.0, base, 0.0);
		glVertex3f(base, 0.0, 0.0);
		glVertex3f(-base, 0.0, 0.0);
	glEnd();
}

void Circulo::desenhaCirculoLinha(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB){
	float theta, px, py;
	defineCor(corR, corG, corB);
	glPointSize(1.0);
	glBegin(GL_POINTS);
		for (int i = 0; i < 360; i++) {
			theta = (i * M_PI) / 180.0;
			px = cos(theta) * raio;
			py = sin(theta) * raio;
			glVertex2f(px, py);
		}
	glEnd();
}

void Circulo::desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB){
	float theta, px, py;
	glPushMatrix();
		defineCor(corR, corG, corB);
		glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i++) {
				theta = (i * M_PI) / 180.0;
				px = cos(theta) * raio;
				py = sin(theta) * raio;
				glVertex2f(px, py);
			}
		glEnd();
		this->desenhaCirculoLinha(raio, 1, 1, 1);
	glPopMatrix();
}