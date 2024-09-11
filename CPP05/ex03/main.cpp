/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:47 by cgray             #+#    #+#             */
/*   Updated: 2024/09/11 14:47:16 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	{
		Intern 		SomeRandomIntern;
		Bureaucrat	hermes = Bureaucrat("hermes", 1);
		AForm		*rrf;

		try
		{
			rrf = SomeRandomIntern.makeForm("RobotomyRequestForm", "Bender");
			hermes.signForm(*rrf);
			hermes.executeForm(*rrf);
		}
		catch (std::exception &e)
		{
			std::cerr << "main caught exception of " << e.what() << "\n";
		}
		delete rrf;
	}
}
