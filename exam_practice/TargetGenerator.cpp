/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:54:09 by cgray             #+#    #+#             */
/*   Updated: 2024/10/21 15:18:49 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it_begin = this->targets.begin();
	std::map<std::string, ATarget *>::iterator  it_end = this->targets.end();

	for (; it_begin != it_end; ++it_begin)
		delete it_begin->second;
	this->targets.clear();
}

void	TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
		targets.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void	TargetGenerator::forgetTargetType(std::string const &target)
{
	targets.erase(target);
}

ATarget *TargetGenerator::createTarget(std::string const &target)
{
	std::map<std::string, ATarget *>::iterator it = targets.find(target);
	 if (it != targets.end())
        return targets[target];
    return NULL;
}
