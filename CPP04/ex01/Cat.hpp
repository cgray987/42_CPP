/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:09 by cgray             #+#    #+#             */
/*   Updated: 2024/07/22 15:20:02 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <cstdio> //perror
#include <cstdlib> //exit

class Cat : public Animal
{

	private:
		Brain	*_brain;
	public:
		//constructors
		Cat();
		Cat(const Cat &copy);

		//overloaded ops
		Cat &operator = (const Cat &src);

		//destructors
		~Cat();

		//member functions
		void	makeSound() const;
		void	getIdeas(size_t ideas) const;
		void	setIdea(size_t i, std::string idea);
};
