/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:52:11 by cgray             #+#    #+#             */
/*   Updated: 2024/09/26 15:06:45 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
*	./PmergeMe `shuf -i 1-100000 -n 30 | tr "\n" " "`
*/
int	main(int ac, char **av)
{
	try
	{
		PmergeMe test(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Main caught exception: " << e.what() << '\n';
	}
}
