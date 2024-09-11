/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:39:32 by cgray             #+#    #+#             */
/*   Updated: 2024/09/09 15:58:28 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//constructors
AForm::AForm(): _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << GRAY << "Form default constructor\n" << RST;
}

AForm::AForm(const AForm &copy): _name(copy.getName() + "_copy"), _signed(copy.getSignedBool()),
							_signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade())
{
	std::cout << GRAY << "Form copy constructor\n" << RST;
	*this = copy;
}

AForm::AForm(const std::string name, unsigned int sign_grade, unsigned int exec_grade):
					_name(name), _signed(false), _signGrade(sign_grade), _execGrade(exec_grade)
{
	std::cout << GRAY << "Form constructor for " << name << " with sign grade: " << sign_grade
				<< " and exec grade: " << exec_grade << "\n" << RST;
	int	sg = sign_grade;
	int	eg = exec_grade;
	if (sg > 150 || eg > 150)
		throw (AForm::GradeTooLowException());
	if (sg < 1 || eg < 1)
		throw (AForm::GradeTooHighException());
}

//destructor
AForm::~AForm()
{
	std::cout << GRAY << "Form destructor for: " << this->getName() << "\n" << RST;
}

//assignation
AForm &AForm::operator = (const AForm &src)
{
	std::cout << "Assigning Form\n";
	if (this == &src)
		return (*this);
	//need to set Form attributes?
	return (*this);
}

//member functions
const std::string AForm::getName()const
{
	return (this->_name);
}

bool AForm::getSignedBool()const
{
	return (this->_signed);
}

unsigned int AForm::getSignGrade()const
{
	return (this->_signGrade);
}

unsigned int AForm::getExecGrade()const
{
	return (this->_execGrade);
}

void	AForm::beSigned(Bureaucrat &b)
{
	if ((b.getGrade() < this->getSignGrade()))
	{
		std::cerr << RED << b.getName() << " couldn't sign form " << this->getName() << RST << "\n";
		throw(AForm::GradeTooLowException());
	}
	if (b.getGrade() < 1)
	{
		std::cerr << RED << b.getName() << " couldn't sign form " << this->getName() << RST << "\n";
		throw(AForm::GradeTooHighException());
	}
	else if (this->getSignedBool() == false)
	{
		this->_signed = true;
		std::cout << GRN << b.getName() << " signed " << this->getName() << "\n" << RST;
	}
	else
	{
		std::cout << RED << b.getName() << " couldn't sign " << this->getName() << " because form is already signed.\n" << RST;
	}

}

//exceptions
const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

//ostream overload
std::ostream	&operator << (std::ostream &o, AForm *f)
{
	o << "Form " << f->getName() << ":"
			<< "\n\tsign grade:\t" << f->getSignGrade()
			<< "\n\texec grade:\t" << f->getExecGrade()
			<< "\n\tis signed?\t" << f->getSignedBool() << "\n";
	return (o);
}
