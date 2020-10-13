#pragma once
#include "libUnicornio.h"
#include "Objeto.h"

enum Direcao{ dParado, dDireita, dEsquerda };

class Personagem
{
public:
	Personagem() {}
	~Personagem() {}

	void inicializar();
	void atualizar();
	void desenhar();
	void resetar();

	Sprite getSprite();
	Vetor2D getPosicao();

protected:
	Sprite sprite;
	Vetor2D posicao;
	Direcao direcao;
	float velocidade;
	Objeto tiro;
};

