/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:08:36 by cgray             #+#    #+#             */
/*   Updated: 2024/09/27 12:43:59 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#define RED "\033[31m"
#define RST "\033[0m"
#define MAX_VAL 750

void sep(std::string test)
{
	std::cout << RED << "~~~~~~~~~~~ " << test << " ~~~~~~~~~~~\n" << RST;
}

int	main(void)
{
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	{
		srand(time(0));


		int	*a = new int();
		std::cout << "empty int:\t" << *a << "\n";
		delete a;

		sep("empty array");
		Array<int> empty;
		std::cout << "empty len:\t" << empty.size() << "\n";
		std::cout << "empty arr:\t";
		empty.print();

		sep("out of bounds test");
		try
		{
			std::cout << "empty[42]:\t" << empty[42] << "\n";
		}
		catch (std::exception &e)
		{
			std::cerr << "main caught exception: " << e.what() << "\n";
		}

		sep("fill int array");
		Array<int> intArr(5);
		for (int i = 0; i < 5; i++)
			intArr[i] = i;
		std::cout << "intArr len:\t" << intArr.size() << "\n";
		std::cout << "intArr:\t\t";
		intArr.print();

		sep("fill double array");
		Array<double> dblArr(5);
		for (int i = 0; i < 5; i++)
			dblArr[i] = rand() / 4200.69;
		std::cout << "dblArr len:\t" << dblArr.size() << "\n";
		std::cout << "dblArr:\t\t";
		dblArr.print();

		sep("copy constructor");
		Array<int> intArrCopy(intArr);
		std::cout << "intArrCopy len:\t" << intArrCopy.size() << "\n";
		std::cout << "intArrCopy:\t";
		intArrCopy.print();

		sep("assignment operator");
		Array<int> arrAss = intArr;
		std::cout << "arrAss len:\t" << arrAss.size() << "\n";
		std::cout << "arrAss:\t\t";
		arrAss.print();
	}
}
