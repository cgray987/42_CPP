/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:42:16 by cgray             #+#    #+#             */
/*   Updated: 2024/09/16 16:41:33 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>

template <typename T>
void swap(T &arg1, T &arg2)
{
	T temp(arg1);
	arg1 = arg2;
	arg2 = temp;
}

template <typename T>
T min(T arg1, T arg2)
{
	if (arg1 < arg2)
		return (arg1);
	else
		return (arg2);
};

template <typename T>
T max(T arg1, T arg2)
{
	if (arg1 > arg2)
		return (arg1);
	else
		return (arg2);
};
