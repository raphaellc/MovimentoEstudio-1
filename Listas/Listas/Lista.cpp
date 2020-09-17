#include "Lista.h"
#include <iostream> 

Lista::Lista()
{
	inicio_lista = fim_lista = nullptr;

	qtdNo = 0;
}

void Lista::inserirLista(int elemento)
{
	
	No * n = new No; //Define o nó e insere o elemento no nó
	n->setDado(elemento); //Encapsula o dado no nó
	if (listaVazia()) { //Caso a lista esteja vazia
		inicio_lista = n; //Insere o nó na lista
	}
	else {//Caso não esteja vazia
		percorrerLista(); //Encontrar o último nó da lista
		aux->setProximo(n); //Insere o nó na lista
	}
	fim_lista = n; //Configura o novo nó como sendo o último da lista
	qtdNo++;
}

void Lista::removerLista()
{
	percorrerListaAte(fim_lista); //Encontrar o penúltimo nó da lista
	delete fim_lista; //Desaloca a última posição
	aux->setProximo(nullptr); //Configura valor nulo para a variável proximoNo do penúltimo nó
	fim_lista = aux; //Corrige qual o último nó da lista
	qtdNo--;
}

int Lista::buscarLista(int pos)
{
	aux = inicio_lista;
	for(int i= 0; i < pos; i++) { //Percorre a lista até encontrar o nó na posição inserida
		aux = aux->getProximo();
	}

	return aux->getDado(); //Retorna o nó desejado
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

void Lista::percorrerListaAte(No* n) //Modificação do método percorrerLista(), percorre a lista até o nó recebido por parâmetro
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