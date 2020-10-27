#pragma once
#include "No.h"
#include<iostream>
template<typename T>
class PilhaNo
{
public:
	PilhaNo();
	~PilhaNo();

	void push(T* elemento);
	void pop();
	T front();
	T back();
	bool estaVazia();
	int tamanho();
	void print();
	void erase();

private:
	void percorrerPilha();

	No<T>* no_inicial;
	No<T>* no_final; 
	No<T>* aux;
	int tam;
};
using namespace std;

template<typename T>
inline PilhaNo<T>::PilhaNo()
{
	tam = 0;
	no_inicial = no_final = aux = nullptr;
}

template<typename T>
inline PilhaNo<T>::~PilhaNo()
{

}

template<typename T>
inline void PilhaNo<T>::push(T* elemento)
{
	No<T>* n = new No<T>;
	n->setDado(*elemento);
	if (estaVazia() == true) {
		no_inicial = n;
	}
	else {
		percorrerPilha();
		aux->setSeguinte(n);
		n->setAnterior(aux);
	}
	no_final = n;
	tam++;
}

template<typename T>
inline void PilhaNo<T>::pop()
{
	tam--;
	percorrerPilha();
	delete no_final;
	no_final = nullptr;
	if (no_final == no_inicial) {
		no_final = aux = no_inicial = nullptr;
	}
	else {
		aux->setSeguinte(nullptr);
		no_final = aux;
	}
}

template<typename T>
inline T PilhaNo<T>::front()
{
	return no_inicial->getDado();
}

template<typename T>
inline T PilhaNo<T>::back()
{
	return no_final->getDado();
}

template<typename T>
inline bool PilhaNo<T>::estaVazia()
{
	if (tam == 0)
	{
		return true;
	}

	else return false;
}

template<typename T>
inline int PilhaNo<T>::tamanho()
{
	return tam;
}

template<typename T>
inline void PilhaNo<T>::percorrerPilha()
{
	aux = no_inicial;
	for (int x = 0; x < tam - 1; x++) {
		aux = aux->getSeguinte();
	}
}

template<class T>
inline void PilhaNo<T>::print()
{
	if (estaVazia()) cout << "A pilha está vazia!\n";
	else {
		aux = no_inicial;
		for (int x = 0; x < tam; x++) {
			cout << "O Nó de número " << x + 1 << " possui o dado: " << aux->getDado() << ";\n";
			aux = aux->getSeguinte();
		}
	}


}

template<class T>
inline void PilhaNo<T>::erase()
{
	while (!estaVazia()) pop();
}

