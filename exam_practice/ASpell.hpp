/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:08:31 by cgray             #+#    #+#             */
/*   Updated: 2024/10/21 13:58:55 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ATarget;

class	ASpell
{
	private:
		std::string	name;
		std::string	effects;

	public:
		ASpell();
		ASpell(const ASpell &src);
		ASpell &operator = (const ASpell &src);
		ASpell(std::string const &name, std::string const &effects);
		virtual ~ASpell();


		std::string const &getName() const;
		std::string const &getEffects() const;

		void	launch(const ATarget &target) const;

		virtual ASpell	*clone() const = 0;

};

#include "ATarget.hpp"
