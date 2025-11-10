/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:18:19 by aokhapki          #+#    #+#             */
/*   Updated: 2025/11/10 19:33:44 by aokhapki         ###   ########.fr       */
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
    size_t len = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Original numbers: ";
    iter(numbers, len, printInt);
    std::cout << std::endl;

    iter(numbers, len, increment);

    std::cout << "After increment: ";
    iter(numbers, len, printInt);
    std::cout << std::endl;

    const std::string words[] = {"Hello", "World", "Template", "C++"};
    size_t wordsLen = sizeof(words) / sizeof(words[0]);

    std::cout << "Words: ";
    iter(words, wordsLen, printString);
    std::cout << std::endl;
    
    return 0;
}