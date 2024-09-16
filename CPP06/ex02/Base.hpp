/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:36:31 by cgray             #+#    #+#             */
/*   Updated: 2024/09/16 12:40:42 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>

class	Base
{
	public:
		virtual ~Base();
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);
