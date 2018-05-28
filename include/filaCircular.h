/**
* @file		filaCircular.h
* @brief	Declaração e implementação dos métodos e atributos da classe FilaCircular<T>
*
* @author	Alison Sidnei Ferreira de Andrade
*/

#ifndef _FILACIRCULAR_H_
#define _FILACIRCULAR_H_

#include "listaCircular.h"

template<typename T>
class FilaCircular{
private:
	ListaCircular<T> m_listaC;
	shared_ptr<Node<T>> m_front;
	shared_ptr<Node<T>> m_back;
public:
	FilaCircular();
	~FilaCircular();

	/**
	* @brief Verifica se a fila está vazia
	* @return true, se a fila está vazia
	*/
	bool empty();

	/**
	* @brief Verifica tamanho da fila
	* @return Tamanho de \a "lista circular" que contem os elementos da fila
	*/
	int size();

	/**
	* @brief Busca elemento na frente da fila
	* @return Elemento na frente da fila
	*/
	T front();

	/**
	* @brief Busca elemento no final da fila
	* @return Elemento no final da fila
	*/
	T back();

	/**
	* @brief Insere elemento no final da fila
	* @param _valor Elemento a ser inserido
	* @return true, se inserido corretamente
	*/
	bool push(T _valor);

	/**
	* @brief Remove primeiro elemento da fila
	* @return true, se removido corretamente
	*/
	bool pop();
};

template<typename T>
FilaCircular<T>::FilaCircular(): m_front(nullptr), m_back(nullptr)
{}

template<typename T>
FilaCircular<T>::~FilaCircular(){
	while(!this->empty()){
		this->pop();
	}
}

template<typename T>
bool FilaCircular<T>::empty(){
	return this->size() == 0 ? true : false;
}

template<typename T>
int FilaCircular<T>::size(){
	return m_listaC.size();
}

template<typename T>
T FilaCircular<T>::front(){
	return m_front->getValor();
}

template<typename T>
T FilaCircular<T>::back(){
	return m_back->getValor();
}

template<typename T>
bool FilaCircular<T>::push(T _valor){
	if(!m_listaC.InsereNoFinal(_valor)) return false;

	if(this->size() == 1) {
		m_front = m_listaC.getCauda();
		m_back = m_front;
	}

	m_back = m_listaC.getCauda();

	return true;
}

template<typename T>
bool FilaCircular<T>::pop(){
	if(this->empty() || !m_listaC.RemoveNoInicio()){
		
		std::cerr << "ERRO: Impossível remover, fila vazia." << endl;

		return false;
	}

	if(this->size() != 0) {
		m_front = m_listaC.getCauda()->getNext();
	}

	return true;

}

#endif