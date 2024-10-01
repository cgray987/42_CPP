/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:33:20 by cgray             #+#    #+#             */
/*   Updated: 2024/10/01 16:53:30 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#define RED "\033[31m"
#define RST "\033[0m"

void sep(std::string test)
{
	std::cout << RED << "~~~~~~~~~~~ " << test << " ~~~~~~~~~~~\n" << RST;
}

int	main(void)
{
	sep("subject tests");
	Span sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.printVec();

		std::cout << "shortest: " << sp.shortestSpan() << "\n";
		std::cout << "longest: " << sp.longestSpan() << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << "Main caught exception: " << e.what() << "\n";
	}

	sep("Int min to Int max");
	Span test = Span(10);
	try
	{
		test.addNumber(std::numeric_limits<int>::min());
		test.addNumber(42);
		test.addNumber(0);
		test.addNumber(420);
		test.addNumber(69);
		test.addNumber(-777);
		test.addNumber(std::numeric_limits<int>::max());
		test.addNumber(6969);
		test.addNumber(1);
		test.addNumber(2);

		test.printVec();

		std::cout << "shortest: " << test.shortestSpan() << "\n";
		std::cout << "longest: " << test.longestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "main caught exception: " << e.what() << '\n';
	}

	sep("Test adding vector to vector");
	//create a big ass random vector
	std::vector<int> bigguy;
	for (size_t i = 0; i < 1000; ++i)
		bigguy.push_back(rand() % 1000);
	Span test2 = Span(bigguy.size() + 1);
	try
	{
		test2.vectorAdd(bigguy.begin(), bigguy.end());
		test2.addNumber(1); //can still add numbers regularly

		// test2.printVec();
		std::cout << "largest value: " << *std::max_element(bigguy.begin(), bigguy.end()) << "\n";
		std::cout << "smallest value: " << *std::min_element(bigguy.begin(), bigguy.end()) << "\n";
		std::cout << "shortest: " << test2.shortestSpan() << "\n";
		std::cout << "longest: " << test2.longestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "main caught exception: " << e.what() << '\n';
	}

	sep("test adding too many numbers");
	Span too_small = Span(3);
	try
	{
		too_small.addNumber(42);
		too_small.addNumber(12);
		too_small.addNumber(69);
		too_small.printVec();
		too_small.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "main caught exception: " << e.what() << '\n';
	}

	sep("test span with 1 number");
	Span one_num = Span(1);
	try
	{
		one_num.addNumber(42);
		one_num.printVec();
		one_num.longestSpan();
		one_num.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << "main caught exception: " << e.what() << '\n';
	}


}

