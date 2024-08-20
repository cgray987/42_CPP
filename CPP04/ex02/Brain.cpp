/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:10:49 by cgray             #+#    #+#             */
/*   Updated: 2024/07/22 14:23:47 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//constructors
Brain::Brain()
{
	std::cout << "🧠 Brain Default Constructor🧠\n";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "🧠 Brain Copy Constructor🧠\n";
	*this = copy;
}
//-------------

//destructor
Brain::~Brain()
{
	std::cout << "🧠🚫Brain Destructor🚫🧠\n";
}

// overloaded ops
Brain	&Brain::operator = (const Brain &src)
{
	std::cout << "Assigning Brain\n";
	if (this == &src)
		return (*this);
	for(int i = 0; i < 100; i++)
	{
		if (src._ideas[i].length() > 0)
			this->_ideas[i].assign(src._ideas[i]);
	}
	return (*this);
}

const std::string	Brain::getIdea(size_t i) const
{
	if (i < 100) return (this->_ideas[i]);
	else		return ("This animal can only hold 100 ideas!\n");
}

const std::string	*Brain::getAddress(size_t i) const
{
	if (i < 100)
	{
		const std::string	&stringREF = this->_ideas[i];

		return (&stringREF);
	}
	else
	{
		std::cout << "Cannot get address; idea index out of bounds.\n";
		return (NULL);
	}
}

void	Brain::setIdea(size_t i, std::string idea)
{
	if (i < 100) this->_ideas[i] = idea;
	else
		std::cout << "This animal can only hold 100 ideas!\n";
}
