/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:47 by cgray             #+#    #+#             */
/*   Updated: 2024/08/21 15:10:22 by cgray            ###   ########.fr       */
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
			hermes->incGrade(); //not called because decGrade throws exception
			delete hermes;
		}
		catch(const std::exception& e)
		{
			/* note that because hermes is a pointer, decGrade() does not exit when caught exception,
				meaning this message is printed*/
			delete hermes;
			std::cerr << "Exception caught in main: "<< e.what() << '\n';
		}
	}
	{
		std::cout << RED << "~~~~~~~~~~~~~~~~~~~~test 2~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RST;
		Bureaucrat	test("test", 2);
		try
		{
			std::cout << &test;
			test.incGrade();
			test.incGrade();
		}
		catch(const std::exception& e)
		{
			/* note that this error is not printed because test is not a pointer, so it catches in
				incGrade() and exits out*/
			std::cerr << "Exception caught in main: "<< e.what() << '\n';
		}
	}
	{
		std::cout << RED << "~~~~~~~~~~~~~~~~~~~~test 3~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RST;
		try
		{
			Bureaucrat	test("too high", 200);
			std::cout << &test;
			test.incGrade();
			test.incGrade();
		}
		catch(const std::exception& e)
		{
			/* note that this error is not printed because test is not a pointer, so it catches in
				incGrade() and exits out*/
			std::cerr << "Exception caught in main: "<< e.what() << '\n';
		}
	}
}
