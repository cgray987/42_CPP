/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:07 by cgray             #+#    #+#             */
/*   Updated: 2024/07/22 16:27:55 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "🐶Dog Constructor🐶\n";
	this->type = "Dog";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Dog Brain alloc failure!");
		std::cerr << "Exiting.\n";
		exit(1);
	}
}

Dog::Dog(const Dog &copy)
{
	this->type = copy.getType();
	this->_brain = new Brain(*copy._brain);
	std::cout << "🐕Dog Copy Constructor🐕\n";
}

Dog &Dog::operator = (const Dog &src)
{
	std::cout << "Assigning Dog\n";
	if (this != &src)
	{
		if (this->_brain)
		{
			delete (this->_brain);
			this->_brain = NULL;
		}
		if (src._brain)
			this->_brain = new Brain(*src._brain);
		else
			this->_brain = NULL;
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "🐕Dog Destructor🐕\n";
}

void	Dog::makeSound() const
{
	std::cout << "Bark Bark!\n";
}

void	Dog::getIdeas(size_t ideas) const
{
	for (size_t i = 0; i < ideas + 1; i++)
		std::cout << "Dog Idea " << i << ":\t" << this->_brain->getIdea(i)
					<< " - at address:\t" << this->_brain->getAddress(i) << "\n";
}

void	Dog::setIdea(size_t i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}
