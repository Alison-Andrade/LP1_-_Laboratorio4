#ifndef _PILHA_H
#define _PILHA_H

#include "lista.h"

template <typename T>
class pilha {
private:
	ListaLigada<T> m_fila;
	shared_ptr<Node<T>> m_top;
public:
	pilha();
	~pilha();

	T top();
	void pop();
	void push(T top_);
	bool empty();
};

#endif

template <typename T>
pilha<T>::pilha(): m_top(nullptr)
{}

template <typename T>
pilha<T>::~pilha()
{}

template <typename T>
void pilha<T>::push(T top_){
	m_fila.InsereNoInicio(top_);
	m_top = m_fila.getCabeca();
}

template <typename T>
void pilha<T>::pop(){
	m_fila.RemoveNoInicio();
	m_top = m_fila.getCabeca();
}

template <typename T>
T pilha<T>::top(){
	return m_top->getValor();
}

template<typename T>
bool pilha<T>::empty(){
	return m_fila.getCabeca() == m_fila.getCauda() ? true : false;
}
