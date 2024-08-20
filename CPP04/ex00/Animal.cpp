/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:14 by cgray             #+#    #+#             */
/*   Updated: 2024/07/18 16:10:54 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Constructor\n";
	this->type = "Animal";
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy Constructor\n";
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor\n";
}

Animal &Animal::operator = (const Animal &src)
{
	std::cout << "Assigning Animal\n";
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Animal Sounds!\n";
}

std::string Animal::getType() const
{
	return (this->type);
}
