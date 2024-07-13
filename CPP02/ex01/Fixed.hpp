/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:08:23 by cgray             #+#    #+#             */
/*   Updated: 2024/07/13 18:40:23 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					_fixedPointNumber;
		static const int	_fractBits = 8;

	public:
	//constructors
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &copy);
	//destructors
		~Fixed();
	//overloaded ops
		Fixed &operator = (const Fixed &copy);
	//public methods
		float	toFloat(void) const;
		int		toInt(void) const;
	//getter
		int		getRawBits(void)const;
	//setter
		void	setRawBits( int const raw );
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
