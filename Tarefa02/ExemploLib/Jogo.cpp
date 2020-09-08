#include "Jogo.h"
#include <ctime>

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	srand(time(0));
	//Fonte
	if (!gRecursos.carregouFonte("fonte"))
	{
		gRecursos.carregarFonte("fonte", "assets/fontes/fonte_padrao.ttf", 32);
	}
	menuArma.setFonte("fonte");
	menuMunicao.setFonte("fonte");
	menuAtacar.setFonte("fonte");
	menuArma.setAncora(0, 0);
	menuMunicao.setAncora(0, 0);
	menuAtacar.setAncora(0, 0);

	//Inicialização
	arrayArmas[PISTOLA] = Pistola();
	arrayArmas[MOTOSSERRA] = Motosserra();
	arrayArmas[METRALHADORA] = Metralhadora();
	arrayArmas[CALIBRE12] = Calibre12();

	sair = false;
	i = NADA;

}

void Jogo::finalizar()
{
	gRecursos.descarregarTudo();

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair && !sair)
	{
		uniIniciarFrame();
		srand(time(0));

		//Menus
		if (getArma() != NADA) {
			menuArma.setString("Using: " + arrayArmas[i].getID());
			menuMunicao.setString(arrayArmas[i].getAmmo());
			if (gTeclado.segurando[TECLA_A]){
				menuAtacar.setString("Atacking!");
			}
			else menuAtacar.setString("");
		}
		else {
			menuArma.setString("Using: Nothing");
		}		

		//Troca de arma
		if (gTeclado.pressionou[TECLA_1]) {
			mudarArma(PISTOLA);
		}
		if (gTeclado.pressionou[TECLA_2]) {
			mudarArma(MOTOSSERRA);
		}
		if (gTeclado.pressionou[TECLA_3]) {
			mudarArma(METRALHADORA);
		}
		if (gTeclado.pressionou[TECLA_4]) {
			mudarArma(CALIBRE12);
		}
			
		//Atira e Recarrega
		if (getArma() != NADA) {
			if (getArma() == METRALHADORA) {
				if (gTeclado.segurando[TECLA_A]) {
					arrayArmas[i].atacar();
					Sleep(80);
				}
			}
			else if (gTeclado.pressionou[TECLA_A]) {
				arrayArmas[i].atacar();
			}
			if (gTeclado.pressionou[TECLA_D]) {
				arrayArmas[i].recarregar();
			}
		}

		//Sair
		if (gTeclado.pressionou[TECLA_S]) {
			sair = true;
		}

		menuArma.desenhar(10, 20);
		menuMunicao.desenhar(10, 100);
		menuAtacar.desenhar(10, 180);

		uniTerminarFrame();
	}
}

void Jogo::mudarArma(tipoArma t)
{
	i = t;
}
