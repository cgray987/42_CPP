/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:12 by cgray             #+#    #+#             */
/*   Updated: 2024/07/18 16:47:11 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		//constructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);

		//destructor
		virtual ~WrongAnimal();

		//overloaded ops
		WrongAnimal &operator = (const WrongAnimal &src);

		//member functions
		void	makeSound() const; //non virtual means inherited classes
									//will call this function, not their own members
		//getter
		std::string		getType() const;
		//setter
};
