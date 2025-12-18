/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:28:01 by aokhapki          #+#    #+#             */
/*   Updated: 2025/12/18 12:23:56 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// function templates => реализация должна быть в header.

template <typename T> void swap(T& a, T& b)
{
	T	temp;
	temp = a;
	a = b;
	b = temp;
}

/*
* when values are equal, min/max must return the second argument, 
* so I use strict comparisons <, >, and otherwise return b
*/
template <typename T> 
T const& min(T const& a, T const& b)
{
	return ((a < b) ? a : b);
}

template <typename T> 
T const& max(T const& a, T const& b)
{
	return ((a > b) ? a : b);
}

#endif
