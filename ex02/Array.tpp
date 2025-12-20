/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:08:14 by aokhapki          #+#    #+#             */
/*   Updated: 2025/12/20 11:13:38 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// I set m_data to nullptr so the pointer is never garbage; destructor could call delete[] on a garbage pointer

template <typename T>
Array<T>::Array() : m_data(nullptr), m_size(0) {}

/**
*Here nullptr is not required, we assign m_data immediately.
*new T[n]() value-initializes elements: int -> 0 (or if new int[3] without () = int -> garbage)
*new T - class objects are created using their default constructor.
*n can be 0, it is allowed (delete[] is still safe).
 */ 
template <typename T>
Array<T>::Array(unsigned int n) : m_size(n)
{
	m_data = new T[m_size]();
}

// Copy constr, allocate a new arr and copy each el
template <typename T>
Array<T>::Array(const Array<T>& src) : m_size(src.m_size) 
{
	m_data = new T[m_size];
	for (unsigned int i = 0; i < m_size; i++)
		m_data[i] = src.m_data[i];
}

template <typename T>
Array<T>::~Array() 
{ 
	delete[] m_data;
}

//Assignment: handle self-assignment, free old memory, then deep copy from rhs.
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) 
{
	if (this != &rhs) 
	{
		delete[] m_data;
		m_size = rhs.m_size;
		m_data = new T[m_size];
		for (unsigned int i = 0; i < m_size; i++)
			m_data[i] = rhs.m_data[i];
	}
	return *this;
}

// operator[] to have access to i
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
