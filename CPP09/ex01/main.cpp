/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:19:29 by cgray             #+#    #+#             */
/*   Updated: 2024/10/03 12:07:54 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int	main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			RPN	op;
			op.calculate(av[1]);
		}
		catch (std::exception &e)
		{
			std::cerr << "Main caught exception: " << e.what() << "\n";
		}
	}
	else
	{
		std::cerr << "Argument error: ./RPN 'num num op num op'\n";
		return (1);
	}
	return (0);
}
