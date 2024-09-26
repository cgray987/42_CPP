/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:49:54 by cgray             #+#    #+#             */
/*   Updated: 2024/09/20 15:03:52 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <algorithm>

class NotFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Number not found in container.");
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int nbr)
{
	typename T::iterator found;

	found = std::find(container.begin(), container.end(), nbr);
	if (found == container.end())
		throw NotFoundException();
	return (found);
}

