/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:53 by cgray             #+#    #+#             */
/*   Updated: 2024/09/09 15:58:28 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

//constructors
Bureaucrat::Bureaucrat() : _name("default")
{
	this->setGrade(42);
	std::cout << GRAY << "Default Bureaucrat constructor\n" << RST;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
	this->setGrade(42);
	std::cout << name << " Bureaucrat constructor\n";
}

Bureaucrat::Bureaucrat(unsigned int grade) : _name("default")
{
	this->setGrade(grade);
	std::cout << "Default Bureaucrat with grade: " << grade << "constructor\n";
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	this->setGrade(grade);
	std::cout << GRAY << name << " Bureaucrat with grade: " << grade << " constructor\n" << RST;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << this->_name << " Bureaucrat copy construcor\n";
	*this = copy;
}

//destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << GRAY << "Bureaucrat destructor for " << this->getName() << "\n" << RST;
}

//assignation
Bureaucrat &Bureaucrat::operator = (const Bureaucrat &src)
{
	std::cout << "Assigning Bureaucrat\n";
	if (this == &src)
		return (*this);
	this->setGrade( src.getGrade() );
	return (*this);
}

//getters
unsigned int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string		Bureaucrat::getName() const
{
	return (this->_name);
}

//setters
void			Bureaucrat::setGrade(unsigned int grade)
{
	if (grade > 150)
		throw	Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw	Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

//overloaded ops
std::ostream	&operator << (std::ostream &o, Bureaucrat *b)
{
	o << b->getName() << ", bureaucrat grade: " << b->getGrade() << "\n";
	return (o);
}

//member functions
void	Bureaucrat::decGrade()
{
	try
	{
		std::cout << "decrementing grade of " << this->getGrade() << "\n";
		this->setGrade(this->_grade + 1);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\tdecrementing grade failed: " << e.what() << "\n";
	}
}

void	Bureaucrat::incGrade()
{
	try
	{
		std::cout << "incrementing grade of " << this->getGrade() << "\n";
		this->setGrade(this->_grade - 1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\tincrementing grade failed: " << e.what() << "\n";
	}
}

void	Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

//exceptions
//grade 1 is "highest" grade 150 is "lowest"
const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high, max grade is 1");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low, min grade is 150");
}

