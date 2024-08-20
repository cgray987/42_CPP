/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:05:36 by cgray             #+#    #+#             */
/*   Updated: 2024/07/18 13:56:54 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	{
		std::cout << "~~~~~~~~SCAVTRAP MAIN~~~~~~~~~~~\n";

		ScavTrap big_robot;
		ScavTrap big_automaton("big automaton");
		ScavTrap big_copy(big_automaton);

		big_automaton.attack("frank"); //damage should change
		big_automaton.takeDamage(99); //should have 1 hp left
		for (int i = 0; i < 50; i++)
			big_automaton.attack("exhausting enemy"); //last should be exhausted
		big_automaton.takeDamage(2); //kill
		big_automaton.takeDamage(1);

		big_robot.guardGate();
		big_robot.guardGate();

		big_copy.attack("fred");

	}
}
