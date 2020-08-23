#pragma once
class ArrayFloat
{
public:
	ArrayFloat();

	void adiciona(int i);
	void remover();
	int obterValorEm(int i);
	int obterValor();
	void mostrarValores();
	void desalocaArray();

	int getQtdElementos();
	int getTamanhoArray();

protected:
	int *array, *arrayTemp;
	int indice, tamanho, tamNovo;

	void realocar();
};