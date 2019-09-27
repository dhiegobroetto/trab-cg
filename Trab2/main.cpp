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
std::chrono::high_resolution_clock::time_point tempoAntigo, tempoNovo;
GLfloat tempoMultiplicador;


// Flags
bool decolagem = false;
bool teste = false;

// Objetos auxiliares
list<Circulo*> listaInimigosAereos;
list<Circulo*> listaInimigosTerrestres;
Arena* circuloArena = NULL;
Jogador* jogador = NULL;
Circulo* circulo = NULL;
Linha* linha = NULL;


// ---- Métodos ---- //
void criaInimigosAereos(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b) {
    circulo = new Circulo(id, raioCirculo, x, y, r, g, b);
    listaInimigosAereos.push_back(circulo);
}
void criaInimigosTerrestres(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b) {
    circulo = new Circulo(id, raioCirculo, x, y, r, g, b);
    listaInimigosTerrestres.push_back(circulo);
}

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

float distanciaCirculos(Circulo *c, float x, float y){
    return sqrt(pow((c->getX() - x), 2) + pow((c->getY() - y), 2));
}

void keyPress(unsigned char key, int x, int y){
  vetFlags[key] = 1;
}

void keyup(unsigned char key, int x, int y){
  vetFlags[key] = 0;
}

void display(void){
    float theta, px, py;

    // Limpar todos os pixels
    glClear(GL_COLOR_BUFFER_BIT);

    if(circuloArena != NULL){
        circuloArena->desenhaArena();
    }
    if(linha != NULL){
        linha->desenhaLinha();
    }
    // Círculos criados
    for(list<Circulo*>::iterator c = listaInimigosAereos.begin(); c != listaInimigosAereos.end(); ++c){
        (*c)->desenha();
    }
     for(list<Circulo*>::iterator c = listaInimigosTerrestres.begin(); c != listaInimigosTerrestres.end(); ++c){
        (*c)->desenha();
    }
    if(jogador != NULL){
        jogador->desenhaJogador();
    }
    glutSwapBuffers();
}

void idle(void){
    if(vetFlags['u'] && !teste){
        teste = true;
        tempoNovo = std::chrono::high_resolution_clock::now();
	    // jogador->moveX(1.0);
        // jogador->decola(linha);

    }
    tempoAntigo = tempoNovo;
    GLfloat t = std::chrono::duration_cast<std::chrono::seconds>(tempoNovo - tempoAntigo).count();
    jogador->setTempoMultiplicador(t);
    //x = xo + vot + 1/2at^2
    if(teste){
        while(jogador->getY() <= linha->getY2()){
            GLfloat tempoDecolagem = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - tempoAntigo).count();
            jogador->decola(linha);
            std::cout << jogador->getX() << std::endl;
        }
        teste = false;
        decolagem = true;
    }

    if(decolagem){
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
        glutPostRedisplay();
    }
    tempoNovo = std::chrono::high_resolution_clock::now();
    
}

void init(float fundoR, float fundoG, float fundoB){
    glClearColor(fundoR, fundoG, fundoB, 0.0);

    // Iniciar sistema de viz
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(circuloArena->getX() - circuloArena->getRaio(), 
        circuloArena->getX() + circuloArena->getRaio(), 
        circuloArena->getY() - circuloArena->getRaio(), 
        circuloArena->getY() + circuloArena->getRaio(), 
        -1.0, 1.0);
}

int main(int argc, char** argv){
    if(argv[1] != NULL){
        TiXmlDocument doc(strcat(argv[1], "/config.xml"));
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
            std::string arquivoSVG = "";
            arquivoSVG = (std::string)caminho->GetText() + '/' + (std::string)nome->GetText() + '.' + (std::string)tipo->GetText();
            const char *abrirArquivo = arquivoSVG.c_str();
            TiXmlDocument svgFile(abrirArquivo);
            svgFile.LoadFile();
            TiXmlElement *arena = svgFile.RootElement();
            
            if(arena != NULL) {
                TiXmlElement *circulo = NULL;
                circulo = arena->FirstChildElement("circle");
                GLint id;
                GLfloat cx, r, cy, *cores;
                while(circulo){
                    if(((std::string)circulo->Attribute("fill")).compare("blue") == 0){
                        r = atof(circulo->Attribute("r"));
                        larguraDimensao = r * 2;
                        alturaDimensao = r * 2;
                        id = atoi(circulo->Attribute("id"));
                        cx = atof(circulo->Attribute("cx"));
                        cy = alturaDimensao - atof(circulo->Attribute("cy"));
                        cores = retornaCor(circulo->Attribute("fill"));
                        circuloArena = new Arena(id, r, cx, cy, cores[0], cores[1], cores[2]);
                    }else{
                        id = atoi(circulo->Attribute("id"));
                        r = atof(circulo->Attribute("r"));
                        cx = atof(circulo->Attribute("cx"));
                        cy = alturaDimensao - atof(circulo->Attribute("cy"));
                        cores = retornaCor(circulo->Attribute("fill"));
                        if(((std::string)circulo->Attribute("fill")).compare("green") == 0){
                            jogador = new Jogador(id, r, cx, cy, cores[0], cores[1], cores[2]);
                            GLfloat vel = atof(jogadorElemento->Attribute("vel"));
                            jogador->setVelocidade(vel);
                        }else if(((std::string)circulo->Attribute("fill")).compare("red") == 0){
                            criaInimigosAereos(id, r, cx, cy, cores[0], cores[1], cores[2]);
                        }else if(((std::string)circulo->Attribute("fill")).compare("orange") == 0){
                            criaInimigosTerrestres(id, r, cx, cy, cores[0], cores[1], cores[2]);
                        }
                    }
                    circulo = circulo->NextSiblingElement("circle");
                }
                TiXmlElement *linhaElemento = NULL;
                linhaElemento = arena->FirstChildElement("line");
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
                    linha = new Linha(id, x1, y1, x2, y2, cor[0], cor[1], cor[2]);
                }
            }
            fundoR = 1.0;
            fundoG = 1.0;
            fundoB = 1.0;
            tempoAntigo = std::chrono::high_resolution_clock::now();
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
