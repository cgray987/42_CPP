/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:09:41 by cgray             #+#    #+#             */
/*   Updated: 2024/09/10 16:30:54 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <stdlib.h> //rand
#include <unistd.h> //execlp
#include <ctime> //time to seed rand()

class RobotomyRequestForm: public AForm
{
	private:
		std::string		_target;
		void	performAction() const;

	public:
	//constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);

	//destructor
		~RobotomyRequestForm();

	//overloaded ops
		RobotomyRequestForm &operator = (const RobotomyRequestForm &src);

	//member functions
		void		execute(Bureaucrat const &b) const;
		std::string	getTarget(void)const;
};
