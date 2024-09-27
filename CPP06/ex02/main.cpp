/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:36:34 by cgray             #+#    #+#             */
/*   Updated: 2024/09/27 12:11:08 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		Base *ptr;
		ptr = generate(); //assigns ptr class of A,B, or C

		std::cout << "identify via ptr:\t";
		identify(ptr);
		std::cout << "identify via ref:\t";
		identify(*ptr);
		std::cout << "~~~~~~~~~~~~~~~~~~~~\n";

		delete ptr;

	}
}
