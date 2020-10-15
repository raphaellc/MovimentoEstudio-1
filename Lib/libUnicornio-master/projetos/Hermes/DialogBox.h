#pragma once
#include "GameObject.h"

class DialogBox : public GameObject
{
public:
	DialogBox();
	~DialogBox();

	void setTexto(string t);
	void setSprite(string s);

	Texto* getTexto();
	Sprite* getSprite();

private:
	Texto* texto;
	Sprite* sprite;
};