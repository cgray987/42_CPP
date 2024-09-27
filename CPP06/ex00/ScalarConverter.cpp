/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:34:53 by cgray             #+#    #+#             */
/*   Updated: 2024/09/27 12:06:50 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//constructors
Scalar::Scalar(){}
Scalar::Scalar(const std::string &string){Scalar::convert(string);}
Scalar::Scalar(const Scalar &copy){ *this = copy;}

//destructor
Scalar::~Scalar(){}

//overloaded ops
Scalar &Scalar::operator = (const Scalar &src)
{
		if (this == &src)
			return (*this);
		return (*this);
}

//member functions
bool Scalar::findOne(std::string string, char c)
{
	if (string.find_first_of(c) == string.find_last_of(c))
		return (true);
	return (false);
}

bool	Scalar::isChar(std::string string)
{
	if (string.size() == 1 && !isdigit(string[0]))
		return true;
	return (false);
}

bool	Scalar::isInt(std::string string)
{
	unsigned long	i;
	if (string[0] == '-' || string[0] == '+')
		i = 1;
	else
		i = 0;
	for (; i < string.size(); i++) //iterate through string, returning false if any non digits
	{
		if (!isdigit(static_cast<unsigned char>(string[i])))
			return (false);
	}
	return (true);
}

bool	Scalar::isFloat(std::string string)
{
	if (string.size() < 2)
		return (false);
	unsigned long	i;
	if (string[0] == '-' || string[0] == '+')
		i = 1;
	else
		i = 0;
	if (!Scalar::findOne(string, 'f') && !Scalar::findOne(string, '.'))
		return (false); //maybe bad input
	for (; i < string.size() - 1; i++) //iterate thru string - 1(ends in f), false if any non digits and one '.'
	{
		if (!isdigit(static_cast<unsigned char>(string[i])) && string[i] != '.')
			return (false);
	}
	if (string[string.length() - 1] == 'f' && string.find_first_of('.') != std::string::npos)
		return (true);
	return (false);
}

bool	Scalar::isDouble(std::string string)
{
	if (string.size() < 2)
		return (false);
	unsigned long	i;
	if (string[0] == '-' || string[0] == '+')
		i = 1;
	else
		i = 0;
	if (!Scalar::findOne(string, '.'))
		return (false); //maybe bad input
	for (; i < string.size(); i++) //iterate thru string, false if any non digits and one '.'
	{
		if (!isdigit(static_cast<unsigned char>(string[i])) && string[i] != '.')
			return (false);
	}
	return (true);
}

int	Scalar::chooseType(std::string string)
{
	if (string.empty())
		return (ERROR);
	else if (Scalar::isChar(string))
		return (CHAR);
	else if (Scalar::isInt(string))
		return (INT);
	else if (Scalar::isFloat(string))
		return (FLOAT);
	else if (Scalar::isDouble(string))
		return (DOUBLE);
	else if (string == "nan" || string == "nanf"
			|| string == "inf" || string == "-inf"
			|| string == "inff" || string == "-inff"
			|| string == "+inf" || string == "+inff")
		return (OTHER);
	else
		return (ERROR);
}

void	Scalar::convert(std::string string)
{
	values	values;

	values._conversionFrom = chooseType(string);

	if (values._conversionFrom != ERROR)
	{
		if (values._conversionFrom == CHAR)
			Scalar::fromChar(values, string);
		else if (values._conversionFrom == INT)
			Scalar::fromInt(values, string);
		else if (values._conversionFrom == DOUBLE)
			Scalar::fromDouble(values, string);
		else if (values._conversionFrom == FLOAT)
			Scalar::fromFloat(values, string);
		else if (values._conversionFrom == OTHER)
			return (printSpecial(values, string));
		print(values);
	}
	else
		throw badInput();
}
void	Scalar::fromChar(values &v, std::string string)
{
	v._charVal = static_cast<unsigned char>(string[0]);
	v._intVal = static_cast<long long>(v._charVal);
	v._floatVal = static_cast<float>(v._charVal);
	v._doubleVal = static_cast<double>(v._charVal);
}

void	Scalar::fromInt(values &v, std::string string)
{
	v._intVal = std::atoll(string.c_str()); //cast to long long to check if in bounds of int

	long long min = std::numeric_limits<int>::min();
	long long max = std::numeric_limits<int>::max();
	if (v._intVal >= max || v._intVal <= min)
	{
		v._conversionFrom = DOUBLE;
		Scalar::fromDouble(v, string);
		return ;
	}
	v._charVal = static_cast<unsigned char>(v._intVal);
	v._floatVal = static_cast<float>(v._intVal);
	v._doubleVal = static_cast<double>(v._intVal);

}

void	Scalar::fromFloat(values &v, std::string string)
{
	v._floatVal = std::strtof(string.c_str(), NULL);
	v._intVal = static_cast<long long>(v._floatVal);
	v._charVal = static_cast<unsigned char>(v._floatVal);
	v._doubleVal = static_cast<double>(v._floatVal);
}

void	Scalar::fromDouble(values &v, std::string string)
{
	v._doubleVal = std::strtod(string.c_str(), NULL);
	v._intVal = static_cast<long long>(v._doubleVal);
	v._charVal = static_cast<unsigned char>(v._doubleVal);
	v._floatVal = static_cast<double>(v._doubleVal);
}

void	Scalar::print(values &v)
{
		Scalar::printChar(v);
		Scalar::printInt(v);
		Scalar::printFloat(v);
		Scalar::printDouble(v);
}

void	Scalar::printChar(values &v)
{
	long long max = std::numeric_limits<unsigned char>::max();
	long long min = std::numeric_limits<unsigned char>::min();

	if (v._conversionFrom != CHAR)
	{
		if (v._intVal >= min && v._intVal <= max)
		{
			if (isprint(v._charVal))
				std::cout << "char: " << v._charVal << "\n";
			else
				std::cout << "char: Non printable\n";
		}
		else
			std::cout << "char: impossible\n";
	}
	else
		std::cout << "char: " << v._charVal << "\n";
}

void	Scalar::printInt(values &v)
{
	long long max = std::numeric_limits<int>::max();
	long long min = std::numeric_limits<int>::min();

	if (v._intVal >= min && v._intVal <= max)
		std::cout << "int: " << v._intVal << "\n";
	else
		std::cout << "int: impossible\n";
}

void	Scalar::printFloat(values &v)
{
	std::cout << "float: " << v._floatVal;
	if ((v._floatVal - v._intVal == 0 && (v._floatVal < 1e6 && v._floatVal > -1e6)))
	{
		std::cout << ".0";
	}
	std::cout << "f\n";
}

void	Scalar::printDouble(values &v)
{
	std::cout << "double: " << v._doubleVal;
	if ((v._doubleVal - v._intVal == 0 && (v._doubleVal < 1e6 && v._doubleVal > -1e6)))
	{
		std::cout << ".0";
	}
	std::cout << "\n";

}

void	Scalar::printSpecial(values &v, std::string string)
{
	if (string == "nan" || string == "nanf")
	{
		v._floatVal = std::numeric_limits<float>::quiet_NaN();
		v._doubleVal = std::numeric_limits<double>::quiet_NaN();
	}
	else if (string == "inf" || string == "inff"
		|| string == "+inf" || string == "+inff")
	{
		v._floatVal = std::numeric_limits<float>::infinity();
		v._doubleVal = std::numeric_limits<double>::infinity();
	}
	else if (string == "-inf" || string == "-inff")
	{
		v._floatVal = static_cast<float>(std::numeric_limits<float>::infinity() * -1);
		v._doubleVal = static_cast<double>(std::numeric_limits<double>::infinity() * -1);
	}
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << v._floatVal << "f\n";
	std::cout << "double: " << v._doubleVal << "\n";
}

//exceptions
const char *Scalar::badInput::what() const throw()
{
	return ("bad input! use CHAR, INT, FLOAT, DOUBLE");
}


