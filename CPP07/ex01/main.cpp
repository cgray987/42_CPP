/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:38 by cgray             #+#    #+#             */
/*   Updated: 2024/09/20 13:02:05 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define RED "\033[31m"
#define RST "\033[0m"

template <typename T>
void	add_forty_two(T &nbr)
{
	nbr = nbr + 42;
}

template <typename T>
void	sum_array(T &nbr)
{
	nbr += nbr;
}

void	str_to_upper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}


int	main(void)
{
	int arr[3] = {0, 42, 69};

	std::cout << RED << "~~~~~~~ add_forty_two (int) ~~~~~~~\n" << RST;
	std::cout << "arr pre iter:\t";
	print_array(arr, 3, ", ");

	iter(arr, 3, add_forty_two<int>);
	std::cout << "arr post iter:\t";
	print_array(arr, 3, ", ");

	double darr[3] = {0.1, .42, 6.9};

	std::cout << RED << "\n~~~~~~~ add_forty_two (double) ~~~~~~~\n" << RST;
	std::cout << "arr pre iter:\t";
	print_array(darr, 3, ", ");

	iter(darr, 3, add_forty_two<double>);
	std::cout << "arr post iter:\t";
	print_array(darr, 3, ", ");


	std::cout << RED << "\n~~~~~~~ str_to_upper ~~~~~~~\n" << RST;
	std::string str_arr[] = {"hello", "world", "I", "am", "screaming!"};
	std::cout <<"string array pre iter:\t";
	print_array(str_arr, 5, " ");
	iter(str_arr, 5, str_to_upper);
	std::cout <<"string array post iter:\t";
	print_array(str_arr, 5, " ");
}
