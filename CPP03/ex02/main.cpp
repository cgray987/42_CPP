/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:05:36 by cgray             #+#    #+#             */
/*   Updated: 2024/07/18 13:57:35 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	{
		std::cout << "~~~~~~~~FRAGTRAP MAIN~~~~~~~~~~~\n";

		FragTrap big_robot;
		FragTrap big_automaton("big automaton");
		FragTrap big_copy(big_automaton);

		big_automaton.attack("frank"); //damage should change
		big_automaton.takeDamage(99); //should have 1 hp left
		big_automaton.takeDamage(2); //kill
		big_automaton.takeDamage(1);

		big_robot.highFivesGuys();

		big_copy.attack("fred");
	}
}
