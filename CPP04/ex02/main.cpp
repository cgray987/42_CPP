/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:03 by cgray             #+#    #+#             */
/*   Updated: 2024/08/13 12:47:29 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define RED "\033[31m"
#define MGT "\033[95m"
#define RST "\033[0m"

int	main(void)
{
	//subject main
	{
		std::cout << "~~~~~~~subject main~~~~~~~\n\n";
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();

		/* uncomment this to show that Animal cannot be instantiated! */
		// const Animal animal = new Animal();
		delete dog;
		delete cat;
	}
}

/*

	Shallow Copy:
		member variables point to the same location in memory, meaning
		if a value is modified at any point, the value will be modified
		in both places
	Deep Copy:
		Each object has its own allocated memory for member variables
 */
