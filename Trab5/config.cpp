#include "config.h"

void defineCor(GLfloat corR, GLfloat corG, GLfloat corB){
	glColor3f(corR, corG, corB);
}

void configuraIluminacao(){
    GLfloat light_ambient[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat light_diffuse[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light0_position[] = {0, 0, 1, 0.0};
    GLfloat light1_position[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat light1_direction[] = {0.0, 0.0, -1.0};
    GLfloat light1_angle[] = {20.0};

    // GLfloat lightModel[] = {0.0, 0.0, 0.0, 1.0};
    // glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightModel);

    // glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light1_direction);
    glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, light1_angle);

    //GLfloat mat_emission[] = {0.1, 0.1, 0.1, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {100.0};

    //glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
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
