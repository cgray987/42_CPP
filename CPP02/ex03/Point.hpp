/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:43:27 by cgray             #+#    #+#             */
/*   Updated: 2024/07/22 16:49:13 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		//constructors
		Point();
		Point(const Point &copy);
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);

		//overloaded ops
		Point &operator = (Point &src);

		//destructor
		~Point();

		void	setX(Fixed f);
		void	setY(Fixed f);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};
			// a,b,c -- points of a triangle
			// point -- point to check if inside triangle
bool	bsp(const Point a, const Point b, const Point c, const Point point);
