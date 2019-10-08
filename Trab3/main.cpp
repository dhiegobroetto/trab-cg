#include <GL/glut.h>
#include <stdio.h>
#include <list>
#include "tinyxml/tinyxml.h"
#include "math.h"
#include "circulo.h"
#include "linha.h"
#include "arena.h"
#include "jogador.h"
#include <sstream>
#include <string>

GLfloat vermelho[] = {1.0, 0.0, 0.0};
GLfloat verde[] = {0.0, 0.8, 0.3};
GLfloat azul[] = {0.0, 0.0, 1.0};
GLfloat laranja[] = {1.0, 0.7, 0.0};
GLfloat amarelo[] = {1.0, 1.0, 0.0};
GLfloat preto[] = {0.0, 0.0, 0.0};

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
}

void keyPress(unsigned char key, int x, int y){
  teclasTeclado[key] = 1;
}

void keyup(unsigned char key, int x, int y){
  teclasTeclado[key] = 0;
}

void mouseMove(int x, int y){
    if(jogador->getMouseX() == 0.0){
        jogador->setMouseX(x);
    }
    if(jogador->getAnguloCanhao() == -45 && x >= jogador->getMouseX()){
        std::cout << "Direita" << std::endl;
        jogador->setMouseX(x);
    }else if(jogador->getAnguloCanhao() == 45 && x <= jogador->getMouseX()){
        std::cout << "Esquerda" << std::endl;
        jogador->setMouseX(x);
    }else{
        GLfloat angulo = (jogador->getMouseX() - x) / 2.0;
        std::cout << jogador->getAnguloCanhao() << " " << jogador->getMouseX() << " " << x << std::endl;
        if(angulo >= -45 && angulo <= 45){
            jogador->setAnguloCanhao(angulo);
        }else {
            if(angulo < -45){
                jogador->setAnguloCanhao(-45);
            }else if(angulo > 45){
                jogador->setAnguloCanhao(45);
            }
        }
    }
    
    
}

void display(void){
    // Inicialização das variáveis
    float theta, px, py;
    jogador = arena->getJogador();
    Linha* linha = arena->getLinha();
    list<Circulo*> inimigosAereos = arena->getInimigosAereos();
    list<Circulo*> inimigosTerrestres = arena->getInimigosTerrestres();

    // Limpar todos os pixels
    glClear(GL_COLOR_BUFFER_BIT);

    if(arena != NULL){
        arena->desenhaArena();
    }
    if(linha != NULL){
        linha->desenhaLinha();
    }
    for(list<Circulo*>::iterator c = inimigosAereos.begin(); c != inimigosAereos.end(); ++c){
        (*c)->desenha();
    }
     for(list<Circulo*>::iterator c = inimigosTerrestres.begin(); c != inimigosTerrestres.end(); ++c){
        (*c)->desenha();
    }
    if(jogador != NULL){
        jogador->desenhaJogador();
    }
    glutSwapBuffers();
}

void idle(void){
    Jogador* jogador = arena->getJogador();
    if(teclasTeclado['u'] && !jogador->isLigado()){
        jogador->setLigado(true);
        tempoAntigoDecolagem = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    }
    if(jogador->isLigado() && !jogador->isVoando()){
        tempoDecolagem = (glutGet(GLUT_ELAPSED_TIME) / 1000.0) - tempoAntigoDecolagem;
        jogador->decola(arena->getLinha(), tempoAntigoDecolagem, tempoDecolagem);
    }
    if(jogador->isLigado() && jogador->isVoando()){
        GLfloat vel = jogador->getVelocidade();
        if (teclasTeclado['w'] && teclasTeclado['a'] && teclasTeclado['d']) {
            jogador->moveY(vel);
        }else if (teclasTeclado['a'] && teclasTeclado['s'] && teclasTeclado['d']) {
            jogador->moveY(-vel);
        }else if (teclasTeclado['w'] && teclasTeclado['d']) {
            jogador->moveXY(vel, vel);
        }else if (teclasTeclado['w'] && teclasTeclado['a']) {
            jogador->moveXY(-vel, vel);
        }else if (teclasTeclado['w'] && teclasTeclado['d']) {
            jogador->moveXY(vel, vel);
        }else if (teclasTeclado['a'] && teclasTeclado['s']) {
            jogador->moveXY(-vel, -vel);
        }else if (teclasTeclado['s'] && teclasTeclado['d']) {
            jogador->moveXY(vel, -vel);
        }else if (teclasTeclado['w'] && teclasTeclado['a']) {
            jogador->moveXY(-vel, vel);
        }else if (teclasTeclado['w'] && teclasTeclado['d']) {
            jogador->moveXY(vel, vel);
        }else if (teclasTeclado['a'] && teclasTeclado['s']) {
            jogador->moveXY(-vel, -vel);
        }else if (teclasTeclado['s'] && teclasTeclado['d']) {
            jogador->moveXY(vel, -vel);
        }else if(teclasTeclado['w']){
            jogador->moveY(vel);
        }else if(teclasTeclado['a']){
            jogador->moveX(3.0);
        }else if(teclasTeclado['s']){
            jogador->moveY(-vel);
        }else if(teclasTeclado['d']){
            jogador->moveX(-3.0);
        }
        jogador->voa(vel);
    }
    
    // Cálculo do tempo de sincronização.
    tempoNovo = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    GLfloat t = tempoNovo - tempoAntigo;
    tempoAntigo = tempoNovo;
    jogador->setTempoAjustador(t);
    glutPostRedisplay();
}

void init(float fundoR, float fundoG, float fundoB){
    glClearColor(fundoR, fundoG, fundoB, 0.0);

    // Iniciar sistema de viz
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(
        arena->getX() - arena->getRaio(), 
        arena->getX() + arena->getRaio(), 
        arena->getY() - arena->getRaio(), 
        arena->getY() + arena->getRaio(), 
        -1.0, 1.0);
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

        // Atribui valores
        arquivoDaArena = aplicacao->FirstChildElement("arquivoDaArena");
        nome = arquivoDaArena->FirstChildElement("nome");
        tipo = arquivoDaArena->FirstChildElement("tipo");
        caminho = arquivoDaArena->FirstChildElement("caminho");
        jogadorElemento = aplicacao->FirstChildElement("jogador");

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
            GLfloat cx, r, cy, *cores;

            // Leitura de círculos
            while(circuloElemento){
                // Leitura da arena
                if(((std::string)circuloElemento->Attribute("fill")).compare("blue") == 0){
                    r = atof(circuloElemento->Attribute("r"));
                    larguraDimensao = r * 2;
                    alturaDimensao = r * 2;
                    id = atoi(circuloElemento->Attribute("id"));
                    cx = atof(circuloElemento->Attribute("cx")) - 500;
                    cy = alturaDimensao - atof(circuloElemento->Attribute("cy")) - 100;
                    cores = retornaCor(circuloElemento->Attribute("fill"));
                    arena = new Arena(id, r, cx, cy, cores[0], cores[1], cores[2]);
                    break;
                }
                circuloElemento = circuloElemento->NextSiblingElement("circle");
            }
            circuloElemento = arenaElement->FirstChildElement("circle");
            while(circuloElemento){
                // Leitura dos demais círculos
                id = atoi(circuloElemento->Attribute("id"));
                r = atof(circuloElemento->Attribute("r"));
                cx = atof(circuloElemento->Attribute("cx")) - 500;
                cy = alturaDimensao - atof(circuloElemento->Attribute("cy")) - 100;
                cores = retornaCor(circuloElemento->Attribute("fill"));

                // Leitura do jogador
                if(((std::string)circuloElemento->Attribute("fill")).compare("green") == 0){
                    Jogador* jogador = new Jogador(id, r, cx, cy, cores[0], cores[1], cores[2], arena);
                    GLfloat vel = atof(jogadorElemento->Attribute("vel"));

                    // Velocidade no final da decolagem
                    jogador->setTempoMultiplicador(vel);
                    arena->setJogador(jogador);

                    // Leitura dos inimigos aéreos
                }else if(((std::string)circuloElemento->Attribute("fill")).compare("red") == 0){
                    arena->criaInimigosAereos(id, r, cx, cy, cores[0], cores[1], cores[2]);

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
                GLfloat x1 = atof(linhaElemento->Attribute("x1")) - 500;
                GLfloat y1 = alturaDimensao - atof(linhaElemento->Attribute("y1")) - 100;
                GLfloat x2 = atof(linhaElemento->Attribute("x2")) - 500;
                GLfloat y2 = alturaDimensao - atof(linhaElemento->Attribute("y2")) - 100;
                std::stringstream coresStream(coresLinha);
                GLfloat cor[3];
                int i = 0;
                while(std::getline(coresStream,coresLinha,',')){
                    cor[i++] = stof(coresLinha);
                }
                Linha* linha = new Linha(id, x1, y1, x2, y2, cor[0], cor[1], cor[2]);
                arena->setLinha(linha);
                arena->getJogador()->calculaPontoCrescimento(linha);
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
    if(argc > 1){
        if(lerXML(argv[1])){
            fundoR = 1.0;
            fundoG = 1.0;
            fundoB = 1.0;
            tempoAntigo = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
            // Inicializa
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
            glutInitWindowSize(larguraDimensao, alturaDimensao);
            glutInitWindowPosition(50, 50);
            glutCreateWindow("Airplane Combat");
            init(fundoR, fundoG, fundoB);
            glutDisplayFunc(display);
            glutKeyboardUpFunc(keyup);
            glutKeyboardFunc(keyPress);
            glutPassiveMotionFunc(mouseMove);
            glutIdleFunc(idle);
            glutMainLoop();
        }
    }else{
        std::cout << "Localização do arquivo config.xml não foi informada." << std::endl;
    }

    return 0;
}
