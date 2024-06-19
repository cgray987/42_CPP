/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:32:28 by cgray             #+#    #+#             */
/*   Updated: 2024/06/17 14:35:17 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
private:
	Weapon	&_weapon;
	std::string	_name;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack();
};





#endif
