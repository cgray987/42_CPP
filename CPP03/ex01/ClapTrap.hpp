/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:05:49 by cgray             #+#    #+#             */
/*   Updated: 2024/07/18 14:06:08 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

class	ClapTrap
{
	protected: //changed from private for inheritance
		std::string		_Name;
		unsigned int	_HP;
		unsigned int	_EnergyPt;
		unsigned int	_AttackDmg;

	public:
		//constructors
		ClapTrap();
		ClapTrap(std::string _Name);
		ClapTrap(const ClapTrap &copy);


		//destructors
		virtual	~ClapTrap();

		ClapTrap &operator=(const ClapTrap &src);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
