#pragma once
#include <iostream>
#include "No.h"
template <class T>

class Lista
{
public: 
	Lista();
	~Lista() {};

	//Novos métodos
	void insereFimLista(T * elemento); //Insere um nó com dado definido por parâmetro no fim da lista
	void insereInicioLista(T * elemento);
	void insereEm(int posicao, T * elemento);
	void removeUltimoNo();
	void removePrimeiroNo();
	void removeNo(T * elemento);//
	void esvaziaLista();
	bool contemNaLista(T* elemento/*, No * param_lista = lista*/);
	T* obterUltimoElemento();
	T* obterPrimeiroElemento();
	T* obterElementoEm(int posicao);
	
	void imprimirLista();

private:
	void percorrerLista(); //Percorre todos elementos da lista
	bool listaVazia(); //Verifica se a lista está vazia

	No<T>* inicio_lista;
	No<T>* fim_lista;
	No<T>* aux;
	T* temp;
	T temporaria;
	int qtdNo;
};

using namespace std;

template <class T>
inline Lista<T>::Lista()
{
	inicio_lista = fim_lista = aux = nullptr;
	temp = new T;
	qtdNo = 0;
}

template <class T>
inline bool Lista<T>::listaVazia()
{
	if (inicio_lista == nullptr)
		return true;
	else
		return false;
}
template <class T>
inline void Lista<T>::percorrerLista()
{
	aux = inicio_lista;
	for (int i = 0; i < qtdNo - 1; i++) {
		aux = aux->getProximo();
	}
}
template <class T>
inline void Lista<T>::insereFimLista(T* elemento)
{
	No<T>* n = new No<T>; //Define o nó e insere o elemento no nó
	n->setDado(*elemento); //Encapsula o dado no nó
	if (listaVazia()) { //Caso a lista esteja vazia
		inicio_lista = n; //Insere o nó na lista
		n->setAnterior(nullptr);
	}
	else {//Caso não esteja vazia
		percorrerLista(); //Encontrar o último nó da lista
		aux->setProximo(n); //Insere o nó na lista
		n->setAnterior(aux);
	}
	fim_lista = n; //Configura o novo nó como sendo o último da lista
	qtdNo++;
}
template <class T>
inline void Lista<T>::insereInicioLista(T* elemento)
{
	No<T>* n = new No<T>; //Define o nó e insere o elemento no nó
	n->setDado(*elemento); //Encapsula o dado no nó

	aux = inicio_lista;
	if (listaVazia()) { //Caso a lista esteja vazia
		inicio_lista = fim_lista = n; //Insere o nó na lista
	}
	else {//Caso não esteja vazia
		aux->setAnterior(n); //Insere o nó na lista
		n->setProximo(aux);
		inicio_lista = n;
	}
	n->setAnterior(nullptr);
	qtdNo++;
}
template <class T>
inline void Lista<T>::insereEm(int posicao, T* elemento)
{
	if (posicao == 0)
	{
		insereInicioLista(elemento);
	}
	else if (posicao == qtdNo)
	{
		insereFimLista(elemento);
	}
	else
	{
		// 0 * 1
		// aux = 0  proximoNo(aux) = * anteriorNo(auxiliar) = * auxiliar = 1
		No<T>* n = new No<T>; //Define o nó e insere o elemento no nó
		n->setDado(*elemento); //Encapsula o dado no nó

		No<T>* auxiliar; //Define um ponteiro de nó como auxiliar para o método

		aux = inicio_lista;
		for (int i = 0; i < posicao - 1; i++) {//Atinge a posição anterior a dejada
			aux = aux->getProximo();
		}
		auxiliar = aux->getProximo(); //Define o ponteiro auxiliar do método como sendo o antigo nó na posição que será alterada
		n->setAnterior(aux);
		n->setProximo(auxiliar);
		aux->setProximo(n); //Define o endereço da próxima posição do nó anterior ao que foi "afastado"
		auxiliar->setAnterior(n);//Define o endereço da posição anterior ao nó que estava na posição do novo como o novo nó

		qtdNo++;
	}
}
template <class T>
inline void Lista<T>::removeUltimoNo()
{
	qtdNo--;
	percorrerLista(); //Encontrar o penúltimo nó da lista
	delete fim_lista; //Desaloca a última posição
	if (fim_lista == inicio_lista) {
		inicio_lista = fim_lista = aux = nullptr;
	}
	else {
		aux->setProximo(nullptr); //Configura valor nulo para o ponteiro proximoNo do penúltimo nó
		fim_lista = aux; //Corrige qual o último nó da lista
	}
}
template <class T>
inline void Lista<T>::removePrimeiroNo()
{
	qtdNo--;
	aux = inicio_lista;//Seta o Aux na posição Inicial
	aux = aux->getProximo();//Se desloca para a segunda posição
	if (inicio_lista->getProximo() == nullptr) {
		delete inicio_lista;//Desaloca a primeira posição
		inicio_lista = fim_lista = aux = nullptr;
	}
	else {
		delete inicio_lista;//Desaloca a primeira posição
		inicio_lista = aux; //Corrige qual o primeiro nó da lista
		aux->setAnterior(nullptr);
	}
}
template <class T>
inline void Lista<T>::removeNo(T* elemento)
{
	No<T>* auxiliar;

	aux = inicio_lista;//Seta o Aux na posição Inicial
	while (aux->getDado() != *elemento)//Avança até chegar na posição em que o Elemento se encontra
	{
		aux = aux->getProximo();
		if (aux == nullptr) break;
	}
	if (aux == nullptr)
	{
		cout << "O elemento inserido não está presente na lista!\n";
	}
	else if (aux->getAnterior() == nullptr) removePrimeiroNo();
	else if (aux->getProximo() == nullptr) removeUltimoNo();
	else
	{
		auxiliar = aux->getAnterior();
		auxiliar->setProximo(aux->getProximo());

		auxiliar = aux->getProximo();
		auxiliar->setAnterior(aux->getAnterior());

		delete aux;
		aux = auxiliar = nullptr;
		qtdNo--;
	}
}
template <class T>
inline void Lista<T>::esvaziaLista()
{
	if (!listaVazia()) {
		aux = inicio_lista;
		while (aux->getProximo() != nullptr) removePrimeiroNo();//Esvazia até o penúltimo Nó
		removePrimeiroNo();//Esvazia o último Nó
	}
	else cout << "Lista vazia!\n";
}
template <class T>
inline bool Lista<T>::contemNaLista(T* elemento/*, No* param_lista*/)
{
	aux = inicio_lista;
	for (int i = 0; i < qtdNo; i++)
	{
		if (aux->getDado() == *elemento) return true;
		else if (aux->getProximo() != nullptr) aux = aux->getProximo();
	}
	return false;
}
template <class T>
inline T* Lista<T>::obterUltimoElemento()
{
	temporaria = fim_lista->getDado();
	return &temporaria;
}
template <class T>
inline T* Lista<T>::obterPrimeiroElemento()
{
	*temp = inicio_lista->getDado();
	return temp;
}
template <class T>
inline T* Lista<T>::obterElementoEm(int posicao)
{
	buscarLista(posicao);
	*temp = aux->getDado();
	return temp;
}
template <class T>
inline void Lista<T>::imprimirLista()
{
	aux = inicio_lista;
	if (listaVazia()) {
		cout << "Lista vazia!\n";
	}
	else {
		cout << "Posição 0: " << aux->getDado() << endl;
		for (int i = 0; i < qtdNo - 1; i++) {
			aux = aux->getProximo();
			cout << "Posição " << i + 1 << ": " << aux->getDado() << endl;
		}
	}
}
