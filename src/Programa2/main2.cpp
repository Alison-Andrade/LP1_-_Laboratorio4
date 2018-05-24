#include <iostream>
#include <vector>
#include <string>

#include "pilha.h"

int main(int argc, char const *argv[]){
	
	pilha<int> s;
	std::string in;
	int val1, val2, result;

	std::cout << "Digite a expressão a ser calculada: ";
	std::getline(std::cin, in);

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

	return 0;
}