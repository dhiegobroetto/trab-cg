#ifndef JOGADOR_H
#define JOGADOR_H

#include <GL/glut.h>
#include "math.h"
#include "linha.h"
#include "circulo.h"
#include "arena.h"
#include <iostream>
#include <string>

using namespace std;

class Arena;

class Jogador
{
    private:
        GLint id;
        GLfloat raio;
        GLfloat x;
        GLfloat y;
        GLfloat corR;
        GLfloat corG;
        GLfloat corB;
        GLfloat velocidade;
        GLfloat tempoMultiplicador;
        GLfloat tempoAjustador;
        GLfloat pontoCrescimento;
        GLfloat distanciaPontos;
        GLfloat raioInicial;
        GLfloat tempoRaio;
        Arena* arena;
        GLfloat anguloJogador;
        GLfloat anguloCanhao;
        GLfloat anguloHelice;
        bool ligado;
        bool voando;

    public:
    	// ------------ Construtor ------------ //
        Jogador(GLint& id, GLfloat& raio, GLfloat& x, GLfloat& y, GLfloat& corR, GLfloat& corG, GLfloat& corB, Arena* arena);

        // ------------ Getters e Setters ------------ //
        GLint getId();
        void setId(GLint& id);
        GLfloat getRaio();
        void setRaio(GLfloat& raio);
        GLfloat getX();
        void setX(GLfloat& x);
        GLfloat getY();
        void setY(GLfloat& y);
        GLfloat getCorR();
        void setCorR(GLfloat& corR);
        GLfloat getCorG();
        void setCorG(GLfloat& corG);
        GLfloat getCorB();
        void setCorB(GLfloat& corB);
        GLfloat getTempoMultiplicador();
        void setTempoMultiplicador(GLfloat& tempoMultiplicador);
        GLfloat getTempoAjustador();
        void setTempoAjustador(GLfloat& tempoAjustador);
        GLfloat getVelocidade();
        void setVelocidade(GLfloat velocidade);
        GLfloat getPontoCrescimento();
        void setPontoCrescimento(GLfloat pontoCrescimento);
        GLfloat getDistanciaPontos();
        void setDistanciaPontos(GLfloat distanciaPontos);
        GLfloat getRaioInicial();
        void setRaioInicial(GLfloat& raioInicial);
        bool isLigado();
        void setLigado(bool ligado);
        bool isVoando();
        void setVoando(bool voando);
        Arena* getArena();
        void setArena(Arena* arena);
        void desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaQuadrado(GLfloat base, GLfloat altura);
        void desenhaTriangulo(GLfloat tamanho);
        void desenhaElipse(GLfloat cx, GLfloat cy);
        void desenhaBase();
        void desenhaAsas(int asa);
        void desenhaAsa(int asa);
        void desenhaHelice(int asa);
        void desenhaCanhao();
        void desenhaJogador();
        void moveX(GLfloat x);
        void moveY(GLfloat y);
        void moveXY(GLfloat x, GLfloat y);
        bool verificaColisao(GLfloat x, GLfloat y);
        void decola(Linha* linha, GLfloat tempoAntigo, GLfloat tempoDecolagem);
        GLfloat distanciaEntrePontos(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
        void calculaPontoCrescimento(Linha* linha);
        void exibeTexto(GLfloat x, GLfloat y);
};

#endif /* JOGADOR_H */

