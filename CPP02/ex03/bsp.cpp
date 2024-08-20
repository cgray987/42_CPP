/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:56:01 by cgray             #+#    #+#             */
/*   Updated: 2024/07/22 17:51:15 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
Formula from:
	https://www.youtube.com/watch?v=HYAgJN3x4GA

	find vector proportion of first side of triangle (v1)
	find vector proportion of second side of triangle (v2)

	if ((w1 && w2) > 0 and (w1 + w2) < 1)
		than point is inside triangle, vertexes/edges don't count

	v1 = (A.x * (C.y - A.y)) + (P.y - A.y) * (C.x - A.x) - P.x * (C.y - A.y)
		--------------------------------------------------------------------
				(B.y - A.y) * (C.x - A.x) - (B.x - A.x) * (C.y - A.y)

	v2 = P.y - A.y - w1 * (b.y - A.y)
		-----------------------------
				C.y - A.y
*/

Fixed	*getV1(const Point A, const Point B, const Point C, const Point p)
{
	Fixed Ax = A.getX();
	Fixed Ay = A.getY();
	Fixed Bx = B.getX();
	Fixed By = B.getY();
	Fixed Cx = C.getX();
	Fixed Cy = C.getY();

	Fixed num = (Ax * (Cy - Ay)) + (p.getY() - Ay) * (Cx - Ax) - p.getX() * (Cy - Ay);
	Fixed den = (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay);
	Fixed *v1 = new Fixed( num / den);

	return (v1);
}

Fixed	*getV2(Fixed v1, const Point A, const Point B, const Point C, const Point p)
{
	Fixed Ay = A.getY();
	Fixed By = B.getY();
	Fixed Cy = C.getY();

	Fixed num = p.getY() - Ay - v1 * (By - Ay);
	Fixed den = Cy - Ay;

	Fixed *v2 = new Fixed( num / den);
	return (v2);
}

bool	bsp(const Point A, const Point B, const Point C, const Point point)
{
	Fixed *v1 = getV1(A, B, C, point);
	Fixed *v2 = getV2(*v1, A, B, C, point);
	// std::cout << "V1: " << *v1 << " V2: " << *v2 << "\n";
	bool	bsp = false;

	if (*v1 > 0 && *v2 > 0 && (*v1 + *v2) < 1)
		bsp = true;
	delete v1;
	delete v2;
	return (bsp);
}
