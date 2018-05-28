#include <iostream>
#include "filaCircular.h"

int main(int argc, char const *argv[]){
	
	FilaCircular<string> fila;

	std::cout << "Teste remoção em fila vazia: " << std::endl;
	fila.pop();
	std::cout << std::endl;

	fila.push("João");
	fila.push("Maria");
	fila.push("Pedro");

	std::cout << "Primeiro elemento da fila: " <<fila.front() << std::endl;
	std::cout << "Ultimo elemento da fila: " << fila.back() << std::endl;

	std::cout << std::endl;
	fila.pop();
	std::cout << "Um elemento removido da fila." << std::endl;
	std::cout << std::endl;
	std::cout << "Após remoção:" << std::endl;
	std::cout << "Primeiro elemento da fila: " <<fila.front() << std::endl;
	std::cout << "Ultimo elemento da fila: " << fila.back() << std::endl;

	return 0;
}