#pragma once
#include "ArmaBase.h"
#include "Pistola.h"
#include "Motosserra.h"
#include "Metralhadora.h"
#include "Calibre12.h"
#include <windows.h>

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();

	void mudarArma(tipoArma t);
	tipoArma getArma() { return i; }

private:
	ArmaBase arrayArmas[4];
	tipoArma i;
	bool sair;
	Texto menuArma, menuMunicao, menuAtacar;
};

