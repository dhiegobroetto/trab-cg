#include "arena.h"

Arena::Arena(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB){
	this->id = id;
    this->raio = raio;
    this->x = x;
    this->y = y;
	this->z = 0;
    this->corR = corR;
    this->corG = corG;
    this->corB = corB;
    this->iluminacao = true;
	this->maiorRaioTerrestre = 0;
	this->camera = false;
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

GLfloat Arena::getZ(){
	return this->z;
}

void Arena::setZ(GLfloat& z){
	this->z = z;
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

GLfloat Arena::getMaiorRaioTerrestre(){
	return this->maiorRaioTerrestre;
}

void Arena::setMaiorRaioTerrestre(GLfloat& maiorRaioTerrestre){
	this->maiorRaioTerrestre = maiorRaioTerrestre;
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

GLuint Arena::getTexturaMar(){
	return this->texturaMar;
}

void Arena::setTexturaMar(GLuint texturaMar){
	this->texturaMar = texturaMar;
}

GLuint Arena::getTexturaCeu(){
	return this->texturaCeu;
}

void Arena::setTexturaCeu(GLuint texturaCeu){
	this->texturaCeu = texturaCeu;
}

GLuint Arena::getTexturaCeuTopo(){
	return this->texturaCeuTopo;
}

void Arena::setTexturaCeuTopo(GLuint texturaCeuTopo){
	this->texturaCeuTopo = texturaCeuTopo;
}

bool Arena::getIluminacao(){
	return this->iluminacao;
}
void Arena::trocaIluminacao(){
	this->iluminacao = !this->iluminacao;
}

std::list<Inimigo*> Arena::getInimigosAereos(){
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

std::list<Circulo*> Arena::getInimigosTerrestres(){
	return this->inimigosTerrestres;
}

std::list<Circulo*> Arena::getInimigosTerrestresMortos(){
	return this->inimigosTerrestresMortos;
}

void Arena::desenhaArena(bool modoNoturno){
	float theta, px, py;

	glPushMatrix();
	    glTranslatef(this->x, this->y, 0);

	    // Corpo da arena
	    if(modoNoturno){
			GLfloat mat_emission[] = {0.0, 0.0, 0.0, 1.0};
		    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		    // this->setTexturaCeu(LoadTextureRAW("nightsky.bmp"));
		}else{
			GLfloat mat_emission[] = {1.0, 1.0, 1.0, 1.0};
		    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
		}

	    // Habilitando texturas aqui por não haver outros objs com textura.
	    glEnable(GL_TEXTURE_2D);
			defineCor(1.0, 1.0, 1.0);
			glMatrixMode(GL_TEXTURE);
				glPushMatrix();
					glScalef(2, 2, 1);
					glBindTexture(GL_TEXTURE_2D, this->getTexturaMar());
					// Base da arena
					GLUquadric* obj = gluNewQuadric();
				    gluQuadricOrientation(obj, GLU_OUTSIDE);
				    gluQuadricTexture(obj, GLU_TRUE);
				    gluQuadricDrawStyle(obj, GLU_FILL);
				    gluQuadricNormals(obj, GLU_SMOOTH);
					gluDisk(obj, 0, this->getRaio() + this->getJogador()->getRaio()*5, 150, 1);
					gluDeleteQuadric(obj);
				glPopMatrix();
    		glMatrixMode(GL_MODELVIEW);
		glDisable(GL_TEXTURE_2D);

		// Corpo da arena
		glEnable(GL_TEXTURE_2D);
			defineCor(1.0, 1.0, 1.0);
			glMatrixMode(GL_TEXTURE);
				glPushMatrix();
					glScalef(5, 1, 1);
					glBindTexture(GL_TEXTURE_2D, this->getTexturaCeu());
				    GLUquadric* qobj = gluNewQuadric();
				    gluQuadricOrientation(qobj, GLU_INSIDE);
				    gluQuadricTexture(qobj, GLU_TRUE);
				    gluQuadricDrawStyle(qobj, GLU_FILL);
				    gluQuadricNormals(qobj, GLU_SMOOTH);
				    gluCylinder(qobj, this->getRaio() + this->getJogador()->getRaio()*5, this->getRaio() + this->getJogador()->getRaio()*5, this->getRaio(), 150, 1);
				    gluDeleteQuadric(qobj);
				glPopMatrix();
			glMatrixMode(GL_MODELVIEW);
		glDisable(GL_TEXTURE_2D);

		// Topo da arena
		glEnable(GL_TEXTURE_2D);
			defineCor(1.0, 1.0, 1.0);
			glPushMatrix();
			    glTranslatef(0.0, 0.0, this->getRaio());
				glMatrixMode(GL_TEXTURE);
					glPushMatrix();
						glScalef(5, 1, 1);
						glBindTexture(GL_TEXTURE_2D, this->getTexturaCeuTopo());
					    obj = gluNewQuadric();
					    gluQuadricOrientation(obj, GLU_OUTSIDE);
					    gluQuadricTexture(obj, GLU_TRUE);
					    gluQuadricDrawStyle(obj, GLU_FILL);
					    gluQuadricNormals(obj, GLU_SMOOTH);
						gluDisk(obj, 0, this->getRaio() + this->getJogador()->getRaio()*5, 150, 1);
						gluDeleteQuadric(obj);
					glPopMatrix();
				glMatrixMode(GL_MODELVIEW);
			glPopMatrix();
		glDisable(GL_TEXTURE_2D);

		GLfloat mat_emission2[] = {0.0, 0.0, 0.0, 1.0};
    	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission2);

		    // Topo da arena
			// glBegin(GL_POLYGON);
		 //        for (int i = 0; i < 360; i++) {
		 //            theta = (i * M_PI) / 180.0;
		 //            px = cos(theta) * this->getRaio();
		 //            py = sin(theta) * this->getRaio();
		 //            glVertex3f(px, py, 4);
		 //        }
		 //    glEnd();

	    // Desabilitando texturas pelo mesmo motivo de habilitar.
	glPopMatrix();
}

void Arena::criaInimigosAereos(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b, Arena* arena, GLfloat vel, GLfloat velTiro, GLfloat freqTiro) {
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
	this->setCamera(false);
}

void Arena::desenhaCirculoBorda(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB) {
	float theta, px, py;
    defineCor(corR, corG, corB);
	glBegin(GL_LINE_LOOP);
	// glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			theta = (i * M_PI) / 180.0;
			px = cos(theta) * raio;
			py = sin(theta) * raio;
			glVertex2f(px, py);
		}
	glEnd();
}

void Arena::desenhaMinimapa(GLfloat raio){
	glPushMatrix();
		glScalef(0.25, 0.25, 0);
		glTranslatef(raio*2, -raio*2, 0.0);
		this->desenhaCirculoBorda(raio, 1, 1, 1);
		for (auto e : this->getInimigosTerrestres()) {
			glPushMatrix();
				glTranslatef(e->getX(), e->getY(), 0);
				e->desenhaCirculo(e->getRaio(), e->getCorR(), e->getCorG(), e->getCorB());
			glPopMatrix();
		}

		for (auto e : this->getInimigosAereos()) {
			glPushMatrix();
				glTranslatef(e->getX(), e->getY(), 0);
				e->desenhaCirculo(e->getRaio(), e->getCorR(), e->getCorG(), e->getCorB());
			glPopMatrix();
		}
		glPushMatrix();
			glTranslatef(this->getJogador()->getX(), this->getJogador()->getY(), 0);
			this->getJogador()->desenhaCirculo(
				this->getJogador()->getRaio(),
				this->getJogador()->getCorR(),
				this->getJogador()->getCorG(),
				this->getJogador()->getCorB());
		glPopMatrix();
	glPopMatrix();
}

void Arena::setCamera(bool status){
	this->camera = status;
}
bool Arena::hasCamera(){
	return this->camera;
}
