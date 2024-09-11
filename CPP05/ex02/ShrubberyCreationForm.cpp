/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:12:13 by cgray             #+#    #+#             */
/*   Updated: 2024/09/10 16:57:57 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//constructors
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << GRAY << "Shrub Form default constructor\n" << RST;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << GRAY << "Shrub Form constructor for " << target << "\n" << RST;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm("ShrubberyCreationForm", 145, 137), _target(copy.getTarget())
{
	std::cout << GRAY << "Shrub Form copy constructor copying " << copy.getName() <<
		"into " << this->getName() << "\n" << RST;

	*this = copy;
}

//destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GRAY << "Shrub destructor for " << this->getName() << "\n" << RST;
}

//overloaded ops
ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &src)
{
	std::cout << "Shrub assignation for " << this->getName() << "\n";

	if (this == &src)
		return (*this);
	return (*this);
}

//member functions
void	ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
	if (this->getSignedBool() == false)
		throw AForm::IsNotSignedException();
	if (this->getExecGrade() < b.getGrade()){
		std::cout << "grade: " << b.getGrade() << "\n";
		throw AForm::GradeTooLowException();
	}
	this->performAction();
}

void	ShrubberyCreationForm::performAction() const
{
	std::string fd;
	std::ofstream out_fd;

	fd = this->getTarget() + "_shrubbery";

	out_fd.open(fd.c_str(), std::ios::out);
	if (!out_fd.is_open())
	{
		throw ShrubberyCreationForm::OutfileException();
		return ;
	}

	for (int i = 1; i < 4; i++)
	{
		out_fd << "~~~~~~~~~~~~~~~~~~~~~~~~~~~|🌳ASCII TREE #" << i << "🌳|~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"
		<< "               &                     @& %##&&% " << std::endl
		<< "         %&#|%#%#             &@@#&@##%%  # " << std::endl
		<< "     @#&% ##|@&#%#&%           ##|&@%%#@##@ " << std::endl
		<< " ##&@%_#&@@%%%#@@@@&%@@&      @&%&|__%_:__%@@& " << std::endl
		<< " %  &%&@%#&& &%%#&%&@          %:##|@%@#%&#@%#  & " << std::endl
		<< "&%%#&&%@&_\\_;#|%%@%&&#           &_\\@&@&&#&&@ %;%&#@ " << std::endl
		<< " %@@@%@#@@ # :#%@@%@ %%       =__#&:&&#@%&%%&  #&@&@ " << std::endl
		<< "%   &&%%     ##\\&# @        //  &###%%#%&&@   @&%;#@@# " << std::endl
		<< "    #%@ %       =__:___     |      &&&%&#@___%@%@&&%& % " << std::endl
		<< "   @  @                __~ |      #%  & &/   #%%@%@ " << std::endl
		<< "                         |=~     #    //   %&#%#&%%% " << std::endl
		<< "                          ||         /     &  % %%###%@ " << std::endl
		<< "                           ~|        :       @@@%%&&##%# " << std::endl
		<< "                            ||     /|             %#@@&@# " << std::endl
		<< "                            ;=|   /;   __;_=     # #&@\\&@_&%#& " << std::endl
		<< "                             |;: ~:_~__     ~\\~_;_@&%&#&#&&%%& " << std::endl
		<< "                             |=|~/            |\\ %@##&@@@&&% " << std::endl
		<< "                             |/:            # = _;|#%&@#&@%%@ " << std::endl
		<< "                              =~|          @;&%###@@#&#@& % " << std::endl
		<< "                              :||            %@##%@&@% @ " << std::endl
		<< "                               ||~            @%& @&#% " << std::endl
		<< "                   \\_________./;|:\\._____.--./ " << std::endl
		<< "                    \\                 *     / " << std::endl
		<< "                     \\_____________________/ " << std::endl
		<< "                       ‾                 ‾ " << std::endl;
	}

	out_fd.close();
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

//exceptions
const char	*ShrubberyCreationForm::OutfileException::what(void) const throw()
{
	return ("Output file could not be opened");
}
