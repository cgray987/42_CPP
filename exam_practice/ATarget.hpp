/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:14:44 by cgray             #+#    #+#             */
/*   Updated: 2024/10/21 14:00:38 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ASpell;

class ATarget
{
	private:
		std::string	type;

	public:
		ATarget();
		ATarget(const ATarget &src);
		ATarget &operator = (const ATarget &src);
		ATarget(std::string const &type);
		virtual ~ATarget();


		std::string const &getType() const;

		void	getHitBySpell(ASpell const &spell) const;

		virtual ATarget	*clone() const = 0;
};
#include "ASpell.hpp"
