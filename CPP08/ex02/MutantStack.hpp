/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:34:20 by cgray             #+#    #+#             */
/*   Updated: 2024/09/23 12:59:50 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <algorithm>


template <class T>
class MutantStack : public std::stack<T>
{
	public:
		//constructors
		MutantStack();
		MutantStack(const MutantStack &ref);

		//destructor
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator c_iterator;

		iterator		begin();
		c_iterator		begin() const;

		iterator		end();
		c_iterator		end() const;

};

template <class T>
MutantStack<T>::MutantStack(){};

template <class T>
MutantStack<T>::~MutantStack(){};

template <class T>
MutantStack<T>::MutantStack(const MutantStack &ref)
{
	//uses assignation from std::stack
	*this = ref;
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <class T>
typename MutantStack<T>::c_iterator	MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}

template <class T>
typename MutantStack<T>::c_iterator	MutantStack<T>::end() const
{
	return (this->c.end());
}
