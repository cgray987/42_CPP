/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:50 by cgray             #+#    #+#             */
/*   Updated: 2024/09/09 15:58:28 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define GRAY "\033[38;5;247m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define RST "\033[0m"

class AForm; //need to forward declare form class

class Bureaucrat
{
	private:
		const std::string _name;
		unsigned int	_grade;
		void			setGrade(unsigned int grade);

	public:
	//constructors
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(unsigned int grade);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, unsigned int grade);

	//destructors
		~Bureaucrat();

	//overloaded ops
		Bureaucrat &operator = (const Bureaucrat &src);

	//member functions
		std::string		getName() const;
		unsigned int	getGrade() const;

		void			incGrade();
		void			decGrade();
		void			signForm(AForm &form);

	//exceptions
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator << (std::ostream &o, Bureaucrat *b);
