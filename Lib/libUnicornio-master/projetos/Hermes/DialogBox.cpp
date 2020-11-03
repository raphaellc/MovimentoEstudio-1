#include "DialogBox.h"

DialogBox::DialogBox()
{
	texto = new Texto;
	sprite = new Sprite;

	inicializar();
}

DialogBox::~DialogBox()
{
}

void DialogBox::inicializar()
{

}

void DialogBox::atualizar(Vetor2D p, Sprite s)
{
}

void DialogBox::desenhar()
{
}

void DialogBox::resetar()
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
