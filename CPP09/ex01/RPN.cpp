/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:19:37 by cgray             #+#    #+#             */
/*   Updated: 2024/09/25 16:28:46 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &ref) { *this = ref;}

RPN	&RPN::operator = (const RPN &ref) { (void)ref; return (*this);}

RPN::~RPN(){}

void	RPN::valid_input(std::string input)
{
	for (size_t i = 0; i < input.length(); ++i)
	{
		char	c = input[i];
		std::string	valid = "+-*/ ";
		if (!isdigit(c) && valid.find(c) == std::string::npos)
			throw(std::invalid_argument("Invalid characters in input!"));
	}
}

void	RPN::calculate(std::string input)
{
	valid_input(input);

	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
	{
		char	c = *it;

		if (isspace(c))
			continue;
		if (isdigit(c)) //nums will always be < 10
		{
			stack.push(c - '0');
			continue;
		}
		else
			op(c);
	}
	if (stack.size() == 1)
		std::cout << stack.top() << "\n";
	else //means too many numbers, not enough ops
		throw(std::invalid_argument("How do I work this"));
}

void	RPN::get_nums(int *a, int *b)
{
	*a = stack.top();
	stack.pop();
	*b = stack.top();
	stack.pop();
}

void	RPN::op(char c)
{
	if (stack.size() < 2) //means multiple ops follow each other
		throw(std::invalid_argument("this is not my beautiful wife"));
	if (c == '/' && stack.top() == 0)
		throw(std::invalid_argument("cannot divide by zero, ya dingus"));

	int a, b;
	get_nums(&a, &b);

	switch (c)
	{
		case '+':
			stack.push(a + b);
			break ;
		case '-':
			stack.push(b - a);
			break ;
		case '*':
			stack.push(a * b);
			break ;
		case '/':
			stack.push(b / a);
			break ;
		default:
			throw(std::invalid_argument("well, how did I get here"));
	}
}
