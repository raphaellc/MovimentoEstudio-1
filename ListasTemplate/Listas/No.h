#pragma once
class No
{
public:
	No();
	~No() {};
	
	//Insira um metodo aqui
	int getDado();
	void setDado(int d); //O que faz esse método. 
	//Insira outro metodo aqui
	No* getProximo();
	No* getAnterior();
	void setProximo(No * prox);
	void setAnterior(No * ant);
private:
	int dado;
	No* proximoNo;
	No* anteriorNo;
};

