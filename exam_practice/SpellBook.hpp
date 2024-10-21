/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:45:53 by cgray             #+#    #+#             */
/*   Updated: 2024/10/21 15:19:54 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <map>

class ASpell;

class SpellBook
{
	private:
		std::map<std::string, ASpell *>	spells;

		SpellBook(SpellBook const &src);
		SpellBook	&operator = (SpellBook const &src);

	public:

		SpellBook();
		~SpellBook();
		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string const &spell);
		ASpell	*createSpell(std::string const &spell);

};
#include "ASpell.hpp"
