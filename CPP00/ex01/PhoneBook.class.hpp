/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:54 by cgray             #+#    #+#             */
/*   Updated: 2024/06/12 17:39:01 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_H

# define PHONEBOOK_H
# include "Contact.class.hpp"
# include <sstream> //stringstream
# include <stdlib.h>

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		_index;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);
		void	print(Contact entry);

		Contact	get_contact(int index);

};

std::string	enter_string(std::string type);
#endif
