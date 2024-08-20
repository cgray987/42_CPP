/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:47 by cgray             #+#    #+#             */
/*   Updated: 2024/08/20 17:18:14 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	*hermes = new Bureaucrat("Hermes", 150);

	hermes->decGrade();
	hermes->decGrade();
	std::cout << hermes;
}
