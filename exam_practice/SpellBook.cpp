/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:40:47 by cgray             #+#    #+#             */
/*   Updated: 2024/10/21 15:21:00 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it_begin = this->spells.begin();
	std::map<std::string, ASpell *>::iterator  it_end = this->spells.end();

	for (; it_begin != it_end; ++it_begin)
		delete it_begin->second;
	this->spells.clear();
}

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		spells.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void	SpellBook::forgetSpell(std::string const &spell)
{
	std::map<std::string, ASpell *>::iterator it = spells.find(spell);
	if (it != spells.end())
		delete it->second;
	spells.erase(spell);
}

ASpell *SpellBook::createSpell(std::string const &spell)
{
	std::map<std::string, ASpell *>::iterator it = spells.find(spell);
	 if (it != spells.end())
        return spells[spell];
    return NULL;
}
