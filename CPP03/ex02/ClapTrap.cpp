/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:13:10 by cgray             #+#    #+#             */
/*   Updated: 2024/07/17 15:27:15 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//constructors
ClapTrap::ClapTrap(): _Name("no name"), _HP(10), _EnergyPt(10), _AttackDmg(0)
{
	std::cout << "-ClapTrap default constructor-\n";
}

ClapTrap::ClapTrap(std::string name): _Name(name), _HP(10), _EnergyPt(10), _AttackDmg(0)
{
	std::cout << "-ClapTrap constructor for " << name << "-\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "-ClapTrap copy constructor for " << this->_Name << "-\n";
}
//-------------------

//destructor
ClapTrap::~ClapTrap()
{
	std::cout << "-ClapTrap destructor for " << this->_Name << "-\n";
}

ClapTrap &ClapTrap::operator = (const ClapTrap &src)
{
	std::cout << "-Assigning ClapTrap copy-\n";

	this->_Name = src._Name;
	this->_HP = src._HP;
	this->_EnergyPt = src._EnergyPt;
	this->_AttackDmg = src._AttackDmg;
	return *this;
}

//public methods
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_HP > amount)
		this->_HP -=amount;
	else if (this->_HP == 0)
	{
		std::cout << this->_Name << " ClapTrap is already dead! :( \n";
		return ;
	}
	else if (this->_HP <= amount)
	{
		std::cout << this->_Name << " ClapTrap lost " << amount
				<< " of HP and is now dead :(\n";
		this->_HP = 0;
		return ;
	}
	std::cout << this->_Name << " ClapTrap lost " << amount
				<< " HP and now has " << this->_HP << " left\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPt >= 1
		&& this->_HP < 10 && this->_HP > 0)
	{
		this->_EnergyPt--;
		if (this->_HP  + amount >= 10)
		{
			amount = 10 - this->_HP;
			std::cout << this->_Name << " ClapTrap will only heal "
				<< amount << " HP!\n";
		}
		this->_HP += amount;
		std::cout << this->_Name << " ClapTrap repairs itself for "
					<< amount << " HP and now has " << this->_HP << " left\n";
	}
	else if (this->_EnergyPt == 0)
		std::cout << this->_Name << " ClapTrap is out of energy and cannot repair themselves!\n";
	else if (this->_HP == 0)
		std::cout << this->_Name << " ClapTrap is dead and cannot be resurrected!\n";
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_EnergyPt > 0 && this->_HP > 0)
	{
		std::cout << this->_Name << " ClapTrap attacks '" << target
				<< "' for " << this->_AttackDmg << " damage.\n";
		this->_EnergyPt--;
	}
	else if (this->_EnergyPt == 0)
		std::cout << this->_Name << " ClapTrap is exhausted and cannot attack '"
			<< target << "'.\n";
	else //hp = 0
		std::cout << this->_Name << " ClapTrap cannot attack '" << target
				<< "' because they are dead.\n";
}
