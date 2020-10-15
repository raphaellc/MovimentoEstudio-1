#pragma once
#include "Lista.h"
#include "Fase.h"
#include "Player.h"
#include "Lista.h"
#include "DialogManager.h"
#include "GameObject.h"
#include "Personagem.h"

enum Telas { tInicial, tInstrucoes, tCreditos, tJogo, tSaida,tTeste };
enum Botoes { bJogar, bInstrucoes, bCreditos, bSair, bOk, bVoltar, bVPausa, bSPausa };

class GameManager
{
public:
	void inicializar();
	void atualizar();

private:
	void criaConversas(Personagem &personagem);

	DialogManager* dm;
	Personagem* personagens;
};

