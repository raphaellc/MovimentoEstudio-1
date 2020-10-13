#pragma once
#include "libUnicornio.h"
class GameObject
{
public:
	virtual void inicializar() = 0;
	virtual void atualizar(Vetor2D p, Sprite s) = 0;
	virtual void desenhar() = 0;
	virtual void resetar() = 0;

	Sprite getSprite();
	Vetor2D getPosicao();
protected:
	Sprite sprite;
	Vetor2D posicao;
};

