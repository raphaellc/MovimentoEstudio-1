#pragma once
#include "GameManager.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();

protected:
	GameManager manager;
};

