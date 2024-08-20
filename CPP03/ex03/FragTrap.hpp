/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:34:16 by cgray             #+#    #+#             */
/*   Updated: 2024/07/18 14:20:21 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap //must be virtual bc DT uses it as well
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
