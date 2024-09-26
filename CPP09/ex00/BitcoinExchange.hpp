/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:59:16 by cgray             #+#    #+#             */
/*   Updated: 2024/09/25 15:47:01 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	Bitcoin Exchange
*	-take database csv
*	-take input file
*		-check validity of header (date | value)
*	-multiply database exchange rate and btc amount on day specified in input
*		-if date doesn't exist, go to next earlier date in DB
*		-check validity of date in line (Year-Month-Day, leap years, valid date after 2009-01-02)
*		-check validity of btc amount ( 0 <= x <= 1000 , must be a number)
*		-check validity of input format (line too short <12 chars, no pipe, multiple pipes)
*	-output result
*		- "date" => "amount" = "total"
*		- Error: "error msg"
*
*	-using std::map
*		-ordered set of key-value pairs
*		-saving stack for ex01, vector and deque for ex02
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <ctime>

class BitcoinExchange
{
	private:
		std::string						_date;
		float							_rate;
		std::map<std::string, float>	btcMap;
		std::map<std::string, int>		monthIndex;

		void	read_database(std::string line);
		bool	get_rate(std::string date, float value);
		bool	check_line(std::string line);
		bool	valid_date(std::string date);
		bool	valid_value(std::string value);
		
	public:
		//constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &ref);

		//overloaded ops
		BitcoinExchange &operator = (const BitcoinExchange &src);

		//destructor
		~BitcoinExchange();

		void	read_input(std::string fd);
};

inline std::string &trim(std::string &s);
