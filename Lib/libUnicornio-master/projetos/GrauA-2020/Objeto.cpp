#include "Objeto.h"

void Objeto::inicializar(float x, float y, TipoObjeto tipo)
{
	this->tipo = tipo;

	switch (tipo)
	{
		case tMoeda:
			if (!gRecursos.carregouSpriteSheet("moeda"))
			{
				gRecursos.carregarSpriteSheet("moeda", "./assets/outros/coin.png", 1, 6);
			}
			sprite.setSpriteSheet("moeda");

			if (!gRecursos.carregouAudio("somMoeda"))
			{
				gRecursos.carregarAudio("somMoeda", "./assets/outros/coinSound.wav");
			}
			sprite.setSpriteSheet("somMoeda");
			break;
		case tInimigo:
			if (!gRecursos.carregouSpriteSheet("inimigo"))
			{
				gRecursos.carregarSpriteSheet("inimigo", "./assets/personagens/it.png");
			}
			sprite.setSpriteSheet("inimigo");
			break;
		case tSpawner:
			if (!gRecursos.carregouSpriteSheet("spawner"))
			{
				gRecursos.carregarSpriteSheet("spawner", "./assets/outros/spawner.png");
			}
			sprite.setSpriteSheet("spawner");

			dSpawner = direita;
			break;
		case tTiro:
			if (!gRecursos.carregouSpriteSheet("tiro"))
			{
				gRecursos.carregarSpriteSheet("tiro", "./assets/outros/tiro.png");
			}
			sprite.setSpriteSheet("tiro");
			
			break;
	}	
	vivo = true;
	posicao.x = x;
	posicao.y = y;
	
	if (tipo == tTiro) vivo = false;
}

bool Objeto::atualizar(Vetor2D p, Sprite s)
{
	if (vivo)
	{
		sprite.avancarAnimacao();
		switch (tipo)
		{
		case tInimigo:
			posicao.y++;
			if (posicao.y > 500) {
				posicao.x = p.x;
				posicao.y = 100;
			}
			break;
		case tSpawner:
			if (posicao.x <= sprite.getLargura() / 2 + 4) {
				dSpawner = direita;
				posicao.x++;
			}
			if (posicao.x >= gJanela.getLargura() - sprite.getLargura() / 2 - 4) {
				dSpawner = esquerda;
				posicao.x--;
			}
			if (dSpawner == esquerda) posicao.x--;
			else posicao.x++;

			break;
		case tTiro:
			break;
		}
		if (uniTestarColisao(sprite, posicao.x, posicao.y, 0, s, p.x, p.y, 0)) {
			switch (tipo)
			{
				case tMoeda:
					vivo = false;
					gAudios.tocar("somMoeda", 100);
					return true;
					break;
				case tInimigo:

					vivo = false;
					return true;
					break;
			}
		}
		return false;
	}
	if (tipo == tTiro) {
		if (gTeclado.pressionou[TECLA_ESPACO]) {
			vivo = true;
		}
		if (!vivo) {
			posicao.x = p.x;
			posicao.y = p.y - 70;
		}
		else {
			
			if (posicao.y > sprite.getAltura() / 2) {
				posicao.y--;
			}
			else {
				vivo = false;
				posicao.y = p.y - 70;
			}
		}
	}
}

void Objeto::desenhar()
{
	if (tipo == tTiro) {
		sprite.desenhar(posicao.x, posicao.y);
	}
	else if (vivo) {
		sprite.desenhar(posicao.x, posicao.y);
	}
}