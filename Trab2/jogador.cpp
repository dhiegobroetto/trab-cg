#include "jogador.h"

Jogador::Jogador(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB){
	this->id = id;
    this->raio = raio;
    this->x = x;
    this->y = y;
    this->corR = corR;
    this->corG = corG;
    this->corB = corB;
	this->ligado = false;
	this->voando = false;
	this->tempoDecolagem = 0.0;
	this->distanciaPontos = 0.0;
	this->raioInicial = raio;
	this->tempoRaio = 0.0;
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
GLfloat Jogador::getTempoAjustador(){
	return this->tempoAjustador;
}
void Jogador::setTempoAjustador(GLfloat& tempoAjustador){
	this->tempoAjustador = tempoAjustador;
}
GLfloat Jogador::getVelocidade(){
	return this->velocidade;
}
void Jogador::setVelocidade(GLfloat velocidade){
	this->velocidade = velocidade;
}
GLfloat Jogador::getPontoCrescimento(){
	return this->pontoCrescimento;
}
void Jogador::setPontoCrescimento(GLfloat pontoCrescimento){
	this->pontoCrescimento = pontoCrescimento;
}
GLfloat Jogador::getTempoDecolagem(){
	return this->tempoDecolagem;
}
void Jogador::setTempoDecolagem(GLfloat tempoDecolagem){
	this->tempoDecolagem = tempoDecolagem;
}
GLfloat Jogador::getDistanciaPontos(){
	return this->distanciaPontos;
}
void Jogador::setDistanciaPontos(GLfloat distanciaPontos){
	this->distanciaPontos = distanciaPontos;
}
GLfloat Jogador::getRaioInicial() {
    return this->raioInicial;
}
void Jogador::setRaioInicial(GLfloat& raioInicial) {
    this->raioInicial = raioInicial;
}
bool Jogador::isLigado(){
	return this->ligado;
}
void Jogador::setLigado(bool ligado){
	this->ligado = ligado;
}
bool Jogador::isVoando(){
	return this->voando;
}
void Jogador::setVoando(bool voando){
	this->voando = voando;
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
    this->x += x * this->tempoMultiplicador * this->tempoAjustador;
}
void Jogador::moveY(GLfloat y){
    this->y += y * this->tempoMultiplicador * this->tempoAjustador;
}
void Jogador::decola(Linha* linha, GLfloat tempoAntigo){
	if(this->ligado && !this->voando){
		// S = So + Vo * t + (a * t^2)/2
		GLfloat tempo = 4.0;

		GLfloat dx = linha->getX2() - linha->getX1();
		GLfloat x = 2 * dx / pow(tempo, 2);

		GLfloat dy = linha->getY2() - linha->getY1();
		GLfloat y = 2 * dy / pow(tempo, 2);

		GLfloat x1 = linha->getX1() + (x * pow(this->tempoDecolagem, 2)) / 2;
		GLfloat y1 = linha->getY1() + (y * pow(this->tempoDecolagem, 2)) / 2;
		this->setX(x1);
		this->setY(y1);
		this->distanciaPontos = this->distanciaEntrePontos(this->x, this->y, linha->getX2(), linha->getY2());
		if(this->distanciaPontos <= this->pontoCrescimento and this->ligado and !this->voando){
			GLfloat	velocidadeRaio = 0.0;
			if(this->tempoRaio == 0.0){
				this->tempoRaio = (glutGet(GLUT_ELAPSED_TIME) / 1000.0) - tempoAntigo;
			}
			if(this->tempoDecolagem > this->tempoRaio){
				// V = S / t
				velocidadeRaio = this->raioInicial / (tempo - this->tempoRaio);
			}
			
			// s = so + vt
			GLfloat passoRaio = velocidadeRaio * (this->tempoDecolagem - this->tempoRaio);
			GLfloat raioCrescente = this->raioInicial + passoRaio;
			this->setRaio(raioCrescente);
		}
	
		if(this->distanciaPontos <= 1 or this->tempoDecolagem >= 4.0){
			GLfloat vel = sqrt(pow(x, 2) + pow(y, 2)) * 4.0;
			this->setVelocidade(vel);
			this->setVoando(true);
			GLfloat raioFinal = this->raioInicial * 2;
			this->setRaio(raioFinal);
		}
	}
}
GLfloat Jogador::distanciaCirculos(Circulo *c, GLfloat x, GLfloat y){
    return sqrt(pow((c->getX() - x), 2) + pow((c->getY() - y), 2));
}
GLfloat Jogador::distanciaEntrePontos(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2){
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
void Jogador::calculaPontoCrescimento(Linha* linha){
	GLfloat pontoCrescimento = this->distanciaEntrePontos(linha->getX1(), linha->getY1(), linha->getX2(), linha->getY2()) / 2.0;
	this->pontoCrescimento = pontoCrescimento;
}