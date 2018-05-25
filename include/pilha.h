#ifndef _PILHA_H
#define _PILHA_H

#include "lista.h"

template <typename T>
class pilha {
private:
	ListaLigada<T> m_lista;
	shared_ptr<Node<T>> m_top;
public:
	pilha();
	~pilha();

	T top();
	void pop();
	void push(T top_);
	bool empty();
	int size();
};

#endif

template <typename T>
pilha<T>::pilha(): m_top(nullptr)
{}

template <typename T>
pilha<T>::~pilha(){
	while(!this->empty()){
		this->pop();
	}
}

template <typename T>
void pilha<T>::push(T top_){
	m_lista.InsereNoInicio(top_);
	m_top = m_lista.getCabeca();
}

template <typename T>
void pilha<T>::pop(){
	m_lista.RemoveNoInicio();
	m_top = m_lista.getCabeca();
}

template <typename T>
T pilha<T>::top(){
	return m_top->getValor();
}

template<typename T>
bool pilha<T>::empty(){
	return m_lista.size() == 0 ? true : false;
}

template<typename T>
bool pilha<T>::size(){
	return m_lista.size();
}