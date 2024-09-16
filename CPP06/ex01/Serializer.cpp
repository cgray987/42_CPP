/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:03:38 by cgray             #+#    #+#             */
/*   Updated: 2024/09/16 12:13:26 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ~~~Reinterpret_cast conversion~~~
	converts between types by reinterpreting the underlying bit pattern

	happens at compilation time
		has a lot of edge-cases and not always safest option*/

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &copy){*this = copy;}

Serializer::~Serializer(){}

const	Serializer &Serializer::operator = (const Serializer &src)
{
	(void) src;

	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t bits)
{
	return (reinterpret_cast<Data *>(bits));
}
