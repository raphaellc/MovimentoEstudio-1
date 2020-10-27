#pragma once
#include "Lista.h"
template<class T>

class FilaLista
{
public:
	FilaLista();
	~FilaLista();
	void push(T* elemento);
	void pop();
	T* front();
	T* back();
	bool estaVaia();
	int tamanho();
	void print();
	void erase();

private:

	Lista<T>* fila = new Lista<T>;

};
using namespace std;

template<class T>
inline FilaLista<T>::FilaLista()
{
}

template<class T>
inline FilaLista<T>::~FilaLista()
{
}

template<class T>
inline void FilaLista<T>::push(T* elemento)
{
	fila->inserirFimLista(elemento);
}

template<class T>
inline void FilaLista<T>::pop()
{
	fila->removePrimeiroNo();
}

template<class T>
inline T* FilaLista<T>::front()
{
	return fila->obterPrimeiroElemento();
}

template<class T>
inline T* FilaLista<T>::back()
{
	return fila->obterUltimoElemento();
}

template<class T>
inline bool FilaLista<T>::estaVaia()
{
	return fila->listaVazia();
}

template<class T>
inline int FilaLista<T>::tamanho()
{
	return fila->quantidadeElementos();
}

template<class T>
inline void FilaLista<T>::print()
{
	fila->imprimirLista();
}

template<class T>
inline void FilaLista<T>::erase()
{
	fila->esvaziaLista();
}
