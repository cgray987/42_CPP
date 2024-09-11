/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:47 by cgray             #+#    #+#             */
/*   Updated: 2024/09/10 13:20:47 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
		std::cout << RED << "~~~~~~~~~~~~~~~~~~~~test beSigned (sign grade too high)~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RST;

		Bureaucrat	*b = new Bureaucrat("hermes"); //default grade of 42
		AForm		*f = new AForm("untitled form", 150, 42);

		std::cout << b << f; //show ostream info

		try{f->beSigned(*b);}
		catch(const std::exception& e)
		{
			std::cout << "main caught exception: " << e.what() << "\n";
		}

		std::cout << b << f; //show form sign status
		delete b;
		delete f;
	}
		{
		std::cout << GRN << "~~~~~~~~~~~~~~~~~~~~test beSigned (should work)~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RST;

		Bureaucrat	*b = new Bureaucrat("hermes");
		AForm		*f = new AForm("untitled form", 42, 42);

		std::cout << b << f; //show ostream info

		try{f->beSigned(*b);}
		catch(const std::exception& e)
		{
			std::cout << "main caught exception: " << e.what() << "\n";
		}

		std::cout << b << f; //show form sign status
		delete b;
		delete f;
	}
}
