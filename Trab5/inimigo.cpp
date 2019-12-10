#include "inimigo.h"

Inimigo::Inimigo(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB, Arena* arena, GLfloat velocidade, GLfloat velocidadeTiro, GLfloat frequenciaTiro){
	this->id = id;
    this->raio = raio;
    this->x = x;
    this->y = y;
	this->z = arena->getRaio()/2;
	this->xInicial = x;
	this->yInicial = y;
    this->corR = corR;
    this->corG = corG;
    this->corB = corB;
	this->ligado = true;
	this->voando = false;
	this->distanciaPontos = 0.0;
	this->raioInicial = raio;
	this->tempoRaio = 0.0;
	this->segundosIA = (GLfloat) (rand() % 2) + 1;
	this->arena = arena;
	this->anguloInimigo = (GLfloat) (rand() % 360);
	this->anguloInimigoVertical = 0.0;
	this->anguloCanhao = 0.0;
	this->anguloCanhaoVertical = 0.0;
	this->anguloHelice = 0.0;
	this->mouseX = 0.0;
	this->vivo = true;
	this->velocidadeMultiplicadora = velocidade;
	this->velocidadeTiro = velocidadeTiro;
	this->frequenciaTiro = frequenciaTiro;
	this->estado = RETO;
	this->tempoIA = 0;
	this->tempoAtira = 0;
	this->estadoVertical = RETO;
}

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

GLfloat Inimigo::getZ(){
	return this->z;
}

void Inimigo::setZ(GLfloat& z){
	this->z = z;
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

void Inimigo::setTempoIA(GLfloat tempoIA){
	this->tempoIA = tempoIA;
}

void Inimigo::setTempoAtira(GLfloat tempoAtira){
	this->tempoAtira = tempoAtira;
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

GLfloat Inimigo::getAnguloInimigoVertical(){
	return this->anguloInimigoVertical;
}

void Inimigo::setAnguloInimigoVertical(GLfloat anguloInimigoVertical){
	this->anguloInimigoVertical = anguloInimigoVertical;
}

GLfloat Inimigo::getAnguloCanhao(){
	return this->anguloCanhao;
}

void Inimigo::setAnguloCanhao(GLfloat anguloCanhao){
	this->anguloCanhao += anguloCanhao;
}

GLfloat Inimigo::getAnguloCanhaoVertical(){
	return this->anguloCanhaoVertical;
}

void Inimigo::setAnguloCanhaoVertical(GLfloat anguloCanhaoVertical){
	this->anguloCanhaoVertical += anguloCanhaoVertical;
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

void Inimigo::desenhaQuadrado(GLfloat base, GLfloat altura, GLfloat corR, GLfloat corG, GLfloat corB){
	defineCor(corR, corG, corB);
	glBegin(GL_POLYGON);
		glVertex3f(base/2, 0.0, 0.0);
		glVertex3f(base/2, altura, 0.0);
		glVertex3f(-base/2, altura, 0.0);
		glVertex3f(-base/2, 0.0, 0.0);
	glEnd();
}

void Inimigo::desenhaTriangulo(GLfloat tamanho){
	defineCor(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(-tamanho, -tamanho/2, 0.0);
		glVertex3f(-tamanho, tamanho/2, 0.0);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(tamanho, -tamanho/2, 0.0);
		glVertex3f(tamanho, tamanho/2, 0.0);
	glEnd();
}

void Inimigo::desenhaAsa(int asa){
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

void Inimigo::desenhaAerodinamica(GLfloat tamanho, GLfloat corR, GLfloat corG, GLfloat corB){
	defineCor(corR, corG, corB);
	// glBegin(GL_TRIANGLES);
	// 	glVertex3f(0.0, tamanho, 0.0);
	// 	glVertex3f(tamanho, 0.0, 0.0);
	// 	glVertex3f(-tamanho, 0.0, 0.0);
	// glEnd();
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


void Inimigo::desenhaHelice(int asa){
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


void Inimigo::desenhaElipseBorda(GLfloat cx, GLfloat cy, GLfloat corR, GLfloat corG, GLfloat corB){
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

void Inimigo::desenhaElipse(GLfloat cx, GLfloat cy, GLfloat corR, GLfloat corG, GLfloat corB){
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

void Inimigo::desenhaElipsoide(GLfloat cx, GLfloat cy, GLfloat corR, GLfloat corG, GLfloat corB, GLuint textura){
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

void Inimigo::desenhaBase(GLuint textura){
	glPushMatrix();
		desenhaElipsoide((this->getRaio()/3), this->getRaio(), this->getCorR(), this->getCorG(), this->getCorB(), textura);
		// desenhaElipse((this->getRaio()/3), this->getRaio(), this->getCorR(), this->getCorG(), this->getCorB());
	glPopMatrix();
}

void Inimigo::desenhaAsas(int asa){
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

void Inimigo::desenhaCirculoLinha(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB){
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

void Inimigo::desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB){
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

void Inimigo::desenhaCilindro(GLfloat raio, GLfloat altura, GLfloat corR, GLfloat corG, GLfloat corB){
	glColor3f(corR, corG, corB);
	GLUquadric* qobj = gluNewQuadric();
    gluQuadricTexture(qobj, GLU_TRUE);
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_SMOOTH);
    gluCylinder(qobj, raio, raio, altura, 180, 180);
}

void Inimigo::desenhaCanhao(){
	glPushMatrix();
		glTranslatef(0.0, this->raio - 2, 0);
		glRotatef(-90, 1, 0, 0);
		glRotatef(-this->anguloCanhao, 0.0, 1.0, 0.0);

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

void Inimigo::desenhaProjeteis(GLuint texturaProjetil){
	for(int i = 0; i < projeteis.size(); i++){
		if(this->verificaColisao(projeteis[i]->getX(), projeteis[i]->getY(), projeteis[i]->getZ(), true, projeteis[i]->getRaio())){
			projeteis[i]->desenhaProjetil(this->corR, this->corG, this->corB, texturaProjetil);
		}else{
			projeteis.erase(projeteis.begin() + i);
		}
	}
}

void Inimigo::desenhaInimigo(GLuint textura, GLuint texturaProjetil){
	glPushMatrix();
		glTranslatef(this->x, this->y, this->z);
		glRotatef(this->anguloInimigo, 0.0, 0.0, 1.0);
		glRotatef(this->anguloInimigoVertical, 1.0, 0.0, 0.0);
		glRotatef(-this->anguloInimigoCurva, 0.0, 1.0, 0.0);
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

void Inimigo::moveX(GLfloat x){
	this->anguloInimigo += x * this->tempoAjustador;
	GLfloat anguloLimite = 45;
	GLfloat novoAngulo = this->anguloInimigoCurva + x * this->tempoAjustador;

	if(x > 0 && novoAngulo > anguloLimite)
			novoAngulo = anguloLimite;
	else if(x < 0 && novoAngulo < -anguloLimite)
			novoAngulo = -anguloLimite;

	this->anguloInimigoCurva = novoAngulo;
}

void Inimigo::moveY(GLfloat y){
	GLfloat cx = this->getX();
    GLfloat cy = this->getY() + (y * this->velocidadeMultiplicadora * this->tempoAjustador);

	this->setY(cy);
	this->anguloHelice += this->velocidade;
}

void Inimigo::moveZ(GLfloat z){
	GLfloat anguloLimite = 45;
	GLfloat novoAngulo = this->anguloInimigoVertical + z * this->tempoAjustador;

	if(z > 0 && novoAngulo > anguloLimite)
			novoAngulo = anguloLimite;
	else if(z < 0 && novoAngulo < -anguloLimite)
			novoAngulo = -anguloLimite;

	this->anguloInimigoVertical = novoAngulo;
}

void Inimigo::resetZ(GLfloat angSpeed){
	if(this->anguloInimigoVertical == 0)
		return;

	GLfloat novoAngulo;
	if(this->anguloInimigoVertical > 0){
		novoAngulo = this->anguloInimigoVertical - angSpeed * this->tempoAjustador;
		if(novoAngulo < 0)
			novoAngulo = 0;
	}else{
		novoAngulo = this->anguloInimigoVertical + angSpeed * this->tempoAjustador;
		if(novoAngulo > 0)
			novoAngulo = 0;
	}

	this->anguloInimigoVertical = novoAngulo;
}

void Inimigo::resetX(GLfloat angSpeed){
	if(this->anguloInimigoCurva == 0)
		return;

	GLfloat novoAngulo;
	if(this->anguloInimigoCurva > 0){
		novoAngulo = this->anguloInimigoCurva - angSpeed * this->tempoAjustador;
		if(novoAngulo < 0)
			novoAngulo = 0;
	}else{
		novoAngulo = this->anguloInimigoCurva + angSpeed * this->tempoAjustador;
		if(novoAngulo > 0)
			novoAngulo = 0;
	}

	this->anguloInimigoCurva = novoAngulo;
}


GLfloat calculaProbabilidadeGirar(){
	return ((GLfloat) rand() / (RAND_MAX));
}

void Inimigo::giraInimigo(GLfloat vel, GLfloat curva){
	switch(this->estado){
		case ESQUERDA:
			this->moveX(curva);
			break;
		case DIREITA:
			this->moveX((-1)*curva);
			break;
		default:
			this->resetX(curva*this->getVelocidade()*this->getVelocidadeMultiplicadora()/103);
	}

	switch(this->estadoVertical){
		case CIMA:
			if(this->getZ() < this->getArena()->getRaio() - 105)
				this->moveZ(curva);
			else
				this->resetZ(curva*this->getVelocidade()*this->getVelocidadeMultiplicadora()/103);
			break;
		case BAIXO:
			if(this->getZ() > this->getArena()->getMaiorRaioTerrestre() + 80)
				this->moveZ((-1)*curva);
			else
				this->resetZ(curva*this->getVelocidade()*this->getVelocidadeMultiplicadora()/103);
			break;
		case RETO:
			this->resetZ(curva*this->getVelocidade()*this->getVelocidadeMultiplicadora()/103);
			break;
	}
}
void Inimigo::atira(){
	GLfloat raio = this->getRaio();
	GLfloat anguloHorizontal = this->getAnguloInimigo() *M_PI/180;
	GLfloat anguloVertical = this->getAnguloInimigoVertical() *M_PI/180;
	GLfloat anguloCanhaoHorizontal = this->getAnguloCanhao() *M_PI/180;
	GLfloat anguloCanhaoVertical = this->getAnguloCanhaoVertical() *M_PI/180;

	GLfloat distPontaAviao_x = raio*cos(anguloVertical)*cos(anguloHorizontal);
	GLfloat distPontaAviao_y = raio*cos(anguloVertical)*sin(anguloHorizontal);
	GLfloat distPontaAviao_z = raio*sin(anguloVertical);

	GLfloat distPontaCanhao_x = raio/2*cos(anguloCanhaoVertical + anguloVertical)*cos(anguloCanhaoHorizontal + anguloHorizontal);
	GLfloat distPontaCanhao_y = raio/2*cos(anguloCanhaoVertical + anguloVertical)*sin(anguloCanhaoHorizontal + anguloHorizontal);
	GLfloat distPontaCanhao_z = raio/2*sin(anguloCanhaoVertical + anguloVertical);

	Projetil *p = new Projetil(
		this->getX() + distPontaAviao_x + distPontaCanhao_x,
		this->getY() + distPontaAviao_y + distPontaCanhao_y,
		this->getZ() + distPontaAviao_z + distPontaCanhao_z,
		(GLfloat) (this->getRaio()*0.1),
		(GLfloat) 0.0,
		(GLfloat) 0.0,
		(GLfloat) 0.0,
		this->getVelocidade() * this->getVelocidadeMultiplicadora() * this->getVelocidadeTiro(),
		this->getAnguloCanhao(),
		this->getAnguloInimigo(),
		this->getAnguloInimigoVertical() + this->getAnguloCanhaoVertical(),
		(GLfloat) (this->getRaio() / 2),
		(GLfloat) (this->getRaio() - 1)
	);
	this->addProjetil(p);
}
void Inimigo::voa(GLfloat curva){
	GLfloat cx = this->getX() + (cos(this->getAnguloInimigoVertical() * (M_PI / 180)) * cos(((this->getAnguloInimigo()) * (M_PI / 180))) * velocidade * this->velocidadeMultiplicadora * this->tempoAjustador);
  	GLfloat cy = this->getY() + (cos(this->getAnguloInimigoVertical() * (M_PI / 180)) * sin(((this->getAnguloInimigo()) * (M_PI / 180))) * velocidade * this->velocidadeMultiplicadora * this->tempoAjustador);
	GLfloat cz = this->getZ() + (sin(this->getAnguloInimigoVertical() * (M_PI / 180)) * velocidade * this->velocidadeMultiplicadora * this->tempoAjustador);

	GLfloat tempoAgora = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	if(this->tempoIA + this->segundosIA <= tempoAgora){

		GLfloat prob = calculaProbabilidadeGirar();
		GLfloat probRotateVert = calculaProbabilidadeGirar();
		// >= 0 ~ <= 0.6: anda reto
		// > 0.6 ~ <= 0.8: gira esquerda
		// > 0.8 ~ <= 1.0: gira direita
		if(prob > 0.6 && prob <= 0.8){
			this->estado = ESQUERDA;
		}else if(prob > 0.8 && prob <= 1.0){
			this->estado = DIREITA;
		}else{
			this->estado = RETO;
		}

		if(probRotateVert > 0.6 && probRotateVert <= 0.8){
			this->estadoVertical = CIMA;
		}else if(probRotateVert > 0.8 && probRotateVert <= 1.0){
			this->estadoVertical = BAIXO;
		}else{
			this->estadoVertical = RETO;
		}
		this->tempoIA = tempoAgora;
		this->segundosIA = (GLfloat) (rand() % 2) + 1;
	}
	if(this->tempoAtira + (1/this->frequenciaTiro) <= tempoAgora){
		this->atira();
		this->tempoAtira = tempoAgora;
	}
	this->giraInimigo(velocidade, curva);
	if(verificaColisao(cx, cy, cz, false, 0.0)){
		this->setX(cx);
		this->setY(cy);
		this->setZ(cz);
		this->anguloHelice += this->velocidade;
	}
}

void Inimigo::voaProjeteis(GLfloat tempoAjustador){
	for(Projetil *p : this->projeteis){
		p->voa(tempoAjustador);
	}
}

bool Inimigo::verificaColisao(GLfloat x, GLfloat y, GLfloat z, bool projetil, GLfloat raio){
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
	// Verifica colisão com jogador
	if(projetil && arena->getJogador()->isLigado() && arena->getJogador()->isVoando()) {
		GLfloat distanciaJogador = this->distanciaEntrePontos(x, y, z, arena->getJogador()->getX(), arena->getJogador()->getY(), arena->getJogador()->getZ());
		GLfloat raioJogador = arena->getJogador()->getRaio();
		raioJogador += raio;
		if ((distanciaJogador < raioJogador) && this->isVoando()) {
			arena->getJogador()->morre();
			return false;
		}
	}
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
		this->distanciaPontos = this->distanciaEntrePontos(this->x, this->y, 0, linha->getX2(), linha->getY2(), 0);
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

GLfloat Inimigo::distanciaEntrePontos(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2){
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
}

void Inimigo::calculaPontoCrescimento(Linha* linha){
	GLfloat pontoCrescimento = this->distanciaEntrePontos(linha->getX1(), linha->getY1(), 0, linha->getX2(), linha->getY2(), 0) / 2.0;
	this->pontoCrescimento = pontoCrescimento;
}

void Inimigo::calculaAngulo(){
	this->setAnguloInimigo((GLfloat) (rand() % 360));
}

void Inimigo::reseta(){
	this->x = this->xInicial;
	this->y = this->yInicial;
	this->ligado = false;
	this->voando = false;
	this->distanciaPontos = 0.0;
	this->raio = raioInicial;
	this->tempoRaio = 0.0;
	this->calculaAngulo();
	this->anguloCanhao = 0.0;
	this->anguloHelice = 0.0;
	this->mouseX = 0.0;
	this->velocidade = 0.0;
	this->projeteis.clear();
	this->vive();
}
