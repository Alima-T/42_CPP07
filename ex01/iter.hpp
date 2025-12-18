/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:28:01 by aokhapki          #+#    #+#             */
/*   Updated: 2025/12/18 14:25:50 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for size_t

/* Function template 'iter' that applies a given function to each element of an array
iter(array, length, func):
- returns nothing
- calls func for each array element

Why func is a template (F), not only a function pointer:
- it can accept normal functions AND lambdas/functors
- it also works with functions taking const T& (e.g., printing)
Почему func — шаблон (F), а не только function pointer:
- тогда можно передавать не только обычные функции, но и лямбды/функторы
- и можно использовать функции, которые принимают const T& (например, печать)

Two overloads:
- iter(T* ...)  -> array[i] это T& (элемент можно менять modifiable)
- iter(const T* ...) -> array[i] это const T& (элемент менять нельзя read-only)

RU: Если массив T*, то array[i] даёт изменяемый элемент (T&). Если массив const T*, то array[i] даёт только чтение (const T&).
EN: With T*, array[i] is mutable (T&). With const T*, array[i] is read-only (const T&).
*/
template <typename T, typename F>
void iter(T* array, std::size_t length, F func)
{
    // when nullptr - length == 0 - do nothing.
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]);// array[i] -> T& ссылка на обычный эл, его можно менять
}

template <typename T, typename F>
void iter(T const* array, std::size_t length, F func)
{
    for (std::size_t i = 0; i < length; ++i)
        func(array[i]); // array[i] -> T const& - нельзя менять
}
#endif
