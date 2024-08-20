/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:09 by cgray             #+#    #+#             */
/*   Updated: 2024/07/18 16:06:41 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : public Animal
{
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
};
