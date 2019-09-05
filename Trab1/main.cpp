#include <GL/glut.h>
#include <stdio.h>
#include <list>
#include "tinyxml/tinyxml.h"
#include "math.h"
#include "circulo.h"

float globalX;
float globalY;
int vetFlags[256];
float raioUltCirc, ultCircR, ultCircG, ultCircB, ultCircX, ultCircY;
float raioCirculo;
float circuloR, circuloG, circuloB;
float circuloModeloR, circuloModeloG, circuloModeloB, circuloModeloSobreposicaoR, circuloModeloSobreposicaoG, circuloModeloSobreposicaoB;
float larguraDimensao, alturaDimensao;
float fundoR, fundoG, fundoB;
bool sobreposicao = false;
bool moverCirculo = false;
bool botaoDireitoMouse = false;
bool desenhaCirculo = false;
float compensacaoX, compensacaoY;
list<Circulo*> listaCirculos;
Circulo* circuloModeloMouse;
Circulo* circulo = NULL;
Circulo* circuloMover = NULL;

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
    if(desenhaCirculo){
        glColor3f(circuloModeloMouse->getCorR(), circuloModeloMouse->getCorG(), circuloModeloMouse->getCorB());
        glBegin(GL_LINE_LOOP);
            for (int i = 0; i < 360; i++) {
                theta = (i * M_PI) / 180.0;
                px = cos(theta) * circuloModeloMouse->getRaio();
                py = sin(theta) * circuloModeloMouse->getRaio();
                glVertex2f(px + globalX, py + globalY);
            }
        glEnd();
    }
    // Não esperar
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
    TiXmlDocument doc( strcat(argv[1], "config.xml") );
    doc.LoadFile();

    TiXmlElement *aplicacao = doc.RootElement();
    if(aplicacao !=  NULL){
        // Declaração de variáveis
        TiXmlElement *circulo = NULL;
        TiXmlElement *circuloModelo = NULL;
        TiXmlElement *janela = NULL;
        TiXmlElement *dimensao = NULL;
        TiXmlElement *fundo = NULL;
        TiXmlElement *titulo = NULL;

        // Atribui valores
        circulo = aplicacao->FirstChildElement( "circulo" );
        circuloModelo = aplicacao->FirstChildElement( "circuloModelo" );
        janela = aplicacao->FirstChildElement( "janela" );
        if(janela != NULL){
            dimensao = janela->FirstChildElement( "dimensao" );
            fundo = janela->FirstChildElement( "fundo" );
            titulo = janela->FirstChildElement( "titulo" );
        }
        raioCirculo = atof(circulo->Attribute("raio"));
        circuloR = atof(circulo->Attribute("corR"));
        circuloG = atof(circulo->Attribute("corG"));
        circuloB = atof(circulo->Attribute("corB"));

        circuloModeloR = atof(circuloModelo->Attribute("corR"));
        circuloModeloG = atof(circuloModelo->Attribute("corG"));
        circuloModeloB = atof(circuloModelo->Attribute("corB"));
        circuloModeloSobreposicaoR = atof(circuloModelo->Attribute("corSobreposicaoR"));
        circuloModeloSobreposicaoG = atof(circuloModelo->Attribute("corSobreposicaoG"));
        circuloModeloSobreposicaoB = atof(circuloModelo->Attribute("corSobreposicaoB"));

        larguraDimensao = atof(dimensao->Attribute("largura"));
        alturaDimensao = atof(dimensao->Attribute("altura"));

        fundoR = atof(fundo->Attribute("corR"));
        fundoG = atof(fundo->Attribute("corG"));
        fundoB = atof(fundo->Attribute("corB"));
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(larguraDimensao, alturaDimensao);
        glutInitWindowPosition(50, 50);
        glutCreateWindow(titulo->GetText());
        globalX = globalY = 0;
        circuloModeloMouse = new Circulo(raioCirculo, globalX, globalY, circuloModeloR, circuloModeloG, circuloModeloB);
        init(fundoR, fundoG, fundoB);
        glutDisplayFunc(display);
        glutMouseFunc(mouse);
        glutPassiveMotionFunc(passiveMotionFunc);
        glutMotionFunc(motionFunc);
        glutMainLoop();
    }else{
        printf("Arquivo nao encontrado!\n");
    }

    // C ANSI requer que main retorne um inteiro
    return 0;
}
