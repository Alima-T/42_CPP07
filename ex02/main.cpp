/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:05:34 by aokhapki          #+#    #+#             */
/*   Updated: 2025/12/20 12:15:22 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include "Array.hpp"
// #include <cstddef> // size_t
// #include <cstdlib> //rand()/srand()
// #include <ctime>

/*** 42 main tests ***/

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}

/*** my main with extra tests ***/

// int main()
// {
// 	try
// 	{
// 		// 1. Default cnstr: should create an empty array.
// 		Array<int> emptyArray;
// 		std::cout << "Empty array size: " << emptyArray.size() << "\n";

// 		// 2. Cnstr with size: if Array uses new T[n](), ints should be initialized to 0.
// 		Array<int> intArray(5);
// 		std::cout << "Array of size 5 with default values:\n";
// 		for (std::size_t i = 0; i < intArray.size(); ++i)
// 			std::cout << intArray[i] << " ";
// 		std::cout << "\n";
		
// 		// 3. Cnstr with size: if Array uses new T[n](), ints should be initialized to 0.
// 		const Array<int> constArray(intArray); // const object (copy)
// 		std::cout << "Read from constArray element 2:\n";
// 		std::cout << constArray[1] << "\n";    // here calls const operator[]
// 		// constArray[1] = 5;                  // this must NOT compile (read-only)

// 		// 4) Modify elements using operator[] (valid indices).
// 		// static_cast<int> to catch negative index
// 		for (std::size_t i = 0; i < intArray.size(); ++i)
// 			intArray[static_cast<int>(i)] = static_cast<int>(i * 5);

// 		std::cout << "Modified array:\n";
// 		for (std::size_t i = 0; i < intArray.size(); ++i)
// 			std::cout << intArray[i] << " ";
// 		std::cout << "\n";

// 		// 4. Copy constructor: copiedArray is created from intArray (deep copy- own mem).
// 		Array<int> copiedArray(intArray);
// 		std::cout << "Copied array:\n";
// 		for (std::size_t i = 0; i < copiedArray.size(); ++i)
// 			std::cout << copiedArray[i] << " ";
// 		std::cout << "\n";

// 		// 5. Prove deep copy (own mem), after change we see that original didn't change
// 		copiedArray[1] = 999;
// 		std::cout << "After change copiedArray[1] = 999:\n";
// 		std::cout << "intArray[1] = " << intArray[1]
// 				  << ", copiedArray[1] = " << copiedArray[1] << "\n";

// 		std::cout << "Modified array again:\n";
// 		for (std::size_t i = 0; i < intArray.size(); ++i)
// 			std::cout << intArray[i] << " ";
// 		std::cout << "\n";
		
// 		std::cout << "All copiedArray after change second el = 999:\n";
// 		for (std::size_t i = 0; i < copiedArray.size(); ++i)
// 			std::cout << copiedArray[i] << " ";
// 		std::cout << "\n";
		
// 		// 6. Assignment operator
// 		Array<int> assignedArray;
// 		std::cout << "Before assignment: size = " << assignedArray.size() << "\n";
// 		assignedArray = intArray;
// 		std::cout << "Assigned array:\n";
// 		for (std::size_t i = 0; i < assignedArray.size(); ++i)
// 			std::cout << assignedArray[i] << " ";
// 		std::cout << "\n";

// 		// 7. Out-of-bounds access ex.
// 		std::cout << "Accessing out-of-bounds element:\n";
// 		std::cout << intArray[10] << "\n";

// 		// 8. Out-of-bounds, negative index ex. 
// 		// std::cout << "Out-of-bounds: negative index:\n";
// 		// std::cout << intArray[-1] << "\n"; 
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << "Error: " << e.what() << "\n";
// 	}

// 	return 0;
// }
