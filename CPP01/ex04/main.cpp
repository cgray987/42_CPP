/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:20:11 by cgray             #+#    #+#             */
/*   Updated: 2024/06/19 14:21:13 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream> //open/close

//uses std::string.find to find arg, erases amount needed and inserts replace where found
//counter increases for each replacement made
std::string	my_replace(std::string line, std::string find, std::string replace, int &counter)
{
	size_t	found_position = line.find(find);

	while (found_position != std::string::npos) //while found is not the end of the string
	{
		line.erase(found_position, find.length());
		line.insert(found_position, replace);
		counter++;
		found_position = line.find(find, found_position + replace.length()); //goto next find
	}
	return (line);
}

//opens infile and outfile, returning error if fail
int	open_things(std::string fd, std::ifstream &infile, std::ofstream &outfile)
{
		infile.open(fd.c_str());
		if (infile.is_open())
		{
			std::string	outfile_name = fd + ".replace";
			const char	*outfile_name_c = outfile_name.c_str();
			outfile.open(outfile_name_c);
			if (outfile.is_open())
			{
				return (0);
			}
			else
			{
				std::cerr << "outfile error!\n";
				infile.close();
				return (1);
			}
		}
		else
		{
			std::cerr << "infile error!\n";
			return (1);
		}
		std::cerr << "i/o error!\n";
		return (1);

}

// ./replace <filename> <find> <replace>
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		const std::string	fd = av[1];
		const std::string	find = av[2];
		const std::string	replace = av[3];
		std::ifstream		infile;
		std::ofstream		outfile;
		if (find.size() == 0)
		{
			std::cerr << "Search string cannot be empty!\n";
			return (1);
		}
		if (open_things(fd, infile, outfile))
			return (1);
		int	counter = 0;
		for (std::string line; std::getline(infile, line);)
		{
			line = my_replace(line, find, replace, counter);
			outfile << line << '\n';
			if (infile.peek() == EOF)
				outfile << std::endl;
		}
		outfile.close();
		infile.close();
		std::cout << "made " << counter << " replacements in "
					<< fd << ".replace\n";
	}
	else
	{
		std::cerr << "Wrong number of parameters!\n"
				<< "Usage: ./replace <filename> <find> <replace>\n";
		return (1);
	}
	return (0);
}
