#include "Fase.h"

void Fase::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("fundo0"))
	{
		gRecursos.carregarSpriteSheet("fundo0", "./assets/fundos/back0.png", 1, 1);
	}
	fundo[0].setSpriteSheet("fundo0");

	if (!gRecursos.carregouSpriteSheet("fundo1"))
	{
		gRecursos.carregarSpriteSheet("fundo1", "./assets/fundos/back1.png", 1, 1);
	}
	fundo[1].setSpriteSheet("fundo1");

	if (!gRecursos.carregouSpriteSheet("fundo2"))
	{
		gRecursos.carregarSpriteSheet("fundo2", "./assets/fundos/back2.png", 1, 4);
	}
	fundo[2].setSpriteSheet("fundo2");

	
	moeda.inicializar(300, 500, tMoeda);
	

	spawner.inicializar(400, 20, tSpawner);
	inimigo.inicializar(spawner.getPosicao().x, 100, tInimigo);

	if (!gRecursos.carregouFonte("fonte"))
	{
		gRecursos.carregarFonte("fonte", "assets/fontes/fonte_padrao.ttf", 32);
	}

	TPontos.setFonte("fonte");
	TVida.setFonte("fonte");

	TPontos.setAncora(0, 0.5);
	TVida.setAncora(0, 0.5);
	fundo[2].setAncora(1, 0);
	
}

void Fase::atualizar(Personagem personagem)//ponteiro
{
	fundo[2].avancarAnimacao();

	
	if (moeda.atualizar(personagem.getPosicao(), personagem.getSprite())) {
		ganhaPontos(1);
	}

	TPontos.setString("Pontuação: " + to_string(getPontos()));
	TVida.setString("Vida: " + to_string(getVida()));

	spawner.atualizar(spawner.getPosicao(), spawner.getSprite());

	inimigo.atualizar(spawner.getPosicao(), inimigo.getSprite());

	pontos = 0;
	vida = 10;

}

void Fase::desenhar(int i)
{
	switch (i)
	{
		case 0:
			fundo[0].desenhar(400, 300);

			spawner.desenhar();

			inimigo.desenhar();

			moeda.desenhar();
			
			break;
		case 1: 
			fundo[1].desenhar(400, 300);
			break;
		case 2:
			fundo[2].desenhar(749, 41);

			TPontos.desenhar(10, 20);

			TVida.desenhar(10, 60);
		default:
			break;
		}	
}

void Fase::ganhaPontos(int pontos)
{
	this->pontos += pontos;
}

void Fase::perdePontos(int pontos)
{
	this->pontos -= pontos;
}

void Fase::perdeVida()
{
	vida--;
}

void Fase::ganhaVida()
{
	vida++;
}