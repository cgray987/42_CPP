/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:33:23 by cgray             #+#    #+#             */
/*   Updated: 2024/10/02 16:17:11 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _maxNbrs(N){}

Span::Span(const Span &ref) {*this = ref;}

Span::~Span(){}

Span &Span::operator = (const Span &ref)
{
	if (this != &ref)
	{
		this->_maxNbrs = ref._maxNbrs;
		this->_vector = ref._vector;
	}
	return (*this);
}

void	Span::addNumber(int nbr)
{
	if (this->_vector.size() >= this->_maxNbrs)
		throw std::out_of_range("Span vector full");
	else if (this->_vector.size() < this->_maxNbrs)
		this->_vector.push_back(nbr);
}


/* Returns shortest distance between all numbers in vector
	-check vector is not empty
	-copy the vector so it can be sorted
	-start with uintmax as shortest span
	-compare differences between next numbers
	-return smallest span
	 */
unsigned int		Span::shortestSpan() const
{
	if (_vector.empty() || _vector.size() == 1)
		throw std::out_of_range("Span must have more than 2 values");

	std::vector<int>	sortvec = _vector;
	unsigned int					min_span = std::numeric_limits<unsigned int>::max();

	std::sort(sortvec.begin(), sortvec.end());

	for (size_t i = 0; i < _vector.size() - 1; ++i)
	{
		unsigned int temp_span = sortvec[i + 1] - sortvec[i];
		if (temp_span < min_span)
			min_span = temp_span;
	}
	return (min_span);
}

/* Return longest distance between numbers
	-check if empty or < 2 elements
	-find max and min of vector, return difference

	more longs == more smart*/
long long int	Span::longestSpan() const
{
	if (_vector.empty() || _vector.size() == 1)
		throw std::out_of_range("Span must have more than 2 values");

	std::vector<int>::const_iterator max = std::max_element(_vector.begin(), _vector.end());
	std::vector<int>::const_iterator min = std::min_element(_vector.begin(), _vector.end());

	// std::cout << "max: " << *max << " min: " << *min << "\n";
	long long int res = static_cast<long long int>(*max) - static_cast<long long int>(*min);
	return (res);
}

/* Adds vector from begin to end into Span _vector
	-check if _vector has enough room
	-insert at beginning */
void	Span::vectorAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vector.size() + std::distance(begin, end) > this->_maxNbrs)
		throw std::out_of_range("Vector not large enough to add this range.");

	this->_vector.insert(_vector.begin(), begin, end);
}

/* prints entirety of span _vector
	-first checks if vector is empty */
void	Span::printVec() const
{
	if (_vector.empty())
		return ;

	std::cout << "[";
	for (size_t i = 0; i < _vector.size(); ++i)
	{
		std::cout << _vector[i];
		if (i != _vector.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]\n";
}
