/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:13:41 by cgray             #+#    #+#             */
/*   Updated: 2024/07/13 18:34:56 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//default constructor
Fixed::Fixed() : _fixedPointNumber(0)
{
	std::cout << "Default constructor called\n";
}

//copy constructor
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

//destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

//overloaded operator
Fixed & Fixed::operator = (const Fixed &copy)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &copy)
		_fixedPointNumber = copy.getRawBits();
	return *this;
}

//getter
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return this->_fixedPointNumber;
}

//setter
void	Fixed::setRawBits( int const raw)
{
	this->_fixedPointNumber = raw;
}
