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

// Variáveis globais de configuração
Jogador* jogador;
float larguraDimensao, alturaDimensao;
float fundoR, fundoG, fundoB;
int teclasTeclado[256];
GLfloat tempoAntigo, tempoNovo, tempoAntigoDecolagem, tempoDecolagem;

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
}

void keyup(unsigned char key, int x, int y){
  teclasTeclado[key] = 0;
}

void limpaTeclas(){
    for(int i = 0; i < 256; i++){
        teclasTeclado[i] = 0;
    }
}

void mouseAction(int button, int state, int x, int y){
    if(jogador->isVoando() && jogador->isVivo()){
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
            Projetil *p = new Projetil(
                jogador->getX() + ((jogador->getRaio()) * cos(jogador->getAnguloJogador() * M_PI / 180)) + (jogador->getRaio()/2) * cos(jogador->getAnguloJogador() * M_PI / 180 + jogador->getAnguloCanhao() * M_PI / 180),
                jogador->getY() + ((jogador->getRaio()) * sin(jogador->getAnguloJogador() * M_PI / 180)) + (jogador->getRaio()/2) * sin(jogador->getAnguloJogador() * M_PI / 180 + jogador->getAnguloCanhao() * M_PI / 180),
                (GLfloat) (jogador->getRaio()/8),
                (GLfloat) 0.0,
                (GLfloat) 0.0,
                (GLfloat) 0.0,
                jogador->getVelocidade() * jogador->getVelocidadeMultiplicadora() * jogador->getVelocidadeTiro(),
                jogador->getAnguloCanhao(),
                jogador->getAnguloJogador(),
                (GLfloat) (jogador->getRaio() / 2),
                (GLfloat) (jogador->getRaio() - 1)
            );
            jogador->addProjetil(p);
        }
        if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
            Bomba *b = new Bomba(
                jogador->getX(),
                jogador->getY(),
                (GLfloat) (jogador->getRaio()/3),
                (GLfloat) 0.0,
                (GLfloat) 0.0,
                (GLfloat) 0.0,
                jogador->getVelocidade() * jogador->getVelocidadeMultiplicadora(),
                jogador->getAnguloJogador()
            );
            jogador->addBomba(b);
        }
    }

}

void mouseMove(int x, int y){
    if(jogador->isVoando() && jogador->isVivo()){
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
}

void configCamera1(){
  GLfloat distPontaAviao_x = jogador->getRaio()*cos(jogador->getAnguloJogadorVertical() *M_PI/180)*cos(jogador->getAnguloJogador() *M_PI/180);
  GLfloat distPontaAviao_y = jogador->getRaio()*cos(jogador->getAnguloJogadorVertical() *M_PI/180)*sin(jogador->getAnguloJogador() *M_PI/180);
  GLfloat distPontaAviao_z = jogador->getRaio()*sin(jogador->getAnguloJogadorVertical() *M_PI/180);

  GLfloat distCamera_x = jogador->getRaio()*cos((jogador->getAnguloJogadorVertical()+45) *M_PI/180)*cos(jogador->getAnguloJogador() *M_PI/180)*0.8;
  GLfloat distCamera_y = jogador->getRaio()*cos((jogador->getAnguloJogadorVertical()+45) *M_PI/180)*sin(jogador->getAnguloJogador() *M_PI/180)*0.8;
  GLfloat distCamera_z = jogador->getRaio()*sin((jogador->getAnguloJogadorVertical()+45) *M_PI/180)*0.8;

  gluLookAt(jogador->getX() + distCamera_x,
      jogador->getY() + distCamera_y,
      jogador->getZ() + distCamera_z,
      jogador->getX() + distPontaAviao_x*2,
      jogador->getY() + distPontaAviao_y*2,
      jogador->getZ() + distPontaAviao_z*2,
      0, 0, 1);
}

void configCamera2() {
  GLfloat distPontaAviao_x = jogador->getRaio()*cos(jogador->getAnguloJogadorVertical() *M_PI/180)*cos(jogador->getAnguloJogador() *M_PI/180);
  GLfloat distPontaAviao_y = jogador->getRaio()*cos(jogador->getAnguloJogadorVertical() *M_PI/180)*sin(jogador->getAnguloJogador() *M_PI/180);
  GLfloat distPontaAviao_z = jogador->getRaio()*sin(jogador->getAnguloJogadorVertical() *M_PI/180);

  gluLookAt(jogador->getX() + distPontaAviao_x,
      jogador->getY() + distPontaAviao_y,
      jogador->getZ() + distPontaAviao_z,
      jogador->getX() + distPontaAviao_x*2,
      jogador->getY() + distPontaAviao_y*2,
      jogador->getZ() + distPontaAviao_z*2,
      0, 0, 1);
}

void configCamera(){
  switch (flagCamera) {
    case 1:
      configCamera1();
      break;
    case 2:
      configCamera2();
      break;
    // case 3:
    //   configCamera3();
    //   break;
  }
}

void display(void){
    // Inicialização das variáveis
    float theta, px, py;
    jogador = arena->getJogador();
    Linha* linha = arena->getLinha();
    std::list<Inimigo*> inimigosAereos = arena->getInimigosAereos();
    std::list<Circulo*> inimigosTerrestres = arena->getInimigosTerrestres();
    // Limpar todos os pixels
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    configCamera();

    GLfloat posicaoLuz[] = {arena->getX(), arena->getY(), 1, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    if(arena != NULL){
        arena->desenhaArena();
    }

    if(linha != NULL){
        linha->desenhaLinha();
    }

    for(std::list<Circulo*>::iterator c = inimigosTerrestres.begin(); c != inimigosTerrestres.end(); ++c){
        (*c)->desenha();
    }

    if(jogador != NULL){
        jogador->desenhaBombas();
    }

    if(jogador != NULL){
        jogador->desenhaJogador();
    }

    for(std::list<Inimigo*>::iterator c = inimigosAereos.begin(); c != inimigosAereos.end(); ++c){
        (*c)->desenhaInimigo();
    }
    if(jogador != NULL){
        if(!jogador->isLigado() && !jogador->isVoando()){
            arena->exibeDecolagem(arena->getX() - 110, arena->getY() + 40);
        }
        if(!jogador->isVivo()){
                arena->exibeGameOver(arena->getX() - 155, arena->getY() + 40);
        }
        if(jogador->isVivo() && arena->getInimigosTerrestres().size() == 0){
            arena->exibeVitoria(arena->getX() - 155, arena->getY() + 40);
        }
    }
    arena->exibePontuacao(arena->getX() + arena->getRaio() - 210, arena->getY() + arena->getRaio() - 20);
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
            flagCamera = 1;
        }
        if(teclasTeclado['2']){
            flagCamera = 2;
        }
        if(teclasTeclado['3']){
            flagCamera = 3;
        }

        if(arena->getInimigosAereos().size() > 0 && !arena->getInimigosAereos().front()->isVoando()){
            inicializaInimigosAereos(calculaVelocidadeFinal());
        }
        arena->voaInimigosAereos(curva, t);
        if((teclasTeclado['u'] || teclasTeclado['U']) && !jogador->isLigado()){
            jogador->setLigado(true);
            tempoAntigoDecolagem = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
        }
        if(jogador->isLigado() && !jogador->isVoando()){
            tempoDecolagem = (glutGet(GLUT_ELAPSED_TIME) / 1000.0) - tempoAntigoDecolagem;
            jogador->decola(arena->getLinha(), tempoAntigoDecolagem, tempoDecolagem);
        }
        if(jogador->isLigado() && jogador->isVoando()){
            GLfloat vel = jogador->getVelocidade();
            if(teclasTeclado['a'] || teclasTeclado['A']){
                jogador->moveX(curva);
            }else if(teclasTeclado['d'] || teclasTeclado['D']){
                jogador->moveX(-curva);
            }
            if(teclasTeclado['w'] || teclasTeclado['W']){
                jogador->moveZ(curva);
            }else if(teclasTeclado['s'] || teclasTeclado['S']){
                jogador->moveZ(-curva);
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
    }

    glutPostRedisplay();
}

void init(float fundoR, float fundoG, float fundoB){
    glClearColor(fundoR, fundoG, fundoB, 0.0);
    // glShadeModel(GL_SMOOTH);
    // glEnable(GL_LIGHTING);
    // glEnable(GL_DEPTH_TEST);
    // // glEnable(GL_TEXTURE_2D);
    // glDepthFunc(GL_LEQUAL);
    // glEnable(GL_NORMALIZE);
    // glEnable(GL_LIGHT0);
    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    // Iniciar sistema de visão
    gluPerspective(90, (arena->getRaio() * 2) / (arena->getRaio() * 2), arena->getJogador()->getRaio()*0.3, arena->getRaio() * 2);

    glEnable(GL_DEPTH_TEST);

    //glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);

    glDepthFunc(GL_LEQUAL);

    arena->setTexturaCeu(LoadTextureRAW("sky.bmp"));
    arena->setTexturaMar(LoadTextureRAW("water.bmp"));

    glEnable(GL_LIGHT0);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    GLfloat light_ambient[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat light_diffuse[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_position[] = {arena->getX(), arena->getY(), arena->getRaio(), 1.0};

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    //GLfloat mat_emission[] = {0.1, 0.1, 0.1, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {100.0};

    //glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);




    // glOrtho(
    //     arena->getX() - arena->getRaio(),
    //     arena->getX() + arena->getRaio(),
    //     arena->getY() - arena->getRaio(),
    //     arena->getY() + arena->getRaio(),
    //     -1.0, 1.0);

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
                    larguraDimensao = arenaRaio * 2;
                    alturaDimensao = arenaRaio * 2;
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
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
            glutInitWindowSize(larguraDimensao, alturaDimensao);
            glutInitWindowPosition(50, 50);
            glutCreateWindow("Airplane Combat");
            init(fundoR, fundoG, fundoB);
            glutDisplayFunc(display);
            glutKeyboardUpFunc(keyup);
            glutKeyboardFunc(keyPress);
            glutMouseFunc(mouseAction);
            glutPassiveMotionFunc(mouseMove);
            glutIdleFunc(idle);
            glutMainLoop();
        }
    }else{
        std::cout << "Localização do arquivo config.xml não foi informada." << std::endl;
    }

    return 0;
}
