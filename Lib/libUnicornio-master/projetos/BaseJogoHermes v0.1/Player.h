#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{
public:
    Player();
    ~Player() {};

private:
    int hp;
};

