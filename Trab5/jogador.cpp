#include "jogador.h"

Jogador::Jogador(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB, Arena* arena){
	this->id = id;
    this->raio = raio;
    this->x = x;
    this->y = y;
	this->z = raio/3;
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
	this->anguloCanhaoVertical = 0.0;
	this->anguloHelice = 0.0;
	this->mouseX = 0.0;
	this->mouseY = 0.0;
	this->vivo = true;
	this->velocidade = 0.0;
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

GLfloat Jogador::getAnguloCanhaoVertical(){
	return this->anguloCanhaoVertical;
}

void Jogador::setAnguloCanhaoVertical(GLfloat anguloCanhaoVertical){
	this->anguloCanhaoVertical += anguloCanhaoVertical;
}

GLfloat Jogador::getMouseX(){
	return this->mouseX;
}

void Jogador::setMouseX(GLfloat mouseX){
	this->mouseX = mouseX;
}

GLfloat Jogador::getMouseY(){
	return this->mouseY;
}

void Jogador::setMouseY(GLfloat mouseY){
	this->mouseY = mouseY;
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

void Jogador::desenhaCirculoLinha(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB){
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

void Jogador::desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB){
    float theta, px, py;
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
}

void Jogador::desenhaQuadrado(GLfloat base, GLfloat altura, GLfloat corR, GLfloat corG, GLfloat corB){
	defineCor(corR, corG, corB);
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
    defineCor(corR, corG, corB);
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
    defineCor(corR, corG, corB);
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
	defineCor(corR, corG, corB);
	glPushMatrix();
		glScalef(2.0, 0.2, 0.1625);
		glutSolidCube(tamanho);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, 0, 2);
		glScalef(0.1625, 0.2, 1);
		glutSolidCube(tamanho);
	glPopMatrix();
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
        	defineCor(0, 0, 0);
            glScalef(0.3, 1.0, 0.0825);
            glutSolidCube(this->raio/2);
        glPopMatrix();
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
	defineCor(corR, corG, corB);

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
	defineCor(corR, corG, corB);
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

void Jogador::desenhaElipsoide(GLfloat cx, GLfloat cy, GLfloat corR, GLfloat corG, GLfloat corB, GLuint textura){
	defineCor(corR, corG, corB);
	GLfloat raioMenor = cx/cy;
	glScalef(raioMenor, 1, raioMenor);
	if(textura == 0){
		glutSolidSphere(cy, 30, 30);
	}else{
		glEnable(GL_TEXTURE_2D);
			defineCor(1.0, 1.0, 1.0);
			glMatrixMode(GL_TEXTURE);
				glBindTexture(GL_TEXTURE_2D, textura);
				GLUquadric* obj = gluNewQuadric();
			    gluQuadricOrientation(obj, GLU_OUTSIDE);
			    gluQuadricTexture(obj, GLU_TRUE);
			    gluQuadricDrawStyle(obj, GLU_FILL);
			    gluQuadricNormals(obj, GLU_SMOOTH);
				gluSphere(obj, cy, 30, 30);
				gluDeleteQuadric(obj);
			glMatrixMode(GL_MODELVIEW);
		glDisable(GL_TEXTURE_2D);
	}
}

void Jogador::desenhaBase(GLuint textura){
	glPushMatrix();
		// glLoadIdentity();

		glRotatef(90, 0.0, 0.0, 1.0);
		glTranslatef(this->getRaio(), 0.0, 0);
		// glRotatef(90, 0.0, 1.0, 0.0);
		// glRotatef(-90, 1, 0, 0);
		GLfloat light1_position[] = {0.0, 0.0, 0.0, 1.0};
	    GLfloat light1_direction[] = {1.0, 0.0, 0.0};
		glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light1_direction);
	glPopMatrix();
	glPushMatrix();
		desenhaElipsoide((this->getRaio()/3), this->getRaio(), this->getCorR(), this->getCorG(), this->getCorB(), textura);
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
		glTranslatef(0.0, this->raio - 2, 0);
		glRotatef(-90, 1, 0, 0);
		glRotatef(-this->anguloCanhao, 0.0, 1.0, 0.0);
		glRotatef(this->anguloCanhaoVertical, 1.0, 0.0, 0.0);

		desenhaCilindro(this->raio*0.1, this->raio/3, 0.0, 0.0, 0.0);
		glPushMatrix();
			glTranslatef(0.0, 0.0, this->raio/3);
			GLUquadric* obj = gluNewQuadric();
		    gluQuadricOrientation(obj, GLU_OUTSIDE);
		    gluQuadricTexture(obj, GLU_TRUE);
		    gluQuadricDrawStyle(obj, GLU_FILL);
		    gluQuadricNormals(obj, GLU_SMOOTH);
			gluDisk(obj, 0, this->raio*0.1, 180, 1);
			gluDeleteQuadric(obj);
		glPopMatrix();
	glPopMatrix();
}

void Jogador::desenhaProjeteis(GLuint texturaProjetil){
	for(int i = 0; i < projeteis.size(); i++){
		if(this->verificaColisao(projeteis[i]->getX(), projeteis[i]->getY(), projeteis[i]->getZ(), true, projeteis[i]->getRaio())){
			projeteis[i]->desenhaProjetil(this->corR, this->corG, this->corB, texturaProjetil);
		}else{
			projeteis.erase(projeteis.begin() + i);
		}
	}
}

void Jogador::desenhaBombas(GLuint texturaBomba){
	for(int i = 0; i < bombas.size(); i++){
		if(this->verificaColisao(bombas[i]->getX(), bombas[i]->getY(), bombas[i]->getZ(), true, bombas[i]->getRaio()) && !this->verificaColisaoBomba(bombas[i]->getX(), bombas[i]->getY(), bombas[i]->getZ(), bombas[i]->getRaio()) && bombas[i]->getZ() > bombas[i]->getRaio()){
			bombas[i]->desenhaBomba(texturaBomba);
		}else{
			bombas[i]->explodeBomba();
			bombas.erase(bombas.begin() + i);
		}
	}
}

void Jogador::desenhaJogador(GLuint textura, GLuint texturaProjetil){
	glPushMatrix();
		glTranslatef(this->x, this->y, this->z);
		glRotatef(this->anguloJogador, 0.0, 0.0, 1.0);
		glRotatef(this->anguloJogadorVertical, 1.0, 0.0, 0.0);
		glRotatef(-this->anguloJogadorCurva, 0.0, 1.0, 0.0);
		desenhaAsas(0);
		desenhaAsas(1);
		desenhaCanhao();
		glPushMatrix();
			glTranslatef(0.0, -(this->raio) , 0.0);
			glTranslatef(0.0, this->raio/16, 0.0);
			desenhaAerodinamica(this->raio/2, 0.0, 0.0, 0.0);
		glPopMatrix();
		desenhaBase(textura);
		glPushMatrix();
			glTranslatef(0.0, -this->raio, 0.0);
			desenhaQuadrado(this->raio/8, this->raio/3, 0.0, 0.0, 0.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0, this->raio/2, this->raio/this->raio);
			desenhaElipsoide(this->raio/4, this->raio/4, 0.0, 0.0, 0.0, 0);
		glPopMatrix();
	glPopMatrix();
	desenhaProjeteis(texturaProjetil);
}

void Jogador::moveX(GLfloat x){
	this->anguloJogador += x * this->tempoAjustador;
	GLfloat anguloLimite = 45;
	GLfloat novoAngulo = this->anguloJogadorCurva + x * this->tempoAjustador;

	if(x > 0 && novoAngulo > anguloLimite)
			novoAngulo = anguloLimite;
	else if(x < 0 && novoAngulo < -anguloLimite)
			novoAngulo = -anguloLimite;

	this->anguloJogadorCurva = novoAngulo;
}

void Jogador::moveY(GLfloat y){
	GLfloat cx = this->getX();
    GLfloat cy = this->getY() + (y * this->velocidadeMultiplicadora * this->tempoAjustador);

    if(verificaColisao(cx, cy, 0, false, 0.0)){
    	this->setY(cy);
		this->anguloHelice += this->velocidade;
	}
}

void Jogador::moveZ(GLfloat z){
	GLfloat anguloLimite = 45;
	GLfloat novoAngulo = this->anguloJogadorVertical + z * this->tempoAjustador;

	if(z > 0 && novoAngulo > anguloLimite)
			novoAngulo = anguloLimite;
	else if(z < 0 && novoAngulo < -anguloLimite)
			novoAngulo = -anguloLimite;

	this->anguloJogadorVertical = novoAngulo;
}

void Jogador::resetZ(GLfloat angSpeed){
	if(this->anguloJogadorVertical == 0)
		return;

	GLfloat novoAngulo;
	if(this->anguloJogadorVertical > 0){
		novoAngulo = this->anguloJogadorVertical - angSpeed * this->tempoAjustador;
		if(novoAngulo < 0)
			novoAngulo = 0;
	}else{
		novoAngulo = this->anguloJogadorVertical + angSpeed * this->tempoAjustador;
		if(novoAngulo > 0)
			novoAngulo = 0;
	}

	this->anguloJogadorVertical = novoAngulo;
}

void Jogador::resetX(GLfloat angSpeed){
	if(this->anguloJogadorCurva == 0)
		return;

	GLfloat novoAngulo;
	if(this->anguloJogadorCurva > 0){
		novoAngulo = this->anguloJogadorCurva - angSpeed * this->tempoAjustador;
		if(novoAngulo < 0)
			novoAngulo = 0;
	}else{
		novoAngulo = this->anguloJogadorCurva + angSpeed * this->tempoAjustador;
		if(novoAngulo > 0)
			novoAngulo = 0;
	}

	this->anguloJogadorCurva = novoAngulo;
}

void Jogador::voa(GLfloat velocidade){
	GLfloat cx = this->getX() + (cos(this->getAnguloJogadorVertical() * (M_PI / 180)) * cos(((this->getAnguloJogador()) * (M_PI / 180))) * velocidade * this->velocidadeMultiplicadora * this->tempoAjustador);
    GLfloat cy = this->getY() + (cos(this->getAnguloJogadorVertical() * (M_PI / 180)) * sin(((this->getAnguloJogador()) * (M_PI / 180))) * velocidade * this->velocidadeMultiplicadora * this->tempoAjustador);
	GLfloat cz = this->getZ() + (sin(this->getAnguloJogadorVertical() * (M_PI / 180)) * velocidade * this->velocidadeMultiplicadora * this->tempoAjustador);
	if(verificaColisao(cx, cy, cz, false, 0.0)){
    	this->setX(cx);
		this->setY(cy);
		this->setZ(cz);
		this->anguloHelice += this->velocidade;
	}
}

void Jogador::voaProjeteis(GLfloat tempoAjustador){
	int i = 0;
	for(Projetil *p : this->projeteis){
		if(verificaColisaoProjetil(p->getX(), p->getY(), p->getZ())){
			p->voa(tempoAjustador);
		}else{
			this->projeteis.erase(this->projeteis.begin()+i);
		}
		i++;
	}
}

bool Jogador::verificaColisaoProjetil(GLfloat x, GLfloat y, GLfloat z){
	// Verifica colisão com inimigos aéreos
	for (auto inimigo : this->arena->getInimigosAereos()) {
		GLfloat distanciaInimigo = this->distanciaEntrePontos(x, y, z, inimigo->getX(), inimigo->getY(), inimigo->getZ());
		GLfloat raioInimigo = inimigo->getRaio();
		if ((distanciaInimigo < raioInimigo) && this->isVoando()) {
			arena->mataInimigoAereo(inimigo);
			return false;
		}
	}
	return true;
}

bool Jogador::verificaColisaoBomba(GLfloat x, GLfloat y, GLfloat z, GLfloat raio){
	bool resposta = false;
	// Verifica colisão com inimigos terrestres
	std::list<Circulo*> inimigosMortos;
	for (auto inimigo : this->arena->getInimigosTerrestres()) {
		GLfloat distanciaInimigo = this->distanciaEntrePontos(x, y, z, inimigo->getX(), inimigo->getY(), inimigo->getZ());
		GLfloat raioInimigo = inimigo->getRaio();
		raioInimigo += raio;
		if ((distanciaInimigo < raioInimigo) && this->isVoando()) {
			arena->mataInimigoTerrestre(inimigo);
			resposta = true;
		}
	}
	inimigosMortos.clear();
	return resposta;
}

void Jogador::voaBombas(GLfloat tempoAjustador){
	for(Bomba *b : this->bombas){
		b->voa(tempoAjustador);
	}
}

bool Jogador::verificaColisao(GLfloat x, GLfloat y, GLfloat z, bool projetil, GLfloat raio){
	GLfloat distanciaBorda = this->distanciaEntrePontos(this->arena->getX(), this->arena->getY(), 0, x, y, 0);

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
			GLfloat distanciaInimigo = this->distanciaEntrePontos(x, y, z, inimigo->getX(), inimigo->getY(), inimigo->getZ());
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

void Jogador::decola(Linha* linha, GLfloat tempoDiferencial, GLfloat tempoDecolagem){
	if(this->ligado && !this->voando){
		GLfloat distancia = this->distanciaEntrePontos(linha->getX1(), linha->getY1(), 0, linha->getX2(), linha->getY2(), 0);
		GLfloat tempo = 4.0;
		GLfloat velFinal = 2 * distancia / tempo;
		GLfloat aceleracao = 2*distancia/(pow(tempo, 2));

		this->velocidade += aceleracao*tempoDiferencial;

		this->voa(this->velocidade);

		if(tempoDecolagem >= tempo/2){
			this->moveZ(25.0);
		}

		if(tempoDecolagem > tempo){
			this->setVoando(true);
		}

		// // S = So + Vo * t + (a * t^2)/2
		// GLfloat tempoFinal = 4.0;
		//
		// GLfloat dx = linha->getX2() - linha->getX1();
		// GLfloat x = 2 * dx / pow(tempoFinal, 2);
		//
		// GLfloat dy = linha->getY2() - linha->getY1();
		// GLfloat y = 2 * dy / pow(tempoFinal, 2);
		//
		// GLfloat x1 = linha->getX1() + (x * pow(tempoDecolagem, 2)) / 2;
		// GLfloat y1 = linha->getY1() + (y * pow(tempoDecolagem, 2)) / 2;
		// this->setX(x1);
		// this->setY(y1);
		// this->distanciaPontos = this->distanciaEntrePontos(this->x, this->y, 0, linha->getX2(), linha->getY2(), 0);
		// GLfloat aceleracao = (this->distanciaPontos/tempoFinal);
		// this->anguloHelice = this->anguloHelice + aceleracao * tempoDecolagem;
		//
		// // Subindo voo (dobrando o raio)
		// if(this->distanciaPontos <= this->pontoCrescimento and this->ligado and !this->voando){
		// 	GLfloat dz = this->getRaio()*2;
		// 	GLfloat z = 2 * dz / pow(tempoFinal, 2);
		//
		// 	this->moveZ(50.0);
		// 	GLfloat z1 = z * pow(tempoDecolagem, 2) / 2;
		// 	this->setZ(z1);
		// }
		//
		// // Completado decolagem
		// if(this->distanciaPontos <= 1 or tempoDecolagem >= 4.0){
		// 	GLfloat vel = sqrt(pow(x, 2) + pow(y, 2)) * 4.0;
		// 	this->setVelocidade(vel);
		// 	this->setVoando(true);
		// }
	}
}

GLfloat Jogador::distanciaEntrePontos(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2){
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
}

void Jogador::calculaPontoCrescimento(Linha* linha){
	GLfloat pontoCrescimento = this->distanciaEntrePontos(linha->getX1(), linha->getY1(), 0, linha->getX2(), linha->getY2(), 0) / 2.0;
	this->pontoCrescimento = pontoCrescimento;
}

void Jogador::calculaAngulo(Linha* linha){
	this->setAnguloJogador(-90 + atan2(linha->getDistanciaY(), linha->getDistanciaX()) * 180 / M_PI);
}

void Jogador::reseta(){
	this->x = this->xInicial;
	this->y = this->yInicial;
	this->z = this->raio/3;
	this->anguloJogadorVertical = 0.0;
	this->anguloCanhaoVertical = 0.0;
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
