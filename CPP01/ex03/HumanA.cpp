/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:35:20 by cgray             #+#    #+#             */
/*   Updated: 2024/06/18 15:18:18 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon)
{
	this->_name = name;
	this->_weapon = weapon;
	std::cout << this->_name
		<< " has started with a "
		<< this->_weapon.getType() << "!\n";
}

HumanA::~HumanA()
{
	std::cout << this->_name << " has died. "
		<< "Thank you for your service. 🫡\n";
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their "
		<< this->_weapon.getType() << ".\n";
}
