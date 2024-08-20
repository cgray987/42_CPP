/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:10 by cgray             #+#    #+#             */
/*   Updated: 2024/07/18 16:28:55 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "🐱WrongCat Constructor🐱\n";
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "🐈Copy WrongCat Constructor🐈\n";
	*this = copy;
}

WrongCat &WrongCat::operator = (const WrongCat &src)
{
	std::cout << "Assigning WrongCat\n";
	if (this != &src)
		this->type = src.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "🐈WrongCat Destructor🐈\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "Moo!\n";
}
