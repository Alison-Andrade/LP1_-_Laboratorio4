/**
* @file		main1.cpp
* @brief	Verifica se strings são palindromos
* @details	
*
* @author	Alison Sidnei Ferreira de Andrade
*/

#include <iostream>

#include "pilha.h"
#include "tratarString.h"

int main (int argc, char const* argv[]){
	
	char continuar{'s'};
	std::string in, out = "";

	pilha<char> s;

	while(continuar == 's') {
		std::cout << "Digite a plavra ou frase a ser verificada: ";

	    in.clear();
	    out.clear();

		while(in.size() == 0) {
		    std::getline(std::cin, in);
		}

		in = TratarString(in);

		for(unsigned i = 0; i < in.size(); i++) {
			s.push(in[i]);
		}

		while(!s.empty()) {
		    out += s.top();
		    s.pop();
		}

		in == out ? std::cout << "É palindromo!" << std::endl : std::cout << "Não é palindromo!" << std::endl;

		continuar = ' ';

		while((continuar != 's') && (continuar != 'n')) {
		    std::cout << "Deseja inserir uma nova entrada?(s/n): ";
		    std::cin >> continuar;
		}
	}

	return 0;
}
