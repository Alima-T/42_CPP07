/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:28:01 by aokhapki          #+#    #+#             */
/*   Updated: 2025/11/10 19:35:12 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b) 
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(const T &a, const T &b) 
{
    return (a < b) ? a : b;
}

template <typename T>
T max(const T &a, const T &b) 
{
    return (a > b) ? a : b;
}

#endif
