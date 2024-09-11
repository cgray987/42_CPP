/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:34:58 by cgray             #+#    #+#             */
/*   Updated: 2024/09/11 14:35:44 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
	public:

		//constructors
		Intern();
		Intern(const Intern &copy);

		//destructors
		~Intern();
		//overloaded ops
		Intern &operator = (const Intern &src);

		//member functions
		AForm *makeForm(const std::string formName, const std::string target);

		static AForm *createPresForm(const std::string target);
		static AForm *createRoboForm(const std::string target);
		static AForm *createShrubForm(const std::string target);

		//exceptions
		class UnknownForm : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
