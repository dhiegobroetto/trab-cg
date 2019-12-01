#ifndef CONFIG_H
#define CONFIG_H

#include <GL/glut.h>

void defineIluminacao(GLfloat corR, GLfloat corG, GLfloat corB);
void habilitaIluminacao(bool iluminacao);
bool lerXML(char* caminhoArquivo);

#endif /* CONFIG_H */
