#include <GL/glut.h>
#include <stdio.h>
#include <list>
#include "tinyxml/tinyxml.h"
#include "math.h"
#include "circulo.h"
#include <iostream>
#include <string>

GLfloat red[] = {1.0, 0.0, 0.0};
GLfloat green[] = {0.0, 1.0, 0.0};
GLfloat blue[] = {0.0, 0.0, 1.0};
GLfloat orange[] = {1.0, 0.7, 0.0};

// Variáveis globais de configuração
float globalX;
float globalY;
float raioCirculo;
float circuloR, circuloG, circuloB;
float circuloModeloR, circuloModeloG, circuloModeloB, circuloModeloSobreposicaoR, 
circuloModeloSobreposicaoG, circuloModeloSobreposicaoB;
float larguraDimensao, alturaDimensao;
float fundoR, fundoG, fundoB;


// Flags
bool sobreposicao = false;
bool moverCirculo = false;
bool botaoDireitoMouse = false;
bool desenhaCirculo = false;
float compensacaoX, compensacaoY;

// Objetos auxiliares de círculos
list<Circulo*> listaCirculos;
Circulo* circuloModeloMouse;
Circulo* circulo = NULL;
Circulo* circuloMover = NULL;


// ---- Métodos ---- //
void criaCirculo(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b) {
    circulo = new Circulo(id, raioCirculo, x, y, r, g, b);
    listaCirculos.push_back(circulo);
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

// float distanciaCirculos(Circulo *c, float x, float y){
//     return sqrt(pow((c->getX() - x), 2) + pow((c->getY() - y), 2));
// }

// void mouse(int button, int state, int x, int y){
//     // Manter a origem no bottom
//     y = alturaDimensao - y;

//     globalX = x;
//     globalY = y;
//     if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !sobreposicao){
//         criaCirculo();
//         sobreposicao = true;
//         circuloModeloMouse->setCorR(circuloModeloSobreposicaoR);
//         circuloModeloMouse->setCorG(circuloModeloSobreposicaoG);
//         circuloModeloMouse->setCorB(circuloModeloSobreposicaoB);
//     }
//     if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && moverCirculo){
//         botaoDireitoMouse = true;
//         desenhaCirculo = false;
//         for(list<Circulo*>::iterator c = listaCirculos.begin(); c != listaCirculos.end(); ++c){
//             if((*c)->getRaio() >= distanciaCirculos((*c), globalX, globalY)){
//                 circuloMover = (*c);
//                 compensacaoX = x - circuloMover->getX();
//                 compensacaoY = y - circuloMover->getY();
//                 break;
//             }
//         }
//     }else{
//         botaoDireitoMouse = false;
//         circuloMover = NULL;
//         desenhaCirculo = true;
//     }
//     glutPostRedisplay();
// }

// void motionFunc(int x, int y){
//     // Manter a origem no bottom
//     y = alturaDimensao - y;
//     globalX = x;
//     globalY = y;
//     if(botaoDireitoMouse){
//         float aux = globalX - compensacaoX;
//         circuloMover->setX(aux);
//         aux = globalY - compensacaoY;
//         circuloMover->setY(aux);
//     }
//     glutPostRedisplay();
// }

// void passiveMotionFunc(int x, int y){
//     // Manter a origem no bottom
//     desenhaCirculo = true;
//     y = alturaDimensao - y;
//     sobreposicao = moverCirculo = false;
//     globalX = x;
//     globalY = y;
//     for(list<Circulo*>::iterator c = listaCirculos.begin(); c != listaCirculos.end(); ++c){
//         if((circuloModeloMouse->getRaio() + (*c)->getRaio()) >= distanciaCirculos((*c), globalX, globalY)){
//             circuloModeloMouse->setCorR(circuloModeloSobreposicaoR);
//             circuloModeloMouse->setCorG(circuloModeloSobreposicaoG);
//             circuloModeloMouse->setCorB(circuloModeloSobreposicaoB);
//             sobreposicao = true;
//         }
//         if((*c)->getRaio() >= distanciaCirculos((*c), globalX, globalY) && !moverCirculo){
//             moverCirculo = true;
//             break;
//         }
//     }
//     if(!sobreposicao){
//         circuloModeloMouse->setCorR(circuloModeloR);
//         circuloModeloMouse->setCorG(circuloModeloG);
//         circuloModeloMouse->setCorB(circuloModeloB);
//     }
    
//     glutPostRedisplay();
// }

void display(void){
    float theta, px, py;

    // Limpar todos os pixels
    glClear(GL_COLOR_BUFFER_BIT);

    // Círculos criados
    for(list<Circulo*>::iterator c = listaCirculos.begin(); c != listaCirculos.end(); ++c){
        glColor3f((*c)->getCorR(), (*c)->getCorG(), (*c)->getCorB());
        glBegin(GL_POLYGON);
            for (int i = 0; i < 360; i++) {
                theta = (i * M_PI) / 180.0;
                px = cos(theta) * (*c)->getRaio();
                py = sin(theta) * (*c)->getRaio();
                glVertex2f(px + (*c)->getX(), py + (*c)->getY());
            }
        glEnd();
    }
    glutSwapBuffers();
}

void init (float fundoR, float fundoG, float fundoB){
    glClearColor(fundoR, fundoG, fundoB, 0.0);

    // Iniciar sistema de viz
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(200, 800, 200, 800, -1.0, 1.0);
}

int main(int argc, char** argv){
    if(argv[1] != NULL){
        TiXmlDocument doc( strcat(argv[1], "/config.xml") );
        doc.LoadFile();
        TiXmlElement *aplicacao = doc.RootElement();
        if(aplicacao !=  NULL){
            // Declaração de variáveis
            TiXmlElement *arquivoDaArena = NULL;
            TiXmlElement *nome = NULL;
            TiXmlElement *tipo = NULL;
            TiXmlElement *caminho = NULL;
            TiXmlElement *jogador = NULL;

            // Atribui valores
            arquivoDaArena = aplicacao->FirstChildElement( "arquivoDaArena" );
            nome = arquivoDaArena->FirstChildElement( "nome" );
            tipo = arquivoDaArena->FirstChildElement( "tipo" );
            caminho = arquivoDaArena->FirstChildElement( "caminho" );
            jogador = aplicacao->FirstChildElement( "jogador" );
            std::string arquivoSVG = "";
            arquivoSVG = (std::string)caminho->GetText() + '/' + (std::string)nome->GetText() + '.' + (std::string)tipo->GetText();
            const char *abrirArquivo = arquivoSVG.c_str();
            TiXmlDocument svgFile(abrirArquivo);
            svgFile.LoadFile();
            TiXmlElement *arena = svgFile.RootElement();
            if(arena != NULL) {
                TiXmlElement *circulo = NULL;
                circulo = arena->FirstChildElement( "circle" );
                while(circulo){
                    GLint id = atoi(circulo->Attribute("id"));
                    GLfloat cx = atof(circulo->Attribute("cx"));
                    GLfloat cy = atof(circulo->Attribute("cy"));
                    GLfloat r = atof(circulo->Attribute("r"));
                    GLfloat *cores = retornaCor(circulo->Attribute("fill"));
                    criaCirculo(id, r, cx, cy, cores[0], cores[1], cores[2]);
                    circulo = circulo->NextSiblingElement("circle");
                }
            }
            // raioCirculo = atof(circulo->Attribute("raio"));
            // circuloR = atof(circulo->Attribute("corR"));
            // circuloG = atof(circulo->Attribute("corG"));
            // circuloB = atof(circulo->Attribute("corB"));

            // circuloModeloR = atof(circuloModelo->Attribute("corR"));
            // circuloModeloG = atof(circuloModelo->Attribute("corG"));
            // circuloModeloB = atof(circuloModelo->Attribute("corB"));
            // circuloModeloSobreposicaoR = atof(circuloModelo->Attribute("corSobreposicaoR"));
            // circuloModeloSobreposicaoG = atof(circuloModelo->Attribute("corSobreposicaoG"));
            // circuloModeloSobreposicaoB = atof(circuloModelo->Attribute("corSobreposicaoB"));

            larguraDimensao = 500.0;
            alturaDimensao = 500.0;

            fundoR = 1.0;
            fundoG = 1.0;
            fundoB = 1.0;

            // Inicializa
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
            glutInitWindowSize(larguraDimensao, alturaDimensao);
            glutInitWindowPosition(50, 50);
            glutCreateWindow("Airplane Combat");
            init(fundoR, fundoG, fundoB);
            glutDisplayFunc(display);
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
