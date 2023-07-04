/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:30:49 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/04 22:32:54 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (std::runtime_error("invalid argument: ./btc <input_file>"));
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::ifstream inputFile(argv[1]);
	try
	{
		if (!inputFile)
			throw (std::ios_base::failure("Failed to open file"));
	}
	catch (const std::ios_base::failure &e)
	{
		std::cout << e.what() << std::endl;
		exit(1);
	}
	//db data = DbToMap("data.csv");
	std::cout << getYear("2020-01-03") << std::endl;
	std::string line;
	while (getline(inputFile, line))
	{
		std::cout << line << std::endl;
	}
	inputFile.close();
	return (0);
}
