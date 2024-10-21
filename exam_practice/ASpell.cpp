/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:12:53 by cgray             #+#    #+#             */
/*   Updated: 2024/10/21 13:59:49 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() {}
ASpell::ASpell(const ASpell &src) {*this = src;}
ASpell::ASpell(std::string const &name, std::string const &effects) : name(name), effects(effects)
{
	// std::cout << getName() << ": This looks like another boring day.\n";
}
ASpell::~ASpell()
{
	// std::cout << getName() << ": My job here is done!\n";
}

ASpell &ASpell::operator = (const ASpell &src)
{
	if (this != &src)
	{
		this->name = src.name;
		this->effects = src.effects;
	}
	return (*this);
}

std::string const &ASpell::getName() const
{
	return (this->name);
}
std::string const &ASpell::getEffects() const
{
	return (this->effects);
}

void	ASpell::launch(ATarget const &target) const
{
	target.getHitBySpell((*this));
}
