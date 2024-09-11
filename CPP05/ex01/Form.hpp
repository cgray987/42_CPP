/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:29:00 by cgray             #+#    #+#             */
/*   Updated: 2024/09/09 15:58:28 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat; //need to forward declare bureaucrat class

class AForm
{

	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;

	public:
		//constructors
		AForm();
		AForm(const AForm &copy);
		AForm(const std::string name,
			unsigned int signGrade, unsigned int execGrade);

		//destructor
		~AForm();

		//overloaded ops
		AForm &operator = (const AForm &src);
		//member functions
		const std::string	getName() const;
		bool				getSignedBool() const;
		unsigned int	getSignGrade() const;
		unsigned int	getExecGrade() const;

		void	beSigned(Bureaucrat &b);

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

std::ostream	&operator << (std::ostream &o, AForm *f);
