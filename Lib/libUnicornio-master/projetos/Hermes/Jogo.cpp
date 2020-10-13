#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	manager.inicializar();
}

void Jogo::finalizar()
{
	manager.finalizar();
}

void Jogo::executar()
{
	manager.executar();
}

