#pragma once

template<class T>

class Tree
{
public:
	Tree();
	~Tree() {};

	//Novos m�todos
	void push(T* elemento); //Insere um n� com dado definido por par�metro no fim da lista

	void removeRoot();
	void removeNode(T* elemento);//
	void empty();
	bool searchNode(T* elemento/*, No * param_lista = lista*/);
	T* getRoot();
	void print();

private:
	bool isEmpty(); //Verifica se a lista est� vazia

	No<T>* root;
	int qtdNodes;
	int qtdLeafNodes;
};

