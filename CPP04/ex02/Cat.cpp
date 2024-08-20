/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:10 by cgray             #+#    #+#             */
/*   Updated: 2024/07/22 16:27:26 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "🐱Cat Constructor🐱\n";
	this->type = "Cat";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Cat Brain alloc failure!");
		std::cerr << "Exiting.\n";
		exit(1);
	}
}

Cat::Cat(const Cat &copy)
{
	this->type = copy.getType();
	this->_brain = new Brain(*copy._brain);
	std::cout << "🐈Copy Cat Constructor🐈\n";
}

Cat &Cat::operator = (const Cat &src)
{
	std::cout << "Assigning Cat\n";
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

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "🐈Cat Destructor🐈\n";
}

void	Cat::makeSound() const
{
	std::cout << "Meow!\n";
}

void	Cat::getIdeas(size_t ideas) const
{
	for (size_t i = 0; i < ideas + 1; i++)
		std::cout << "Cat Idea " << i << ":\t" << this->_brain->getIdea(i)
					<< " - at address:\t" << this->_brain->getAddress(i) << "\n";
}

void	Cat::setIdea(size_t i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}
