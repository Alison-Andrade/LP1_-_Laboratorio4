#include <iostream>
#include <string>
#include <vector>

#include "pilha.h"


// std::string RemoverAcentos(std::string in){
// 	std::vector<string> comAcentos = {"Á", "Â", "À", "Ã", "á", "â", "à", "ã", "É", "Ê", "È", "é", "ê", "è", "Í", "Î", "Ì", "í",
// 	 "î", "ì", "Ó", "Ô", "Ò", "Õ", "ó", "ô", "ò", "õ", "Ú", "Û", "ú", "û", "ù", "Ç", "ç"};
// 	std::vector<string> semAcentos = {"A", "A", "A", "A", "a", "a", "a", "a", "E", "E", "E", "e", "e", "e", "I", "I", "I", "i",
// 	 "i", "i", "O", "O", "O", "O", "o", "o", "o", "o", "U", "U", "u", "u", "u", "C", "c"};
	
// 	for (unsigned i = 0; i < comAcentos.size(); i++){
// 		std::cout << comAcentos[i] << std::endl;
// 		in.replace(in.begin(), in.end(), comAcentos[i], semAcentos[i]);
// 	}

// 	return in;
// }

std::string TratarString(std::string in){

	std::string aux="";

	//in = RemoverAcentos(in);

	for (unsigned i = 0; i < in.size(); i++){
		if((in[i] >= 65 && in[i] <= 90) || (in[i] >= 97 && in[i] <= 122)) {
			if(in[i] >= 65 && in[i] <= 90) {
				aux += in[i]+32;
			}else{
				aux += in[i];
			}
		}
	}

	return aux;
}

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

	// std::cout << in << std::endl;
	// std::cout << out << std::endl;

	in == out ? std::cout << "É palindromo!" << std::endl : std::cout << "Não é palindromo!" << std::endl;

	return 0;
}
