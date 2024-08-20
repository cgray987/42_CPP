/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:08:20 by cgray             #+#    #+#             */
/*   Updated: 2024/07/22 17:55:26 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point A(0, 0); //see triangle.png
	Point B(0, 2);
	Point C(2, 0.5);

	Point p1(1, 1); //inside triangle
	Point p2(1, 2); //outside triangle

	std::cout << "BSP of point p1: " << bsp(A, B, C, p1) << "\n";
	std::cout << "BSP of point p2: " << bsp(A, B, C, p2) << "\n";
}
