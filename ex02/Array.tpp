/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:08:14 by aokhapki          #+#    #+#             */
/*   Updated: 2025/11/10 19:29:48 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Default constructor
template <typename T>
Array<T>::Array() : _data(nullptr), _size(0) {}

// Constructor with size n
template <typename T>
Array<T>::Array(unsigned int n) : _size(n) 
{
    _data = new T[n](); // value-initialize elements
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array<T>& other) : _size(other._size) 
{
    _data = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _data[i] = other._data[i];
}

// Destructor
template <typename T>
Array<T>::~Array() { delete[] _data;}

// Assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) 
{
    if (this != &other) {
        delete[] _data; // free old memory
        _size = other._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
    return *this;
}

// Element access with bounds checking (handles negative indices)
template <typename T>
T& Array<T>::operator[](int index) 
{
    if (index < 0 || static_cast<unsigned int>(index) >= _size)
        throw std::out_of_range("Index out of bounds");
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const 
{
    if (index < 0 || static_cast<unsigned int>(index) >= _size)
        throw std::out_of_range("Index out of bounds");
    return _data[index];
}

// Return size of array
template <typename T>
unsigned int Array<T>::size() const { return _size;}
