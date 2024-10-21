/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:37:36 by cgray             #+#    #+#             */
/*   Updated: 2024/10/21 15:21:28 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock() {}
// Warlock::Warlock(const Warlock &src) {*this = src;}
Warlock::Warlock(std::string const &name, std::string const &title) : name(name), title(title)
{
	std::cout << getName() << ": This looks like another boring day.\n";
}
Warlock::~Warlock()
{
	std::cout << getName() << ": My job here is done!\n";
}

// Warlock &Warlock::operator = (const Warlock &src)
// {
// 	if (this != &src)
// 	{
// 		this->name = src.name;
// 		this->spells = src.spells;
// 	}
// 	return (*this);
// }

std::string const &Warlock::getName() const
{
	return (this->name);
}
std::string const &Warlock::getTitle() const
{
	return (this->title);
}

void	Warlock::setTitle(std::string const &tit)
{
	this->title = tit;
}

void	Warlock::introduce() const
{
	std::cout << getName() << ": I am "
			<< getName() << ", " << getTitle() << "!\n";
}

void	Warlock::learnSpell(ASpell *spell)
{
	spells.learnSpell(spell);
}
void	Warlock::forgetSpell(std::string spell)
{
	spells.forgetSpell(spell);
}
void	Warlock::launchSpell(std::string spell, ATarget const &target)
{
	ASpell *tmp = spells.createSpell(spell);
	if (tmp)
	{
		tmp->launch(target);
	}
}
