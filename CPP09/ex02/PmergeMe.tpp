/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:33:50 by cgray             #+#    #+#             */
/*   Updated: 2024/10/03 12:02:26 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


template <typename T>
void	print_con(const T &con)
{
	if (con.empty())
		return ;
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
	std::cout << "} \n";
}

template <typename T>
void		print_pairs(const T &pairs)
{
	typename T::const_iterator it;

	if (pairs.empty())
		return ;
	std::cout << "pairs:\n";
	for (it = pairs.begin(); it != pairs.end(); ++it)
		std::cout << it->first << " | " << it->second << "\n";
	std::cout << "\n";
}

template <typename container, typename pair_con>
PmergeMe<container, pair_con>::PmergeMe(int ac, char **av, std::string container_name)
{
	_conName = container_name;
	input_container(ac, av);
}

template <typename container, typename pair_con>
PmergeMe<container, pair_con>::PmergeMe(const PmergeMe &ref)
{
	*this = ref;
}

template <typename container, typename pair_con>
PmergeMe<container, pair_con>::~PmergeMe()
{
}

template <typename container, typename pair_con>
PmergeMe<container, pair_con> &PmergeMe<container, pair_con>::operator=(const PmergeMe &ref)
{
	if (this != &ref)
	{
		_pairs = ref._pairs;
		_original = ref._original;
		_sorted = ref._sorted;
		_jacobs = ref._jacobs;
		_conName = ref._conName;
	}
	return (*this);
}

template <typename container, typename pair_con>
void PmergeMe<container, pair_con>::input_container(int ac, char **av)
{
	int	nbr;
	_start = clock();
	for (int i = 1; i < ac; ++i)
	{
		nbr = atoi(av[i]);
		if (nbr <= 0)
		{
			throw(std::invalid_argument("Error: invalid input -- only positive ints allowed"));
		}
		_original.push_back(nbr);
	}
	if (_original.empty())
		throw(std::invalid_argument("Error: input container is empty."));
}

//Main sorting algorithm
template <typename container, typename pair_con>
void PmergeMe<container, pair_con>::ford_johnson()
{
	if (_original.empty())
		throw(std::runtime_error("Error: input container is empty."));

	clock_t	end;
	double	elapsed;

	std::cout << "Before:\t";
	print_con(_original);

	make_pairs();
	make_jacob_array(_pairs.size());

	sort_each_pair();
	sort_pair_sequence();
	insert_larger_num_from_pair();
	insert_rest();
	end = clock();
	elapsed = static_cast<double>(end - _start) / CLOCKS_PER_SEC * 1e6;

	std::cout << "After:\t";
	print_con(_sorted);
	std::cout << "Time to process a range of " << MGT << _sorted.size()
		<< RST << " elements with std::" << _conName << " : " << MGT << elapsed << RST << " μs\n";
}

template <typename container, typename pair_con>
void PmergeMe<container, pair_con>::make_pairs(void)
{
	for (size_t i = 0; i < _original.size() - 1; i += 2)
		_pairs.push_back(std::make_pair(_original[i], _original[i + 1]));
	if (_original.size() % 2 != 0)
		_pairs.push_back(std::make_pair(std::numeric_limits<int>::max(), _original.back()));
}

template <typename container, typename pair_con>
void PmergeMe<container, pair_con>::sort_each_pair(void)
{
	typename pair_con::iterator it;
	for (it = _pairs.begin(); it != _pairs.end(); ++it)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
}

/* used for sorting pairs recursively */
template <typename container, typename pair_con>
void PmergeMe<container, pair_con>::merge(pair_con &left, pair_con &right, pair_con &result)
{
	size_t left_index = 0, right_index = 0, result_index = 0;

	while (left_index < left.size() && right_index < right.size())
	{
		if (left[left_index] <= right[right_index])
			result[result_index++] = left[left_index++];
		else
			result[result_index++] = right[right_index++];
	}

	while (left_index < left.size())
		result[result_index++] = left[left_index++];

	while (right_index < right.size())
		result[result_index++] = right[right_index++];
}

/* used for sorting pairs recursively */
template <typename container, typename pair_con>
void PmergeMe<container, pair_con>::merge_insertion_sort(pair_con &pairs)
{
	if (pairs.size() <= 1)
		return;

	size_t		mid = pairs.size() / 2;
	pair_con	left(pairs.begin(), pairs.begin() + mid);
	pair_con	right(pairs.begin() + mid, pairs.end());

	merge_insertion_sort(left);
	merge_insertion_sort(right);

	merge(left, right, pairs);
}

template <typename container, typename pair_con>
void PmergeMe<container, pair_con>::sort_pair_sequence(void)
{
	merge_insertion_sort(_pairs);
}

template <typename container, typename pair_con>
void PmergeMe<container, pair_con>::insert_larger_num_from_pair(void)
{
	typename pair_con::const_iterator it;
	typename pair_con::const_iterator itEnd;
	if (_original.size() % 2)
		itEnd = _pairs.end() - 1;
	else
		itEnd = _pairs.end();
	for (it = _pairs.begin(); it != itEnd; ++it)
		_sorted.push_back(it->first);
}

template <typename container, typename pair_con>
void PmergeMe<container, pair_con>::insert_rest(void)
{
	typename container::const_iterator j_it;
	for (j_it = _jacobs.begin(); j_it != _jacobs.end(); ++j_it)
	{
		typename container::iterator it_end;
		typename container::iterator it_res;
		//find position of first element of the pair in sorted array
		it_end = std::find(_sorted.begin(), _sorted.end(), _pairs[*j_it].first);
		//finds position to insert secon delement in sorted array
		it_res = std::lower_bound(_sorted.begin(), it_end, _pairs[*j_it].second);
		//inserts second element into sorted array
		_sorted.insert(it_res, _pairs[*j_it].second);
	}
}

/* returns an index for an array using jacobsthal number */
template <typename container, typename pair_con>
int PmergeMe<container, pair_con>::get_jacobs_number(int i)
{
	if (i == 0)
		return 1;
	if (i == 1)
		return 1;
	return ((2 * get_jacobs_number(i - 2)) + get_jacobs_number(i - 1));
}

/* creates array of indicies to insert into array from jacobsthal number */
template <typename container, typename pair_con>
void PmergeMe<container, pair_con>::make_jacob_array(int size)
{
	int	i = 0;
	int num;
	if (size == 1)
	{
		_jacobs.push_back(get_jacobs_number(0) - 1);
		return ;
	}
	while (get_jacobs_number(i) < size)
	{
		num = get_jacobs_number(i);
		if (i == 0)
		{
			i++;
			continue;
		}
		_jacobs.push_back(num - 1);
		num--;
		while (num > get_jacobs_number(i - 1))
		{
			_jacobs.push_back(num - 1);
			num--;
		}
		i++;
	}
	while (size > get_jacobs_number(i - 1))
	{
		_jacobs.push_back(size - 1);
		size--;
	}
}

template class PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > >;
template class PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > >;

