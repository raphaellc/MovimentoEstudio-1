#pragma once
#include "libUnicornio.h"

class Fase
{
public:
	Fase() {}
	~Fase() {}

	void inicializar();
	void atualizar();
	void descarregar() {};
	void desenhar();

	Sprite getIntSprite() { return interacao; }
	Vetor2D getPosInteracao() { return posicaoInt; }

protected:
	void resetar();

	Sprite fundo, interacao;
	Vetor2D posicaoInt;
};

