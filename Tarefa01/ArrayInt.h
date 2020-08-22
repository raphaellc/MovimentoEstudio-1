#pragma once
class ArrayInt
{
public:
	ArrayInt();

	void adiciona(int i);
	void remover();
	int obterValorEm(int i);
	int obterValor();
	int mostrarValores();
	void desalocaArray();

protected:
	int *array, *arrayTemp;
	int indice, tamanho, tamNovo, qtd_elementos;

	void realocar();
};