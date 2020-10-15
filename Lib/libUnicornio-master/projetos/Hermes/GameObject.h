#pragma once
#include "libUnicornio.h"
#include <string>

enum ID { MC, Posdo, Amanda, Helena, Ariel };

class GameObject
{
public:
	virtual void inicializar() = 0;
	virtual void atualizar(Vetor2D p, Sprite s) = 0;
	virtual void desenhar() = 0;
	virtual void resetar() = 0;
	
	ID getId();
	Sprite getSprite();
	Vetor2D getPosicao();
protected:
	Sprite sprite;
	Vetor2D posicao;
	ID id;
};

