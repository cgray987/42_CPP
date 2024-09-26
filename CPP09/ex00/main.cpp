/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:59:21 by cgray             #+#    #+#             */
/*   Updated: 2024/09/25 15:02:43 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		BitcoinExchange	bit;

		try
		{
			bit.read_input(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Main caught exception: " << e.what() << '\n';
		}

	}
	else
		std::cerr << "Error: could not open file.\n";
}