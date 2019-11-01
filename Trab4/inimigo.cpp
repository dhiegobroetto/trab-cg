#include "inimigo.h"

Inimigo::Inimigo(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB, Arena* arena, GLfloat velocidade, GLfloat velocidadeTiro, GLfloat frequenciaTiro){
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
	this->anguloInimigo = 0.0;
	this->anguloCanhao = 0.0;
	this->anguloHelice = 0.0;
	this->mouseX = 0.0;
	this->vivo = true;
	this->velocidade = velocidade;
	this->velocidadeTiro = velocidadeTiro;
	this->frequenciaTiro = frequenciaTiro;
}
// static char str[2000];
// void * fonte = GLUT_BITMAP_TIMES_ROMAN_24;

GLint Inimigo::getId(){
	return this->id;
}

void Inimigo::setId(GLint& id){
	this->id = id;
}

GLfloat Inimigo::getRaio() {
    return this->raio;
}

void Inimigo::setRaio(GLfloat& raio) {
    this->raio = raio;
}

GLfloat Inimigo::getX(){
	return this->x;
}

void Inimigo::setX(GLfloat& x){
	this->x = x;
}

GLfloat Inimigo::getY(){
	return this->y;
}

void Inimigo::setY(GLfloat& y){
	this->y = y;
}

GLfloat Inimigo::getCorR(){
	return this->corR;
}

void Inimigo::setCorR(GLfloat& corR){
	this->corR = corR;
}

GLfloat Inimigo::getCorG(){
	return this->corG;
}

void Inimigo::setCorG(GLfloat& corG){
	this->corG = corG;
}

GLfloat Inimigo::getCorB(){
	return this->corB;
}

void Inimigo::setCorB(GLfloat& corB){
	this->corB = corB;
}

GLfloat Inimigo::getVelocidadeMultiplicadora(){
	return this->velocidadeMultiplicadora;
}

void Inimigo::setVelocidadeMultiplicadora(GLfloat& velocidadeMultiplicadora){
	this->velocidadeMultiplicadora = velocidadeMultiplicadora;
}

GLfloat Inimigo::getVelocidadeTiro(){
	return this->velocidadeTiro;
}

void Inimigo::setVelocidadeTiro(GLfloat& velocidadeTiro){
	this->velocidadeTiro = velocidadeTiro;
}

GLfloat Inimigo::getFrequenciaTiro(){
	return this->frequenciaTiro;
}

void Inimigo::setFrequenciaTiro(GLfloat& frequenciaTiro){
	this->frequenciaTiro = frequenciaTiro;
}

GLfloat Inimigo::getTempoAjustador(){
	return this->tempoAjustador;
}

void Inimigo::setTempoAjustador(GLfloat& tempoAjustador){
	this->tempoAjustador = tempoAjustador;
}

GLfloat Inimigo::getVelocidade(){
	return this->velocidade;
}

void Inimigo::setVelocidade(GLfloat velocidade){
	this->velocidade = velocidade;
}

void Inimigo::incrementaVelocidade(GLfloat velocidade){
	this->velocidade += velocidade;
}

void Inimigo::decrementaVelocidade(GLfloat velocidade){
	this->velocidade -= velocidade;
	if(this->velocidade < 0){
		this->velocidade = 0;
	}
}

GLfloat Inimigo::getPontoCrescimento(){
	return this->pontoCrescimento;
}

void Inimigo::setPontoCrescimento(GLfloat pontoCrescimento){
	this->pontoCrescimento = pontoCrescimento;
}

GLfloat Inimigo::getDistanciaPontos(){
	return this->distanciaPontos;
}

void Inimigo::setDistanciaPontos(GLfloat distanciaPontos){
	this->distanciaPontos = distanciaPontos;
}

GLfloat Inimigo::getRaioInicial() {
    return this->raioInicial;
}

void Inimigo::setRaioInicial(GLfloat& raioInicial) {
    this->raioInicial = raioInicial;
}

bool Inimigo::isLigado(){
	return this->ligado;
}

void Inimigo::setLigado(bool ligado){
	this->ligado = ligado;
}

bool Inimigo::isVoando(){
	return this->voando;
}

void Inimigo::setVoando(bool voando){
	this->voando = voando;
}

bool Inimigo::isVivo(){
	return this->vivo;
}

void Inimigo::vive(){
	this->vivo = true;
}

void Inimigo::morre(){
	this->vivo = false;
}

Arena* Inimigo::getArena(){
	return this->arena;
}

void Inimigo::setArena(Arena* arena){
	this->arena = arena;
}

void Inimigo::addProjetil(Projetil *p){
	this->projeteis.push_back(p);
}

GLfloat Inimigo::getAnguloInimigo(){
	return this->anguloInimigo + 90;
}

void Inimigo::setAnguloInimigo(GLfloat anguloInimigo){
	this->anguloInimigo = anguloInimigo;
}

GLfloat Inimigo::getAnguloCanhao(){
	return this->anguloCanhao;
}

void Inimigo::setAnguloCanhao(GLfloat anguloCanhao){
	this->anguloCanhao += anguloCanhao;
}

GLfloat Inimigo::getMouseX(){
	return this->mouseX;
}

void Inimigo::setMouseX(GLfloat mouseX){
	this->mouseX = mouseX;
}

GLfloat Inimigo::getLimiteCanhaoX(){
	return this->limiteCanhaoX;
}

void Inimigo::setLimiteCanhaoX(GLfloat limiteCanhaoX){
	this->limiteCanhaoX = limiteCanhaoX;
}

GLfloat Inimigo::getLimiteCanhaoY(){
	return this->limiteCanhaoY;
}

void Inimigo::setLimiteCanhaoY(GLfloat limiteCanhaoY){
	this->limiteCanhaoY = limiteCanhaoY;
}

void Inimigo::desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB){
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

// void Inimigo::exibeTexto(GLfloat x, GLfloat y){
//     // Cria string para printar na tela.
//     char *strTemporaria;
//     sprintf(str, "Raio: %.2f X: %.2f Y: %.2f", this->getRaio(), this->getX(), this->getY());
//     // Posição do texto na tela
//     glRasterPos2f(x, y);
//     strTemporaria = str;
//     // Printa cada caractere na tela através da função glutBitmapCharacter.
//     while( *strTemporaria ){
//         glutBitmapCharacter(fonte, *strTemporaria);
//         strTemporaria++;
//     }
// }

// void Inimigo::exibeDecolagem(GLfloat x, GLfloat y){
// 	char *strTemporaria;
// 	char decolagem[50];
// 	glColor3f(0.0,0.0,0.0);
//     sprintf(decolagem, "Pressione U para decolar.");
//     glRasterPos2f(x, y);
//     strTemporaria = decolagem;
//     while( *strTemporaria ){
//         glutBitmapCharacter(fonte, *strTemporaria);
//         strTemporaria++;
//     }
// }

// void Inimigo::exibeGameOver(GLfloat x, GLfloat y){
// 	char *strTemporaria;
// 	char gameOver[80];
// 	glColor3f(0.0,0.0,0.0);
//     sprintf(gameOver, "Game Over!\n\nPressione R para tentar novamente!");
//     glRasterPos2f(x, y);
//     strTemporaria = gameOver;
//     while( *strTemporaria ){
//         glutBitmapCharacter(fonte, *strTemporaria);
//         strTemporaria++;
//     }
// }

void Inimigo::desenhaQuadrado(GLfloat base, GLfloat altura, GLfloat corR, GLfloat corG, GLfloat corB){
	glColor3f(corR, corG, corB);
	glBegin(GL_POLYGON);
		glVertex3f(base/2, 0.0, 0.0);
		glVertex3f(base/2, altura, 0.0);
		glVertex3f(-base/2, altura, 0.0);
		glVertex3f(-base/2, 0.0, 0.0);
	glEnd();
}

void Inimigo::desenhaTriangulo(GLfloat tamanho){
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(-tamanho, -tamanho/2, 0.0);
		glVertex3f(-tamanho, tamanho/2, 0.0);
	glEnd();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(tamanho, -tamanho/2, 0.0);
		glVertex3f(tamanho, tamanho/2, 0.0);
	glEnd();
}

void Inimigo::desenhaAsa(int asa){
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

void Inimigo::desenhaAerodinamica(GLfloat tamanho, GLfloat corR, GLfloat corG, GLfloat corB){
	glColor3f(corR, corG, corB);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0, tamanho, 0.0);
		glVertex3f(tamanho, 0.0, 0.0);
		glVertex3f(-tamanho, 0.0, 0.0);
	glEnd();
}


void Inimigo::desenhaHelice(int asa){
	GLfloat angulo = this->anguloHelice;
	glPushMatrix();
		if(asa == 0){
			glTranslatef(-this->raio/8, this->raio/2, 0);
			angulo *= -1;
		}else if (asa == 1){
			glTranslatef((-(this->raio/4)*3)/2, this->raio/2, 0);
		}
		desenhaQuadrado(this->raio/6, this->raio/4, 0.0, 0.0, 0.0);
		glTranslatef(0.0, this->raio/4, 0.0);
			glRotatef(angulo, 0.0, 1.0, 0.0);
			desenhaTriangulo(this->raio/4);
			glRotatef(-angulo, 0.0, 1.0, 0.0);
		
			glRotatef(angulo + 90, 0.0, 1.0, 0.0);
			desenhaTriangulo(this->raio/4);
			glRotatef(-(angulo + 90), 0.0, 1.0, 0.0);
		
			glRotatef(angulo + 180, 0.0, 1.0, 0.0);
			desenhaTriangulo(this->raio/4);
			glRotatef(-(angulo + 180), 0.0, 1.0, 0.0);
		
			glRotatef(angulo + 270, 0.0, 1.0, 0.0);
			desenhaTriangulo(this->raio/4);
			glRotatef(-(angulo + 270), 0.0, 1.0, 0.0);
	glPopMatrix();
}


void Inimigo::desenhaElipseBorda(GLfloat cx, GLfloat cy, GLfloat corR, GLfloat corG, GLfloat corB){
	glColor3f(corR, corG, corB);
	float x,y,z;
	int t;
	glPointSize(1.0);
	glBegin(GL_POINTS);
        for(t = 0; t <= 360; t +=20){
			x = cx * sin(t);
			y = cy * cos(t);
			z = 0;
			glVertex3f(x,y,z);
       }
	glEnd();
}

void Inimigo::desenhaElipse(GLfloat cx, GLfloat cy, GLfloat corR, GLfloat corG, GLfloat corB){
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

void Inimigo::desenhaBase(){
	glPushMatrix();
		desenhaElipse((this->getRaio()/3), this->getRaio(), this->getCorR(), this->getCorG(), this->getCorB());
	glPopMatrix();
}

void Inimigo::desenhaAsas(int asa){
	glPushMatrix();
		if(asa == 0){
			glTranslatef(-this->raio/2, -this->raio/3, 0);
		}else if(asa == 1){
			glTranslatef(this->raio, -this->raio/3, 0);
		}
		desenhaAsa(asa);
		desenhaHelice(asa);
	glPopMatrix();
	
}

void Inimigo::desenhaCanhao(){
	glPushMatrix();
		glTranslatef(0.0, this->raio - 1, 0);
		glRotatef(this->anguloCanhao, 0.0, 0.0, 1.0);
		desenhaQuadrado(this->raio/4, this->raio/2 + 1, 0.0, 0.0, 0.0);
	glPopMatrix();
}

void Inimigo::desenhaProjeteis(){
	for(int i = 0; i < projeteis.size(); i++){
		if(this->verificaColisao(projeteis[i]->getX(), projeteis[i]->getY(), true, projeteis[i]->getRaio())){
			projeteis[i]->desenhaProjetil();
		}else{
			projeteis.erase(projeteis.begin() + i);
		}
	}
}

void Inimigo::desenhaInimigo(){
	glPushMatrix();
		glTranslatef(this->x, this->y, 0);
		glRotatef(this->anguloInimigo, 0.0, 0.0, 1.0);
		desenhaAsas(0);
		desenhaAsas(1);
		desenhaCanhao();
		glPushMatrix();
			glTranslatef(0.0, -(this->raio) , 0.0);
			glTranslatef(0.0, this->raio/16, 0.0);
			desenhaAerodinamica(this->raio/2, 0.0, 0.0, 0.0);
		glPopMatrix();
		desenhaBase();
		glPushMatrix();
			glTranslatef(0.0, -this->raio, 0.0);
			desenhaQuadrado(this->raio/8, this->raio/3, 0.0, 0.0, 0.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0, this->raio/2, 0.0);
			desenhaElipse(this->raio/4, this->raio/8, 0.0, 0.0, 0.0);
			desenhaElipseBorda(this->raio/4, this->raio/8, 1.0, 1.0, 1.0);
		glPopMatrix();
	glPopMatrix();
	desenhaProjeteis();
}	

void Inimigo::moveX(GLfloat x){
	this->anguloInimigo += x * this->tempoAjustador;
}

void Inimigo::moveY(GLfloat y){
	GLfloat cx = this->getX();
    GLfloat cy = this->getY() + (y * this->velocidadeMultiplicadora * this->tempoAjustador);

    if(verificaColisao(cx, cy, false, 0.0)){
    	this->setY(cy);
		this->anguloHelice += this->velocidade;
	}
}

void Inimigo::voa(GLfloat velocidade){
	GLfloat cx = this->getX() + (cos(((this->getAnguloInimigo()) * (M_PI / 180))) * velocidade * this->velocidadeMultiplicadora * this->tempoAjustador);
    GLfloat cy = this->getY() + (sin(((this->getAnguloInimigo()) * (M_PI / 180))) * velocidade * this->velocidadeMultiplicadora * this->tempoAjustador);
	if(verificaColisao(cx, cy, false, 0.0)){
    	this->setX(cx);
		this->setY(cy);
		this->anguloHelice += this->velocidade;
	}
}

void Inimigo::voaProjeteis(GLfloat tempoAjustador){
	for(Projetil *p : this->projeteis){
		p->voa(tempoAjustador);
	}
}

bool Inimigo::verificaColisao(GLfloat x, GLfloat y, bool projetil, GLfloat raio){
	GLfloat distanciaBorda = this->distanciaEntrePontos(this->arena->getX(), this->arena->getY(), x, y);
	
	// Verifica colisão da borda
	if(raio != 0){
		distanciaBorda += raio;
	}
    if ((distanciaBorda) >= this->arena->getRaio()) {
		if(!projetil){
			this->atravessaBorda();
		}
        return false;
    }

	// Verifica colisão com inimigos aéreos
	// if(!projetil) { 
	// 	for (auto inimigo : this->arena->getInimigosAereos()) {
	// 		GLfloat distanciaInimigo = this->distanciaEntrePontos(x, y, inimigo->getX(), inimigo->getY());
	// 		GLfloat raioInimigo = inimigo->getRaio();
	// 		raioInimigo += this->getRaio(); 
	// 		if ((distanciaInimigo < raioInimigo) && this->isVoando()) {
	// 			this->morre();
	// 			return false;
	// 		}
	// 	}
	// }
	return true;
}

void Inimigo::atravessaBorda(){
	GLfloat cx = this->getX();
    GLfloat cy = this->getY();
    GLfloat alpha = atan2(cy, cx) * 180 / M_PI;
    GLfloat theta = (-2 * (alpha - this->anguloInimigo)) * M_PI / 180;
    GLfloat novoX = (cx * cos(theta)) - (cy * sin(theta));
	GLfloat novoY = (cx * sin(theta)) + (cy * cos(theta));
	this->setX(novoX);
	this->setY(novoY);
}

void Inimigo::decola(Linha* linha, GLfloat tempoAntigo, GLfloat tempoDecolagem){
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
		GLfloat aceleracao = (this->distanciaPontos/tempoFinal);
		this->anguloHelice = this->anguloHelice + aceleracao * tempoDecolagem;

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

GLfloat Inimigo::distanciaEntrePontos(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2){
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void Inimigo::calculaPontoCrescimento(Linha* linha){
	GLfloat pontoCrescimento = this->distanciaEntrePontos(linha->getX1(), linha->getY1(), linha->getX2(), linha->getY2()) / 2.0;
	this->pontoCrescimento = pontoCrescimento;
}

void Inimigo::calculaAngulo(Linha* linha){
	this->setAnguloInimigo(-90 + atan2(linha->getDistanciaY(), linha->getDistanciaX()) * 180 / M_PI);
}

void Inimigo::reseta(){
	this->x = this->xInicial;
	this->y = this->yInicial;
	this->ligado = false;
	this->voando = false;
	this->distanciaPontos = 0.0;
	this->raio = raioInicial;
	this->tempoRaio = 0.0;
	this->calculaAngulo(this->getArena()->getLinha());
	this->anguloCanhao = 0.0;
	this->anguloHelice = 0.0;
	this->mouseX = 0.0;
	this->velocidade = 0.0;
	this->projeteis.clear();
	this->vive();
}