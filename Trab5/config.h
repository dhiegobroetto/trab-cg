#ifndef CONFIG_H
#define CONFIG_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "imageloader.h"
#include "stdio.h"

void defineCor(GLfloat corR, GLfloat corG, GLfloat corB);
void trocaTextura(bool modoSemTextura);
void habilitaIluminacao(bool iluminacao);
bool lerXML(char* caminhoArquivo);
GLuint LoadTextureRAW(const char * filename);
void configuraIluminacao();

#endif /* CONFIG_H */
