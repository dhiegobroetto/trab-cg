#ifndef ARENA_H
#define ARENA_H

#include <GL/glut.h>
#include "math.h"
#include "config.h"
#include "linha.h"
#include "jogador.h"
#include "inimigo.h"
#include "circulo.h"
#include <iostream>
#include <string>
#include <list>

class Jogador;
class Inimigo;
class Linha;
class Circulo;

class Arena
{
    private:
        GLint id;
        GLfloat raio;
        GLfloat x;
        GLfloat y;
        GLfloat z;
        GLfloat corR;
        GLfloat corG;
        GLfloat corB;
        bool iluminacao;
        GLfloat velocidade;
        Jogador* jogador;
        Linha* linha;
        std::list<Inimigo*> inimigosAereos;
        std::list<Inimigo*> inimigosAereosMortos;
        std::list<Circulo*> inimigosTerrestres;
        std::list<Circulo*> inimigosTerrestresMortos;

    public:
    	// ------------ Construtor ------------ //
        Arena(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB);

        // ------------ Getters e Setters ------------ //
        GLint getId();
        void setId(GLint& id);
        GLfloat getRaio();
        void setRaio(GLfloat& raio);
        GLfloat getX();
        void setX(GLfloat& x);
        GLfloat getY();
        void setY(GLfloat& y);
        GLfloat getZ();
        void setZ(GLfloat& z);
        GLfloat getCorR();
        void setCorR(GLfloat& corR);
        GLfloat getCorG();
        void setCorG(GLfloat& corG);
        GLfloat getCorB();
        void setCorB(GLfloat& corB);
        Jogador* getJogador();
        void setJogador(Jogador* jogador);
        Linha* getLinha();
        bool getIluminacao();
        void trocaIluminacao();
        void setLinha(Linha* linha);
        std::list<Inimigo*> getInimigosAereos();
        void mataInimigoAereo(Inimigo* inimigo);
        void mataInimigoTerrestre(Circulo* inimigo);
        std::list<Circulo*> getInimigosTerrestres();
        void desenhaArena();
        void criaInimigosAereos(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b, Arena* arena, GLfloat vel, GLfloat velTiro, GLfloat freqTiro);
        void criaInimigosTerrestres(GLint id, GLfloat raioCirculo,GLfloat x,GLfloat y,GLfloat r,GLfloat g,GLfloat b);
        void voaInimigosAereos(GLfloat curva, GLfloat tempoMultiplicador);
        void reseta();
        void exibeTexto(GLfloat x, GLfloat y);
        void exibeDecolagem(GLfloat x, GLfloat y);
        void exibeVitoria(GLfloat x, GLfloat y);
        void exibeGameOver(GLfloat x, GLfloat y);
        void exibePontuacao(GLfloat x, GLfloat y);
};

#endif /* ARENA_H */
