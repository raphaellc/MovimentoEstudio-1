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
	int mostrarValores();
	void desalocaArray();

protected:
	string* array, *arrayTemp;
	int indice, tamanho, tamNovo, qtd_elementos;

	void realocar();
};