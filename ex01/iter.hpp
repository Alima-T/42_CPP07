/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:28:01 by aokhapki          #+#    #+#             */
/*   Updated: 2025/11/10 18:40:46 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for size_t

// Function template 'iter' that applies a given function to each element of an array
template <typename T>
void iter(T* array, const size_t length, void (*func)(T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

//overload for const arrays
template <typename T>
void iter(const T* array, const size_t length, void (*func)(const T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif
