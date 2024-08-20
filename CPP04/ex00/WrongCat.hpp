/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:09 by cgray             #+#    #+#             */
/*   Updated: 2024/07/22 13:58:19 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	//constructors
	WrongCat();
	WrongCat(const WrongCat &copy);

	//overloaded ops
	WrongCat &operator = (const WrongCat &src);

	//destructors
	~WrongCat();

	//member functions
	void	makeSound() const; //will not be called bc WrongAnimal makeSound is
								//not virtual
};
