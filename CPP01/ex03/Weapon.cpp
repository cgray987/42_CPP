/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:26:19 by cgray             #+#    #+#             */
/*   Updated: 2024/06/17 15:39:33 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &weapon)
{
	this->setType(weapon);
}

Weapon::~Weapon()
{
}

std::string	Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(const std::string &weapon)
{
	int	flag = 0;
	if (this->getType() != "")
	{
		flag = 1;
		std::cout << "the " << this->getType()
			<< " has become a ";
	}
	_type = weapon;
	if (flag == 1)
		std::cout << this->getType() << ".\n";
}
