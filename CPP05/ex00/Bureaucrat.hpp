/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:50 by cgray             #+#    #+#             */
/*   Updated: 2024/08/20 16:36:01 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

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