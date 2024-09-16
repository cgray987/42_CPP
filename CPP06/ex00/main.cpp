/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:34:50 by cgray             #+#    #+#             */
/*   Updated: 2024/09/13 17:44:58 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac == 2)
			Scalar::convert(std::string(av[1]));
		// Scalar s = Scalar("42"); //show that class is not instantiable
	}
	catch (const std::exception &e)
	{
		std::cerr << "Main caught exception: " << e.what() << "\n";
	}
}
