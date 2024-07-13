/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:08:23 by cgray             #+#    #+#             */
/*   Updated: 2024/07/13 18:24:30 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Fixed
{
	private:
		int					_fixedPointNumber;
		static const int	_fractBits = 8;

	public:
	//constructors
		Fixed();
		Fixed(const Fixed &copy);
	//destructors
		~Fixed();
	//overloaded ops
		Fixed &operator = (const Fixed &copy);
	//getter
		int		getRawBits(void)const;
	//setter
		void	setRawBits( int const raw );
};
