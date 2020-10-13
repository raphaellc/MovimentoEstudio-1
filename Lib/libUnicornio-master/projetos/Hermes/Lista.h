#pragma once
#include <iostream>
#include "No.h"
template <class T>

class Lista
{
public: 
	Lista();
	~Lista() {};

	//Novos m�todos
	void insereFimLista(T * elemento); //Insere um n� com dado definido por par�metro no fim da lista
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
	bool listaVazia(); //Verifica se a lista est� vazia

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
	No<T>* n = new No<T>; //Define o n� e insere o elemento no n�
	n->setDado(*elemento); //Encapsula o dado no n�
	if (listaVazia()) { //Caso a lista esteja vazia
		inicio_lista = n; //Insere o n� na lista
		n->setAnterior(nullptr);
	}
	else {//Caso n�o esteja vazia
		percorrerLista(); //Encontrar o �ltimo n� da lista
		aux->setProximo(n); //Insere o n� na lista
		n->setAnterior(aux);
	}
	fim_lista = n; //Configura o novo n� como sendo o �ltimo da lista
	qtdNo++;
}
template <class T>
inline void Lista<T>::insereInicioLista(T* elemento)
{
	No<T>* n = new No<T>; //Define o n� e insere o elemento no n�
	n->setDado(*elemento); //Encapsula o dado no n�

	aux = inicio_lista;
	if (listaVazia()) { //Caso a lista esteja vazia
		inicio_lista = fim_lista = n; //Insere o n� na lista
	}
	else {//Caso n�o esteja vazia
		aux->setAnterior(n); //Insere o n� na lista
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
		No<T>* n = new No<T>; //Define o n� e insere o elemento no n�
		n->setDado(*elemento); //Encapsula o dado no n�

		No<T>* auxiliar; //Define um ponteiro de n� como auxiliar para o m�todo

		aux = inicio_lista;
		for (int i = 0; i < posicao - 1; i++) {//Atinge a posi��o anterior a dejada
			aux = aux->getProximo();
		}
		auxiliar = aux->getProximo(); //Define o ponteiro auxiliar do m�todo como sendo o antigo n� na posi��o que ser� alterada
		n->setAnterior(aux);
		n->setProximo(auxiliar);
		aux->setProximo(n); //Define o endere�o da pr�xima posi��o do n� anterior ao que foi "afastado"
		auxiliar->setAnterior(n);//Define o endere�o da posi��o anterior ao n� que estava na posi��o do novo como o novo n�

		qtdNo++;
	}
}
template <class T>
inline void Lista<T>::removeUltimoNo()
{
	qtdNo--;
	percorrerLista(); //Encontrar o pen�ltimo n� da lista
	delete fim_lista; //Desaloca a �ltima posi��o
	if (fim_lista == inicio_lista) {
		inicio_lista = fim_lista = aux = nullptr;
	}
	else {
		aux->setProximo(nullptr); //Configura valor nulo para o ponteiro proximoNo do pen�ltimo n�
		fim_lista = aux; //Corrige qual o �ltimo n� da lista
	}
}
template <class T>
inline void Lista<T>::removePrimeiroNo()
{
	qtdNo--;
	aux = inicio_lista;//Seta o Aux na posi��o Inicial
	aux = aux->getProximo();//Se desloca para a segunda posi��o
	if (inicio_lista->getProximo() == nullptr) {
		delete inicio_lista;//Desaloca a primeira posi��o
		inicio_lista = fim_lista = aux = nullptr;
	}
	else {
		delete inicio_lista;//Desaloca a primeira posi��o
		inicio_lista = aux; //Corrige qual o primeiro n� da lista
		aux->setAnterior(nullptr);
	}
}
template <class T>
inline void Lista<T>::removeNo(T* elemento)
{
	No<T>* auxiliar;

	aux = inicio_lista;//Seta o Aux na posi��o Inicial
	while (aux->getDado() != *elemento)//Avan�a at� chegar na posi��o em que o Elemento se encontra
	{
		aux = aux->getProximo();
		if (aux == nullptr) break;
	}
	if (aux == nullptr)
	{
		cout << "O elemento inserido n�o est� presente na lista!\n";
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
		while (aux->getProximo() != nullptr) removePrimeiroNo();//Esvazia at� o pen�ltimo N�
		removePrimeiroNo();//Esvazia o �ltimo N�
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
		cout << "Posi��o 0: " << aux->getDado() << endl;
		for (int i = 0; i < qtdNo - 1; i++) {
			aux = aux->getProximo();
			cout << "Posi��o " << i + 1 << ": " << aux->getDado() << endl;
		}
	}
}
