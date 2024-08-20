/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:52:03 by cgray             #+#    #+#             */
/*   Updated: 2024/08/13 12:45:57 by cgray            ###   ########.fr       */
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
		delete dog;
		delete cat;
	}
	{
		std::cout << "\n~~~~~~~array test~~~~~~~\n\n";
		Animal	*animal_arr[5];
		for (int i = 0; i < 5; i++)
		{
			if (i % 2 == 0)
				animal_arr[i] = new Cat();
			else
				animal_arr[i] = new Dog();
		}

		for (int i = 0; i < 5; i++)
		{
			std::cout << "This is a " << animal_arr[i]->getType() << "\n";
			animal_arr[i]->makeSound();
		}
		for (int i = 0; i < 5; i++)
			delete animal_arr[i];
	}

	{
		std::cout << "\n~~~~~~~deep copy tests~~~~~~~\n\n";
		Dog	Margo;
		Cat	Maris;

		Dog	&MargoREF = Margo; //MargoRef will be shallow copy, no construction neccessary

		Dog	Margo_copy(Margo);
		Cat	Maris_copy(Maris);



		Maris.setIdea(2, "World domination!");
		Margo.setIdea(3, "Squirrel!"); //also sets Margo_REF!
		std::cout << "\nIdeas from Maris:\n";
		Maris.getIdeas(2);
		std::cout << MGT << "Ideas from Maris copy:\n";
		Maris_copy.getIdeas(2);
		std::cout << RST;
		std::cout << "! Copy doesn't have idea 2 from Maris! !\n";

		//Assigning copy
		Maris_copy = Maris;
		
		std::cout << MGT << "Ideas from Maris_copy after assignment:\n";
		Maris_copy.getIdeas(2);
		std::cout << RST << "! Even though Maris_copy now has the same idea,"
						<< "it is stored in a different place in memory !\n\n";

		std::cout << "Ideas from Margo:\n";
		Margo.getIdeas(3);
		std::cout << RED << "Ideas from Margo copy:\n";
		Margo_copy.getIdeas(3);
		std::cout << RST;
		std::cout << "Ideas from Margo_REF:\n";
		MargoREF.getIdeas(3);
		std::cout << "! Margo_REF has same idea at same place in memory! !\n";

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
