/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:52:16 by cgray             #+#    #+#             */
/*   Updated: 2024/09/26 15:14:21 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	~~PMergeMe~~
*	-https://en.wikipedia.org/wiki/Merge-insertion_sort
*	-using vector and deque
*	-algo
*		-group elements into (n/2) pairs (leave one unpaired if odd group of elements)
*		-compare each pair to find larger in pair
*		-recursively sort container by the pair's larger element using merge-insertion (S)
*		-insert the smallest and first element at the start of the sorted container (S)
*		-insert remaining elements one at a time
*			-iterate thru remaining elements
*			-find correct position with binary search
*			-shift elements that are greater than current to make room for new element
*			-repeat recursively
*
*	-insertion sort
*		-builds final sort one item at a time
*	-merge sort
*		-divides array into two halves, recursively sorts them, then merges sorted halves
*	-EXAMPLE
*		[5, 2, 9, 1, 6, 3]
*		pairs:
*			Pairs: (5, 2), (9, 1), (6, 3)
*			Larger elements: [5, 9, 6]
*			Smaller elements: [2, 1, 3]
*		recursively sort large elements: [5, 6, 9] ; [2, 1, 3]
*		insert smallest:				[1, 5, 6, 9] ; [2, 3]
*		repeat
*
*	-Vector is generally faster than deque
*		-vector is fast because elements are in continous place in memory
*		-vector has more efficient random access, slow insertion/deletion at beginning of container
*/

#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include <ctime>

#define MGT "\033[95m"
#define CYN "\033[96m"
#define RST "\033[0m"

class PmergeMe
{
	public:
		//constructors
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &ref);

		//destructors
		~PmergeMe();

		//overloaded ops
		PmergeMe &operator = (const PmergeMe &ref);

		void	input_container(int ac, char **av);
		void	time_and_print(std::deque<int> deq, std::vector<int> vec);


		void	merge_vector(std::vector<int> &con, int left, int mid, int right);
		void	merge_deque(std::deque<int> &con, int left, int mid, int right);

		void	deque_merge_insert(std::deque<int> &con, int left, int right, int threshold);
		void	vector_merge_insert(std::vector<int> &con, int left, int right, int threshold);

		template <typename T>
		void	insertion_sort(T &con, int left, int right);


};

template <typename T>
void	print(const T &con)
{
	if (!con.empty())
	{
		typename T::const_iterator it = con.begin();
		size_t	size = con.size();

		std::cout << "{ ";
		if (size <= 5)
		{
			for (; it != con.end(); ++it)
				std::cout << *it << ", ";
		}
		else
		{
			for (size_t i = 0; i < 4; ++i, ++it)
				std::cout << *it << ", ";
			std::cout << "[...] " << *(con.end() - 1);
		}
	}
	std::cout << "} \n";
}
