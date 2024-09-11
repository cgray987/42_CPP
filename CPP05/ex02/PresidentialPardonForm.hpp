/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:04:08 by cgray             #+#    #+#             */
/*   Updated: 2024/09/10 14:12:48 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string		_target;
		virtual void	performAction() const;

	public:
	//constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);

	//destructor
		~PresidentialPardonForm();

	//overloaded ops
		PresidentialPardonForm &operator = (const PresidentialPardonForm &src);

	//member
		void	execute(Bureaucrat const &b) const;
		std::string	getTarget() const;


};

