#include "Player.h"

Player::Player()
{
	direcao = new Direcao;
	velocidade = new float;
}

float* Player::getVelocidade()
{
	return nullptr;
}

Direcao* Player::getDirecao()
{
	return nullptr;
}

void Player::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("personagem"))
	{
		gRecursos.carregarSpriteSheet("personagem", "./assets/personagens/playerSS.png", 2, 1);
	}
	sprite->setSpriteSheet("personagem");

	resetar();

}

void Player::atualizar(Vetor2D p, Sprite s)
{
	//Mov Horizontal
	if (gTeclado.segurando[TECLA_A])
	{
		if (posicao->x > 130 && !uniTestarColisao(*sprite, posicao->x - 2, posicao->y, 0, s, p.x, p.y, 0) && ((posicao->y < 300 && posicao->x >= 360) || posicao->y > 300))
		{
			if (gTeclado.segurando[TECLA_SHIFT_ESQ])
			{
				posicao->x -= *velocidade * 1.5;
			}
			else posicao->x -= *velocidade;
		}
		*direcao = dEsquerda;
		//sprite.avancarAnimacao();
	}
	if (gTeclado.segurando[TECLA_D])
	{
		if (posicao->x < gJanela.getLargura() - sprite->getLargura() / 2 && !uniTestarColisao(*sprite, posicao->x + 2, posicao->y, 0, s, p.x, p.y, 0) && ((posicao->y < 300 && posicao->x <= gJanela.getLargura() - 360) || posicao->y > 300))
		{
			if (gTeclado.segurando[TECLA_SHIFT_ESQ])
			{
				posicao->x += *velocidade * 1.5;
			}
			else posicao->x += *velocidade;
		}
		*direcao = dDireita;
		//sprite.avancarAnimacao();
	}
	//Mov Vertical
	if (gTeclado.segurando[TECLA_W])
	{
		if (posicao->y > sprite->getAltura() / 2 && !uniTestarColisao(*sprite, posicao->x, posicao->y, 0, s, p.x, p.y + 4, 0) && (posicao->y > 390 || posicao->y < 187))
		{
			if (gTeclado.segurando[TECLA_SHIFT_ESQ])
			{
				posicao->y -= *velocidade;
			}
			else posicao->y -= *velocidade / 1.5;
			//sprite.avancarAnimacao();
		}
		else if (posicao->y < sprite->getAltura() / 2)
		{
			

		}
	}
	
	if (gTeclado.segurando[TECLA_S])
	{
		if (posicao->y < gJanela.getAltura() - sprite->getAltura() / 2 - 40 && !uniTestarColisao(*sprite, posicao->x, posicao->y, 0, s, p.x, p.y - 2, 0) && (posicao->y > 388 || posicao->y < 185))
		{
			if (gTeclado.segurando[TECLA_SHIFT_ESQ])
			{
				posicao->y += *velocidade;
			}
			else posicao->y += *velocidade / 1.5;
			//sprite.avancarAnimacao();
		}
	}
	if (!gTeclado.segurando[TECLA_S] && !gTeclado.segurando[TECLA_W] && !gTeclado.segurando[TECLA_D] && !gTeclado.segurando[TECLA_A])
	{
		*direcao = dEsquerda;
		//sprite.avancarAnimacao();
	}
	sprite->setAnimacao(*direcao);

}

void Player::desenhar()
{
	sprite->desenhar(posicao->x, posicao->y);
}

void Player::resetar()
{
	posicao->y = 50;// gJanela.getAltura() - sprite.getAltura() - 30;

	posicao->x = 400;// gJanela.getLargura() - 20;
	*direcao = dEsquerda;


	*velocidade = 2;
}