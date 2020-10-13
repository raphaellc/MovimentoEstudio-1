#pragma once
#include "Lista.h"
#include "Fase.h"
#include "Player.h"
#include "Lista.h"

enum Telas { tInicial, tInstrucoes, tCreditos, tJogo, tSaida,tTeste };
enum Botoes { bJogar, bInstrucoes, bCreditos, bSair, bOk, bVoltar, bVPausa, bSPausa };

class GameManager
{
public:
	void inicializar();
	void finalizar();
	void executar();

	void criaConversas();
private:
	Telas telaAtual;
	Player player;
	Fase fase;

	BotaoSprite botoes[8];

	string* conversa_atual;
	Texto conversa;

	Sprite fundoPausa, indicacao;
	bool pausa;

	void telaInicial();
	void telaInstrucoes();
	void telaCreditos();
	void telaJogo();
	void resetar();

	void telaTeste();
};

