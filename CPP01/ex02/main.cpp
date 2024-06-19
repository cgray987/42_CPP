/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:09:15 by cgray             #+#    #+#             */
/*   Updated: 2024/06/17 14:21:35 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout	<< "---MEMORY---\n";
	std::cout	<< &string << "-- Mem address of string variable\n";
	std::cout	<< stringPTR << "-- Mem address of stringPTR\n";
	std::cout	<< &stringREF << "-- Mem address of stringREF\n";
	//Mem address of each should be the same
	std::cout	<< "-----------\n";
	std::cout	<< "---Values---\n";
	std::cout	<< string << "-- Value of string variable\n";
	std::cout	<< *stringPTR << "-- Value pointed to by stringPTR\n";
	std::cout	<< stringREF << "-- Value of stringREF\n";
	std::cout	<< "-----------\n";
	//values of each should be the same
}
