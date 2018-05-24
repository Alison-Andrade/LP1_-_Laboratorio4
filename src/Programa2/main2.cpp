/**
* @file		main2.cpp
* @brief	Calcula expressões em notação pós-fixada utilizando propriedades da TAD pilha.
* @details	
*
* @author	Alison Sidnei Ferreira de Andrade
*/

#include <iostream>
#include <vector>
#include <string>

#include "pilha.h"

int main(int argc, char const *argv[]){
	
	pilha<int> s;
	std::string in;
	int val1, val2, result;
	char continuar{'s'};

	while(continuar == 's') {

		std::cout << std::endl << "Digite a expressão a ser calculada: ";
		in.clear();
		while(in.size() == 0) {
		    std::getline(std::cin, in);
		}

		std::string value = "";

		unsigned i = 0;

		do{

			while(in[i] != ' ' && i < in.size()) {
				value += in[i];
				i++;
			}

			if(value != "+" && value != "-" && value != "*" && value != "/") {
				
				s.push(stoi(value));
				value.clear();
			}else{
				char operador = value[0];
				value.clear();
				switch(operador){
					case '+':
						val1 = s.top();
						s.pop();
						val2 = s.top();
						s.pop();
						result = val1 + val2;
						s.push(result);
						break;
					case '-':
						val1 = s.top();
						s.pop();
						val2 = s.top();
						s.pop();
						result = val1 - val2;
						s.push(result);
						break;
					case '*':
						val1 = s.top();
						s.pop();
						val2 = s.top();
						s.pop();
						result = val1 * val2;
						s.push(result);
						break;
					case '/':
						val1 = s.top();
						s.pop();
						val2 = s.top();
						s.pop();
						result = val2 / val1;
						s.push(result);
						break;
				}
			}

			i++;
		}while(i < in.size());

		std::cout << "O resultado da expressão é: " << s.top() << std::endl;

		continuar = ' ';

		while((continuar != 's') && (continuar != 'n')) {
		    std::cout << "Deseja inserir uma nova entrada?(s/n): ";
		    std::cin >> continuar;
		}
	}

	return 0;
}