#pragma once
class ArrayFloat
{
public:
	ArrayFloat();

	void adiciona(float i);
	void remover();
	float obterValorEm(int i);
	float obterValor();
	void mostrarValores();
	void desalocaArray();

	int getQtdElementos();
	int getTamanhoArray();

protected:
	float *array, *arrayTemp;
	int indice, tamanho, tamNovo;

	void realocar();
};