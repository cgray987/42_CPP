/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:38:23 by cgray             #+#    #+#             */
/*   Updated: 2024/07/18 15:21:09 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define RED "\033[31m"
#define RST "\033[0m"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_HP = 100;
	this->_AttackDmg = 20;
	this->_EnergyPt = 50;
	this->_guardGate = false;
	std::cout << RED << "-ScavTrap Default Constructor-\n" << RST;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_HP = 100;
	this->_AttackDmg = 20;
	this->_EnergyPt = 50;
	this->_guardGate = false;
	std::cout << RED << "-ScavTrap Constructor for " << this->_Name << "\n" << RST;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	this->_guardGate = copy._guardGate;
	std::cout << RED << "-ScavTrap copy constructor for " << this->_Name << "\n" << RST;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "-ScavTrap destructor for " << this->_Name << "\n" << RST;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &src)
{
	std::cout << RED << "-Assigning ScavTrap copy-\n" << RST;
	this->_Name = src._Name;
	this->_HP = src._HP;
	this->_EnergyPt = src._EnergyPt;
	this->_AttackDmg = src._AttackDmg;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_EnergyPt > 0 && this->_HP > 0)
	{
		std::cout << RED << this->_Name << " Scavtrap attacks '" << target
				<< "' for " << this->_AttackDmg << " damage.\n" << RST;
		this->_EnergyPt--;
	}
	else if (this->_EnergyPt == 0)
		std::cout << RED << this->_Name << " Scavtrap is exhausted and cannot attack '"
			<< target << "'.\033[0m\n";
	else //hp = 0
		std::cout << RED << this->_Name << " Scavtrap cannot attack '" << target
				<< "' because they are dead.\n" << RST;
}

void	ScavTrap::guardGate()
{
	if (this->_guardGate == false)
	{
		this->_guardGate = true;
		std::cout << RED << this->_Name << " ScavTrap is now in Gate keeper mode.\n" << RST;
	}
	else
	{
		this->_guardGate = false;
		std::cout << RED << this->_Name << " ScavTrap is leaving Gate keeper mode.\n" << RST;
	}
}
