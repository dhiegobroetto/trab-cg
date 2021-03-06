#include "arena.h"

void * fonte = GLUT_BITMAP_TIMES_ROMAN_24;

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

Jogador* Arena::getJogador(){
	return this->jogador;
}

void Arena::setJogador(Jogador* jogador){
	this->jogador = jogador;
}

Linha* Arena::getLinha(){
	return this->linha;
}

void Arena::setLinha(Linha* linha){
	this->linha = linha;
}

list<Inimigo*> Arena::getInimigosAereos(){
	return this->inimigosAereos;
}

void Arena::mataInimigoAereo(Inimigo* inimigo){
	this->inimigosAereosMortos.push_back(inimigo);
	this->inimigosAereos.remove(inimigo);
}

void Arena::mataInimigoTerrestre(Circulo* inimigo){
	this->inimigosTerrestresMortos.push_back(inimigo);
	this->inimigosTerrestres.remove(inimigo);
}

list<Circulo*> Arena::getInimigosTerrestres(){
	return this->inimigosTerrestres;
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

void Arena::criaInimigosAereos(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b, Arena* arena, GLfloat vel, GLfloat velTiro, GLfloat freqTiro) {
    Circulo* circulo = new Circulo(id, raioCirculo, x, y, r, g, b);
	Inimigo* inimigo = new Inimigo(id, raioCirculo, x, y, r, g, b, arena, vel, velTiro, freqTiro);
    this->inimigosAereos.push_back(inimigo);
}

void Arena::criaInimigosTerrestres(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b) {
    Circulo* circulo = new Circulo(id, raioCirculo, x, y, r, g, b);
    this->inimigosTerrestres.push_back(circulo);
}

void Arena::voaInimigosAereos(GLfloat curva, GLfloat tempoMultiplicador){
	if(this->inimigosAereos.size() > 0){
		for(Inimigo* i : this->inimigosAereos){
			i->voa(curva);
			i->voaProjeteis(tempoMultiplicador);
		}
	}
}

void Arena::reseta(){
	for(Inimigo* i : this->inimigosAereosMortos){
		this->inimigosAereos.push_back(i);
	}
	this->inimigosAereosMortos.clear();

	for(Circulo* i : this->inimigosTerrestresMortos){
		this->inimigosTerrestres.push_back(i);
	}
	this->inimigosTerrestresMortos.clear();
	
	for(Inimigo* i : this->inimigosAereos){
		i->reseta();
	}
}

void Arena::exibeDecolagem(GLfloat x, GLfloat y){
	char *strTemporaria;
	char decolagem[50];
	glColor3f(1.0,1.0,1.0);
    sprintf(decolagem, "Pressione U para decolar.");
    glRasterPos2f(x, y);
    strTemporaria = decolagem;
    while( *strTemporaria ){
        glutBitmapCharacter(fonte, *strTemporaria);
        strTemporaria++;
    }
}

void Arena::exibeVitoria(GLfloat x, GLfloat y){
	char *strTemporaria;
	char venceu[80];
	glColor3f(1.0,1.0,1.0);
    sprintf(venceu, "Voce venceu!");
    glRasterPos2f(x + 90, y);
    strTemporaria = venceu;
    while( *strTemporaria ){
        glutBitmapCharacter(fonte, *strTemporaria);
        strTemporaria++;
    }

	glColor3f(1.0,1.0,1.0);
    sprintf(venceu, "Pressione R para jogar novamente!");
    glRasterPos2f(x, y - 25);
    strTemporaria = venceu;
    while( *strTemporaria ){
        glutBitmapCharacter(fonte, *strTemporaria);
        strTemporaria++;
    }
	
}

void Arena::exibeGameOver(GLfloat x, GLfloat y){
	char *strTemporaria;
	char gameOver[80];
	glColor3f(1.0,1.0,1.0);
    sprintf(gameOver, "Game Over!");
    glRasterPos2f(x + 90, y);
    strTemporaria = gameOver;
    while( *strTemporaria ){
        glutBitmapCharacter(fonte, *strTemporaria);
        strTemporaria++;
    }
	glColor3f(1.0,1.0,1.0);
	sprintf(gameOver, "Pressione R para jogar novamente!");
	glRasterPos2f(x, y - 25);
	strTemporaria = gameOver;
	while( *strTemporaria ){
		glutBitmapCharacter(fonte, *strTemporaria);
		strTemporaria++;
	}
}

void Arena::exibePontuacao(GLfloat x, GLfloat y){
	char *strTemporaria;
	char pontuacao[50];
	glColor3f(0.0,0.0,0.0);
    sprintf(pontuacao, "%d/%d bases destruidas.", (int)this->inimigosTerrestresMortos.size(), (int)(this->inimigosTerrestresMortos.size() + this->inimigosTerrestres.size()));
    glRasterPos2f(x, y);
    strTemporaria = pontuacao;
    while( *strTemporaria ){
        glutBitmapCharacter(fonte, *strTemporaria);
        strTemporaria++;
    }
}