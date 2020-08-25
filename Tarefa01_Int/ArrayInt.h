#pragma once
class ArrayInt
{
public:
	ArrayInt();
	~ArrayInt() {};

	void adiciona(int i);
	void remover();
	int obterValorEm(int i);
	int obterValor();
	void mostrarValores();
	void desalocaArray();

	int getQtdElementos();
	int getTamanhoArray();

private:
	int *array, *arrayTemp;
	int indice, tamanho, tamNovo;

	void realocar();
};