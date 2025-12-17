/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:08:14 by aokhapki          #+#    #+#             */
/*   Updated: 2025/12/17 01:26:07 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Default constructor
template <typename T>
Array<T>::Array() : m_data(nullptr), m_size(0) {}

// Constructor with size n
template <typename T>
Array<T>::Array(unsigned int n) : m_size(n) 
{
    m_data = new T[n](); // value-initialize elements
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array<T>& src) : m_size(src.m_size) 
{
    m_data = new T[m_size];
    for (unsigned int i = 0; i < m_size; i++)
        m_data[i] = src.m_data[i];
}

// Destructor
template <typename T>
Array<T>::~Array() 
{ 
    delete[] m_data;
}

// Assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) 
{
    if (this != &rhs) {
        delete[] m_data; // free old memory
        m_size = rhs.m_size;
        m_data = new T[m_size];
        for (unsigned int i = 0; i < m_size; i++)
            m_data[i] = rhs.m_data[i];
    }
    return *this;
}

// Element access with bounds checking (handles negative indices)
template <typename T>
T& Array<T>::operator[](int index) 
{
    if (index < 0 || static_cast<unsigned int>(index) >= m_size)
        throw std::out_of_range("Index out of bounds");
    return m_data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const 
{
    if (index < 0 || static_cast<unsigned int>(index) >= m_size)
        throw std::out_of_range("Index out of bounds");
    return m_data[index];
}

// Return size of array
template <typename T>
unsigned int Array<T>::size() const 
{ 
    return m_size;
}
