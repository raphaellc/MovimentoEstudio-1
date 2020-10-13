#pragma once
#include "Objeto.h"
#include "Personagem.h"

class Fase
{
public:
	Fase() {}
	~Fase() {}

	void inicializar();
	void atualizar(Personagem personagem);
	void descarregar() {};
	void desenhar(int i);

	void ganhaPontos(int TPontos);
	void perdePontos(int TPontos);
	void perdeVida();
	void ganhaVida();

	int getVida() { return vida; }
	int getPontos() { return pontos; }

protected:
	Sprite fundo[3];
	Objeto moeda, spawner, inimigo;
	Texto TPontos, TVida;

	int pontos, vida;
};

