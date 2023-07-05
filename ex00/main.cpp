/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:30:49 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/05 22:08:52 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw(std::runtime_error("invalid argument: ./btc <input_file>"));
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	std::ifstream inputFile(argv[1]);
	try
	{
		if (!inputFile)
			throw(std::ios_base::failure("Failed to open file"));
	}
	catch (const std::ios_base::failure &e)
	{
		std::cout << e.what() << std::endl;
		exit(1);
	}
	db data = DbToMap("data.csv");
	//std::cout << "time_t " << ft_stoepoc("2022-03-29,47115.93") << std::endl;
	//std::cout << data[ft_stoepoc("2022-03-29,47115.93")] << std::endl;
	std::string line;
	getline(inputFile, line);
	while (getline(inputFile, line))
	{
		//std::cout << line << std::endl;
		//std::cout << ft_stoepoc(line) << std::endl;
		findBitcoinPrice(line, data);
	}
	inputFile.close();
	return (0);
}
