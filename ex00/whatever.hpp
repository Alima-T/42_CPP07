/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:28:01 by aokhapki          #+#    #+#             */
/*   Updated: 2025/12/20 10:46:39 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T& a, T& b)
{
	T	temp;
	temp = a;
	a = b;
	b = temp;
}


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
