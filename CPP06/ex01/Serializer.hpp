/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:59:52 by cgray             #+#    #+#             */
/*   Updated: 2024/09/16 12:21:23 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stdint.h>

struct Data
{
	std::string	string;
	int			nbr;
};

class Serializer
{
	public:
		//public methods
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t bits);

	private:
		//constructors
		Serializer();
		Serializer(const Serializer &copy);

		//destructor
		~Serializer();

		//overloaded ops
		const Serializer &operator = (const Serializer &src);
};
