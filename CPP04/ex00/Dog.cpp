/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:07 by cgray             #+#    #+#             */
/*   Updated: 2024/07/18 16:29:12 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "🐶Dog Constructor🐶\n";
	this->type = "Dog";
}

Dog::Dog(const Dog &copy)
{
	std::cout << "🐕Dog Copy Constructor🐕\n";
	*this = copy;
}

Dog &Dog::operator = (const Dog &src)
{
	std::cout << "Assigning Dog\n";
	if (this != &src)
		this->type = src.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "🐕Dog Destructor🐕\n";
}

void	Dog::makeSound() const
{
	std::cout << "Bark Bark!\n";
}
