#pragma once
#include "GameObject.h"

class DialogBox : public GameObject
{
public:
	DialogBox();
	~DialogBox();

	void inicializar() override;
	void atualizar(Vetor2D p, Sprite s) override;
	void desenhar() override;
	void resetar() override;

	void setTexto(string t);
	void setSprite(string s);

	Texto* getTexto();
	Sprite* getSprite();

private:
	Texto* texto;
	Sprite* sprite;
};