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
	
	std::string in, out = "";

	pilha<char> s;

	std::getline(std::cin, in);

	in = TratarString(in);

	for(unsigned i = 0; i < in.size(); i++) {
		s.push(in[i]);
	}

	while(!s.empty()) {
	    out += s.top();
	    s.pop();
	}

	std::cout << in << std::endl;
	std::cout << out << std::endl;

	in == out ? std::cout << "É palindromo!" << std::endl : std::cout << "Não é palindromo!" << std::endl;

	return 0;
}
