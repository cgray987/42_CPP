/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:58:51 by cgray             #+#    #+#             */
/*   Updated: 2024/08/07 11:31:28 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define MGT "\033[95m"
#define RST "\033[0m"

//constructors
DiamondTrap::DiamondTrap(): ClapTrap("no_name_DT_clap_trap")
{
	this->_Name = "no_name";
	this->_HP = FragTrap::_HP;
	this->_EnergyPt = ScavTrap::_EnergyPt;
	this->_AttackDmg = FragTrap::_AttackDmg;
	std::cout << MGT << "-Diamond Trap Default constructor-\n" << RST;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
	this->_Name = name;
	this->_HP = FragTrap::_HP;
	this->_EnergyPt = ScavTrap::_EnergyPt;
	this->_AttackDmg = FragTrap::_AttackDmg;
	std::cout << MGT << "-Diamond Trap constructor for '" << name + "'-\n" << RST;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	*this = copy;
	std::cout << MGT << "-Diamond Trap copy constructor for " << this->_Name + "-\n" << RST;
}
//------------

//destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << MGT << "-Diamond trap destructor for " << this->_Name + "-\n" << RST;
}

//overloaded ops
DiamondTrap &DiamondTrap::operator = (const DiamondTrap &src)
{
	std::cout << MGT << "-Assigning DiamondTrap-\n" << RST;
	this->_Name = src._Name + "_clap_trap";
	this->_HP = src._HP;
	this->_EnergyPt = src._EnergyPt;
	this->_AttackDmg = src._AttackDmg;
	return (*this);
}

//member functions
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << MGT << "I am '" << this->_Name << "' and I come from '"
				<< RST << ClapTrap::_Name << MGT << "'.\n"
				<< "Stats: {HP, Energy, Attack Damage}\t{ "
				<< this->_HP << ", " << this->_EnergyPt << ", "
				<< this->_AttackDmg << " }\n" << RST;
	/* should have
		100 HP (Frag)
		50 En	(Scav)
		30 Dmg	(Frag) */
}
