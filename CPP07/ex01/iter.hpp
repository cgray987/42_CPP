/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:40 by cgray             #+#    #+#             */
/*   Updated: 2024/09/20 12:55:18 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename F>
void iter(T *array, std::size_t len, F function)
{
	for (std::size_t i = 0; i < len; i++)
	{
		function(array[i]);
	}
};

template <typename T>
void	print_array(T *array, std::size_t len, std::string sep)
{
	std::cout << "{";
	for (std::size_t i = 0; i < len; i++)
	{
		std::cout << array[i];
		if ( i != len - 1)
			std::cout << sep;
	}
	std::cout << "}\n";
}
