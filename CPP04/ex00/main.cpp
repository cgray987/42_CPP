/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:03 by cgray             #+#    #+#             */
/*   Updated: 2024/08/13 12:41:27 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		std::cout << "~~~~~~Subject Main~~~~~~\n";
		const Animal	*meta = new Animal();
		const Animal	*j = new Dog();
		const Animal	*i = new Cat();
		std::cout << "Dog type:\t" << j->getType() << " " << std::endl;
		std::cout << "Cat type:\t" << i->getType() << " " << std::endl;
		std::cout << "Cat Sound:\t";
		i->makeSound(); //will output the cat sound!
		std::cout << "Dog Sound:\t";
		j->makeSound();
		std::cout << "Animal Sound:\t";
		meta->makeSound();

		delete meta; //need to delete because they are pointers to Animals
		delete i;
		delete j;
	}

	{
		std::cout << "\n~~~~~~Second Main~~~~~~\n";
		WrongAnimal	animal = WrongAnimal();
		// std::cout << "Animal type:\t" << animal.getType() << "\n";
		WrongCat	cat = WrongCat();
		std::cout << "Cat type:\t" << cat.getType() << "\n";
		std::cout << "Cat Sound:\t";
		cat.makeSound(); //will ouput wrong cat sound
		std::cout << "Animal Sound:\t";
		animal.makeSound();
	}
	{
		std::cout << "\n~~~~~~Third Main~~~~~~\n";
		const WrongAnimal	*meta = new WrongAnimal();
		const WrongAnimal	*w_cat = new WrongCat();
		std::cout << "Cat type:\t" << w_cat->getType() << " " << std::endl;
		std::cout << "Cat Sound:\t";
		w_cat->makeSound(); //will output the wrong animal sound!
		std::cout << "Animal Sound:\t";
		meta->makeSound();

		delete meta; //need to delete because they are pointers to WrongAnimals
		delete w_cat;
	}
}
