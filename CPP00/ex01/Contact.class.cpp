/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:13:33 by cgray             #+#    #+#             */
/*   Updated: 2024/06/11 13:50:54 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}
//getters
std::string	Contact::get_firstname(void) const{
	return (this->_firstName);
}

std::string	Contact::get_lastname(void) const{
	return (this->_lastName);
}

std::string	Contact::get_nickname(void) const{
	return (this->_nickName);
}

std::string	Contact::get_phone_number(void) const{
	return (this->_phoneNumber);
}

std::string	Contact::get_secret(void) const{
	return (this->_darkestSecret);
}

//setters
void	Contact::set_firstname(std::string str){
	this->_firstName = str;
}

void	Contact::set_lastname(std::string str){
	this->_lastName = str;
}

void	Contact::set_nickname(std::string str){
	this->_nickName = str;
}

void	Contact::set_phone_number(std::string str){
	this->_phoneNumber = str;
}

void	Contact::set_secret(std::string str){
	this->_darkestSecret = str;
}
