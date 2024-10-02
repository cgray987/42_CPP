/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:48:58 by cgray             #+#    #+#             */
/*   Updated: 2024/10/02 15:20:47 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <list>

#define RED "\033[31m"
#define RST "\033[0m"

void sep(std::string test)
{
	std::cout << RED << "~~~~~~~~~~~ " << test << " ~~~~~~~~~~~\n" << RST;
}

int	main(void)
{
	{
		sep("Subject Tests");

		MutantStack<int>	mStack;

		mStack.push(5);
		mStack.push(17);

		std::cout << mStack.top() << std::endl;

		mStack.pop();

		std::cout << mStack.size() << std::endl;

		mStack.push(3);
		mStack.push(5);
		mStack.push(737);

		mStack.push(0);

		MutantStack<int>::iterator it = mStack.begin();
		MutantStack<int>::iterator ite = mStack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mStack);
	}
	{
		sep("Replacing mutantStack with std::list");

		std::list<int>	list;

		list.push_back(5);
		list.push_back(17);

		std::cout << list.back() << std::endl;

		list.pop_back();

		std::cout << list.size() << std::endl;

		list.push_back(3);
		list.push_back(5);
		list.push_back(737);

		list.push_back(0);

		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(list);
	}
	{
		sep("Iterator vs Const iterator <float>");

		MutantStack<float> fStack;
		fStack.push(0.5);
		fStack.push(42);
		fStack.push(69.42);
		fStack.push(-42.99);

		std::cout << "\titerator:\n";
		for (MutantStack<float>::iterator it = fStack.begin(); it != fStack.end(); ++it)
		{
			std::cout << *it << std::endl;
		}
		std::cout << "\tconst iterator:\n";
		for (MutantStack<float>::c_iterator c_it = fStack.begin(); c_it != fStack.end(); ++c_it)
		{
			std::cout << *c_it << std::endl;
		}

		sep("Iterating backwards <float>");
		for (MutantStack<float>::iterator it_e = fStack.end(); it_e != fStack.begin();)
		{
			--it_e;
			std::cout << *it_e << std::endl;
		}
	}
	{
		sep("Empty stack");
		MutantStack<int> emptyStack;
		if (emptyStack.empty())
			std::cout << "empty stack!\n";
		else
			std::cout << "non-empty stack!\n";
	}

}
