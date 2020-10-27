#pragma once
#include "Lista.h"
template<class T>

class PilhaLista
{
public:

	PilhaLista();
	~PilhaLista();
	void push(T* elemento);
	void pop();
	T* front();
	T* back();
	bool estaVaia();
	int tamanho();

	void print();
	void erase();

private:

	Lista<T>* pilha = new Lista<T>;
};
using namespace std;

template<class T>
inline PilhaLista<T>::PilhaLista()
{

}

template<class T>
inline PilhaLista<T>::~PilhaLista()
{

}

template<class T>
inline void PilhaLista<T>::push(T* elemento)
{
	pilha->inserirFimLista(elemento);
}

template<class T>
inline void PilhaLista<T>::pop()
{
	pilha->removeUltimoNo();
}

template<class T>
inline T* PilhaLista<T>::front()
{

	return pilha->obterPrimeiroElemento();
}

template<class T>
inline T* PilhaLista<T>::back()
{
	return pilha->obterUltimoElemento();
}

template<class T>
inline bool PilhaLista<T>::estaVaia()
{
	return pilha->listaVazia();

}

template<class T>
inline int PilhaLista<T>::tamanho()
{

	return pilha->quantidadeElementos();
}

template<class T>
inline void PilhaLista<T>::print()
{
	pilha->imprimirLista();
}

template<class T>
inline void PilhaLista<T>::erase()
{
	pilha->esvaziaLista();
}
