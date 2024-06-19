/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:07:56 by cgray             #+#    #+#             */
/*   Updated: 2024/06/12 17:46:57 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits> //for std::numeric_limits
#include "PhoneBook.class.hpp"

std::string	center_text(const std::string str, const int w)
{
	std::stringstream	new_str, spaces;
	int	padding = w - str.size();

	for(int i = 0; i<padding/2; i++)
		spaces << " ";
	new_str << spaces.str() << str << spaces.str();
	if (padding > 0 && padding % 2 !=0)
		new_str << " ";
	return (new_str.str());
}

static void	resize_string(std::string &str, int w)
{
	if (str.size() >= (size_t)w)
	{
		str.resize(w - 1);
		str.append(".");
	}
}

//function to ignore buffer from cin if user inputs extra data
static void	ignore_line(void)
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/*function returns true if prev extraction failed and removes
extra input
*/
static bool	clear_error_input(void)
{
	if (!std::cin) //if prev extraction failed
	{
		if (std::cin.eof()) //if input closed
			exit(0);
		std::cin.clear(); //go back to input
		ignore_line(); //remove bad input
		return (true);
	}
	return (false);
}

/*uses cin to return string from input.
clears cin buffer after first space in input.
Locks cin until input is valid.

input is displayed in cout to prompt user which field
is being requested
*/
std::string	enter_string(std::string type)
{
	std::string input;

	while (true)
	{
		std::cout << "Enter " << type << ": \n";
		std::cin >> input;
		if (clear_error_input())
		{
			std::cout << "Invalid Input!\n";
			continue;
		}
		ignore_line();
		return (input);
	}
}

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	std::cout << "Virtual Rolodex Starting!\n"
		"Created empty phonebook for 8 entries.\n\n";
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Hope you didn't need those contacts!\n"
		"Virtual Rolodex Destroyed.\n";
}

/* function to add contacts, will prompt user if they begin overwriting contacts */
void	PhoneBook::add(void)
{
	std::string	input = "";
	if (this->_index >= 8)
	{
		std::cout << "\nWARNING! Out of space for contacts!\n\n";
		input = enter_string("'y' to continue overwriting contacts, starting from 0");
		if (input == "y")
			this->_index = 0;
		else
			return ;
	}
	input = enter_string("First Name");
	this->contacts[this->_index].set_firstname(input);
	input = enter_string("Last Name");
	this->contacts[this->_index].set_lastname(input);
	input = enter_string("Phone Number");
	this->contacts[this->_index].set_phone_number(input);
	input = enter_string("Nickname");
	this->contacts[this->_index].set_nickname(input);
	std::cout << "Enter what blackmail you have on them: ";
	std::getline(std::cin, input);
	this->contacts[this->_index].set_secret(input);
	std::cout << "Completed entry.\n";
	this->_index++;
}

Contact	PhoneBook::get_contact(int index)
{
	return (this->contacts[index % 8]);
}

/* need 4 columns, right aligned, 10 char wide
|   index   | first name | last name | nickname | */
void	PhoneBook::search()
{
	Contact		entry;
	int			index;
	std::string	first, last, nick;

	std::cout << center_text("index", 10)		<< "|"		//for title of search screen
			<< center_text("first name", 10)	<< "|"
			<< center_text("last name", 10)		<< "|"
			<< center_text("nickname", 10)		<< '\n'
			<< std::string(10 * 4 + 2 * 2, '~')	<< '\n';

	for (int i = 0; i < 8; i++) //display all contacts, even if empty
	{
		entry = this->get_contact(i);
		first = entry.get_firstname();
		last = entry.get_lastname();
		nick = entry.get_nickname();
		resize_string(first, 10);
		resize_string(last, 10);
		resize_string(nick, 10);
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << first << "|"
				<< std::setw(10) << last << "|"
				<< std::setw(10) << nick << '\n';
	}
	std::cout << "Enter index of contact to see more information:\n";
	std::cin >> index;
	if (clear_error_input())
		std::cout << "Error, invalid input!\n";
	else
		this->print(this->contacts[index]);
}

void	PhoneBook::print(Contact entry)
{
	if (!entry.get_firstname().size())
	{
		std::cout << "\nError, contact doesn't exist!\n";
		return ;
	}
	std::cout << "\nFlipping through contacts...\n\n";
	std::cout << "First Name:\t" << entry.get_firstname() << '\n';
	std::cout << "Last Name:\t" << entry.get_lastname() << '\n';
	std::cout << "NickName:\t" << entry.get_nickname() << '\n';
	std::cout << "Phone Number:\t" << entry.get_phone_number() << '\n';
	std::cout << "Secret:\t\t" << entry.get_secret() << "\n\n";
}
