/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:49:19 by cgray             #+#    #+#             */
/*   Updated: 2024/07/22 17:43:35 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0)
{

}

Point::Point(const Point &copy): x(copy.getX()), y(copy.getY())
{

}

Point::Point(const float x, const float y): x(x), y(y)
{

}

Point::Point(const Fixed x, const Fixed y): x(x), y(y)
{

}

Point	&Point::operator = (Point &src)
{
	return (src);
}

Point::~Point()
{
	
}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}
