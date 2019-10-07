#include "jogador.h"

Jogador::Jogador(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB, Arena* arena){
	this->id = id;
    this->raio = raio;
    this->x = x;
    this->y = y;
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

GLfloat Jogador::getAnguloJogador(){
	return this->anguloJogador + 90;
}

void Jogador::setAnguloJogador(GLfloat anguloJogador){
	this->anguloJogador = anguloJogador;
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
    sprintf(str, "Raio: %.2f", this->getRaio());
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
	glPushMatrix();
		if(asa == 0){
			glTranslatef(-this->raio/8, this->raio/2, 0);
		}else if (asa == 1){
			glTranslatef((-(this->raio/4)*3)/2, this->raio/2, 0);
		}
		desenhaQuadrado(this->raio/6, this->raio/4);
		glTranslatef(0.0, this->raio/3, 0.0);
		glPushMatrix();
			glRotatef(this->anguloHelice, 0.0, 1.0, 0.0);
			desenhaTriangulo(this->raio/4);
		glPopMatrix();
		glPushMatrix();
			glRotatef(this->anguloHelice + 90, 0.0, 1.0, 0.0);
			desenhaTriangulo(this->raio/4);
		glPopMatrix();
		glPushMatrix();
			glRotatef(this->anguloHelice + 180, 0.0, 1.0, 0.0);
			desenhaTriangulo(this->raio/4);
		glPopMatrix();
		glPushMatrix();
			glRotatef(this->anguloHelice + 270, 0.0, 1.0, 0.0);
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

void Jogador::desenhaJogador(){
	glPushMatrix();
		glTranslatef(this->x, this->y, 0);
		glRotatef(this->anguloJogador, 0.0, 0.0, 1.0);
		desenhaAsas(0);
		desenhaAsas(1);
		desenhaCanhao();
		desenhaBase();
	glPopMatrix();
	exibeTexto(200.0, -200.0);
}	

void Jogador::moveX(GLfloat x){
	// GLfloat cx = this->getX() + (x * this->tempoMultiplicador * this->tempoAjustador);
    // GLfloat cy = this->getY();

    // if(verificaColisao(cx, cy)){
    	// this->setX(cx);
		this->anguloJogador += x;
	// }
}

void Jogador::moveY(GLfloat y){
	GLfloat cx = this->getX();
    GLfloat cy = this->getY() + (y * this->tempoMultiplicador * this->tempoAjustador);

    if(verificaColisao(cx, cy)){
    	this->setY(cy);
		this->anguloHelice += 5;
	}
}

void Jogador::voa(GLfloat velocidade){
	GLfloat cx = this->getX() + (cos(((this->getAnguloJogador()) * (M_PI / 180))) * velocidade * this->tempoMultiplicador * this->tempoAjustador);
    GLfloat cy = this->getY() + (sin(((this->getAnguloJogador()) * (M_PI / 180))) * velocidade * this->tempoMultiplicador * this->tempoAjustador);
	if(verificaColisao(cx, cy)){
    	this->setX(cx);
		this->setY(cy);
		this->anguloHelice += 5;
	}
}

void Jogador::moveXY(GLfloat x, GLfloat y) {
    GLfloat cx = this->getX() + (cos(M_PI / 4) * x * this->tempoMultiplicador * this->tempoAjustador);
    GLfloat cy = this->getY() + (sin(M_PI / 4) * y * this->tempoMultiplicador * this->tempoAjustador);

    if(verificaColisao(cx, cy)){
    	this->setX(cx);
		this->setY(cy);
	}
}

bool Jogador::verificaColisao(GLfloat x, GLfloat y){
	GLfloat distanciaBorda = this->distanciaEntrePontos(this->arena->getX(), this->arena->getY(), x, y);
	
	// Verifica colisão da borda
    if ((distanciaBorda + this->raio) > this->arena->getRaio()) {
        return false;
    }

	// Verifica colisão com inimigos aéreos
    for (auto inimigo : this->arena->getInimigosAereos()) {
        GLfloat distanciaInimigo = this->distanciaEntrePontos(inimigo->getX(), inimigo->getY(), x, y);
        if ((distanciaInimigo <= (inimigo->getRaio() + getRaio())) && voando) {
            return false;
        }
    }
	return true;
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