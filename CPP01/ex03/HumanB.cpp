/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:36:52 by cgray             #+#    #+#             */
/*   Updated: 2024/06/18 15:18:39 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_has_weapon = false;
	std::cout << this->_name
		<< " has no weapon\n";
}

HumanB::~HumanB()
{
	std::cout << this->_name << " has died. "
		<< "Thank you for your service. 🫡\n";
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	this->_has_weapon = true;
	std::cout << this->_name << " has grabbed a "
		<< this->_weapon->getType() << ".\n";
}

void	HumanB::attack()
{
	if (this->_has_weapon)
	{
		std::cout << this->_name << " attacks with their "
			<< this->_weapon->getType() << ".\n";
	}
	else
	{
		std::cout << this->_name << " attacks using "
			<< "nothing!\n";
	}
}
