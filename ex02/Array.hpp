/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:08:09 by aokhapki          #+#    #+#             */
/*   Updated: 2025/12/17 01:26:47 by aokhapki         ###   ########.fr       */
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
    // Constructors & Destructor
    Array();                        // Default constructor
    Array(unsigned int n);          // Constructor with size
    Array(const Array& src);        // Copy constructor
    ~Array();                       // Destructor

    // Assignment operator
    Array& operator=(const Array& rhs);

    // Element access with bounds checking
    T& operator[](int index);
    const T& operator[](int index) const;

    // Size of array
    unsigned int size() const;
};

#include "Array.tpp"
#endif