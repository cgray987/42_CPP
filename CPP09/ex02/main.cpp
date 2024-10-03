/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:52:11 by cgray             #+#    #+#             */
/*   Updated: 2024/10/03 11:38:42 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
*	./PmergeMe `shuf -i 1-100000 -n 30 | tr "\n" " "`
*/
int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Error: bad input -- ./PmergeMe 4 3 2 1\n";
		return (1);
	}
	try
	{
		std::cout << BLD << CYN << "\tVector\n" << RST;
		PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > > Vector(ac, av, "vector");
		Vector.ford_johnson();


		std::cout << BLD << CYN << "\tDeque\n" << RST;
		PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > > Deque(ac, av, "deque");
		Deque.ford_johnson();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Main caught exception: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
