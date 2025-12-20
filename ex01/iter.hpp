/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:28:01 by aokhapki          #+#    #+#             */
/*   Updated: 2025/12/20 11:36:22 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for size_t

/* applies a given function to each element of an array
Func is a template (F), not only a function pointer:
- it can accept normal functions AND lambdas
- it also works with functions taking const T& (z.B. printing)
Two overloads:
- iter(T* ...)  -> array[i] это T& (modifiable)
- iter(const T* ...) -> array[i] это const T& (read-only)
*/
template <typename T, typename F>
void iter(T* array, std::size_t length, F func)
{
    // when nullptr - length == 0 - do nothing.
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T, typename F>
void iter(T const* array, std::size_t length, F func)
{
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]); 
}
#endif
