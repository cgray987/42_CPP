/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:57 by cgray             #+#    #+#             */
/*   Updated: 2024/06/18 15:17:24 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main(void)
{
	{
		std::cout << "----Given main----\n";
		Weapon	club = Weapon("crude spiked club");
		HumanA	bob("Bob", club);
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");
		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << "----------------\n";


	std::cout << "----My main----\n";
	Weapon	revolver = Weapon("revolver");
	Weapon	glizzy = Weapon("glizzy");
	HumanA	mark = HumanA("Mark David Chapman", revolver);
	HumanB	john = HumanB("John Lennon");
	mark.attack();
	revolver.setType(".38 calibre Charter Arms revolver");
	mark.attack();
	john.attack();
	Weapon	steelChair = Weapon("Steel Chair");
	john.setWeapon(steelChair);
	john.attack();
	john.setWeapon(glizzy);
	john.attack();
	std::cout << "---------\n";

	/*generally prefer references unless you need to
	change where the pointer is pointing to. References
	are not allowed to be null.
	*/
	return (0);

}
