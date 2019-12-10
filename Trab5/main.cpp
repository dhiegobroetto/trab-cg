#include <GL/glut.h>
#include <stdio.h>
#include <list>
#include "tinyxml/tinyxml.h"
#include "math.h"
#include "circulo.h"
#include "config.h"
#include "inimigo.h"
#include "linha.h"
#include "arena.h"
#include "jogador.h"
#include "projetil.h"
#include "bomba.h"
#include <sstream>
#include <string>

GLfloat vermelho[] = {1.0, 0.0, 0.0};
GLfloat verde[] = {0.0, 0.8, 0.3};
GLfloat azul[] = {0.0, 0.0, 1.0};
GLfloat laranja[] = {1.0, 0.7, 0.0};
GLfloat amarelo[] = {1.0, 1.0, 0.0};
GLfloat preto[] = {0.0, 0.0, 0.0};
GLint flagCamera = 1;
GLfloat corTexto[] = {1, 1, 1};


GLuint texturaMar;
GLuint texturaMarNegro;
GLuint ceu;
GLuint texturaCeuTopo;
GLuint texturaCeuNoite;
GLuint texturaJogador;
GLuint texturaVoador;
GLuint texturaTerrestre;
GLuint texturaPista;
GLuint texturaBomba;
GLuint texturaProjetilJogador;
GLuint texturaProjetilInimigo;

bool modoNoturno = false;
bool teclaEspaco = false;
bool modoSemTextura = false;
Bomba *bombaComCamera;

// Variáveis globais de configuração
Jogador* jogador;
float larguraDimensao, alturaDimensao;
float fundoR, fundoG, fundoB;
int teclasTeclado[256];
GLfloat tempoAntigo, tempoNovo, tempoAntigoDecolagem, tempoDecolagem, tempoParaIncrementar, tempoParaIncrementarOld;
GLfloat anguloCamera3Horizontal, anguloCamera3Vertical;
bool camera3IsMoving;
int oldMouseX = -1;
int oldMouseY = -1;
GLfloat maiorRaioTerrestre = 0;

// Objetos auxiliares
Arena* arena = NULL;

// ---- Métodos ---- //
GLfloat* retornaCor(std::string fill){
    if(fill.compare("red") == 0){
        return vermelho;
    }
    if(fill.compare("green") == 0){
        return verde;
    }
    if(fill.compare("blue") == 0){
        return azul;
    }
    if(fill.compare("orange") == 0){
        return laranja;
    }
    return NULL;
}

void keyPress(unsigned char key, int x, int y){
    teclasTeclado[key] = 1;
    if(key == 'l'){
        arena->trocaIluminacao();
        habilitaIluminacao(arena->getIluminacao());
    }
    if(key == 'n'){
        modoNoturno = !modoNoturno;
    }
    if(key == ' '){
        teclaEspaco = true;
    }
    if(key == 't'){
        modoSemTextura = !modoSemTextura;
        trocaTextura(modoSemTextura);
    }
}

void keyup(unsigned char key, int x, int y){
    teclasTeclado[key] = 0;
    if(key == ' '){
        teclaEspaco = false;
    }
}

void limpaTeclas(){
    for(int i = 0; i < 256; i++){
        teclasTeclado[i] = 0;
    }
}

void mouseAction(int button, int state, int x, int y){
    if(jogador->isVoando() && jogador->isVivo() && arena->getInimigosTerrestres().size() > 0){
        GLfloat raio = jogador->getRaio();
        GLfloat anguloHorizontal = jogador->getAnguloJogador() *M_PI/180;
        GLfloat anguloVertical = jogador->getAnguloJogadorVertical() *M_PI/180;
        GLfloat anguloCanhaoHorizontal = jogador->getAnguloCanhao() *M_PI/180;
        GLfloat anguloCanhaoVertical = jogador->getAnguloCanhaoVertical() *M_PI/180;

        GLfloat distPontaAviao_x = raio*cos(anguloVertical)*cos(anguloHorizontal);
        GLfloat distPontaAviao_y = raio*cos(anguloVertical)*sin(anguloHorizontal);
        GLfloat distPontaAviao_z = raio*sin(anguloVertical);

        GLfloat distPontaCanhao_x = raio/2*cos(anguloCanhaoVertical + anguloVertical)*cos(anguloCanhaoHorizontal + anguloHorizontal);
        GLfloat distPontaCanhao_y = raio/2*cos(anguloCanhaoVertical + anguloVertical)*sin(anguloCanhaoHorizontal + anguloHorizontal);
        GLfloat distPontaCanhao_z = raio/2*sin(anguloCanhaoVertical + anguloVertical);

        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
            Projetil *p = new Projetil(
                jogador->getX() + distPontaAviao_x + distPontaCanhao_x,
                jogador->getY() + distPontaAviao_y + distPontaCanhao_y,
                jogador->getZ() + distPontaAviao_z + distPontaCanhao_z,
                (GLfloat) (jogador->getRaio()*0.1),
                (GLfloat) 0.0,
                (GLfloat) 0.0,
                (GLfloat) 0.0,
                jogador->getVelocidade() * jogador->getVelocidadeMultiplicadora() * jogador->getVelocidadeTiro(),
                jogador->getAnguloCanhao(),
                jogador->getAnguloJogador(),
                jogador->getAnguloCanhaoVertical() + jogador->getAnguloJogadorVertical(),
                (GLfloat) (jogador->getRaio() / 2),
                (GLfloat) (jogador->getRaio() - 1)
            );
            jogador->addProjetil(p);
        }
        if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && jogador->getAnguloJogadorVertical() == 0 && !teclaEspaco){
            Bomba *b = new Bomba(
                jogador->getX(),
                jogador->getY(),
                jogador->getZ(),
                (GLfloat) (jogador->getRaio()/3),
                (GLfloat) 0.0,
                (GLfloat) 0.0,
                (GLfloat) 0.0,
                jogador->getVelocidade() * jogador->getVelocidadeMultiplicadora(),
                jogador->getAnguloJogador(),
                arena
            );
            jogador->addBomba(b);

            if(!arena->hasCamera()){
                arena->setCamera(true);
                b->setCamera(true);
                bombaComCamera = b;
            }
        }
    }

    if(button == GLUT_RIGHT_BUTTON && flagCamera == 3){
        if(state == GLUT_DOWN && teclaEspaco){
          camera3IsMoving = true;
        }else if(state == GLUT_UP){
          camera3IsMoving = false;
        }
    }
}

void mouseMove(int x, int y){
    if(jogador->isVoando() && jogador->isVivo() && arena->getInimigosTerrestres().size() > 0){
        if(jogador->getMouseX() == 0.0){
            jogador->setMouseX(x);
        }else{
            GLfloat angulo = (jogador->getMouseX() - x) / 2.0;
            if(jogador->getAnguloCanhao() + angulo >= -30 && jogador->getAnguloCanhao() + angulo <= 30){
                jogador->setAnguloCanhao(angulo);
            }
        }
        jogador->setMouseX(x);

        if(jogador->getMouseY() == 0.0){
            jogador->setMouseY(y);
        }else{
            GLfloat anguloVertical = (jogador->getMouseY() - y) / 2.0;
            if(jogador->getAnguloCanhaoVertical() + anguloVertical >= -30 && jogador->getAnguloCanhaoVertical() + anguloVertical <= 30){
                jogador->setAnguloCanhaoVertical(anguloVertical);
            }
        }
        jogador->setMouseY(y);
    }

    oldMouseX = x;
    oldMouseY = y;
}

void desenhaMinimapaCompleto(){
    glMatrixMode (GL_PROJECTION);
    //Push to recover original PROJECTION MATRIX
    glPushMatrix();
        glLoadIdentity();
        glOrtho(-250,250,-250,250,-1,1);
        glPushAttrib(GL_ENABLE_BIT);
        glDisable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
            arena->desenhaMinimapa(arena->getRaio());
        glPopAttrib();
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}


void RasterChars(GLfloat x, GLfloat y, GLfloat z, const char * text, double r, double g, double b)
{
    //Push to recover original attributes
    glPushAttrib(GL_ENABLE_BIT);
        glDisable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        //Draw text in the x, y, z position
        glColor3f(r,g,b);
        glRasterPos3f(x, y, z);
        const char* tmpStr;
        tmpStr = text;
        while( *tmpStr ){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *tmpStr);
            tmpStr++;
        }
    glPopAttrib();
}

void PrintText(GLfloat x, GLfloat y, const char * text, double r, double g, double b)
{
    //Draw text considering a 2D space (disable all 3d features)
    //Push to recover original PROJECTION MATRIX
    glMatrixMode (GL_PROJECTION);
        glPushMatrix();
                glLoadIdentity ();
                glOrtho(0,100,0,100,-1,1);
                RasterChars(x, y, 0, text, r, g, b);
        glPopMatrix();
    glMatrixMode (GL_MODELVIEW);

}

void exibePontuacao(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b){
    glMatrixMode (GL_PROJECTION);
        glPushMatrix();
            char text[50];
            sprintf(text, "%d/%d bases destruidas.", (int)arena->getInimigosTerrestresMortos().size(), (int)(arena->getInimigosTerrestresMortos().size() + arena->getInimigosTerrestres().size()));
            glLoadIdentity ();
            glOrtho(0,100,0,100,-1,1);
            RasterChars(x, y, 0, text, r, g, b);
        glPopMatrix();
    glMatrixMode (GL_MODELVIEW);
}


void mouseClickedMove(int x, int y){
    if(camera3IsMoving){
      int newVertAng = anguloCamera3Vertical + (y - oldMouseY)*0.5;
      if(newVertAng <= 60 && newVertAng >= -60)
        anguloCamera3Vertical = newVertAng;

        int newHorizAng = anguloCamera3Horizontal - (x - oldMouseX)*0.5;
        anguloCamera3Horizontal = newHorizAng;
    }
    oldMouseX = x;
    oldMouseY = y;
}

void configCamera1(){
  GLfloat raio = jogador->getRaio();
  GLfloat anguloHorizontal = jogador->getAnguloJogador() *M_PI/180;
  GLfloat anguloVertical = jogador->getAnguloJogadorVertical() *M_PI/180;

  GLfloat distPontaAviao_x = raio*cos(anguloVertical)*cos(anguloHorizontal);
  GLfloat distPontaAviao_y = raio*cos(anguloVertical)*sin(anguloHorizontal);
  GLfloat distPontaAviao_z = raio*sin(anguloVertical);

  GLfloat distCamera_x = raio*cos((anguloVertical+45))*cos(anguloHorizontal)*0.8;
  GLfloat distCamera_y = raio*cos((anguloVertical+45))*sin(anguloHorizontal)*0.8;
  GLfloat distCamera_z = raio*sin((anguloVertical+45))*0.8;

  gluLookAt(jogador->getX() + distCamera_x,
      jogador->getY() + distCamera_y,
      jogador->getZ() + distCamera_z,
      jogador->getX() + distPontaAviao_x*2,
      jogador->getY() + distPontaAviao_y*2,
      jogador->getZ() + distPontaAviao_z*2,
      0, 0, 1);
}

void configCamera2() {
  GLfloat raio = jogador->getRaio();
  GLfloat anguloHorizontal = jogador->getAnguloJogador() *M_PI/180;
  GLfloat anguloVertical = jogador->getAnguloJogadorVertical() *M_PI/180;

  GLfloat distPontaAviao_x = raio*cos(anguloVertical)*cos(anguloHorizontal);
  GLfloat distPontaAviao_y = raio*cos(anguloVertical)*sin(anguloHorizontal);
  GLfloat distPontaAviao_z = raio*sin(anguloVertical);

  GLfloat anguloCanhaoHorizontal = jogador->getAnguloCanhao() *M_PI/180;
  GLfloat anguloCanhaoVertical = jogador->getAnguloCanhaoVertical() *M_PI/180;

  GLfloat distPontaCanhao_x = raio/2*cos(anguloCanhaoVertical + anguloVertical)*cos(anguloCanhaoHorizontal + anguloHorizontal);
  GLfloat distPontaCanhao_y = raio/2*cos(anguloCanhaoVertical + anguloVertical)*sin(anguloCanhaoHorizontal + anguloHorizontal);
  GLfloat distPontaCanhao_z = raio/2*sin(anguloCanhaoVertical + anguloVertical);

  GLfloat alturaCamera_x = raio/5*cos(anguloVertical + M_PI/2)*cos(anguloHorizontal);
  GLfloat alturaCamera_y = raio/5*cos(anguloVertical + M_PI/2)*sin(anguloHorizontal);
  GLfloat alturaCamera_z = raio/5*sin(anguloVertical + M_PI/2);

  GLfloat alturaCameraLookTo_x = raio/5*cos(anguloCanhaoVertical + anguloVertical + M_PI/2)*cos(anguloCanhaoHorizontal + anguloHorizontal);
  GLfloat alturaCameraLookTo_y = raio/5*cos(anguloCanhaoVertical + anguloVertical + M_PI/2)*sin(anguloCanhaoHorizontal + anguloHorizontal);
  GLfloat alturaCameraLookTo_z = raio/5*sin(anguloCanhaoVertical + anguloVertical + M_PI/2);

  gluLookAt(jogador->getX() + distPontaAviao_x + alturaCamera_x,
      jogador->getY() + distPontaAviao_y + alturaCamera_y,
      jogador->getZ() + distPontaAviao_z + alturaCamera_z,
      jogador->getX() + distPontaAviao_x + distPontaCanhao_x + alturaCameraLookTo_x,
      jogador->getY() + distPontaAviao_y + distPontaCanhao_y + alturaCameraLookTo_y,
      jogador->getZ() + distPontaAviao_z + distPontaCanhao_z + alturaCameraLookTo_z,
      0, 0, 1);
}

void configCamera3(){
  GLfloat raio = jogador->getRaio()*5;
  GLfloat anguloJogadorHorizontal = jogador->getAnguloJogador() *M_PI/180;

  GLfloat anguloHorizontal = anguloCamera3Horizontal *M_PI/180 + anguloJogadorHorizontal + M_PI;
  GLfloat anguloVertical = anguloCamera3Vertical *M_PI/180;

  GLfloat distCamera_x = raio*cos((anguloVertical))*cos(anguloHorizontal);
  GLfloat distCamera_y = raio*cos((anguloVertical))*sin(anguloHorizontal);
  GLfloat distCamera_z = raio*sin((anguloVertical));

  gluLookAt(jogador->getX() + distCamera_x,
      jogador->getY() + distCamera_y,
      jogador->getZ() + distCamera_z,
      jogador->getX(),
      jogador->getY(),
      jogador->getZ(),
      0, 0, 1);
}

void configCamera(){
  switch (flagCamera) {
    case 1:
        PrintText(0, 95, "Camera 1", corTexto[0], corTexto[1], corTexto[2]);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60, (arena->getRaio() * 2) / (arena->getRaio() * 2), arena->getJogador()->getRaio()*0.3, arena->getRaio() * 3);
        glMatrixMode(GL_MODELVIEW);
        configCamera1();
        break;
    case 2:
        PrintText(0, 95, "Camera 2", corTexto[0], corTexto[1], corTexto[2]);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60, (arena->getRaio() * 2) / (arena->getRaio() * 2), 1, arena->getRaio() * 3);
        glMatrixMode(GL_MODELVIEW);
        configCamera2();
        break;
    case 3:
        PrintText(0, 95, "Camera 3", corTexto[0], corTexto[1], corTexto[2]);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60, (arena->getRaio() * 2) / (arena->getRaio() * 2), 1, arena->getRaio() * 3);
        glMatrixMode(GL_MODELVIEW);
        configCamera3();
        break;
  }
}

void drawArena(GLuint texturaMar, GLuint texturaMarNegro, GLuint texturaJogador, GLuint texturaTerrestre, GLuint texturaVoador, GLuint texturaPista, GLuint texturaBomba, GLuint texturaProjetilJogador, GLuint texturaProjetilInimigo, GLuint ceu, GLuint texturaCeuTopo, GLuint texturaCeuNoite){
	// Inicialização das variáveis
	Linha* linha = arena->getLinha();
	std::list<Inimigo*> inimigosAereos = arena->getInimigosAereos();
	std::list<Circulo*> inimigosTerrestres = arena->getInimigosTerrestres();

	if(modoNoturno){
		corTexto[0] = 1;
		corTexto[1] = 1;
		corTexto[2] = 1;
		glDisable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
	}else{
		corTexto[0] = 0;
		corTexto[1] = 0;
		corTexto[2] = 0;
		glEnable(GL_LIGHT0);
		glDisable(GL_LIGHT1);
	}

	configuraIluminacao();

	if(arena != NULL){
	  arena->desenhaArena(modoNoturno, ceu, texturaCeuTopo, texturaCeuNoite, texturaMar, texturaMarNegro);
	}

	if(jogador != NULL){
	  jogador->desenhaJogador(texturaJogador, texturaProjetilJogador);
	}

	if(linha != NULL){
	  linha->desenhaLinha(texturaPista);
	}

	for(std::list<Circulo*>::iterator c = inimigosTerrestres.begin(); c != inimigosTerrestres.end(); ++c){
	  (*c)->desenha(texturaTerrestre);
	}

	if(jogador != NULL){
	  jogador->desenhaBombas(texturaBomba);
	}

	for(std::list<Inimigo*>::iterator c = inimigosAereos.begin(); c != inimigosAereos.end(); ++c){
	  (*c)->desenhaInimigo(texturaVoador, texturaProjetilInimigo);
	}
}

void display(void){
    jogador = arena->getJogador();
    // Limpar todos os pixels
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0,larguraDimensao,larguraDimensao,200);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 5/2, 1, arena->getRaio() * 3);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if(arena->hasCamera()){
        gluLookAt(bombaComCamera->getX(), bombaComCamera->getY(), bombaComCamera->getZ()-bombaComCamera->getRaio()-1,
                bombaComCamera->getX(), bombaComCamera->getY(), 0,
                0, 1, 0);
        drawArena(texturaMar, texturaMarNegro, texturaJogador, texturaTerrestre, texturaVoador, texturaPista, texturaBomba, texturaProjetilJogador, texturaProjetilInimigo, ceu, texturaCeuTopo, texturaCeuNoite);
    }
    glViewport(0, 0, larguraDimensao, alturaDimensao);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    exibePontuacao(57, 95, corTexto[0], corTexto[1], corTexto[2]);

    if(jogador != NULL){
        if(!jogador->isLigado() && !jogador->isVoando()){
            PrintText(27, 55, "Pressione U para decolar.", corTexto[0], corTexto[1], corTexto[2]);
        }
        if(!jogador->isVivo()){
            PrintText(35, 60, "Game Over!", corTexto[0], corTexto[1], corTexto[2]);
            PrintText(17, 55, "Pressione R para jogar novamente!", corTexto[0], corTexto[1], corTexto[2]);
            arena->setCamera(false);
        }
        if(jogador->isVivo() && arena->getInimigosTerrestres().size() == 0){
            PrintText(37, 60, "Voce venceu!", corTexto[0], corTexto[1], corTexto[2]);
            PrintText(17, 55, "Pressione R para jogar novamente!", corTexto[0], corTexto[1], corTexto[2]);
        }
    }

    desenhaMinimapaCompleto();

    configCamera();
    drawArena(texturaMar, texturaMarNegro, texturaJogador, texturaTerrestre, texturaVoador, texturaPista, texturaBomba, texturaProjetilJogador, texturaProjetilInimigo, ceu, texturaCeuTopo, texturaCeuNoite);

    glutSwapBuffers();
}

void inicializaInimigosAereos(GLfloat vel){
    for(Inimigo* c : arena->getInimigosAereos()){
        c->setVelocidade(vel);
        c->setTempoIA(glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        c->setTempoAtira(glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        c->setVoando(true);
    }
}

void atualizaTempoInimigosAereos(GLfloat tempo){
    for(Inimigo* c : arena->getInimigosAereos()){
        c->setTempoAjustador(tempo);
    }
}

GLfloat calculaVelocidadeFinal(){
    GLfloat dx = arena->getLinha()->getX2() - arena->getLinha()->getX1();
    GLfloat x = 2 * dx / pow(4.0, 2);

    GLfloat dy = arena->getLinha()->getY2() - arena->getLinha()->getY1();
    GLfloat y = 2 * dy / pow(4.0, 2);
    return sqrt(pow(x, 2) + pow(y, 2)) * 4.0;
}

void idle(void){
    Jogador* jogador = arena->getJogador();
    GLfloat curva = 100.0;
    // Cálculo do tempo de sincronização.
    tempoNovo = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    GLfloat t = tempoNovo - tempoAntigo;
    tempoAntigo = tempoNovo;
    jogador->setTempoAjustador(t);
    atualizaTempoInimigosAereos(t);

    if(jogador->isVivo() && arena->getInimigosTerrestres().size() > 0){
        if(teclasTeclado['1']){
            if(flagCamera != 1){
              flagCamera = 1;
              camera3IsMoving = false;
            }
        }
        if(teclasTeclado['2']){
            if(flagCamera != 2){
              flagCamera = 2;
              camera3IsMoving = false;
            }
        }
        if(teclasTeclado['3']){
            if(flagCamera != 3){
              flagCamera = 3;
              anguloCamera3Vertical = 60;
              anguloCamera3Horizontal = 0;
            }
        }

        if(arena->getInimigosAereos().size() > 0 && !arena->getInimigosAereos().front()->isVoando()){
            inicializaInimigosAereos(calculaVelocidadeFinal());
        }
        arena->voaInimigosAereos(curva, t);
        if((teclasTeclado['u'] || teclasTeclado['U']) && !jogador->isLigado()){
            jogador->setLigado(true);
            tempoAntigoDecolagem = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
            tempoParaIncrementarOld = tempoAntigoDecolagem;
        }
        if(jogador->isLigado() && !jogador->isVoando()){
            tempoDecolagem = (glutGet(GLUT_ELAPSED_TIME) / 1000.0) - tempoAntigoDecolagem;
            tempoParaIncrementar = (glutGet(GLUT_ELAPSED_TIME) / 1000.0);
            jogador->decola(arena->getLinha(), tempoParaIncrementar - tempoParaIncrementarOld, tempoDecolagem);
            tempoParaIncrementarOld = tempoParaIncrementar;
        }
        if(jogador->isLigado() && jogador->isVoando()){
            GLfloat vel = jogador->getVelocidade();
            if(teclasTeclado['a'] || teclasTeclado['A']){
                jogador->moveX(curva);
            }else if(teclasTeclado['d'] || teclasTeclado['D']){
                jogador->moveX(-curva);
            } else {
              jogador->resetX(curva*jogador->getVelocidade()*jogador->getVelocidadeMultiplicadora()/103);
            }
            if((teclasTeclado['w'] || teclasTeclado['W']) && jogador->getZ() < arena->getRaio() - 105){
                jogador->moveZ(curva);
            }else if((teclasTeclado['s'] || teclasTeclado['S']) && jogador->getZ() > maiorRaioTerrestre + 80){
                jogador->moveZ(-curva);
            } else {
              jogador->resetZ(curva*jogador->getVelocidade()*jogador->getVelocidadeMultiplicadora()/103);
            }
            if(teclasTeclado['='] || teclasTeclado['+']){
                jogador->incrementaVelocidade(3.0);
            }
            if(teclasTeclado['-']){
                jogador->decrementaVelocidade(3.0);
            }
            jogador->voa(vel);
            jogador->voaProjeteis(t);
            jogador->voaBombas(t);
        }
    }
    if(teclasTeclado['r']){
        jogador->reseta();
        arena->reseta();
        limpaTeclas();
        anguloCamera3Vertical = 60;
        anguloCamera3Horizontal = 0;
    }

    glutPostRedisplay();
}

void init(float fundoR, float fundoG, float fundoB){
    glClearColor(fundoR, fundoG, fundoB, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Iniciar sistema de visão
    gluPerspective(60, (arena->getRaio() * 2) / (arena->getRaio() * 2), arena->getJogador()->getRaio()*0.3, arena->getRaio() * 3);
    glMatrixMode(GL_MODELVIEW);

    texturaMar = LoadTextureRAW("texturas/mar.bmp");
    texturaMarNegro = LoadTextureRAW("texturas/marNegro.bmp");
    ceu = LoadTextureRAW("texturas/ceu.bmp");
    texturaCeuTopo = LoadTextureRAW("texturas/ceuTopo.bmp");
    texturaCeuNoite = LoadTextureRAW("texturas/ceuNoite.bmp");
    texturaJogador = LoadTextureRAW("texturas/jogador.bmp");
    texturaVoador = LoadTextureRAW("texturas/inimigo.bmp");
    texturaTerrestre = LoadTextureRAW("texturas/inimigoTerrestre.bmp");
    texturaPista = LoadTextureRAW("texturas/pista.bmp");
    texturaBomba = LoadTextureRAW("texturas/bomba.bmp");
    texturaProjetilJogador = LoadTextureRAW("texturas/tiro.bmp");
    texturaProjetilInimigo = LoadTextureRAW("texturas/tiroInimigo.bmp");
    
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
}

bool lerXML(char* caminhoArquivo){
    TiXmlDocument doc(strcat(caminhoArquivo, "/config.xml"));
    doc.LoadFile();
    TiXmlElement *aplicacao = doc.RootElement();
    if(aplicacao !=  NULL){
        // Declaração de variáveis
        TiXmlElement *arquivoDaArena = NULL;
        TiXmlElement *nome = NULL;
        TiXmlElement *tipo = NULL;
        TiXmlElement *caminho = NULL;
        TiXmlElement *jogadorElemento = NULL;
        TiXmlElement *inimigoElemento = NULL;

        // Atribui valores
        arquivoDaArena = aplicacao->FirstChildElement("arquivoDaArena");
        nome = arquivoDaArena->FirstChildElement("nome");
        tipo = arquivoDaArena->FirstChildElement("tipo");
        caminho = arquivoDaArena->FirstChildElement("caminho");
        jogadorElemento = aplicacao->FirstChildElement("jogador");
        inimigoElemento = aplicacao->FirstChildElement("inimigo");

        // Abre arquivo SVG
        std::string arquivoSVG = (std::string)caminho->GetText() + '/' + (std::string)nome->GetText() + '.' + (std::string)tipo->GetText();
        const char *abrirArquivo = arquivoSVG.c_str();
        TiXmlDocument svgFile(abrirArquivo);
        svgFile.LoadFile();

        // Leitura da arena
        TiXmlElement *arenaElement = svgFile.RootElement();
        if(arenaElement != NULL) {
            TiXmlElement *circuloElemento = NULL;
            circuloElemento = arenaElement->FirstChildElement("circle");

            GLint id;
            GLfloat arenaX, arenaY, arenaRaio;
            GLfloat cx, r, cy, *cores;

            // Leitura de círculos
            while(circuloElemento){
                // Leitura da arena
                if(((std::string)circuloElemento->Attribute("fill")).compare("blue") == 0){
                    arenaRaio = atof(circuloElemento->Attribute("r"));
                    larguraDimensao = 500;
                    alturaDimensao = 500;
                    id = atoi(circuloElemento->Attribute("id"));
                    cores = retornaCor(circuloElemento->Attribute("fill"));
                    arenaX = arenaY = 0.0;
                    arena = new Arena(id, arenaRaio, arenaX, arenaY, cores[0], cores[1], cores[2]);
                    arenaX = atof(circuloElemento->Attribute("cx"));
                    arenaY = alturaDimensao - atof(circuloElemento->Attribute("cy"));
                    break;
                }
                circuloElemento = circuloElemento->NextSiblingElement("circle");
            }
            circuloElemento = arenaElement->FirstChildElement("circle");
            while(circuloElemento){
                // Leitura dos demais círculos
                id = atoi(circuloElemento->Attribute("id"));
                r = atof(circuloElemento->Attribute("r"));
                cx = atof(circuloElemento->Attribute("cx")) - arenaX;
                cy = alturaDimensao - atof(circuloElemento->Attribute("cy")) - arenaY;
                cores = retornaCor(circuloElemento->Attribute("fill"));

                // Leitura do jogador
                if(((std::string)circuloElemento->Attribute("fill")).compare("green") == 0){
                    r *= 2;
                    Jogador* jogador = new Jogador(id, r, cx, cy, cores[0], cores[1], cores[2], arena);
                    GLfloat vel = atof(jogadorElemento->Attribute("vel"));
                    GLfloat velTiro = atof(jogadorElemento->Attribute("velTiro"));

                    // Velocidade no final da decolagem
                    jogador->setVelocidadeMultiplicadora(vel);
                    jogador->setVelocidadeTiro(velTiro);
                    arena->setJogador(jogador);

                    // Leitura dos inimigos aéreos
                }else if(((std::string)circuloElemento->Attribute("fill")).compare("red") == 0){
                    GLfloat vel = atof(inimigoElemento->Attribute("vel"));
                    GLfloat velTiro = atof(inimigoElemento->Attribute("velTiro"));
                    GLfloat freqTiro = atof(inimigoElemento->Attribute("freqTiro"));
                    arena->criaInimigosAereos(id, r, cx, cy, cores[0], cores[1], cores[2], arena, vel, velTiro, freqTiro);

                    // Leitura dos inimigos terrestres
                }else if(((std::string)circuloElemento->Attribute("fill")).compare("orange") == 0){
                    arena->criaInimigosTerrestres(id, r, cx, cy, cores[0], cores[1], cores[2]);
                    if(r > maiorRaioTerrestre)
                      maiorRaioTerrestre = r;
                }

                // circulo++
                circuloElemento = circuloElemento->NextSiblingElement("circle");
            }

            TiXmlElement *linhaElemento = NULL;
            linhaElemento = arenaElement->FirstChildElement("line");

            // Leitura da pista de lançamento (linha)
            if(linhaElemento != NULL){

                // Parse das cores
                std::string estiloLinha = linhaElemento->Attribute("style");
                int inicio, fim;
                inicio = estiloLinha.find("(") + 1;
                fim = estiloLinha.find(")") - inicio;
                std::string coresLinha = estiloLinha.substr(inicio, fim);

                // Atribuindo valores
                GLint id = atoi(linhaElemento->Attribute("id"));
                GLfloat x1 = atof(linhaElemento->Attribute("x1")) - arenaX;
                GLfloat y1 = alturaDimensao - atof(linhaElemento->Attribute("y1")) - arenaY;
                GLfloat x2 = atof(linhaElemento->Attribute("x2")) - arenaX;
                GLfloat y2 = alturaDimensao - atof(linhaElemento->Attribute("y2")) - arenaY;
                std::stringstream coresStream(coresLinha);
                GLfloat cor[3];
                int i = 0;
                while(std::getline(coresStream,coresLinha,',')){
                    cor[i++] = stof(coresLinha);
                }
                Linha* linha = new Linha(id, x1, y1, x2, y2, cor[0], cor[1], cor[2]);
                arena->setLinha(linha);
                arena->getJogador()->calculaPontoCrescimento(linha);
                arena->getJogador()->calculaAngulo(linha);
                arena->setMaiorRaioTerrestre(maiorRaioTerrestre);
            }
            return true;
        }else{
            std::cout << "Arquivo arena.svg não encontrado! Certifique-se de colocar o caminho do arquivo arena.svg no config.xml." << std::endl;
            return false;
        }
    }else{
        std::cout << "Arquivo config.xml não encontrado!" << std::endl;
        return false;
    }
}

int main(int argc, char** argv){
    srand(time(NULL));
    if(argc > 1){
        if(lerXML(argv[1])){
            fundoR = 0.0;
            fundoG = 0.0;
            fundoB = 0.0;
            tempoAntigo = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
            // Inicializa
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
            glutInitWindowSize(larguraDimensao, alturaDimensao+200);
            glutInitWindowPosition(50, 50);
            glutCreateWindow("Airplane Combat");
            init(fundoR, fundoG, fundoB);
            glutDisplayFunc(display);
            glutKeyboardUpFunc(keyup);
            glutKeyboardFunc(keyPress);
            glutMouseFunc(mouseAction);
            glutPassiveMotionFunc(mouseMove);
            glutMotionFunc(mouseClickedMove);
            glutIdleFunc(idle);
            glutMainLoop();
        }
    }else{
        std::cout << "Localização do arquivo config.xml não foi informada." << std::endl;
    }

    return 0;
}
