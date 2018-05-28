/**
* @file		pilha.h
* @brief	Declaração e implementação dos métodos e atributos da classe pilha<T>
*
* @author	Alison Sidnei Ferreira de Andrade
*/

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

	/**
	* @brief Verifica qual é o elemento no topo da stack
	* @return Elemento no topo da pilha
	*/
	T top();

	/**
	* @brief Remove primeiro elemento da pilha
	* @return true, se removido
	* @return false, se não removido
	*/
	bool pop();

	/**
	* @brief Insere elemento no topo da pilha
	* @return true, se inserido
	* @return false, se não inserido
	* @param top_ Elemento a ser inserido na pilha
	*/
	bool push(T top_);

	/**
	* @brief Verifica se a pilha está vazia
	* @return true, se vazia
	*/
	bool empty();

	/**
	* @brief Verifica tamanho da pilha
	* @returns this->tamanho
	*/
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
bool pilha<T>::push(T top_){
	if(!m_lista.InsereNoInicio(top_)) return false;
	
	m_top = m_lista.getCabeca();
	return true;
}

template <typename T>
bool pilha<T>::pop(){
	if(!m_lista.RemoveNoInicio()) return false;

	m_top = m_lista.getCabeca();
	return true;
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
int pilha<T>::size(){
	return m_lista.size();
}