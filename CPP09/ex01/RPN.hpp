/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:19:39 by cgray             #+#    #+#             */
/*   Updated: 2024/09/25 16:31:22 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*		RPN
* 	-using std::stack
*		-useful because gives last-in, first-out structure
*	-check input for errors (non-digit, symbols other than "+-\* ")
*	-populate stack
*		-skip spaces
*		-add digits to stack
*		-handle arithmetic symbols as you reach them
*		-each action sends the result to top of stack
*		- will always take 2 numbers, then an op, then
*	-display top of stack
*/

#pragma once

#include <stack>
#include <string>
#include <exception>
#include <iostream>
#include <cctype>

class RPN
{
	private:
		std::stack<long int> stack;

		void	op(char c);
		void	get_nums(int *a, int *b);
		void	valid_input(std::string input);
	public:
		//constructors
		RPN();
		RPN(const RPN &ref);

		//destructor
		~RPN();

		//overloaded ops
		RPN &operator = (const RPN &ref);

		void	calculate(std::string input);
};
