/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:12 by cgray             #+#    #+#             */
/*   Updated: 2024/07/22 16:39:11 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string	type;
	public:
		//constructors
		Animal();
		Animal(const Animal &copy);

		//destructor
		virtual ~Animal() = 0; //'=0' makes this class abstract
								//'pure-specifier'
		//overloaded ops
		Animal &operator = (const Animal &src);

		//member functions
		virtual void	makeSound() const = 0;
		//getter
		std::string		getType() const;
		//setter
};
