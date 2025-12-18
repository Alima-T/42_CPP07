/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:18:19 by aokhapki          #+#    #+#             */
/*   Updated: 2025/12/18 11:47:02 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main()
{
	std::cout <<std::endl<< "\033[35m*** subject test: ***\033[0m" << std::endl;
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << '\n';
	std::cout << "min(a, b) = " << ::min(a, b) << '\n';
	std::cout << "max(a, b) = " << ::max(a, b) << '\n';

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << '\n';
	std::cout << "min(c, d) = " << ::min(c, d) << '\n';
	std::cout << "max(c, d) = " << ::max(c, d) << '\n';

	std::cout <<std::endl<< "\033[35m*** equal test: ***\033[0m" << std::endl;
	int x = 42;
	int y = 42;
	std::cout << "x = " << x << ", y = " << y << '\n';
	std::cout << "min(x, y) = " << ::min(x, y) << " (expect second arg)\n";
	std::cout << "max(x, y) = " << ::max(x, y) << " (expect second arg)\n";

	std::cout <<std::endl<< "\033[35m*** int test: ***\033[0m" << std::endl;
	int e = 5;
	int f = 9;
	std::cout << "e = " << e << ", f = " << f << '\n';
	std::cout <<"The min = " << ::min<int>(e, f) << std::endl;
	std::cout <<"The max = " << ::max<int>(e, f) << std::endl;
	std::cout<< "Before swap: e="<< e << ", f="<< f <<std::endl;
	swap<int>(e, f);
	std::cout<< "After swap:  e="<< e << ", f="<< f <<std::endl<<std::endl;

	std::cout << "\033[35m*** float test: ***\033[0m" << std::endl;
	float g = 15.15;
	float h = 7.111;
	std::cout << "g = " << g << ", h = " << h << '\n';
	std::cout <<"The min = " << ::min<float>(g, h) << std::endl;
	std::cout <<"The max = " << ::max<float>(g, h) << std::endl;
	std::cout<< "Before swap: g="<< g << ", h="<< h <<std::endl;
	swap<float>(g, h);
	std::cout<< "After swap:  g="<< g << ", h="<< h <<std::endl;

return 0;
}