/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:34:55 by cgray             #+#    #+#             */
/*   Updated: 2024/09/13 17:44:05 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>


class Scalar
{
	private:
		//constructors
		Scalar();
		Scalar(const std::string &string);
		Scalar(const Scalar &copy);

		//destructor
		~Scalar();

		//overloaded ops
		Scalar &operator = (const Scalar &src);
		
		enum scalarType {ERROR, CHAR, INT, FLOAT, DOUBLE, OTHER};
		struct values {
			int					_conversionFrom;
			char				_charVal;
			long long			_intVal;
			float				_floatVal;
			double				_doubleVal;
		};

		//util functions
		static void	fromChar(values &v, std::string string);
		static void	fromInt(values &v, std::string string);
		static void	fromFloat(values &v, std::string string);
		static void	fromDouble(values &v, std::string string);

		static bool	isChar(std::string string);
		static bool	isInt(std::string string);
		static bool	isFloat(std::string string);
		static bool	isDouble(std::string string);

		static int		chooseType(std::string string);

		static bool findOne(std::string string, char c);

		static void	print(values &v);
		static void	printChar(values &v);
		static void	printInt(values &v);
		static void	printFloat(values &v);
		static void printDouble(values &v);
		static void	printSpecial(values &v, std::string string);


	public:

		//member functions
		static void convert(std::string string);

		//exceptions
		class badInput: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};
