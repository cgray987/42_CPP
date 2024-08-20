/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:10 by cgray             #+#    #+#             */
/*   Updated: 2024/07/18 16:28:55 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "🐱Cat Constructor🐱\n";
	this->type = "Cat";
}

Cat::Cat(const Cat &copy)
{
	std::cout << "🐈Copy Cat Constructor🐈\n";
	*this = copy;
}

Cat &Cat::operator = (const Cat &src)
{
	std::cout << "Assigning Cat\n";
	if (this != &src)
		this->type = src.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "🐈Cat Destructor🐈\n";
}

void	Cat::makeSound() const
{
	std::cout << "Meow!\n";
}
