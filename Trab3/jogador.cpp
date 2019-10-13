#include "jogador.h"

Jogador::Jogador(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB, Arena* arena){
	this->id = id;
    this->raio = raio;
    this->x = x;
    this->y = y;
	this->xInicial = x;
	this->yInicial = y;
    this->corR = corR;
    this->corG = corG;
    this->corB = corB;
	this->ligado = false;
	this->voando = false;
	this->distanciaPontos = 0.0;
	this->raioInicial = raio;
	this->tempoRaio = 0.0;
	this->arena = arena;
	this->anguloJogador = 0.0;
	this->anguloCanhao = 0.0;
	this->anguloHelice = 0.0;
	this->mouseX = 0.0;
}
static char str[2000];
void * fonte = GLUT_BITMAP_TIMES_ROMAN_24;

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

Arena* Jogador::getArena(){
	return this->arena;
}

void Jogador::setArena(Arena* arena){
	this->arena = arena;
}

void Jogador::addProjetil(Projetil *p){
	this->projeteis.push_back(p);
}

GLfloat Jogador::getAnguloJogador(){
	return this->anguloJogador + 90;
}

void Jogador::setAnguloJogador(GLfloat anguloJogador){
	this->anguloJogador = anguloJogador;
}

GLfloat Jogador::getAnguloCanhao(){
	return this->anguloCanhao;
}

void Jogador::setAnguloCanhao(GLfloat anguloCanhao){
	this->anguloCanhao += anguloCanhao;
}

GLfloat Jogador::getMouseX(){
	return this->mouseX;
}

void Jogador::setMouseX(GLfloat mouseX){
	this->mouseX = mouseX;
}

GLfloat Jogador::getLimiteCanhaoX(){
	return this->limiteCanhaoX;
}

void Jogador::setLimiteCanhaoX(GLfloat limiteCanhaoX){
	this->limiteCanhaoX = limiteCanhaoX;
}

GLfloat Jogador::getLimiteCanhaoY(){
	return this->limiteCanhaoY;
}

void Jogador::setLimiteCanhaoY(GLfloat limiteCanhaoY){
	this->limiteCanhaoY = limiteCanhaoY;
}

void Jogador::desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB){
    float theta, px, py;
    glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			theta = (i * M_PI) / 180.0;
			px = cos(theta) * raio;
			py = sin(theta) * raio;
			glVertex2f(px, py);
		}
	glEnd();
}

void Jogador::exibeTexto(GLfloat x, GLfloat y){
    // Cria string para printar na tela.
    char *strTemporaria;
    sprintf(str, "Raio: %.2f X: %.2f Y: %.2f", this->getRaio(), this->getX(), this->getY());
    // Posição do texto na tela
    glRasterPos2f(x, y);
    strTemporaria = str;
    // Printa cada caractere na tela através da função glutBitmapCharacter.
    while( *strTemporaria ){
        glutBitmapCharacter(fonte, *strTemporaria);
        strTemporaria++;
    }
}

void Jogador::desenhaQuadrado(GLfloat base, GLfloat altura){
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3f(base/2, 0.0, 0.0);
		glVertex3f(base/2, altura, 0.0);
		glVertex3f(-base/2, altura, 0.0);
		glVertex3f(-base/2, 0.0, 0.0);
	glEnd();
}

void Jogador::desenhaTriangulo(GLfloat tamanho){
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(-tamanho, -tamanho/2, 0.0);
		glVertex3f(-tamanho, tamanho, 0.0);
	glEnd();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(tamanho, -tamanho/2, 0.0);
		glVertex3f(tamanho, tamanho, 0.0);
	glEnd();
}

void Jogador::desenhaAsa(int asa){
		glColor3f(0.0, 0.0, 0.0);
		if(asa == 0){
			glBegin(GL_POLYGON);
				glVertex3f(this->raio/4, 0.0, 0.0);
				glVertex3f(this->raio/4, this->raio/2, 0.0);
				glVertex3f(-this->raio/2, this->raio/2, 0.0);
				glVertex3f(-this->raio/2, this->raio/4, 0.0);
			glEnd();
		}else if(asa == 1){
			glBegin(GL_POLYGON);
				glVertex3f(0.0, this->raio/4, 0.0);
				glVertex3f(0.0, this->raio/2, 0.0);
				glVertex3f(-(this->raio/4)*3, this->raio/2, 0.0);
				glVertex3f(-(this->raio/4)*3, 0.0, 0.0);
			glEnd();
		}
}

void Jogador::desenhaHelice(int asa){
	GLfloat angulo = this->anguloHelice;
	glPushMatrix();
		if(asa == 0){
			glTranslatef(-this->raio/8, this->raio/2, 0);
			angulo *= -1;
		}else if (asa == 1){
			glTranslatef((-(this->raio/4)*3)/2, this->raio/2, 0);
		}
		desenhaQuadrado(this->raio/6, this->raio/4);
		glTranslatef(0.0, this->raio/3, 0.0);
		glPushMatrix();
			glRotatef(angulo, 0.0, 1.0, 0.0);
			desenhaTriangulo(this->raio/4);
		glPopMatrix();
		glPushMatrix();
			glRotatef(angulo + 90, 0.0, 1.0, 0.0);
			desenhaTriangulo(this->raio/4);
		glPopMatrix();
		glPushMatrix();
			glRotatef(angulo + 180, 0.0, 1.0, 0.0);
			desenhaTriangulo(this->raio/4);
		glPopMatrix();
		glPushMatrix();
			glRotatef(angulo + 270, 0.0, 1.0, 0.0);
			desenhaTriangulo(this->raio/4);
		glPopMatrix();
	glPopMatrix();
}

void Jogador::desenhaElipse(GLfloat cx, GLfloat cy){
	glColor3f(corR, corG, corB);
	float x,y,z;
	int t;
	glBegin(GL_POLYGON);
        for(t = 0; t <= 360; t +=1){
			x = cx * sin(t);
			y = cy * cos(t);
			z = 0;
			glVertex3f(x,y,z);
       }
	glEnd();
}

void Jogador::desenhaBase(){
	glPushMatrix();
		desenhaElipse((this->getRaio()/3), this->getRaio());
	glPopMatrix();
}

void Jogador::desenhaAsas(int asa){
	glPushMatrix();
	if(asa == 0)
		glTranslatef(-this->raio/2, -this->raio/3, 0);
	else if(asa == 1)
		glTranslatef(this->raio, -this->raio/3, 0);
		desenhaAsa(asa);
		desenhaHelice(asa);
	glPopMatrix();
	
}

void Jogador::desenhaCanhao(){
	glPushMatrix();
		glTranslatef(0.0, this->raio - 1, 0);
		glRotatef(this->anguloCanhao, 0.0, 0.0, 1.0);
		desenhaQuadrado(this->raio/4, this->raio/2 + 1);
	glPopMatrix();
}

void Jogador::desenhaProjeteis(){
	for(int i = 0; i < projeteis.size(); i++){
		if(this->verificaColisao(projeteis[i]->getX(), projeteis[i]->getY(), true)){
			projeteis[i]->desenhaProjetil();
		}else{
			projeteis.erase(projeteis.begin() + i);
		}
	}
}

void Jogador::desenhaJogador(){
	glPushMatrix();
		glTranslatef(this->x, this->y, 0);
		glRotatef(this->anguloJogador, 0.0, 0.0, 1.0);
		desenhaAsas(0);
		desenhaAsas(1);
		desenhaCanhao();
		desenhaBase();
	glPopMatrix();
	desenhaProjeteis();
	// exibeTexto(0.0, 0.0);
}	

void Jogador::moveX(GLfloat x){
	this->anguloJogador += x;
}

void Jogador::moveY(GLfloat y){
	GLfloat cx = this->getX();
    GLfloat cy = this->getY() + (y * this->tempoMultiplicador * this->tempoAjustador);

    if(verificaColisao(cx, cy, false)){
    	this->setY(cy);
		this->anguloHelice += 5;
	}
}

void Jogador::voa(GLfloat velocidade){
	GLfloat cx = this->getX() + (cos(((this->getAnguloJogador()) * (M_PI / 180))) * velocidade * this->tempoMultiplicador * this->tempoAjustador);
    GLfloat cy = this->getY() + (sin(((this->getAnguloJogador()) * (M_PI / 180))) * velocidade * this->tempoMultiplicador * this->tempoAjustador);
	if(verificaColisao(cx, cy, false)){
    	this->setX(cx);
		this->setY(cy);
		this->anguloHelice += 5;
	}
}

void Jogador::voaProjeteis(){
	for(Projetil *p : this->projeteis){
		p->voa();
	}
}

bool Jogador::verificaColisao(GLfloat x, GLfloat y, bool projetil = false){
	GLfloat distanciaBorda = this->distanciaEntrePontos(this->arena->getX(), this->arena->getY(), x, y);
	
	// Verifica colisão da borda
	if(projetil){ distanciaBorda += this->getRaio(); }
    if ((distanciaBorda) >= this->arena->getRaio()) {
		// this->atravessaBorda();
		// this->x = cos((this->getAnguloJogador() * (M_PI / 180)) + 180) * this->arena->getRaio();
		// this->y = sin((this->getAnguloJogador() * (M_PI / 180)) + 180) * this->arena->getRaio();
        return false;
    }

	// Verifica colisão com inimigos aéreos
	if(!projetil) { 
		for (auto inimigo : this->arena->getInimigosAereos()) {
			GLfloat distanciaInimigo = this->distanciaEntrePontos(x, y, inimigo->getX(), inimigo->getY());
			GLfloat raioInimigo = inimigo->getRaio();
			raioInimigo += this->getRaio(); 
			if ((distanciaInimigo < raioInimigo) && this->isVoando()) {
				return false;
			}
		}
	}
	return true;
}

void Jogador::atravessaBorda(){
	// y - y0 = m * (x - x0)
	// y = m * (x - x0) + y0
	// x^2 + y^2 = r^2
	GLfloat m = tan(this->getAnguloJogador());
	GLfloat x0 = this->x;
	GLfloat y0 = this->y;
	GLfloat r = this->arena->getRaio();
	GLfloat novoX = (-(2 * m * (y0 - m * x0)) + sqrt(pow((2 * m * (y0 - m * x0)), 2) - 4 * (pow(m, 2) + 1) * (pow((y0 - m * x0), 2) - pow(r, 2)))) / (2 * (pow(m, 2) + 1));
	if(abs(novoX - this->x) <= 0.2){
		GLfloat novoX = (-(2 * m * (y0 - m * x0)) - sqrt(pow((2 * m * (y0 - m * x0)), 2) - 4 * (pow(m, 2) + 1) * (pow((y0 - m * x0), 2) - pow(r, 2)))) / (2 * (pow(m, 2) + 1));
	}
	GLfloat novoY = sqrt(pow(r, 2) - pow(novoX, 2));
	this->setX(novoX);
	this->setY(novoY);

}

void Jogador::decola(Linha* linha, GLfloat tempoAntigo, GLfloat tempoDecolagem){
	if(this->ligado && !this->voando){
		// S = So + Vo * t + (a * t^2)/2
		GLfloat tempoFinal = 4.0;

		GLfloat dx = linha->getX2() - linha->getX1();
		GLfloat x = 2 * dx / pow(tempoFinal, 2);

		GLfloat dy = linha->getY2() - linha->getY1();
		GLfloat y = 2 * dy / pow(tempoFinal, 2);

		GLfloat x1 = linha->getX1() + (x * pow(tempoDecolagem, 2)) / 2;
		GLfloat y1 = linha->getY1() + (y * pow(tempoDecolagem, 2)) / 2;
		this->setX(x1);
		this->setY(y1);
		this->distanciaPontos = this->distanciaEntrePontos(this->x, this->y, linha->getX2(), linha->getY2());

		// Subindo voo (dobrando o raio)
		if(this->distanciaPontos <= this->pontoCrescimento and this->ligado and !this->voando){
			GLfloat	velocidadeRaio = 0.0;
			if(this->tempoRaio == 0.0){
				this->tempoRaio = (glutGet(GLUT_ELAPSED_TIME) / 1000.0) - tempoAntigo;
			}
			// V = S / t
			velocidadeRaio = this->raioInicial / (tempoFinal - this->tempoRaio);
			// S = So + Vt
			GLfloat passoRaio = velocidadeRaio * (tempoDecolagem - this->tempoRaio);
			GLfloat raioCrescente = this->raioInicial + passoRaio;
			this->setRaio(raioCrescente);
		}

		// Completado decolagem
		if(this->distanciaPontos <= 1 or tempoDecolagem >= 4.0){
			GLfloat vel = sqrt(pow(x, 2) + pow(y, 2)) * 4.0;
			this->setVelocidade(vel);
			this->setVoando(true);
			GLfloat raioFinal = this->raioInicial * 2;
			this->setRaio(raioFinal);
		}
	}
}

GLfloat Jogador::distanciaEntrePontos(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2){
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void Jogador::calculaPontoCrescimento(Linha* linha){
	GLfloat pontoCrescimento = this->distanciaEntrePontos(linha->getX1(), linha->getY1(), linha->getX2(), linha->getY2()) / 2.0;
	this->pontoCrescimento = pontoCrescimento;
}

void Jogador::calculaAngulo(Linha* linha){
	this->setAnguloJogador(-90 + atan2(linha->getDistanciaY(), linha->getDistanciaX()) * 180 / M_PI);
}