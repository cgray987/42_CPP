/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:34:16 by cgray             #+#    #+#             */
/*   Updated: 2024/07/17 17:09:59 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		//constructors
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);

		//destructors
		virtual ~FragTrap();

		FragTrap &operator = (const FragTrap &src);

		void	highFivesGuys(void);
};
