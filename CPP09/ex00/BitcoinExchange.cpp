/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:59:19 by cgray             #+#    #+#             */
/*   Updated: 2024/09/25 15:15:26 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	db("data.csv");

	if (!db.is_open())
		throw(std::runtime_error("Error: cannot open database"));

	std::string	line;

	while (getline(db, line))
	{
		if (line == "date,exchange_rate")
			continue ;
		read_database(line);
	}
	db.close();


	// days_in_months();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
	this->_date = ref._date;
	this->_rate = ref._rate;

	for(std::map<std::string, float>::const_iterator it = ref.btcMap.begin(); it != ref.btcMap.end(); ++it)
	{
		this->btcMap[it->first] = it->second;
	}
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange	&BitcoinExchange::operator = (const BitcoinExchange &src)
{
	if (this != &src)
	{
		this->_date = src._date;
		this->_rate = src._rate;

		for(std::map<std::string, float>::const_iterator it = src.btcMap.begin(); it != src.btcMap.end(); ++it)
		{
			this->btcMap[it->first] = it->second;
		}
	}
	return (*this);
}

/* saves database line into btcMap
*	line = "date,exchange_rate" */
void	BitcoinExchange::read_database(std::string line)
{
	std::string			token;
	std::stringstream	ss(line);

	int	i = 0;
	while (getline(ss, token, ','))
	{
		if (i == 0)
		{
			_date = token;
			i = 1;
		}
		else
			_rate = atof(token.c_str());
	}
	if (!valid_date(_date))
		throw(std::runtime_error("Database Error: Invalid date in DB on line: " + line));
	this->btcMap.insert(std::make_pair(_date, _rate));
}

//checks that line contains only one '|' and that it has enough space for date + '|'
bool	BitcoinExchange::check_line(std::string line)
{
	if (line.size() < 12 || line.find_first_of('|') != line.find_last_of('|')
		|| line.find_last_of('|') == std::string::npos)
	{
		std::cerr << "Error: Invalid line:\t" << line << "\n";
		return (false);
	}
	return (true);


		// throw(std::runtime_error("Error: invalid line: " + line));
}

void	BitcoinExchange::read_input(std::string fd)
{
	std::ifstream infile(fd.c_str());

	if (!infile.is_open())
		throw(std::runtime_error("Error: cannot open file: " + fd));

	std::string	line;
	std::getline(infile, line);
	if (line.find_first_of('|') != line.find_last_of('|')
		|| line.find("date") == std::string::npos || line.find("value") == std::string::npos )
		throw(std::runtime_error("Error: first line of input invalid. Expecting 'date | value' received:\t" + line));

	while (std::getline(infile, line))
	{
		if (check_line(line) == false)
			continue ;
		std::stringstream ss(line);

		std::string date;
		std::getline(ss, date, '|');
		if (valid_date(date) == false) //check if this removes whitespace
		{
			std::cerr << "Error: bad input =>\t" << date << "\n";
			continue ;
		}
		std::string value;
		std::getline(ss, value);
		if (valid_value(value) == false)
			continue ;
		if (get_rate(date, strtof(value.c_str(), NULL)) == false)
			continue ;
	}
	infile.close();
}



bool	BitcoinExchange::get_rate(std::string date, float value)
{
	std::map<std::string, float>::const_iterator it = btcMap.find(date);

	if (it == btcMap.end())
	{
		it = btcMap.upper_bound(date);
		if (it != btcMap.begin())
			it--;
		else
		{
			std::cerr << "Error: date out of bounds of DB:\t" << date << "\n";
			return (false);
		}
	}
	std::cout << trim(date) << " => " << value << " =\t" << it->second * value;
	// std::cout << "\tDB date: " << it->first << " rate: " << it->second;
	std::cout << "\n";
	return (true);
}

bool	BitcoinExchange::valid_date(std::string date)
{
	struct tm	tm;
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		return (false);

	int	y = tm.tm_year + 1900;
	int	m = tm.tm_mon + 1;
	int	d = tm.tm_mday;

	if (y < 2009) //check for max year?
		return false;

	if (m == 2) //leap year check
	{
		if ((((y % 4 == 0) &&
			(y % 100 != 0))
			|| (y % 4 == 0)))
			return (d <= 29);
		else
			return (d<= 28);
	}

	if (m == 4 || m == 6
		|| m == 9 || m == 11)
	{
		return (d <= 30);
	}
	return (true);
}

bool	BitcoinExchange::valid_value(std::string value)
{
	if (value.empty())
		return (false);
	if (value.find_first_of('.') != value.find_last_of('.'))
	{
		std::cerr << "Error: Invalid value , multiple decimals:\t" << value << "\n";
		return (false);
	}

	float	val = strtof(value.c_str(), NULL);
	if (val < 0)
	{
		std::cerr << "Error: not a positive number:\t" << val << "\n";
		return (false);
	}
	if (val > 1000)
	{
		std::cerr << "Error: too large a number:\t" << val << "\n";
		return (false);
	}
	return (true);
}

inline std::string &trim(std::string &s)
{
	std::string spaces = " \t\v\r\n";
	s.erase(s.find_last_not_of(spaces) + 1);
	s.erase(0, s.find_first_not_of(spaces));
	return s;
}
