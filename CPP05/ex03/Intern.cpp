/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:35:01 by cgray             #+#    #+#             */
/*   Updated: 2024/09/11 14:37:10 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//constructors
Intern::Intern()
{
	std::cout << GRAY << "Intern default constructor\n" << RST;
}

Intern::Intern(const Intern &copy)
{
	std::cout << GRAY << "Intern copy constructor\n" << RST;
	*this = copy;
}

//destructors
Intern::~Intern()
{
	std::cout << GRAY << "Intern destructor\n" << RST;
}
//overloaded ops
Intern &Intern::operator = (const Intern &src)
{
	std::cout << GRAY << "Intern assignation\n" << RST;
	if (this == &src)
		return (*this);
	return (*this);
}

//member functions

AForm *Intern::createPresForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}
AForm *Intern::createRoboForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}
AForm *Intern::createShrubForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
	const std::string	formHandles[] ={
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
	};
	typedef AForm *(*create)(const std::string);
	create formFuncs[] = {
		&Intern::createPresForm,
		&Intern::createRoboForm,
		&Intern::createShrubForm
	};

	int	arrSize = sizeof(formHandles) / sizeof(formHandles[0]);
	for(int	i = 0; i < arrSize; i++)
	{
		if (formHandles[i] == formName)
		{
			std::cout << GRN << "Intern created " << formName << "\n";
			return (formFuncs[i](target));
		}
	}
	throw Intern::UnknownForm();
	return (NULL);
}


//exceptions
const char *Intern::UnknownForm::what(void) const throw()
{
	return ("Form not found!");
}
