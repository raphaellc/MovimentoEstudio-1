
#include "GameObject.h"
class Personagem : public GameObject
{
public:
    Personagem();
    ~Personagem();

    int* getIndiceConversa();

private:
    int* indice_conversa;
};
