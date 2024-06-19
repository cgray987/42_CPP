/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:34:38 by cgray             #+#    #+#             */
/*   Updated: 2024/06/14 16:48:38 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie	*zombieHorde(int N, std::string name)
{
	if (N < 1)
	{
		std::cout << "Cannot create 0/negative horde!\n";
		return (NULL);
	}
	Zombie	*horde = new Zombie[N];
	if (horde == NULL)
	{
		std::cout << "Alloc failed!\n";
		return (NULL);
	}
	for (int i = 0; i < N; i++)
	{
		std::stringstream ss(name);
		ss << name << ' ' << i + 1;
		horde[i].set_name(ss.str());
		horde[i].announce();
	}
	return (horde);
}
