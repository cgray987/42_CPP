/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:28:48 by cgray             #+#    #+#             */
/*   Updated: 2024/06/19 15:03:30 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void	Harl::complain(std::string level)
{
	void	(Harl::*functionPTRS[])(void) = {&Harl::debug,
											&Harl::info,
											&Harl::warning,
											&Harl::error};
	std::string handles[] = {"DEBUG",
							"INFO",
							"WARNING",
							"ERROR"};
	int	array_size = sizeof(handles)/sizeof(handles[0]);
	for(int i = 0; i < array_size; i++)
	{
		if (handles[i] == level)
		{
			(this->*functionPTRS[i])();
			return ;
		}
	}
	std::cout << "Pointer to member function not found:\n"
			<< "I don't know how to complain about this!\n";
}

void	Harl::debug()
{
	std::cout << "DEBUG:\n"
			<< "I love having extra bacon for my "
			<< "7XL-double-cheese-triple-pickle-special "
			<< "ketchup burger. I really do!\n";
}

void	Harl::info()
{
	std::cout << "INFO:\n"
			<< "I cannot believe adding extra bacon "
			<< "costs more money. You didn’t put enough bacon "
			<< "in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning()
{
	std::cout << "WARNING:\n"
			<< "I think I deserve to have some extra bacon for free. "
			<< "I’ve been coming for years whereas you started working "
			<< "here since last month.\n";
}

void	Harl::error()
{
	std::cout << "ERROR:\n"
			<< "This is unacceptable! I want to speak to the manager now.\n";
}
