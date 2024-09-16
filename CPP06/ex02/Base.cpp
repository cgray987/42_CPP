/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:36:29 by cgray             #+#    #+#             */
/*   Updated: 2024/09/16 13:23:11 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){};

/* ~~~dynamic_cast~~~
	safely converts pointers/references to classes
	up, down, and sideways along inheritance hierarchy

	-downcast can also be done with static_cast, which is cheaper,
	but less safe*/

Base	*generate(void)
{
	// srand(time(0)); //moved to main

	int	random = rand();

	Base	*ptr;
	switch (random % 3)
	{

		case 0:
			ptr = new A();
			break ;
		case 1:
			ptr = new B();
			break ;
		case 2:
			ptr = new C();
			break ;
		default:
			ptr = NULL;
	}
	return (ptr);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C\n";
	else
		std::cout << "unknown type\n";
}

void	identify(Base &p)
{
	try
	{
		A &refA = dynamic_cast<A &>(p);
		(void) refA;
		std::cout << "A\n";
	}
	catch (std::exception &e){};
	try
	{
		B &refB = dynamic_cast<B &>(p);
		(void) refB;
		std::cout << "B\n";
	}
	catch (std::exception &e){};
	try
	{
		C &refC = dynamic_cast<C &>(p);
		(void) refC;
		std::cout << "C\n";
	}
	catch (std::exception &e){};
}
