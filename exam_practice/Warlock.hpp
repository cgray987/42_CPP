/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:33:44 by cgray             #+#    #+#             */
/*   Updated: 2024/10/21 15:13:49 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class	Warlock
{
	private:
		std::string	name;
		std::string	title;
		// std::map<std::string, ASpell *> arr;
		SpellBook spells;
		Warlock();
		Warlock(const Warlock &src);

		Warlock &operator = (const Warlock &src);

	public:
		Warlock(std::string const &name, std::string const &title);
		virtual ~Warlock();


		std::string const &getName() const;
		std::string const &getTitle() const;

		void	setTitle(std::string const &tit);

		void	introduce() const;

		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string spell);
		void	launchSpell(std::string spell, ATarget const &target);

};
