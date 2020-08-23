#include "ArrayInt.h"
#include <iostream>
#include <cstdio>

ArrayString::ArrayString()
{
	array = new string[5];
	arrayTemp = nullptr;
	indice = 0;
	tamanho = tamNovo = 5;

	for (int i = 0; i < tamanho; i++) {
		array[i] = "|*-cédula_vazia-*|";
	}
}

void ArrayString::adiciona(string s)
{
	if (indice >= tamanho) realocar();
	array[indice] = s;
	indice++;
}

void ArrayString::remover()
{
	indice--;
	array[indice] = "|*-cédula_vazia-*|";
}

string ArrayString::obterValorEm(int i)
{
	if (i < tamanho && i >= 0) {
		return array[i];
	}
	else {
		cout << "A posição selecionada é inexistente\n";
		return NULL;
	}
}

string ArrayString::obterValor()
{
	return array[indice - 1];
}

void ArrayString::mostrarValores()
{
	for (int i = 0; i < tamanho; i++) {
		cout << array[i];
		cout << endl;
	}
}

void ArrayString::desalocaArray()
{
	delete[] array;
}

int ArrayString::getQtdElementos()
{
	return indice;
}

int ArrayString::getTamanhoArray()
{
	return tamanho;
}

void ArrayString::realocar()
{
	tamNovo += 5;
	arrayTemp = new string[tamanho];

	for (int i = 0; i < tamanho; i++) {
		arrayTemp[i] = array[i];
	}

	array = new string[tamNovo];

	for (int i = tamanho; i < tamNovo; i++) {
		array[i] = "|*-cédula_vazia-*|";
	}

	for (int i = 0; i < tamanho; i++) {
		array[i] = arrayTemp[i];
	}
	tamanho = tamNovo;

	delete[] arrayTemp;
}
