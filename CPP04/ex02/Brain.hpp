/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:02:54 by cgray             #+#    #+#             */
/*   Updated: 2024/07/22 14:33:29 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class	Brain
{
	private: //private vs protected?
		std::string	_ideas[100];
	public:
		//constructors
		Brain();
		Brain(const Brain &copy);
		//destructors
		~Brain();

		//overloaded ops
		Brain	&operator = (const Brain &src);

		const std::string	getIdea(size_t i) const;
		const std::string	*getAddress(size_t i) const;

		void				setIdea(size_t i, std::string idea);
};
