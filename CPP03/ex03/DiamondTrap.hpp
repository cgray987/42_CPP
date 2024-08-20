/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:58:54 by cgray             #+#    #+#             */
/*   Updated: 2024/08/07 11:31:35 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"


class	DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_Name;

	public:
		//constructors
		DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap(std::string name);
		//destructors
		virtual	~DiamondTrap();

		DiamondTrap &operator = (const DiamondTrap &src);

		void	attack(const std::string &target);
		void	whoAmI(void);

};
