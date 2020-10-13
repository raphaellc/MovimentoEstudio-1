#include "Personagem.h"

void Personagem::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("personagem"))
	{
		gRecursos.carregarSpriteSheet("personagem", "./assets/personagens/personagem2.png", 3, 4);
	}
	sprite.setSpriteSheet("personagem");

	resetar();

	tiro.inicializar(posicao.x, posicao.y - 70, tTiro);
	
}

void Personagem::atualizar()
{
	//Mov Horizontal
	if (gTeclado.segurando[TECLA_A])
	{
		if (posicao.x > sprite.getLargura() / 2 + 4)
		{
			if (gTeclado.segurando[TECLA_SHIFT_ESQ])
			{
				posicao.x -= velocidade * 1.5;
			}
			else posicao.x -= velocidade;
		}
		direcao = dEsquerda;
		sprite.avancarAnimacao();
	}
	if (gTeclado.segurando[TECLA_D])
	{
		if (posicao.x < gJanela.getLargura() - sprite.getLargura() / 2 - 4)
		{
			if (gTeclado.segurando[TECLA_SHIFT_ESQ])
			{
				posicao.x += velocidade * 1.5;
			}
			else posicao.x += velocidade;
		}
		direcao = dDireita;
		sprite.avancarAnimacao();
	}
	//Mov Vertical
	if (gTeclado.segurando[TECLA_W])
	{
		if (posicao.y > 350 + sprite.getAltura() / 2)
		{
			if (gTeclado.segurando[TECLA_SHIFT_ESQ])
			{
				posicao.y -= velocidade;
			}
			else posicao.y -= velocidade / 1.5;
			sprite.avancarAnimacao();
		}
	}
	if (gTeclado.segurando[TECLA_S])
	{
		if (posicao.y < gJanela.getAltura() - sprite.getAltura() / 2 - 30)
		{
			if (gTeclado.segurando[TECLA_SHIFT_ESQ])
			{
				posicao.y += velocidade;
			}
			else posicao.y += velocidade / 1.5;
			sprite.avancarAnimacao();
		}
	}
	if (!gTeclado.segurando[TECLA_S] && !gTeclado.segurando[TECLA_W] && !gTeclado.segurando[TECLA_D] && !gTeclado.segurando[TECLA_A])
	{
		direcao = dParado;
		sprite.avancarAnimacao();
	}
	sprite.setAnimacao(direcao);

	tiro.atualizar(posicao, sprite);

}

void Personagem::desenhar()
{
	sprite.desenhar(posicao.x, posicao.y);
	tiro.desenhar();
}

void Personagem::resetar()
{
	posicao.y = 525;

	posicao.x = 50;
	direcao = dParado;
	sprite.setFrame(1);

	velocidade = 2;
}

Sprite Personagem::getSprite()
{
	return sprite;
}

Vetor2D Personagem::getPosicao()
{
	return posicao;
}
