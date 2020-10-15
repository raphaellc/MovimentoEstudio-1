#pragma once
#include "libUnicornio.h"
#include "GameObject.h"

enum Direcao { dDireita, dEsquerda };

class Player : public GameObject
{
public:
	Player() {};
	~Player() {};

	float* getVelocidade();
	Direcao* getDirecao();

	void inicializar() override;
	void atualizar(Vetor2D p, Sprite s) override;
	void desenhar() override;
	void resetar() override;

protected:
	Direcao* direcao;
	float* velocidade;
};
