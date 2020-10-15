#include "DialogBox.h"

DialogBox::DialogBox()
{
	texto = new Texto;
	sprite = new Sprite;
}

DialogBox::~DialogBox()
{
}

void DialogBox::setTexto(string t)
{
	texto->setString(t);
}

void DialogBox::setSprite(string s)
{
	sprite->setSpriteSheet(s);
}

Texto* DialogBox::getTexto()
{
	return texto;
}

Sprite* DialogBox::getSprite()
{
	return sprite;
}
