/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:42:13 by cgray             #+#    #+#             */
/*   Updated: 2024/09/16 16:42:16 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"


int main(void)
{
	int	a = 2;
	int	b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << "\n"
			<< "min(a, b) = " << ::min(a, b) << "\n"
			<< "max(a, b) = " << ::max(a, b) << "\n";

	std::string c = "hello1";
	std::string d = "hello2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << "\n"
			<< "min(c, d) = " << ::min(c, d) << "\n"
			<< "max(c, d) = " << ::max(c, d) << "\n";
}
