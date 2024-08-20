/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:05:36 by cgray             #+#    #+#             */
/*   Updated: 2024/08/07 11:33:35 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	{
		std::cout << "~~~~~~~~DIAMONDTRAP MAIN~~~~~~~~~~~\n";

		DiamondTrap	jewel_robot;
		DiamondTrap	gem_robot = DiamondTrap("gem robot");
		DiamondTrap	gem_copy = DiamondTrap(gem_robot);

		gem_robot.whoAmI();

		gem_robot.guardGate();
		gem_robot.highFivesGuys();

		gem_copy.attack("jeff"); //should be for 30 hp...
		gem_copy.takeDamage(99);
		gem_copy.beRepaired(1);
	}
}
