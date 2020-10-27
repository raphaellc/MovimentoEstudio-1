#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include"Lista.h"
#include "PilhaLista.h"
#include "PilhaNo.h"
#include "FilaLista.h"
#include "FilaNo.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ptb");

	Lista<int>* lista = new Lista<int>;

	int* zero = new int;
	int* um = new int;
	int* dois = new int;
	int* tres = new int;
	int* quatro = new int;
	int* cinco = new int;

	*zero = 0;
	*um = 1;
	*dois = 2;
	*tres = 3;
	*quatro = 4;
	*cinco = 5;

	lista->insereInicioLista(zero);
	lista->insereInicioLista(um);
	lista->insereInicioLista(dois);
	lista->insereInicioLista(tres);
	lista->insereInicioLista(quatro);
	lista->insereInicioLista(cinco);

	cout << "LISTA PADRÃO\n";

	cout << *lista->obterPrimeiroElemento() << "\n";
	cout << *lista->obterUltimoElemento() << "\n";

	lista->imprimirLista();
	cout << "qtd elementos: " << lista->quantidadeElementos();
	cout << "\n\n";

	lista->removeUltimoNo();

	lista->imprimirLista();
	cout << "qtd elementos: " << lista->quantidadeElementos();
	cout << "\n\n";

	lista->esvaziaLista();
	lista->imprimirLista();
	cout << "qtd elementos: " << lista->quantidadeElementos() << "\n";
	lista->esvaziaLista();
	system("pause");
	cout << "/////////////////////////////////////////////////////////////////\n";

	PilhaLista<int>* pilha = new PilhaLista<int>;

	pilha->push(zero);
	pilha->push(um);
	pilha->push(dois);
	pilha->push(tres);
	pilha->push(quatro);
	pilha->push(cinco);

	cout << *pilha->front() << "\n";
	cout << *pilha->back() << "\n";

	cout << "PILHA COM LISTA\n";

	pilha->print();
	cout << "qtd elementos: " << pilha->tamanho();
	cout << "\n\n";

	pilha->pop();

	pilha->print();
	cout << "qtd elementos: " << pilha->tamanho();
	cout << "\n\n";

	pilha->erase();
	pilha->print();
	cout << "qtd elementos: " << pilha->tamanho() << "\n";
	pilha->erase();
	system("pause");
	cout << "/////////////////////////////////////////////////////////////////\n";

	FilaLista<int>* fila = new FilaLista<int>;

	fila->push(zero);
	fila->push(um);
	fila->push(dois);
	fila->push(tres);
	fila->push(quatro);
	fila->push(cinco);

	cout << *fila->front() << "\n";
	cout << *fila->back() << "\n";

	cout << "FILA COM LISTA\n";

	fila->print();
	cout << "qtd elementos: " << fila->tamanho();
	cout << "\n\n";

	fila->pop();

	fila->print();
	cout << "qtd elementos: " << fila->tamanho();
	cout << "\n\n";

	fila->erase();
	fila->print();
	cout << "qtd elementos: " << fila->tamanho() << "\n";
	fila->erase();
	system("pause");
	cout << "/////////////////////////////////////////////////////////////////\n";

	FilaNo<int>* filano = new FilaNo<int>;

	filano->push(zero);
	filano->push(um);
	filano->push(dois);
	filano->push(tres);
	filano->push(quatro);
	filano->push(cinco);

	cout << filano->front() << "\n";
	cout << filano->back() << "\n";

	cout << "FILA COM NO\n";

	filano->print();
	cout << "qtd elementos: " << filano->tamanho();
	cout << "\n\n";

	filano->pop();

	filano->print();
	cout << "qtd elementos: " << filano->tamanho();
	cout << "\n\n";

	filano->erase();
	filano->print();
	cout << "qtd elementos: " << filano->tamanho() << "\n";
	filano->erase();
	system("pause");
	cout << "/////////////////////////////////////////////////////////////////\n";

	PilhaNo<int>* pilhano = new PilhaNo<int>;

	pilhano->push(zero);
	pilhano->push(um);
	pilhano->push(dois);
	pilhano->push(tres);
	pilhano->push(quatro);
	pilhano->push(cinco);

	cout << pilhano->front() << "\n";
	cout << pilhano->back() << "\n";

	cout << "PILHA COM NO\n";

	pilhano->print();
	cout << "qtd elementos: " << pilhano->tamanho();
	cout << "\n\n";

	pilhano->pop();

	pilhano->print();
	cout << "qtd elementos: " << pilhano->tamanho();
	cout << "\n\n";

	pilhano->erase();
	pilhano->print();
	cout << "qtd elementos: " << pilhano->tamanho() << "\n";
	pilhano->erase();

	system("pause");
	return 0;
}