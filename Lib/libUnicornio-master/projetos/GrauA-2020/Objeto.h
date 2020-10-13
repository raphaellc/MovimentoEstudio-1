#pragma once
#include "libUnicornio.h"

enum TipoObjeto{tMoeda, tInimigo, tSpawner, tTiro};
enum DE { esquerda, direita };

class Objeto
{
public:
	Objeto() {}
	~Objeto() {}

	void inicializar(float x, float y, TipoObjeto tipo);
	bool atualizar(Vetor2D posicao, Sprite s);
	void desenhar();

	TipoObjeto getTipo() { return tipo; };

	Vetor2D getPosicao() { return posicao; };
	Sprite getSprite() { return sprite; };
	bool getVivo() { return vivo; };


protected:
	Sprite sprite;
	Vetor2D posicao;
	bool vivo;
	TipoObjeto tipo;
	DE dSpawner;
};

