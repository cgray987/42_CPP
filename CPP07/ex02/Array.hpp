/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:08:45 by cgray             #+#    #+#             */
/*   Updated: 2024/09/20 14:30:42 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T				*data;
		unsigned int	arraySize;
	public:
		//constructors
		Array();
		Array(unsigned int size);
		Array(const Array &ref);

		//destructor
		~Array();

		//overloaded ops
		Array	&operator = (const Array &ref);
		T	&operator [] (unsigned int index);

		//member funcs
		unsigned int size() const;
		void		print() const;

};

//template funcs
//template default constructor
template <typename T> Array<T>::Array()
{
	this->data = NULL;
	this->arraySize = 0;
}

//template size constructor
template <typename T> Array<T>::Array(unsigned int size)
{
	this->data = new T[size];
	arraySize = size;
}

//copy constructor
template <typename T> Array<T>::Array(const Array &ref)
{
	this->arraySize = ref.arraySize;
	this->data = new T[ref.size()];
	for (unsigned int i = 0; i < this->arraySize; i++)
		this->data[i] = ref.data[i];
}

//assignment operator
template <typename T> Array<T> &Array<T>::operator = (const Array &ref)
{
	if (this != &ref)
	{
		delete[] this->data;
		this->arraySize = ref.size();
		this->data = new T[ref.size()];
		for (unsigned int i = 0; i < this->arraySize; i++)
			this->data[i] = ref.data[i];
	}
	return (*this);
}

//destructor
template <typename T> Array<T>::~Array()
{
	delete[] this->data;
}

//size member func
template <typename T> unsigned int Array<T>::size() const
{
	return (this->arraySize);
}

//print member func
template <typename T> void Array<T>::print() const
{
	std::cout << "{";
	for (unsigned int i = 0; i < this->arraySize; i++)
	{
		std::cout << this->data[i];
		if (i != this->arraySize - 1)
			std::cout << ", ";
	}
	std::cout << "}\n";
}

//index operator
template <typename T> T &Array<T>::operator [] (unsigned int index)
{
	if (index >= this->arraySize)
	{
		throw std::out_of_range("index out of range");
	}
	return (data[index]);
}
