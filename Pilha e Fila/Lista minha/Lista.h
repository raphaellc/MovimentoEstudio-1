#pragma once
#include "No.h"
#include<iostream>
template<class T>

class Lista
{
public:
	Lista();
	~Lista();

	void inserirFimLista(T* elemento);
	void removerLista();
	T buscarLista(int pos);
	int quantidadeElementos();
	T obterPrimeiroElementoObsoleto();
	T obterUltimoElementoObsoleto(); 
	void insereInicioLista(T* elemento);
	void insereEm(int posicao, T* elemento);

	void removeUltimoNo();
	void removePrimeiroNo();
	void removeNo(T* elemento);
	void esvaziaLista();
	bool contemNaLista(T* elemento/*, No * param_lista = lista*/);
	T* obterUltimoElemento();
	T* obterPrimeiroElemento();
	T* obterElementoEm(int posicao);

	void imprimirLista();

private:
	bool listaVazia();
	void percorrerLista();

	No<T>* inicioLista;
	No<T>* fimLista;
	No<T>* aux;
	T* temp;
	T temporaria;
	int qtdNo;
};
using namespace std;

template<class T>
inline Lista<T>::Lista()
{
	inicioLista = fimLista = aux = nullptr;
	qtdNo = 0;
}

template<class T>
inline Lista<T>::~Lista()
{
}

template<class T>
inline void Lista<T>::inserirFimLista(T*elemento)
{
	No<T>* n = new No<T>;

	n->setDado(*elemento);
	if (listaVazia() == true) {
		inicioLista = n;
	}
	else {
		percorrerLista();
		aux->setSeguinte(n);
		n->setAnterior(aux);
	}
	fimLista = n;
	qtdNo++;
}

template<class T>
inline void Lista<T>::removerLista()
{
	qtdNo--;
	percorrerLista();
	delete fimLista;
	fimLista = nullptr;
	if (fimLista == inicioLista) {
		aux = inicioLista = nullptr;
	}
	else {
		aux->setSeguinte(nullptr);
		fimLista = aux;
	}
}

template<class T>
inline T Lista<T>::buscarLista(int pos)
{
	aux = inicioLista;
	for (int x = 0; x < pos; x++)
	{
		aux = aux->getSeguinte();
	}

	return aux->getDado();
}

template<class T>
inline int Lista<T>::quantidadeElementos()
{
	return qtdNo;
}

template<class T>
inline T Lista<T>::obterPrimeiroElementoObsoleto()
{
	return inicioLista->getDado();
}

template<class T>
inline T Lista<T>::obterUltimoElementoObsoleto()
{
	return fimLista->getDado();
}

template<class T>
inline void Lista<T>::insereInicioLista(T* elemento)
{
	No<T>* n = new No<T>;

	n->setDado(*elemento);

	if (listaVazia()) {
		inicioLista = fimLista = n;
	}
	else {
		inicioLista->setAnterior(n);
		n->setSeguinte(inicioLista);
		inicioLista = n;
	}
	qtdNo++;
}

template<class T>
inline void Lista<T>::insereEm(int posicao, T* elemento)
{
	if (posicao == 0) {
		insereInicioLista(elemento);
	}
	else if(posicao == qtdNo){
		inserirFimLista(elemento);
	}
	else {
		No<T>* n = new No<T>;
		n->setDado(*elemento);

		No<T>* auxiliar;
		aux = inicioLista;
		for (int x = 0; x < posicao - 1; x++)
		{
			aux = aux->getSeguinte();
		}
		auxiliar = aux->getAnterior();

		n->setAnterior(aux);
		n->setSeguinte(auxiliar);
		aux->setSeguinte(n);
		auxiliar->setAnterior(n);

	}

	qtdNo++;
}

template<class T>
inline void Lista<T>::removeUltimoNo()
{
	qtdNo--;
	percorrerLista();
	delete fimLista;
	fimLista = nullptr;
	if (fimLista == inicioLista) {
		fimLista = aux = inicioLista = nullptr;
	}
	else {
		aux->setSeguinte(nullptr);
		fimLista = aux;
	}
}

template<class T>
inline void Lista<T>::removePrimeiroNo()
{
	qtdNo--;
	aux = inicioLista;
	aux = aux->getSeguinte();

	delete inicioLista;
	if (aux == nullptr) {
		fimLista = aux = inicioLista = nullptr;
	}
	else {
		aux->setAnterior(nullptr);
		inicioLista = aux;
	}
}

template<class T>
inline void Lista<T>::removeNo(T* elemento)
{
	No<T>* auxiliar;

	aux = inicioLista;

	while (aux->getDado() != *elemento) {
			aux = aux->getSeguinte();
			if (aux == nullptr) break;
	}
	if (aux == nullptr) cout << "O dado não existe na Lista!\n";
	else if (aux->getAnterior() == nullptr) removePrimeiroNo();
	else if (aux->getSeguinte() == nullptr) removeUltimoNo();
	else {
		auxiliar = aux->getAnterior();
		auxiliar->setSeguinte(aux->getSeguinte());
		delete aux;
		aux = auxiliar->getSeguinte();
		aux->setAnterior(auxiliar);

		aux = auxiliar = nullptr;
		qtdNo--;
	}

}

template<class T>
inline void Lista<T>::esvaziaLista()
{
	while (inicioLista != nullptr)removePrimeiroNo();
}

template<class T>
inline bool Lista<T>::contemNaLista(T* elemento)
{
	aux = inicioLista;
	for (int x = 0; x < qtdNo; x++)
	{
		if (aux->getDado() == *elemento) return true;
		else if (aux->getProximo() != nullptr) aux = aux->getProximo();
	}
	return false;
}

template<class T>
inline T* Lista<T>::obterUltimoElemento()
{
	temporaria = fimLista->getDado();
	return &temporaria;
}

template<class T>
inline T* Lista<T>::obterPrimeiroElemento()
{
	temporaria = inicioLista->getDado();
	return &temporaria;
}

template<class T>
inline T* Lista<T>::obterElementoEm(int posicao)
{
	temporaria = buscarLista(posicao);
	return &temporaria;
}

template<class T>
inline void Lista<T>::imprimirLista()
{
	if (listaVazia()) cout << "A lista está vazia!\n";
	else {
		aux = inicioLista;
		for (int x = 0; x < qtdNo; x++) {
			cout << "O Nó de número " << x + 1 << " possui o dado: " << aux->getDado() << ";\n";
			aux = aux->getSeguinte();
		}
	}
}

template<class T>
inline bool Lista<T>::listaVazia()
{
	if (inicioLista == nullptr) return true;
	else return false;
}

template<class T>
inline void Lista<T>::percorrerLista()
{
	aux = inicioLista;
	for(int x = 0; x < qtdNo - 1; x++){
		aux = aux->getSeguinte();
	}
}
