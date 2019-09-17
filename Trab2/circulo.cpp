#include "circulo.h"

Circulo::Circulo(float& raio, float& x, float& y, float& corR, float& corG, float& corB){
    this->raio = raio;
    this->x = x;
    this->y = y;
    this->corR = corR;
    this->corG = corG;
    this->corB = corB;
}

float Circulo::getRaio() {
    return this->raio;
}

void Circulo::setRaio(float& raio) {
    this->raio = raio;
}

float Circulo::getX(){
	return this->x;
}
void Circulo::setX(float& x){
	this->x = x;
}
float Circulo::getY(){
	return this->y;
}
void Circulo::setY(float& y){
	this->y = y;
}
float Circulo::getCorR(){
	return this->corR;
}
void Circulo::setCorR(float& corR){
	this->corR = corR;
}
float Circulo::getCorG(){
	return this->corG;
}
void Circulo::setCorG(float& corG){
	this->corG = corG;
}
float Circulo::getCorB(){
	return this->corB;
}
void Circulo::setCorB(float& corB){
	this->corB = corB;
}
