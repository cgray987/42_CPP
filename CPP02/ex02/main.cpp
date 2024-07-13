/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:08:20 by cgray             #+#    #+#             */
/*   Updated: 2024/07/13 20:25:54 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed		a;
	Fixed const	b( Fixed(5.05f) * Fixed(2) );

	std::cout << a << "\t-'a' start\n"
			<< ++a << "\t-pre inc\n"
			<< a << "\t-after inc\n"
			<< a++ << "\t-post inc\n"
			<< a << "\t-after inc\n"
			<< b << "\t-'b'\n";

	std::cout << Fixed::max(a, b) << "\t-max of 'a', 'b'\n";
	return 0;
}
