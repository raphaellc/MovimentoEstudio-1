#pragma once
#include <string>

using namespace std;

class ArrayString
{
public:
	ArrayString();

	void adiciona(string s);
	void remover();
	string obterValorEm(int i);
	string obterValor();
	void mostrarValores();
	void desalocaArray();

	int getQtdElementos();
	int getTamanhoArray();

protected:
	string* array, *arrayTemp;
	int indice, tamanho, tamNovo;

	void realocar();
};