/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:05 by cgray             #+#    #+#             */
/*   Updated: 2024/07/22 15:19:56 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <cstdio> //perror
#include <cstdlib> //exit

class Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		//constructors
		Dog();
		Dog(const Dog &copy);

		//overloaded ops
		Dog &operator = (const Dog &src);

		//destructors
		~Dog();

		//member functions
		void	makeSound() const;
		void	getIdeas(size_t ideas) const;
		void	setIdea(size_t i, std::string idea);
};
