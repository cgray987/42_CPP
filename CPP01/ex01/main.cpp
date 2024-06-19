/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:47:40 by cgray             #+#    #+#             */
/*   Updated: 2024/06/17 14:06:55 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		horde_count = 5;

	std::cout << "Constructor announce -- creating " << horde_count << " zombies.\n";
	horde = zombieHorde(horde_count, "Clusterfuck of Zombies");
	if (horde == NULL)
		return (1);
	std::cout << "Main announce\n";
	for (int i = 0; i < horde_count; i++)
	{
		horde[i].announce();
	}
	std::cout << "Main delete\n";
	delete[]	horde;
	return (0);
}
