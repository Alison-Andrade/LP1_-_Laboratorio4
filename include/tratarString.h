/**
* @file		tratarString.h
* @brief	Declaração de funções para remover acentos espaços e outros caracteres especiais de strings
*
* @author	Alison Sidnei Ferreira de Andrade
*/

#ifndef _TRATARSTRING_H_
#define _TRATARSTRING_H_

#include <string>
#include <vector>

/**
* @brief Remove acentos de string
* @param in String a ser tratada
* @return in
*/
std::string RemoverAcentos(std::string in);

/**
* @brief Retira espaços e outros caracteres especiais de string
* @param in String a ser tratada
* @return in
*/
std::string TratarString(std::string in);

#endif