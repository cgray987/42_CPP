/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:28:28 by cgray             #+#    #+#             */
/*   Updated: 2024/06/12 17:39:53 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"



int	main(void)
{
	PhoneBook	rolodex;
	std::string	input;

	while (input != "EXIT")
	{
		input = enter_string("a Command (ADD|SEARCH|EXIT)");
		if (input == "ADD")
			rolodex.add();
		else if (input == "SEARCH")
			rolodex.search();
		else if (std::cin.eof())
		{
			std::cout << '\n';
			return (0);
		}
	}
	return (0);
}
