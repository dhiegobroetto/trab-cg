#ifndef JOGADOR_H
#define JOGADOR_H

#include <GL/glut.h>
#include "math.h"
#include "linha.h"
#include "circulo.h"
#include "arena.h"
#include "projetil.h"
#include "bomba.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Arena;
class Projetil;
class Bomba;

class Jogador
{
    private:
        GLint id;
        GLfloat raio;
        GLfloat x;
        GLfloat y;
        GLfloat xInicial;
        GLfloat yInicial;
        GLfloat corR;
        GLfloat corG;
        GLfloat corB;
        GLfloat velocidade;
        GLfloat velocidadeInicial;
        GLfloat velocidadeMultiplicadora;
        GLfloat velocidadeTiro;
        GLfloat tempoAjustador;
        GLfloat pontoCrescimento;
        GLfloat distanciaPontos;
        GLfloat raioInicial;
        GLfloat tempoRaio;
        Arena* arena;
        vector<Projetil*> projeteis;
        vector<Bomba*> bombas;
        GLfloat anguloJogador;
        GLfloat anguloCanhao;
        GLfloat anguloHelice;
        GLfloat mouseX;
        GLfloat limiteCanhaoX;
        GLfloat limiteCanhaoY;
        bool ligado;
        bool voando;
        bool vivo;

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
        GLfloat getVelocidadeMultiplicadora();
        void setVelocidadeMultiplicadora(GLfloat& velocidadeMultiplicadora);
        GLfloat getVelocidadeTiro();
        void setVelocidadeTiro(GLfloat& velocidadeTiro);
        GLfloat getTempoAjustador();
        void setTempoAjustador(GLfloat& tempoAjustador);
        GLfloat getVelocidade();
        void setVelocidade(GLfloat velocidade);
        void setVelocidadeInicial(GLfloat velocidadeInicial);
        void incrementaVelocidade(GLfloat velocidade);
        void decrementaVelocidade(GLfloat velocidade);
        GLfloat getPontoCrescimento();
        void setPontoCrescimento(GLfloat pontoCrescimento);
        GLfloat getDistanciaPontos();
        void setDistanciaPontos(GLfloat distanciaPontos);
        GLfloat getRaioInicial();
        void setRaioInicial(GLfloat& raioInicial);
        GLfloat getMouseX();
        void setMouseX(GLfloat mouseX);
        GLfloat getLimiteCanhaoX();
        void setLimiteCanhaoX(GLfloat limiteCanhaoX);
        GLfloat getLimiteCanhaoY();
        void setLimiteCanhaoY(GLfloat limiteCanhaoY);
        GLfloat getAnguloCanhao();
        void setAnguloCanhao(GLfloat anguloCanhao);
        bool isLigado();
        void setLigado(bool ligado);
        bool isVoando();
        void setVoando(bool voando);
        bool isVivo();
        void vive();
        void morre();
        Arena* getArena();
        void setArena(Arena* arena);
        void addProjetil(Projetil *p);
        void addBomba(Bomba *b);
        GLfloat getAnguloJogador();
        void setAnguloJogador(GLfloat anguloJogador);
        void desenhaCirculo(GLfloat raio, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaQuadrado(GLfloat base, GLfloat altura, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaTriangulo(GLfloat tamanho);
        void desenhaElipse(GLfloat cx, GLfloat cy, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaElipseBorda(GLfloat cx, GLfloat cy, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaBase();
        void desenhaAsas(int asa);
        void desenhaAsa(int asa);
        void desenhaAerodinamica(GLfloat tamanho, GLfloat corR, GLfloat corG, GLfloat corB);
        void desenhaHelice(int asa);
        void desenhaCanhao();
        void desenhaProjeteis();
        void desenhaBombas();
        void desenhaJogador();
        void moveX(GLfloat x);
        void moveY(GLfloat y);
        void voa(GLfloat velocidade);
        void voaProjeteis(GLfloat tempoAjustador);
        void voaBombas(GLfloat tempoAjustador);
        bool verificaColisao(GLfloat x, GLfloat y, bool projetil, GLfloat raioBomba);
        bool verificaColisaoProjetil(GLfloat x, GLfloat y);
        void verificaColisaoBomba(GLfloat x, GLfloat y, GLfloat raio);
        void atravessaBorda();
        void decola(Linha* linha, GLfloat tempoAntigo, GLfloat tempoDecolagem);
        GLfloat distanciaEntrePontos(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
        void calculaPontoCrescimento(Linha* linha);
        void calculaAngulo(Linha* linha);        
        void reseta();
};

#endif /* JOGADOR_H */

