/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:30:49 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/19 17:36:25 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw(std::runtime_error("invalid argument: ./btc <input_file>"));
		std::ifstream inputFile(argv[1]);
		if (!inputFile)
			throw(std::ios_base::failure("Failed to open file"));
		BitcoinExchange btc('|');
		btc.DbToMap("data.csv");
		std::string line;
		getline(inputFile, line);
		while (getline(inputFile, line))
			btc.check_format(line);
		inputFile.close();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	catch (const std::ios_base::failure &e)
	{
		std::cout << e.what() << std::endl;
		exit(1);
	}
	return (0);
}
