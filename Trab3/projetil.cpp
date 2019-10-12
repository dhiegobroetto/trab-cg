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
		glRotatef(this->getAnguloJogadorBase(), 0.0, 0.0, 1.0);
		glTranslatef(0.0, this->baseCanhao, 0);
		glRotatef(this->anguloProjetil, 0.0, 0.0, 1.0);
		glTranslatef(0.0, this->alturaCanhao, 0);
		desenhaQuadrado(this->base, this->altura, this->corR, this->corG, this->corB);
	glPopMatrix();
}	

// void Projetil::moveX(GLfloat x){
// 	// GLfloat cx = this->getX() + (x * this->tempoMultiplicador * this->tempoAjustador);
//     // GLfloat cy = this->getY();

//     // if(verificaColisao(cx, cy)){
//     	// this->setX(cx);
// 		this->anguloProjetil += x;
// 	// }
// }

// void Projetil::moveY(GLfloat y){
// 	GLfloat cx = this->getX();
//     GLfloat cy = this->getY() + (y * this->tempoMultiplicador * this->tempoAjustador);

//     if(verificaColisao(cx, cy)){
//     	this->setY(cy);
// 		this->anguloHelice += 5;
// 	}
// }

void Projetil::voa(){
	GLfloat cx = this->getX() + (cos(((this->getAnguloFinal()) * (M_PI / 180))) * this->velocidade);
    GLfloat cy = this->getY() + (sin(((this->getAnguloFinal()) * (M_PI / 180))) * this->velocidade);
	if(verificaColisao(cx, cy)){
    	this->setX(cx);
		this->setY(cy);
	}
}

bool Projetil::verificaColisao(GLfloat x, GLfloat y){
	// GLfloat distanciaBorda = this->distanciaEntrePontos(this->arena->getX(), this->arena->getY(), x, y);
	
	// Verifica colisão da borda
    // if ((distanciaBorda) > this->arena->getRaio()) {
	// 	this->atravessaBorda();
		// this->x = cos((this->getAnguloProjetil() * (M_PI / 180)) + 180) * this->arena->getRaio();
		// this->y = sin((this->getAnguloProjetil() * (M_PI / 180)) + 180) * this->arena->getRaio();
    //     return false;
    // }

	// Verifica colisão com inimigos aéreos
    // for (auto inimigo : this->arena->getInimigosAereos()) {
    //     GLfloat distanciaInimigo = this->distanciaEntrePontos(inimigo->getX(), inimigo->getY(), x, y);
    //     if ((distanciaInimigo <= (inimigo->getRaio() + getRaio()))  voando) {
    //         return false;
    //     }
    // }
	// return true;
}
