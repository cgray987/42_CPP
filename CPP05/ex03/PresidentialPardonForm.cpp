/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:12:53 by cgray             #+#    #+#             */
/*   Updated: 2024/09/10 16:50:28 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//constructors
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << GRAY << "Pres Form default constructor\n" << RST;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << GRAY << "Pres Form constructor for " << target << "\n" << RST;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm("PresidentialPardonForm", 25, 5), _target(copy.getTarget())
{
	std::cout << GRAY << "Pres Form copy constructor copying " << copy.getName() <<
		"into " << this->getName() << "\n" << RST;

	*this = copy;
}

//destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GRAY << "Pres destructor for " << this->getName() << "\n" << RST;
}

//overloaded ops
PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &src)
{
	std::cout << "Pres assignation for " << this->getName() << "\n";

	if (this == &src)
		return (*this);
	return (*this);
}

//member functions
void	PresidentialPardonForm::execute(Bureaucrat const &b) const
{
	if (this->getSignedBool() == false)
		throw AForm::IsNotSignedException();
	if (this->getExecGrade() < b.getGrade())
		throw AForm::GradeTooLowException();
	this->performAction();
}

void	PresidentialPardonForm::performAction() const
{
	std::cout << YEL << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!\n" << RST;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}
