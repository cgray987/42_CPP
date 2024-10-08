/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:33:26 by cgray             #+#    #+#             */
/*   Updated: 2024/10/02 16:17:26 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <limits>

class Span
{
	private:
		unsigned int		_maxNbrs;
		std::vector<int>	_vector;

	public:
		//constructors
		Span(unsigned int N);
		Span(const Span &ref);

		//destructor
		~Span();

		//overloaded ops
		Span &operator = (const Span &ref);

		//member funcs
		void			addNumber(int nbr);
		unsigned int	shortestSpan() const;
		long long int	longestSpan() const;

		void	vectorAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		void	printVec() const;
};
