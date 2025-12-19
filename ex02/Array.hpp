/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:08:09 by aokhapki          #+#    #+#             */
/*   Updated: 2025/12/19 14:28:03 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // std::out_of_range

template <typename T>
class Array
{
private:
	T* m_data;
	unsigned int m_size;

public:
	// Orthodox Canonical Form 
	Array();                        // default
	Array(unsigned int n);          // with size
	Array(const Array& src);        // deep copy
	~Array();                     

	// Assignment operator - deep copy
	Array& operator=(const Array& rhs);

	// access to m_data index, int to catch negativ nbs
	T& operator[](int index);
	const T& operator[](int index) const;

	// m_size getter
	unsigned int size() const;
};

#include "Array.tpp"
#endif