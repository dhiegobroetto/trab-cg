#include "config.h"

void defineIluminacao(GLfloat corR, GLfloat corG, GLfloat corB){
	glColor3f(corR, corG, corB);
	// GLfloat materialEmission[] = {corR, corG, corB, 1.0};
	// GLfloat materialColor[] = {corR, corG, corB, 1.0};
	// GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	// GLfloat mat_shininess[] = {128};
	// glMaterialfv(GL_FRONT, GL_EMISSION, materialEmission);
	// glMaterialfv(GL_FRONT, GL_AMBIENT, materialColor);
	// glMaterialfv(GL_FRONT, GL_DIFFUSE, materialColor);
	// glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	// glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);//X
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);//Y
}

void habilitaIluminacao(bool iluminacao){
	if(iluminacao){
	    glEnable(GL_LIGHTING);
	}else{
        // Tem que desabilitar o material_emission, 0.0 em tudo
        // GLfloat materialEmission[] = {0.0, 0.0, 0.0, 1.0};
        // glMaterialfv(GL_FRONT, GL_EMISSION, materialEmission);
		glDisable(GL_LIGHTING);
	}
}

GLuint LoadTextureRAW( const char * filename )
{

    GLuint texture;

    Image* image = loadBMP(filename);

    glGenTextures( 1, &texture );
    glBindTexture( GL_TEXTURE_2D, texture );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    // glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
                             0,                            //0 for now
                             GL_RGB,                       //Format OpenGL uses for image
                             image->width, image->height,  //Width and height
                             0,                            //The border of the image
                             GL_RGB, //GL_RGB, because pixels are stored in RGB format
                             GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
                                               //as unsigned numbers
                             image->pixels);               //The actual pixel data
    delete image;

    return texture;
}
