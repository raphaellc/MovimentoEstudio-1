#include "Lista.h"
#include <iostream> 

Lista::Lista()
{
	inicio_lista = fim_lista = nullptr;

	qtdNo = 0;
}

void Lista::inserirLista(int elemento)
{
	//Define o nó e insere o elemento no nó
	//encapsulda o dado no nó
	No * n = new No;
	n->setDado(elemento);
	//insere o nó na lista
	//caso a lista esteja vazia
	if (listaVazia()) {
		inicio_lista = n;
	}
	else {
		//caso não esteja vazia
		//encontrar o último nó da lista
		percorrerLista();
		aux->setProximo(n);
		fim_lista = n;
	}
	qtdNo++;
}

void Lista::removerLista()
{
	percorrerListaAte(fim_lista);
	delete fim_lista;
	aux->setProximo(nullptr);
	fim_lista = aux;
}

int Lista::buscarLista(int pos)
{
	aux = inicio_lista;
	for(int i= 0; i < pos; i++) {
		aux = aux->getProximo();
	}

	return aux->getDado();
}

bool Lista::listaVazia()
{
	if (inicio_lista == nullptr)
		return true;
	else
		return false;
}

void Lista::percorrerLista()
{
	aux = inicio_lista;
	while (aux->getProximo() != nullptr) {
		aux = aux->getProximo();
	}
}

void Lista::percorrerListaAte(No* n)
{
	aux = inicio_lista;
	while (aux->getProximo() != n) {
		aux = aux->getProximo();
	}
}

int Lista::quantidadeElementos()
{
	return qtdNo;
}

int Lista::obterPrimeiroElemento()
{
	return inicio_lista->getDado();
}

int Lista::obterUltimoElemento()
{
	return fim_lista->getDado();
}
