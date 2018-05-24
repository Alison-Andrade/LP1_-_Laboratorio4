/**
* @file		tratarString.cpp
* @brief	Funções para remoção de caracteres especiais e acentuação de strings
* @details	
*
* @author	Alison Sidnei Ferreira de Andrade
*/

#include "tratarString.h"

std::string RemoverAcentos(std::string in){
	std::vector<std::string> comAcentos = {"Á", "Â", "À", "Ã", "á", "â", "à", "ã", "É", "Ê", "È", "é", "ê", "è", "Í", "Î", "Ì", "í",
	 "î", "ì", "Ó", "Ô", "Ò", "Õ", "ó", "ô", "ò", "õ", "Ú", "Û", "ú", "û", "ù", "Ç", "ç"};
	std::vector<std::string> semAcentos = {"A", "A", "A", "A", "a", "a", "a", "a", "E", "E", "E", "e", "e", "e", "I", "I", "I", "i",
	 "i", "i", "O", "O", "O", "O", "o", "o", "o", "o", "U", "U", "u", "u", "u", "C", "c"};
	
	for (unsigned i = 0; i < in.size(); i++){
		for (unsigned j = 0; j < comAcentos.size(); j++){
			std::size_t found = in.find(comAcentos[j]);
			if ( found != std::string::npos ){
				in.replace( found, comAcentos[j].size(), semAcentos[j] );
			}
		}
	}

	return in;
}

std::string TratarString(std::string in){

	std::string aux="";

	in = RemoverAcentos(in);

	for (unsigned i = 0; i < in.size(); i++){
		if((in[i] >= 48 && in[i] <= 57) || (in[i] >= 65 && in[i] <= 90) || (in[i] >= 97 && in[i] <= 122)) {
			if(in[i] >= 65 && in[i] <= 90) {
				aux += in[i]+32;
			}else{
				aux += in[i];
			}
		}
	}

	return aux;
}