/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:37:35 by cgray             #+#    #+#             */
/*   Updated: 2024/06/14 16:46:44 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie()
{

}

void	Zombie::set_name(std::string new_name)
{
	this->_name = new_name;
}

Zombie::Zombie(std::string name) : _name(name)
{
	announce();
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << "'s head has been disconnected. 💀\n";
}

