/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:05 by cgray             #+#    #+#             */
/*   Updated: 2024/07/18 16:07:04 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : public Animal
{
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
};
