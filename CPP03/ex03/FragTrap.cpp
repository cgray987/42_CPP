/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:38:23 by cgray             #+#    #+#             */
/*   Updated: 2024/07/18 15:18:24 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define CYN "\033[96m"
#define RST "\033[0m"


FragTrap::FragTrap(): ClapTrap()
{
	this->_HP = 100;
	this->_AttackDmg = 30;
	this->_EnergyPt = 100;
	std::cout << CYN << "-FragTrap Default Constructor-\n" << RST;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_HP = 100;
	this->_AttackDmg = 30;
	this->_EnergyPt = 100;
	std::cout << CYN << "-FragTrap Constructor for " << this->_Name << "\n" << RST;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << CYN << "-FragTrap copy constructor for " << this->_Name << "\n" << RST;
}

FragTrap::~FragTrap()
{
	std::cout << CYN << "-FragTrap destructor for " << this->_Name << "\n" << RST;
}

FragTrap &FragTrap::operator = (const FragTrap &src)
{
	std::cout << CYN << "-Assigning FragTrap copy-\n" << RST;
	this->_Name = src._Name;
	this->_HP = src._HP;
	this->_EnergyPt = src._EnergyPt;
	this->_AttackDmg = src._AttackDmg;
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << CYN << this->_Name << " FragTrap says: "
			<< " High Five! ✋\n" << RST;
}
