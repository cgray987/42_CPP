/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:52:16 by cgray             #+#    #+#             */
/*   Updated: 2024/10/03 12:00:40 by cgray            ###   ########.fr       */
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
*	-Vector is generally faster than deque (especially for large inputs)
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
#include <limits>

#define MGT "\033[95m"
#define CYN "\033[96m"
#define BLD "\033[1m"
#define RST "\033[0m"

template <typename container, typename pair_con>
class PmergeMe
{
	private:
		container	_original;		//container of input array
		pair_con	_pairs;			//container of pairs created from input array
		container	_sorted;		//final sorted container
		container	_jacobs;		//container of indicies to insert pairs into
		// size_t		_comp;			//comparison counter (not currently correct)
		std::string	_conName;		//holds name of container
		clock_t		_start;			//beginning time, before inputting into container

		//sorting
		void	make_pairs(void);
		void	sort_each_pair(void);
		void	sort_pair_sequence(void);
		void	insert_larger_num_from_pair(void);
		void	insert_rest(void);

		//utils
		void	input_container(int ac, char **av);
		int		get_jacobs_number(int i);
		void	make_jacob_array(int size);

		void merge_insertion_sort(pair_con &pairs);
		void merge(pair_con &left, pair_con &right, pair_con &result);


	public:
		//constructors
		PmergeMe(int ac, char **av, std::string container_name);
		PmergeMe(const PmergeMe &ref);

		//destructors
		~PmergeMe();

		//overloaded ops
		PmergeMe &operator = (const PmergeMe &ref);

		//sorting
		void	ford_johnson(void);
};

#include "PmergeMe.tpp"
