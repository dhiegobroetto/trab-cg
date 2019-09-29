#include <GL/glut.h>
#include <stdio.h>
#include <list>
#include "tinyxml/tinyxml.h"
#include "math.h"
#include "circulo.h"
#include "linha.h"
#include "arena.h"
#include "jogador.h"
#include <chrono>
#include <iostream>
#include <sstream>
#include <string>

GLfloat red[] = {1.0, 0.0, 0.0};
GLfloat green[] = {0.0, 1.0, 0.0};
GLfloat blue[] = {0.0, 0.0, 1.0};
GLfloat orange[] = {1.0, 0.7, 0.0};

// Variáveis globais de configuração
float larguraDimensao, alturaDimensao;
float fundoR, fundoG, fundoB;
int vetFlags[256];
GLfloat tempoAntigo, tempoNovo, tempoAntigoDecolagem;
GLfloat tempoNovoDecolagem;


// Flags
// bool decolagem = false;

// Objetos auxiliares
// list<Circulo*> inimigosAereos;
// list<Circulo*> inimigosTerrestres;
Arena* arena = NULL;
Circulo* circulo = NULL;
// Jogador* jogador = NULL;
// Linha* linha = NULL;


// ---- Métodos ---- //
// void criaInimigosAereos(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b) {
//     circulo = new Circulo(id, raioCirculo, x, y, r, g, b);
//     inimigosAereos.push_back(circulo);
// }
// void criaInimigosTerrestres(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b) {
//     circulo = new Circulo(id, raioCirculo, x, y, r, g, b);
//     inimigosTerrestres.push_back(circulo);
// }

GLfloat* retornaCor(std::string fill){
    if(fill.compare("red") == 0){
        return red;
    }
    if(fill.compare("green") == 0){
        return green;
    }
    if(fill.compare("blue") == 0){
        return blue;
    }
    if(fill.compare("orange") == 0){
        return orange;
    }
}

void keyPress(unsigned char key, int x, int y){
  vetFlags[key] = 1;
}

void keyup(unsigned char key, int x, int y){
  vetFlags[key] = 0;
}

void display(void){
    // Inicialização das variáveis
    float theta, px, py;
    Jogador* jogador = arena->getJogador();
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
    if(vetFlags['u'] && !jogador->isLigado()){
        jogador->setLigado(true);
        tempoAntigoDecolagem = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	    // jogador->moveX(1.0);
        // jogador->decola(linha);

    }
    if(jogador->isLigado() && !jogador->isVoando()){
        tempoNovoDecolagem = (glutGet(GLUT_ELAPSED_TIME) / 1000.0) - tempoAntigoDecolagem;
        jogador->setTempoDecolagem(tempoNovoDecolagem);
        jogador->decola(arena->getLinha(), tempoAntigoDecolagem);
    }
    // tempoAntigo = tempoNovo;
    
    // //x = xo + vot + 1/2at^2
    // if(decolagem){
    //     while(jogador->getY() <= linha->getY2()){
    //         GLfloat tempoDecolagem = std::chrono::duration_cast<std::chrono::seconds>(glutGet(GLUT_ELAPSED_TIME) / 1000.0 - tempoAntigo).count();
    //         jogador->decola(linha);
    //         std::cout << jogador->getX() << std::endl;
    //     }
    //     decolagem = false;
    //     decolagem = true;
    // }

    if(jogador->isLigado() && jogador->isVoando()){
        if(vetFlags['w']){
            jogador->moveY(jogador->getVelocidade());
        }
        if(vetFlags['a']){
            jogador->moveX(-jogador->getVelocidade());
        }
        if(vetFlags['s']){
            jogador->moveY(-jogador->getVelocidade());
        }
        if(vetFlags['d']){
            jogador->moveX(jogador->getVelocidade());
        }
    }
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
    glOrtho(arena->getX() - arena->getRaio(), 
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
                    cx = atof(circuloElemento->Attribute("cx"));
                    cy = alturaDimensao - atof(circuloElemento->Attribute("cy"));
                    cores = retornaCor(circuloElemento->Attribute("fill"));
                    arena = new Arena(id, r, cx, cy, cores[0], cores[1], cores[2]);
                }else{

                    // Leitura dos demais círculos
                    id = atoi(circuloElemento->Attribute("id"));
                    r = atof(circuloElemento->Attribute("r"));
                    cx = atof(circuloElemento->Attribute("cx"));
                    cy = alturaDimensao - atof(circuloElemento->Attribute("cy"));
                    cores = retornaCor(circuloElemento->Attribute("fill"));

                    // Leitura do jogador
                    if(((std::string)circuloElemento->Attribute("fill")).compare("green") == 0){
                        Jogador* jogador = new Jogador(id, r, cx, cy, cores[0], cores[1], cores[2]);
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
                GLfloat x1 = atof(linhaElemento->Attribute("x1"));
                GLfloat y1 = alturaDimensao - atof(linhaElemento->Attribute("y1"));
                GLfloat x2 = atof(linhaElemento->Attribute("x2"));
                GLfloat y2 = alturaDimensao - atof(linhaElemento->Attribute("y2"));
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
            return false;
        }
    }else{
        return false;
    }
}

int main(int argc, char** argv){
    if(argv[1] != NULL){
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
            glutIdleFunc(idle);
            // glutMotionFunc(motionFunc);
            glutMainLoop();
        }else{
            printf("Arquivo config.xml não encontrado!\n");
        }
    }else{
        printf("Localização do arquivo config.xml não foi informada.\n");
    }

    // C ANSI requer que main retorne um inteiro
    return 0;
}
