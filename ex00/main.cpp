/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:30:49 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/05 20:51:56 by rthammat         ###   ########.fr       */
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
	std::cout << "time_t " << ft_stoepoc("2022-03-29,47115.93") << std::endl;
	//std::cout << data[ft_stoepoc("2022-03-29,47115.93")] << std::endl;
	//printDouble(data[ft_stoepoc("2022-03-29,47115.93")]);
	// std::vector<std::string> format = ft_split("2011-01-03 | 3.12", '|');
	// std::vector<std::string> date = ft_split(format[0], '-');
	// std::cout << "Year " << ft_stoi(date[0]) << std::endl;
	// std::cout << "Month " << ft_stoi(date[1]) << std::endl;
	// std::cout << "Day " << ft_stoi(date[2]) << std::endl;
	// std::cout << "Rate " << ft_stof(format[1]) << std::endl;

	// std::string line;
	// while (getline(inputFile, line))
	// {
	// 	std::cout << line << std::endl;
	// }
	// inputFile.close();
	return (0);
}
