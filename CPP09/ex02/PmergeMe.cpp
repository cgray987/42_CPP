/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:52:14 by cgray             #+#    #+#             */
/*   Updated: 2024/09/26 14:38:29 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(int ac, char **av)
{
	input_container(ac, av);
}

PmergeMe::PmergeMe(const PmergeMe &ref) { *this = ref;}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator = (const PmergeMe &ref) {(void) ref; return (*this);}

void	PmergeMe::input_container(int ac, char **av)
{
	std::deque<int> deq;
	std::vector<int> vec;

	for (int i = 1; i < ac; ++i)
	{
		int nbr = atoi(av[i]);
		if (nbr <= 0)
		{
			throw(std::invalid_argument("Error: invalid input -- only positive ints allowed"));
		}
		deq.push_back(nbr);
		vec.push_back(nbr);
	}

	time_and_print(deq, vec);
}

void PmergeMe::deque_merge_insert(std::deque<int> &con, int left, int right, int threshold)
{
	if (left < right)
	{
		if (right - left + 1 <= threshold)
		{
			insertion_sort(con, left, right);
		}
		else
		{
			int mid = left + (right - left) / 2;
			deque_merge_insert(con, left, mid, threshold);
			deque_merge_insert(con, mid + 1, right, threshold);
			merge_deque(con, left, mid, right);
		}
	}
}

void PmergeMe::vector_merge_insert(std::vector<int> &con, int left, int right, int threshold)
{
	if (left < right)
	{
		if (right - left + 1 <= threshold)
		{
			insertion_sort(con, left, right);
		}
		else
		{
			int mid = left + (right - left) / 2;
			vector_merge_insert(con, left, mid, threshold);
			vector_merge_insert(con, mid + 1, right, threshold);
			merge_vector(con, left, mid, right);
		}
	}
}

template <typename T>
void PmergeMe::insertion_sort(T &con, int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
	{
		int temp = con[i];
		int j = i - 1;
		while (j >= left && con[j] > temp)
		{
			con[j + 1] = con[j];
			--j;
		}
		con[j + 1] = temp;
	}
}

void PmergeMe::merge_deque(std::deque<int> &con, int left, int mid, int right)
{
	int	n1 = mid - left + 1;
	int	n2 = right - mid;

	std::deque<int> L(n1), R(n2);

	for (int i = 0; i < n1; ++i)
		L[i] = con[left + i];
	for (int j = 0; j < n2; ++j)
		R[j] = con[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			con[k] = L[i];
			++i;
		}
		else
		{
			con[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1)
	{
		con[k] = L[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		con[k] = R[j];
		++j;
		++k;
	}
}

void PmergeMe::merge_vector(std::vector<int> &con, int left, int mid, int right)
{
	int	n1 = mid - left + 1;
	int	n2 = right - mid;

	std::vector<int> L(n1), R(n2);

	for (int i = 0; i < n1; ++i)
		L[i] = con[left + i];
	for (int j = 0; j < n2; ++j)
		R[j] = con[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			con[k] = L[i];
			++i;
		}
		else
		{
			con[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1)
	{
		con[k] = L[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		con[k] = R[j];
		++j;
		++k;
	}
}

void	PmergeMe::time_and_print(std::deque<int> deq, std::vector<int> vec)
{
	std::cout << MGT << "std::deque " << RST << "before sort:\t\t";
	print(deq);
	// std::cout << CYN << "std::vector " << RST << "before sort:\t";
	// print(vec);

	clock_t	deq_start_time = clock();
	deque_merge_insert(deq, 0, deq.size() - 1, 10);
	clock_t	deq_end_time = clock();
	double	deq_time = static_cast<double>(deq_end_time - deq_start_time) / CLOCKS_PER_SEC * 1e3;

	clock_t	vec_start_time = clock();
	vector_merge_insert(vec, 0, vec.size() - 1, 10);
	clock_t	vec_end_time = clock();
	double	vec_time = static_cast<double>(vec_end_time - vec_start_time) / CLOCKS_PER_SEC * 1e3;

	std::cout << MGT << "std::deque " << RST << "after sort:\t\t";
	print(deq);
	// std::cout << CYN << "std::vector " << RST << "after sort:\t\t";
	// print(vec);

	std::cout << "Time to process a range of " << MGT << deq.size() << RST
				<< " elements with std::deq : " << MGT << deq_time << RST << " μs\n";
	std::cout << "Time to process a range of " << CYN << vec.size() << RST
				<< " elements with std::vec : " << CYN << vec_time << RST << " μs\n";

	// if (vec == std::vector<int>(deq.begin(), deq.end()))
	// 	std::cout << "The sorted containers are equal.\n";
	// else
	// 	std::cout << "The sorted containers are NOT equal.\n";
}
