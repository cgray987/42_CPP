/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:07:34 by cgray             #+#    #+#             */
/*   Updated: 2024/09/11 14:48:00 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//constructors
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << GRAY << "Robo Form default constructor\n" << RST;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << GRAY << "Robo Form constructor for " << target << "\n" << RST;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm("RobotomyRequestForm", 72, 45), _target(copy.getTarget())
{
	std::cout << GRAY << "Robo Form copy constructor copying " << copy.getName() <<
		"into " << this->getName() << "\n" << RST;

	*this = copy;
}

//destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << GRAY << "Robo destructor for " << this->getName() << "\n" << RST;
}

//overloaded ops
RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &src)
{
	std::cout << "Robo assignation for " << this->getName() << "\n";

	if (this == &src)
		return (*this);
	return (*this);
}

//member functions
void	RobotomyRequestForm::execute(Bureaucrat const &b) const
{
	if (this->getSignedBool() == false)
		throw AForm::IsNotSignedException();
	if (this->getExecGrade() < b.getGrade())
		throw AForm::GradeTooLowException();
	this->performAction();
}

void	RobotomyRequestForm::performAction() const
{
	pid_t	c_pid = fork();

	if (c_pid == -1)
	{
		std::cerr << "fork error???\n";
		exit(EXIT_FAILURE);
	}
	else if (c_pid > 0) //it said to play a sound.....
		execlp("mpg123", "mpg123", "-q", "../drill.mp3", NULL);
	else
	{
		srand(time(0)); //seed random with current time, only changes every few seconds or so
		int success = rand() % 2;
		if (success == 0)
			std::cout << YEL << "bleep bloop! " << this->getTarget() << " has been robotomized!\n" << RST;
		else
			std::cout << RED << "bleep bloop! " << this->getTarget() << "'s robotomization has failed!\n" << RST;
	}
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}
