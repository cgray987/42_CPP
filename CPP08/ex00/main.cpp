/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:55:57 by cgray             #+#    #+#             */
/*   Updated: 2024/09/23 14:18:30 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED "\033[31m"
#define RST "\033[0m"

#include "easyfind.hpp"
#include <list>
#include <deque>
#include <vector>

void sep(std::string test)
{
	std::cout << RED << "~~~~~~~~~~~ " << test << " ~~~~~~~~~~~\n" << RST;
}

//prints contents of a generic container
template <typename Container>
void print(const Container &container)
{
	typename Container::const_iterator it;
	std::cout << "{";
	for (it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << ", ";
	}
	std::cout << "}\n";
}

int	main(void)
{
	sep("List container");
	std::list<int> list;
	for (int i = 0; i < 20; i++)
		list.push_back(i);
	std::cout << "list = ";
	print(list);
	try
	{
		std::cout << "find '7': " << *easyfind(list, 7) << "\n";
		std::cout << "find '42': " << *easyfind(list, 42) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << "main caught exception: " << e.what() << "\n";
	}

	sep("vector container");
	std::vector<int> vector;
	for (int i = 0; i > -20; i--)
		vector.push_back(i);
	std::cout << "vector = ";
	print(vector);
	try
	{
		std::cout << "find '0': " << *easyfind(vector, 0) << "\n";
		std::cout << "find '-42': " << *easyfind(vector, -42) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << "main caught exception: " << e.what() << "\n";
	}

	sep("deque container");
	std::deque<int> deque;
	for (int i = 0; i < 1000; i++)
		deque.push_back(i);
	// std::cout << "deque = "; //big ass deque
	// print(deque);
	try
	{
		std::cout << "find '420': " << *easyfind(deque, 420) << "\n";
		std::cout << "find '1001': " << *easyfind(deque, 1001) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << "main caught exception: " << e.what() << "\n";
	}
}
