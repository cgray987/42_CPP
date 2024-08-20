/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:34:16 by cgray             #+#    #+#             */
/*   Updated: 2024/08/07 11:33:05 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap //must be virtual bc DT uses it as well
{
	private:
		bool	_guardGate;

	protected:
		unsigned int	_HP;
		unsigned int	_EnergyPt;
		unsigned int	_AttackDmg;

	public:
		//constructors
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);

		//destructors
		virtual ~ScavTrap();

		ScavTrap &operator = (const ScavTrap &src);

		void	attack(const std::string &target);
		void	guardGate(void);
};
