#include "GameManager.h"

void GameManager::inicializar()
{
	uniInicializar(800, 600, false);

	telaAtual = tInicial;

	if (!gRecursos.carregouSpriteSheet("botaoJogar"))
	{
		gRecursos.carregarSpriteSheet("botaoJogar", "assets/imagens/botoes/Jogar.png", 3, 1);
	}
	botoes[bJogar].setSpriteSheet("botaoJogar");
	botoes[bJogar].setPos(gJanela.getLargura() / 2, 150);

	if (!gRecursos.carregouSpriteSheet("botaoInstrucoes"))
	{
		gRecursos.carregarSpriteSheet("botaoInstrucoes", "assets/imagens/botoes/Instrucoes.png", 3, 1);
	}
	botoes[bInstrucoes].setSpriteSheet("botaoInstrucoes");
	botoes[bInstrucoes].setPos(gJanela.getLargura() / 2, 150 + 70);

	if (!gRecursos.carregouSpriteSheet("botaoCreditos"))
	{
		gRecursos.carregarSpriteSheet("botaoCreditos", "assets/imagens/botoes/Creditos.png", 3, 1);
	}
	botoes[bCreditos].setSpriteSheet("botaoCreditos");
	botoes[bCreditos].setPos(gJanela.getLargura() / 2, 150 + 140);

	if (!gRecursos.carregouSpriteSheet("botaoSair"))
	{
		gRecursos.carregarSpriteSheet("botaoSair", "assets/imagens/botoes/Sair.png", 3, 1);
	}
	botoes[bSair].setSpriteSheet("botaoSair");
	botoes[bSair].setPos(gJanela.getLargura() / 2, 150 + 210);

	if (!gRecursos.carregouSpriteSheet("botaoOk"))
	{
		gRecursos.carregarSpriteSheet("botaoOk", "assets/imagens/botoes/Ok.png", 3, 1);
	}
	botoes[bOk].setSpriteSheet("botaoOk");
	botoes[bOk].setPos(gJanela.getLargura() / 2, 150 + 280);

	if (!gRecursos.carregouSpriteSheet("botaoVoltar"))
	{
		gRecursos.carregarSpriteSheet("botaoVoltar", "assets/imagens/botoes/Voltar.png", 3, 1);
	}
	botoes[bVoltar].setSpriteSheet("botaoVoltar");
	botoes[bVoltar].setPos(gJanela.getLargura() / 2, 230 + 50);

	botoes[bVPausa].setSpriteSheet("botaoVoltar");
	botoes[bVPausa].setPos(gJanela.getLargura() / 2, 230 + 30);

	botoes[bSPausa].setSpriteSheet("botaoSair");
	botoes[bSPausa].setPos(gJanela.getLargura() / 2, 230 + 100);

	if (!gRecursos.carregouSpriteSheet("indicacao"))
	{
		gRecursos.carregarSpriteSheet("indicacao", "./assets/outros/indicacao.png", 1, 2);
	}
	indicacao.setSpriteSheet("indicacao");
	indicacao.setVelocidadeAnimacao(1);

	player.inicializar();

	fase.inicializar();

	if (!gRecursos.carregouSpriteSheet("fundoPausa"))
	{
		gRecursos.carregarSpriteSheet("fundoPausa", "assets/imagens/popUp.png");
	}
	fundoPausa.setSpriteSheet("fundoPausa");
	pausa = false;
}

void GameManager::finalizar()
{
	gRecursos.descarregarTudo();

	uniFinalizar();
}

void GameManager::executar()
{
	while (!gEventos.sair && telaAtual != tSaida)
	{
		uniIniciarFrame();

		switch (telaAtual)
		{
		case tInicial: telaInicial();
			break;
		case tInstrucoes: telaInstrucoes();
			break;
		case tCreditos: telaCreditos();
			break;
		case tJogo: telaJogo();
			break;
		case tTeste: telaTeste();
			break;
		case tSaida:
			break;
		}

		uniTerminarFrame();
	}
}

void GameManager::criaConversas()
{
	Lista<string>* conversa = new Lista<string>;


}

void GameManager::telaInicial()
{
	for (int b = 0; b < 4; b++) {
		botoes[b].atualizar();
	}
	for (int b = 0; b < 4; b++) {
		botoes[b].desenhar();
	}

	if (botoes[bJogar].estaClicado()) {
		telaAtual = tJogo;
		resetar();
	}
	else if (botoes[bInstrucoes].estaClicado()) {
		telaAtual = tInstrucoes;
	}
	else if (botoes[bCreditos].estaClicado()) {
		telaAtual = tCreditos;
	}
	else if (botoes[bSair].estaClicado()) {
		telaAtual = tSaida;
	}
}

void GameManager::telaInstrucoes()
{
	botoes[bVoltar].atualizar();
	botoes[bVoltar].desenhar();

	if (botoes[bVoltar].estaClicado()) {
		telaAtual = tInicial;
	}
}

void GameManager::telaCreditos()
{
	botoes[bVoltar].atualizar();
	botoes[bVoltar].desenhar();

	if (botoes[bVoltar].estaClicado()) {
		telaAtual = tInicial;
	}
}

void GameManager::telaTeste()
{
	botoes[bVoltar].atualizar();
	botoes[bVoltar].desenhar();

	if (botoes[bVoltar].estaClicado()) {
		telaAtual = tInicial;
		player.resetar();
	}

}
void GameManager::telaJogo()
{
	fase.desenhar();

	player.desenhar();

	if (uniTestarColisao(player.getSprite(), player.getPosicao().x, player.getPosicao().y, 0, fase.getIntSprite(), fase.getPosInteracao().x + 4, fase.getPosInteracao().y, 0) || uniTestarColisao(player.getSprite(), player.getPosicao().x, player.getPosicao().y, 0, fase.getIntSprite(), fase.getPosInteracao().x - 4, fase.getPosInteracao().y, 0) || uniTestarColisao(player.getSprite(), player.getPosicao().x, player.getPosicao().y, 0, fase.getIntSprite(), fase.getPosInteracao().x, fase.getPosInteracao().y + 4, 0) || uniTestarColisao(player.getSprite(), player.getPosicao().x, player.getPosicao().y, 0, fase.getIntSprite(), fase.getPosInteracao().x, fase.getPosInteracao().y - 4, 0)) {
		indicacao.desenhar(player.getPosicao().x, player.getPosicao().y - 70);
		indicacao.avancarAnimacao();
		if (gTeclado.segurando[TECLA_E]) {
			criaConversas();
		}
	}

	if (gTeclado.pressionou[TECLA_ESC] || gTeclado.pressionou[TECLA_P]) {
		pausa = !pausa;
	}

	if (pausa) {
		fundoPausa.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		botoes[bVPausa].atualizar();
		botoes[bVPausa].desenhar();

		botoes[bSPausa].atualizar();
		botoes[bSPausa].desenhar();

		if (botoes[bVPausa].estaClicado()) {
			pausa = false;
		}
		if (botoes[bSPausa].estaClicado()) {
			telaAtual = tInicial;
		}
	}
	else {
		fase.atualizar();
		player.atualizar(fase.getPosInteracao(), fase.getIntSprite());
	}

	if(player.getPosicao().y < player.getSprite().getAltura() / 2)
    {
		telaAtual = tTeste;
		telaTeste();
		
	}
	//gDebug.setPos(0, 0);
	//gDebug.depurar("X, Y: ", Vetor2D(player.getPosicao().x, player.getPosicao().y));
}

void GameManager::resetar()
{
	
}