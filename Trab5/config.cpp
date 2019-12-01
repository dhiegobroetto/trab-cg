#include "config.h"

void defineIluminacao(GLfloat corR, GLfloat corG, GLfloat corB){
	glColor3f(corR, corG, corB);
	GLfloat materialEmission[] = {corR, corG, corB, 1.0};
	GLfloat materialColor[] = {corR, corG, corB, 1.0};
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shininess[] = {128};
	glMaterialfv(GL_FRONT, GL_EMISSION, materialEmission);
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialColor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, materialColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void habilitaIluminacao(bool iluminacao){
	if(iluminacao){
		glShadeModel(GL_SMOOTH);
	    glEnable(GL_LIGHTING);
	    glEnable(GL_LIGHT0);
	    glEnable(GL_DEPTH_TEST);
	}else{
		glDisable(GL_LIGHTING);
	}
}