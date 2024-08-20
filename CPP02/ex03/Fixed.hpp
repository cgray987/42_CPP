/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:08:23 by cgray             #+#    #+#             */
/*   Updated: 2024/07/13 19:04:33 by cgray            ###   ########.fr       */
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

		//arithmetic ops
		float operator + (Fixed fixed) const;
		float operator - (Fixed fixed) const;
		float operator * (Fixed fixed) const;
		float operator / (Fixed fixed) const;

		//comparison ops
		bool operator < (Fixed fixed) const;
		bool operator > (Fixed fixed) const;
		bool operator <= (Fixed fixed) const;
		bool operator >= (Fixed fixed) const;
		bool operator == (Fixed fixed) const;
		bool operator != (Fixed fixed) const;

		//inc/dec ops
		Fixed operator ++();
		Fixed operator --();
		Fixed operator ++(int);
		Fixed operator --(int);

	//public methods
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed		&min(Fixed &first, Fixed &second);
		static const Fixed	&min(Fixed const &first, Fixed const &second);
		static Fixed		&max(Fixed &first, Fixed &second);
		static const Fixed	&max(Fixed const &first, Fixed const &second);

	//getter
		int		getRawBits(void)const;
	//setter
		void	setRawBits( int const raw );
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
