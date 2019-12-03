#include "jogador.h"

Jogador::Jogador(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB, Arena* arena){
	this->id = id;
    this->raio = raio;
    this->x = x;
    this->y = y;
		this->z = 0;
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
	this->anguloJogadorVertical = 0.0;
	this->anguloCanhao = 0.0;
	this->anguloHelice = 0.0;
	this->mouseX = 0.0;
	this->vivo = true;
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

GLfloat Jogador::getZ(){
	return this->z;
}

void Jogador::setZ(GLfloat& z){
	this->z = z;
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

GLfloat Jogador::getVelocidadeMultiplicadora(){
	return this->velocidadeMultiplicadora;
}

void Jogador::setVelocidadeMultiplicadora(GLfloat& velocidadeMultiplicadora){
	this->velocidadeMultiplicadora = velocidadeMultiplicadora;
}

GLfloat Jogador::getVelocidadeTiro(){
	return this->velocidadeTiro;
}

void Jogador::setVelocidadeTiro(GLfloat& velocidadeTiro){
	this->velocidadeTiro = velocidadeTiro;
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

void Jogador::incrementaVelocidade(GLfloat velocidade){
	this->velocidade += velocidade;
}

void Jogador::decrementaVelocidade(GLfloat velocidade){
	this->velocidade -= velocidade;
	if(this->velocidade < 0){
		this->velocidade = 0;
	}
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

bool Jogador::isVivo(){
	return this->vivo;
}

void Jogador::vive(){
	this->vivo = true;
}

void Jogador::morre(){
	this->vivo = false;
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

void Jogador::addBomba(Bomba *b){
	this->bombas.push_back(b);
}

GLfloat Jogador::getAnguloJogador(){
	return this->anguloJogador + 90;
}

void Jogador::setAnguloJogador(GLfloat anguloJogador){
	this->anguloJogador = anguloJogador;
}

GLfloat Jogador::getAnguloJogadorVertical(){
	return this->anguloJogadorVertical;
}

void Jogador::setAnguloJogadorVertical(GLfloat anguloJogadorVertical){
	this->anguloJogadorVertical = anguloJogadorVertical;
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
    defineIluminacao(corR, corG, corB);
	glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			theta = (i * M_PI) / 180.0;
			px = cos(theta) * raio;
			py = sin(theta) * raio;
			glVertex2f(px, py);
		}
	glEnd();
}

void Jogador::desenhaQuadrado(GLfloat base, GLfloat altura, GLfloat corR, GLfloat corG, GLfloat corB){
	defineIluminacao(corR, corG, corB);
	glBegin(GL_POLYGON);
		glVertex3f(base/2, 0.0, 0.0);
		glVertex3f(base/2, altura, 0.0);
		glVertex3f(-base/2, altura, 0.0);
		glVertex3f(-base/2, 0.0, 0.0);
	glEnd();
}

void Jogador::desenhaTriangulo(GLfloat tamanho){
    GLfloat corR = 1.0;
    GLfloat corG = 1.0;
    GLfloat corB = 0.0;
    defineIluminacao(corR, corG, corB);
    glBegin(GL_QUADS);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(-tamanho, -tamanho/2, 2.0);
        glVertex3f(-tamanho, tamanho/2, 2.0);
        glVertex3f(-tamanho, tamanho/2, 0.0);
        glVertex3f(-tamanho, -tamanho/2, 0.0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(tamanho, -tamanho/2, 0.0);
        glVertex3f(tamanho, tamanho/2, 2.0);
    glEnd();
}

void Jogador::desenhaAsa(int asa){
    GLfloat corR = 0.0;
    GLfloat corG = 0.0;
    GLfloat corB = 0.0;
    defineIluminacao(corR, corG, corB);
    if(asa == 0){
        glPushMatrix();
            glColor3f(0.0, 0.0, 0.0);

            glScalef(2.0, 1.0, 0.1625);
            glutSolidCube(this->raio/2);
        glPopMatrix();
    }else if(asa == 1){
        glPushMatrix();
            glColor3f(0.0, 0.0, 0.0);

            glScalef(2.0, 1.0, 0.1625);
            glutSolidCube(this->raio/2);
        glPopMatrix();
    }
}

void Jogador::desenhaAerodinamica(GLfloat tamanho, GLfloat corR, GLfloat corG, GLfloat corB){
	defineIluminacao(corR, corG, corB);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0, tamanho, 0.0);
		glVertex3f(tamanho, 0.0, 0.0);
		glVertex3f(-tamanho, 0.0, 0.0);
	glEnd();
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
        glPushMatrix();
            // glColor3f(1.0, 0.2, 0.2);

            glScalef(0.3, 1.0, 0.0825);
            glutSolidCube(this->raio/2);
        glPopMatrix();
        // desenhaQuadrado(this->raio/6, this->raio/4, 0.0, 0.0, 0.0);
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


void Jogador::desenhaElipseBorda(GLfloat cx, GLfloat cy, GLfloat corR, GLfloat corG, GLfloat corB){
	defineIluminacao(corR, corG, corB);

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

void Jogador::desenhaElipse(GLfloat cx, GLfloat cy, GLfloat corR, GLfloat corG, GLfloat corB){
	defineIluminacao(corR, corG, corB);
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

void Jogador::desenhaElipsoide(GLfloat cx, GLfloat cy, GLfloat corR, GLfloat corG, GLfloat corB){
	defineIluminacao(corR, corG, corB);
	GLfloat raioMenor = cx/cy;
	glScalef(raioMenor, 1, raioMenor);
	glutSolidSphere(cy, 180, 180);
}

void Jogador::desenhaBase(){
	glPushMatrix();
		desenhaElipsoide((this->getRaio()/3), this->getRaio(), this->getCorR(), this->getCorG(), this->getCorB());
	glPopMatrix();
}

void Jogador::desenhaAsas(int asa){
    glPushMatrix();
        if(asa == 0){
            glTranslatef(-this->raio/2, -this->raio/3, 0);
            desenhaHelice(asa);
            glTranslatef(0, this->raio/3, 0);
            desenhaAsa(asa);
        }else if(asa == 1){
            glTranslatef(this->raio, -this->raio/3, 0);
            desenhaHelice(asa);
            glTranslatef(-this->raio/2, this->raio/3, 0);
            desenhaAsa(asa);
        }
    glPopMatrix();

}

void Jogador::desenhaCilindro(GLfloat raio, GLfloat altura, GLfloat corR, GLfloat corG, GLfloat corB){
	glColor3f(corR, corG, corB);
	GLUquadric* qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GLU_TRUE);
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_SMOOTH);
    gluCylinder(qobj, raio, raio, altura, 180, 180);
}

void Jogador::desenhaCanhao(){
	glPushMatrix();
		glTranslatef(0.0, this->raio - 1, 0);
		glRotatef(this->anguloCanhao, 0.0, 0.0, 1.0);

		// desenhaCilindro(this->raio/this->raio, this->raio/2 + 1, 0.0, 0.0, 0.0);

		desenhaQuadrado(this->raio/4, this->raio/2 + 1, 0.0, 0.0, 0.0);
	glPopMatrix();
}

void Jogador::desenhaProjeteis(){
	for(int i = 0; i < projeteis.size(); i++){
		if(this->verificaColisao(projeteis[i]->getX(), projeteis[i]->getY(), true, projeteis[i]->getRaio())){
			projeteis[i]->desenhaProjetil(this->corR, this->corG, this->corB);
		}else{
			projeteis.erase(projeteis.begin() + i);
		}
	}
}

void Jogador::desenhaBombas(){
	for(int i = 0; i < bombas.size(); i++){
		if(this->verificaColisao(bombas[i]->getX(), bombas[i]->getY(), true, bombas[i]->getRaio()) && !bombas[i]->explodiu()){
			bombas[i]->desenhaBomba();
		}else if(bombas[i]->explodiu()){
			this->verificaColisaoBomba(bombas[i]->getX(), bombas[i]->getY(), bombas[i]->getRaio());
			bombas.erase(bombas.begin() + i);
		}else{
			bombas.erase(bombas.begin() + i);
		}
	}
}

void Jogador::desenhaJogador(){
	glPushMatrix();
		glTranslatef(this->x, this->y, this->z);
		glRotatef(this->anguloJogador, 0.0, 0.0, 1.0);
		glRotatef(this->anguloJogadorVertical, 1.0, 0.0, 0.0);
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

void Jogador::moveX(GLfloat x){
	this->anguloJogador += x * this->tempoAjustador;
}

void Jogador::moveY(GLfloat y){
	GLfloat cx = this->getX();
    GLfloat cy = this->getY() + (y * this->velocidadeMultiplicadora * this->tempoAjustador);

    if(verificaColisao(cx, cy, false, 0.0)){
    	this->setY(cy);
		this->anguloHelice += this->velocidade;
	}
}

void Jogador::moveZ(GLfloat z){
	this->anguloJogadorVertical += z * this->tempoAjustador;
}

void Jogador::voa(GLfloat velocidade){
	GLfloat cx = this->getX() + (cos(this->getAnguloJogadorVertical() * (M_PI / 180)) * cos(((this->getAnguloJogador()) * (M_PI / 180))) * velocidade * this->velocidadeMultiplicadora * this->tempoAjustador);
    GLfloat cy = this->getY() + (cos(this->getAnguloJogadorVertical() * (M_PI / 180)) * sin(((this->getAnguloJogador()) * (M_PI / 180))) * velocidade * this->velocidadeMultiplicadora * this->tempoAjustador);
		GLfloat cz = this->getZ() + (sin(this->getAnguloJogadorVertical() * (M_PI / 180)) * velocidade * this->velocidadeMultiplicadora * this->tempoAjustador);
	if(verificaColisao(cx, cy, false, 0.0)){
    this->setX(cx);
		this->setY(cy);
		this->setZ(cz);
		this->anguloHelice += this->velocidade;
	}
}

void Jogador::voaProjeteis(GLfloat tempoAjustador){
	int i = 0;
	for(Projetil *p : this->projeteis){
		if(verificaColisaoProjetil(p->getX(), p->getY())){
			p->voa(tempoAjustador);
		}else{
			this->projeteis.erase(this->projeteis.begin()+i);
		}
		i++;
	}
}

bool Jogador::verificaColisaoProjetil(GLfloat x, GLfloat y){
	// Verifica colisão com inimigos aéreos
	for (auto inimigo : this->arena->getInimigosAereos()) {
		GLfloat distanciaInimigo = this->distanciaEntrePontos(x, y, inimigo->getX(), inimigo->getY());
		GLfloat raioInimigo = inimigo->getRaio();
		if ((distanciaInimigo < raioInimigo) && this->isVoando()) {
			arena->mataInimigoAereo(inimigo);
			return false;
		}
	}
	return true;
}

void Jogador::verificaColisaoBomba(GLfloat x, GLfloat y, GLfloat raio){
	// Verifica colisão com inimigos terrestres
	std::list<Circulo*> inimigosMortos;
	for (auto inimigo : this->arena->getInimigosTerrestres()) {
		GLfloat distanciaInimigo = this->distanciaEntrePontos(x, y, inimigo->getX(), inimigo->getY());
		GLfloat raioInimigo = inimigo->getRaio();
		raioInimigo += raio;
		if ((distanciaInimigo < raioInimigo) && this->isVoando()) {
			arena->mataInimigoTerrestre(inimigo);
		}
	}
	inimigosMortos.clear();
}

void Jogador::voaBombas(GLfloat tempoAjustador){
	for(Bomba *b : this->bombas){
		b->voa(tempoAjustador);
	}
}

bool Jogador::verificaColisao(GLfloat x, GLfloat y, bool projetil, GLfloat raio){
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
	if(!projetil) {
		for (auto inimigo : this->arena->getInimigosAereos()) {
			GLfloat distanciaInimigo = this->distanciaEntrePontos(x, y, inimigo->getX(), inimigo->getY());
			GLfloat raioInimigo = inimigo->getRaio();
			raioInimigo += this->getRaio();
			if ((distanciaInimigo < raioInimigo) && this->isVoando()) {
				this->morre();
				return false;
			}
		}
	}
	return true;
}

void Jogador::atravessaBorda(){
	GLfloat cx = this->getX();
    GLfloat cy = this->getY();
    GLfloat alpha = atan2(cy, cx) * 180 / M_PI;
    GLfloat theta = (-2 * (alpha - this->anguloJogador)) * M_PI / 180;
    GLfloat novoX = (cx * cos(theta)) - (cy * sin(theta));
	GLfloat novoY = (cx * sin(theta)) + (cy * cos(theta));
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

void Jogador::reseta(){
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
	this->bombas.clear();
	this->vive();
}
