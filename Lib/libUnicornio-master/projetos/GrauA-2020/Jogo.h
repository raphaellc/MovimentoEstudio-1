#pragma once
#include "Fase.h"

enum Telas { tInicial, tInstrucoes, tCreditos, tJogo, tSaida };
enum Botoes { bJogar, bInstrucoes, bCreditos, bSair, bOk, bVoltar, bVPausa, bSPausa };

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();
protected:
	Personagem personagem;
	Fase fase;

	Telas telaAtual;
	BotaoSprite botoes[8];

	Sprite fundoPausa;
	bool pausa;

	void telaInicial();
	void telaInstrucoes();
	void telaCreditos();
	void telaJogo();
	void resetar();
};

