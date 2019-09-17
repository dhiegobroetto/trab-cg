#ifndef CIRCULO_H
#define CIRCULO_H

using namespace std;

class Circulo
{
    private:
        float raio;
        float x;
        float y;
        float corR;
        float corG;
        float corB;

    public:
    	// ------------ Construtor ------------ //
        Circulo(float& raio, float& x, float& y, float& corR, float& corG, float& corB);

        // ------------ Getters e Setters ------------ //
        float getRaio();
        void setRaio(float& raio);
        float getX();
        void setX(float& x);
        float getY();
        void setY(float& y);
        float getCorR();
        void setCorR(float& corR);
        float getCorG();
        void setCorG(float& corG);
        float getCorB();
        void setCorB(float& corB);

};

#endif /* CIRCULO_H */

