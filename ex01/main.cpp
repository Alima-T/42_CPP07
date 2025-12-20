/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:18:19 by aokhapki          #+#    #+#             */
/*   Updated: 2025/12/20 11:11:16 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

// to test iter
void printInt(int &n) 
{
	std::cout << n << " ";
}

void printConstInt(const int &n) {
	std::cout << n << " ";
}

void increment(int &n) 
{
	n += 1;
}

void printString(const std::string &s) 
{
	std::cout << s << " ";
}   

int main( void ) 
{
	int numbers[] = {1, 22, 30, -1, 0};
	std::size_t len = sizeof(numbers) / sizeof(numbers[0]);

	std::cout << "Original numbers: ";
	iter(numbers, len, printInt);        // const& ok
	std::cout << '\n';

	iter(numbers, len, increment);       // modify only non-const&

	std::cout << "After increment: ";
	iter(numbers, len, printInt);
	std::cout << std::endl;

	const std::string words[] = {"Hello", "World", "Template", "C++"};
	std::size_t wordsLen = sizeof(words) / sizeof(words[0]);

	std::cout << "Words: ";
	iter(words, wordsLen, printString);
	std::cout << std::endl;
	
	// Тест с const arr - read only autput is ok, we don't change:
	std::string const constWords[] = {"const", "array.", "Lambda in C++ is", "Okay."};
	std::cout << "Const words: ";
	iter(constWords, 4, [](std::string const& s) { std::cout << s << ' '; }); //lambda to print
	std::cout << '\n';
	
	return 0;
}