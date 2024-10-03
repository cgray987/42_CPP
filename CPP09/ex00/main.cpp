/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:59:21 by cgray             #+#    #+#             */
/*   Updated: 2024/10/03 13:41:09 by cgray            ###   ########.fr       */
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
		std::cerr << "Argument Error: ./btc 'input_file.txt'\n";
}
