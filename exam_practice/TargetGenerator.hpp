/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:51:10 by cgray             #+#    #+#             */
/*   Updated: 2024/10/21 15:19:24 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <map>

class ATarget;

class TargetGenerator
{
	private:
		std::map<std::string, ATarget *>	targets;

		TargetGenerator(TargetGenerator const &src);
		TargetGenerator	&operator = (TargetGenerator const &src);

	public:

		TargetGenerator();
		~TargetGenerator();
		void	learnTargetType(ATarget *target);
		void	forgetTargetType(std::string const &target);
		ATarget	*createTarget(std::string const &target);

};

#include "ATarget.hpp"
