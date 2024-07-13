/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:13:41 by cgray             #+#    #+#             */
/*   Updated: 2024/07/13 18:51:33 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//default constructor
Fixed::Fixed() : _fixedPointNumber(0)
{
	std::cout << "Default constructor called\n";
}

//int constructor
Fixed::Fixed(const int number)
{
	std::cout << "Int Constructor called\n";
	this->_fixedPointNumber = number << this->_fractBits;
}

//float constructor
Fixed::Fixed(const float number)
{
	std::cout << "Float Constructor called\n";
	this->_fixedPointNumber = roundf(number * (1 << this->_fractBits));
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

//public methods
int	Fixed::toInt(void) const
{
	return (this->_fixedPointNumber >> this->_fractBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointNumber / (float)(1 << this-> _fractBits));
}

//getter
int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called\n";
	return this->_fixedPointNumber;
}

//setter
void	Fixed::setRawBits( int const raw)
{
	this->_fixedPointNumber = raw;
}

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed)
{
	output << fixed.toFloat();
	return (output);
}
