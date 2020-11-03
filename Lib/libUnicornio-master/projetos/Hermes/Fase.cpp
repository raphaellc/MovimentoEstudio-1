#include "Fase.h"

void Fase::inicializar()
{
	fundo = new Sprite;
	interacao = new Sprite;
	posicaoInt = new Vetor2D;

	if (!gRecursos.carregouSpriteSheet("fundo"))
	{
		gRecursos.carregarSpriteSheet("fundo", "./assets/fundos/CenaDemo.png", 1, 1);
	}
	fundo->setSpriteSheet("fundo");

	if (!gRecursos.carregouSpriteSheet("interacao"))
	{
		gRecursos.carregarSpriteSheet("interacao", "./assets/outros/interacao.png", 1, 6);
	}
	interacao->setSpriteSheet("interacao");
	interacao->setVelocidadeAnimacao(3.2);

	resetar();
}

void Fase::atualizar()//ponteiro
{

}

void Fase::desenhar()
{
	fundo->desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	interacao->desenhar(posicaoInt->x, posicaoInt->y);
	interacao->avancarAnimacao();
}

void Fase::resetar()
{
	posicaoInt->x = 190;
	posicaoInt->y = 400;
}