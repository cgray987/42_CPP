/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:47:40 by cgray             #+#    #+#             */
/*   Updated: 2024/06/13 15:32:18 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	//heap zombie, will need to be freed manually
	Zombie	*heap_zom = newZombie("George Harrison (heap)");
	//stack zombie, alloc and dealloc are handled by compiler
	Zombie	Zombie("John Lennon (stack)");

	randomChump("Ringo Starr (stack)");
	delete heap_zom;
	return (0);
}
