/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:47 by cgray             #+#    #+#             */
/*   Updated: 2024/09/10 17:02:48 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	{
		std::cout << RED << "~~~~~~~~~~~~~~~~~~~~test Shrub~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RST;

		Bureaucrat			hermes = Bureaucrat("hermes", 1);
		ShrubberyCreationForm	f = ShrubberyCreationForm("bender");

		std::cout << hermes << f; //show ostream info

		try{hermes.signForm(f);}
		catch(const std::exception& e)
		{
			std::cout << "main caught exception: " << e.what() << "\n";
		}
		std::cout << f;
		hermes.executeForm(f);
	}
	{
		std::cout << RED << "~~~~~~~~~~~~~~~~~~~~test Robo~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RST;

		Bureaucrat			hermes = Bureaucrat("hermes", 42);
		RobotomyRequestForm	f = RobotomyRequestForm("bender");

		std::cout << hermes << f; //show ostream info

		try{hermes.signForm(f);}
		catch(const std::exception& e)
		{
			std::cout << "main caught exception: " << e.what() << "\n";
		}
		std::cout << f;
		hermes.executeForm(f);
	}
	{
		std::cout << RED << "~~~~~~~~~~~~~~~~~~~~test Pres~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RST;

		Bureaucrat	hermes = Bureaucrat("hermes", 1);
		PresidentialPardonForm	f = PresidentialPardonForm("bender");

		std::cout << hermes << f; //show ostream info

		try{hermes.signForm(f);}
		catch(const std::exception& e)
		{
			std::cout << "main caught exception: " << e.what() << "\n";
		}
		std::cout << f;
		hermes.executeForm(f);
	}
}
