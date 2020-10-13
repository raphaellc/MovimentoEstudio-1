#pragma once
#include "libUnicornio.h"

enum ID {Player, Item};

class GameObject
{
public:
	GameObject() {};
	~GameObject() {};

	virtual void boot() = 0;

protected:
	Sprite sprite;
	Vetor2D position;
	ID id;
};

