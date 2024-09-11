/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:10:49 by cgray             #+#    #+#             */
/*   Updated: 2024/09/10 13:43:37 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string> //use string functions
#include <fstream> //outfile operations

class ShrubberyCreationForm: public AForm
{
	private:
		std::string		_target;
		void	performAction() const;

	public:
	//constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);

	//destructor
		~ShrubberyCreationForm();

	//overloaded ops
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &src);

	//member functions
		void		execute(Bureaucrat const &b)const;
		std::string	getTarget(void)const;

	//exceptions
	class OutfileException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};
