/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:47 by cgray             #+#    #+#             */
/*   Updated: 2024/08/29 15:44:43 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	{
		std::cout << RED << "~~~~~~~~~~~~~~~~~~~~test 1~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RST;
		Bureaucrat	*hermes = new Bureaucrat("Hermes", 150);
		Bureaucrat	test("test", 1);
		try
		{
			std::cout << hermes << &test;
			hermes->decGrade();
			hermes->incGrade(); //not called because previous decGrade throws exception
			delete hermes;
		}
		catch(const std::exception& e)
		{
			delete hermes;
			std::cerr << "Exception caught in main: "<< e.what() << '\n';
		}
	}
	{
		std::cout << RED << "~~~~~~~~~~~~~~~~~~~~test 2~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RST;
		Bureaucrat	test("too high", 2);
		try
		{
			std::cout << &test;
			test.incGrade();
			test.incGrade(); //will throw exception
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught in main: "<< e.what() << '\n';
		}
	}
	{
		std::cout << RED << "~~~~~~~~~~~~~~~~~~~~test 3~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RST;
		try
		{
			Bureaucrat	test("too low", 200); //will throw exception
			std::cout << &test;
			test.incGrade();
			test.incGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught in main: "<< e.what() << '\n';
		}
	}
}
