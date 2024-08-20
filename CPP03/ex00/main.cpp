/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:05:36 by cgray             #+#    #+#             */
/*   Updated: 2024/07/17 14:26:45 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	{
		ClapTrap robot;
		ClapTrap automaton("automaton");
		ClapTrap android(automaton);

		robot.attack("someone else");
		robot.takeDamage(5);
		robot.takeDamage(5); //kill 'no name'
		robot.takeDamage(5); //damage while dead
		robot.beRepaired(42); //repair while dead
		robot.takeDamage(42); //damage while dead
		robot.attack("yet another someone"); //attack while dead
		automaton.takeDamage(1);
		automaton.beRepaired(10); //repair over full hp

		for (int i = 0; i < 10; i++) //attack without enough energy
			automaton.attack("horde");

		android.takeDamage(5); //copy should be seperate (still have full hp) from 'automaton'
	}
}
