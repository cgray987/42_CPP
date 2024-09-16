/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:14:06 by cgray             #+#    #+#             */
/*   Updated: 2024/09/16 12:26:28 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	// Serializer	s;

	uintptr_t	ptr;
	Data		*data = new Data;

	data->string = "hello";
	data->nbr = 42;

	std::cout << "Data before serializer:\t" << data << "\n";
	ptr = Serializer::serialize(data);
	std::cout << "Serialized data ptr:\t" << ptr << "\n";
	data = Serializer::deserialize(ptr);
	std::cout << "Deserialized data:\t" << data << "\n";
	std::cout << "Data struct:\n\t" << data->string << "\n\t" << data->nbr << "\n";

	delete data;
}
