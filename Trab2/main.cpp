#include <GL/glut.h>
#include <stdio.h>
#include <list>
#include "tinyxml/tinyxml.h"
#include "math.h"
#include "circulo.h"

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
void criaCirculo() {
    circulo = new Circulo(raioCirculo, globalX, globalY, circuloR, circuloG, circuloB);
    listaCirculos.push_back(circulo);
}

float distanciaCirculos(Circulo *c, float x, float y){
    return sqrt(pow((c->getX() - x), 2) + pow((c->getY() - y), 2));
}

void mouse(int button, int state, int x, int y){
    // Manter a origem no bottom
    y = alturaDimensao - y;

    globalX = x;
    globalY = y;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !sobreposicao){
        criaCirculo();
        sobreposicao = true;
        circuloModeloMouse->setCorR(circuloModeloSobreposicaoR);
        circuloModeloMouse->setCorG(circuloModeloSobreposicaoG);
        circuloModeloMouse->setCorB(circuloModeloSobreposicaoB);
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && moverCirculo){
        botaoDireitoMouse = true;
        desenhaCirculo = false;
        for(list<Circulo*>::iterator c = listaCirculos.begin(); c != listaCirculos.end(); ++c){
            if((*c)->getRaio() >= distanciaCirculos((*c), globalX, globalY)){
                circuloMover = (*c);
                compensacaoX = x - circuloMover->getX();
                compensacaoY = y - circuloMover->getY();
                break;
            }
        }
    }else{
        botaoDireitoMouse = false;
        circuloMover = NULL;
        desenhaCirculo = true;
    }
    glutPostRedisplay();
}

void motionFunc(int x, int y){
    // Manter a origem no bottom
    y = alturaDimensao - y;
    globalX = x;
    globalY = y;
    if(botaoDireitoMouse){
        float aux = globalX - compensacaoX;
        circuloMover->setX(aux);
        aux = globalY - compensacaoY;
        circuloMover->setY(aux);
    }
    glutPostRedisplay();
}

void passiveMotionFunc(int x, int y){
    // Manter a origem no bottom
    desenhaCirculo = true;
    y = alturaDimensao - y;
    sobreposicao = moverCirculo = false;
    globalX = x;
    globalY = y;
    for(list<Circulo*>::iterator c = listaCirculos.begin(); c != listaCirculos.end(); ++c){
        if((circuloModeloMouse->getRaio() + (*c)->getRaio()) >= distanciaCirculos((*c), globalX, globalY)){
            circuloModeloMouse->setCorR(circuloModeloSobreposicaoR);
            circuloModeloMouse->setCorG(circuloModeloSobreposicaoG);
            circuloModeloMouse->setCorB(circuloModeloSobreposicaoB);
            sobreposicao = true;
        }
        if((*c)->getRaio() >= distanciaCirculos((*c), globalX, globalY) && !moverCirculo){
            moverCirculo = true;
            break;
        }
    }
    if(!sobreposicao){
        circuloModeloMouse->setCorR(circuloModeloR);
        circuloModeloMouse->setCorG(circuloModeloG);
        circuloModeloMouse->setCorB(circuloModeloB);
    }
    
    glutPostRedisplay();
}

void display(void){
    float theta, px, py;

    // Limpar todos os pixels
    glClear(GL_COLOR_BUFFER_BIT);

    // Círculos criados
    if(circulo != NULL){
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
    }

    // Círculo aro que acompanha o mouse
    if(desenhaCirculo){
        glColor3f(circuloModeloMouse->getCorR(), circuloModeloMouse->getCorG(), 
            circuloModeloMouse->getCorB());
        glBegin(GL_LINE_LOOP);
            for (int i = 0; i < 360; i++) {
                theta = (i * M_PI) / 180.0;
                px = cos(theta) * circuloModeloMouse->getRaio();
                py = sin(theta) * circuloModeloMouse->getRaio();
                glVertex2f(px + globalX, py + globalY);
            }
        glEnd();
    }
    glFlush();
}

void init (float fundoR, float fundoG, float fundoB){
    // Selecionar cor de fundo (preto)
    glClearColor(fundoR, fundoG, fundoB, 0.0);

    // Iniciar sistema de viz
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, larguraDimensao, 0.0, alturaDimensao, -1.0, 1.0);
}

int main(int argc, char** argv){
    if(argv[1] != NULL){
        // TiXmlDocument doc( strcat(argv[1], "config.xml") );
        TiXmlDocument arena("Test_1/arena.svg" );
        // doc.LoadFile();
        arena.LoadFile();

        // TiXmlElement *aplicacao = doc.RootElement();
        TiXmlElement *svg = arena.RootElement();
        if(svg !=  NULL){
            // Declaração de variáveis
            // TiXmlElement *arquivoDaArena = NULL;
            // TiXmlElement *nome = NULL;
            // TiXmlElement *tipo = NULL;
            // TiXmlElement *caminho = NULL;
            // TiXmlElement *jogador = NULL;

            TiXmlElement *circulo = NULL;

            circulo = svg->FirstChildElement( "circle" );

            printf("%s\n", circulo->Attribute("fill"));

            // Atribui valores
            // arquivoDaArena = aplicacao->FirstChildElement( "arquivoDaArena" );
            // nome = arquivoDaArena->FirstChildElement( "nome" );
            // tipo = arquivoDaArena->FirstChildElement( "tipo" );
            // caminho = arquivoDaArena->FirstChildElement( "caminho" );
            // jogador = aplicacao->FirstChildElement( "jogador" );
            
           
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

            // larguraDimensao = atof(dimensao->Attribute("largura"));
            // alturaDimensao = atof(dimensao->Attribute("altura"));

            // fundoR = atof(fundo->Attribute("corR"));
            // fundoG = atof(fundo->Attribute("corG"));
            // fundoB = atof(fundo->Attribute("corB"));

            // Inicializa
            // glutInit(&argc, argv);
            // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
            // glutInitWindowSize(larguraDimensao, alturaDimensao);
            // glutInitWindowPosition(50, 50);
            // glutCreateWindow(titulo->GetText());
            // globalX = globalY = 0;
            // circuloModeloMouse = new Circulo(raioCirculo, globalX, globalY, 
            //     circuloModeloR, circuloModeloG, circuloModeloB);
            // init(fundoR, fundoG, fundoB);
            // glutDisplayFunc(display);
            // glutMouseFunc(mouse);
            // glutPassiveMotionFunc(passiveMotionFunc);
            // glutMotionFunc(motionFunc);
            // glutMainLoop();
        }else{
            printf("Arquivo config.xml não encontrado!\n");
        }
    }else{
        printf("Localização do arquivo config.xml não foi informada.\n");
    }

    // C ANSI requer que main retorne um inteiro
    return 0;
}
