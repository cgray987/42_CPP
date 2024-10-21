/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:16:58 by cgray             #+#    #+#             */
/*   Updated: 2024/10/21 14:00:34 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget() {}
ATarget::ATarget(const ATarget &src) {*this = src;}
ATarget::ATarget(std::string const &type) : type(type)
{
	// std::cout << gettype() << ": This looks like another boring day.\n";
}
ATarget::~ATarget()
{
	// std::cout << gettype() << ": My job here is done!\n";
}

ATarget &ATarget::operator = (const ATarget &src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

std::string const &ATarget::getType() const
{
	return (this->type);
}


void	ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << getType() << " has been " << spell.getEffects() << "!\n";
}
