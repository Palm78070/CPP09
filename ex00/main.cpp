/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:30:49 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/08 01:41:33 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void check_format(const std::string &line, const db &data)
{
	std::string *format = NULL;
	std::cout << std::flush;
	double value;
	try
	{
		format = ft_split(line, '|');
		value = ft_stod(format[1]);
		isNum(format[1]);
		findBitcoinPrice(format, value, data);
		if (format)
			delete[] format;
	}
	catch (BadInput &e)
	{
		std::cout << e.what() << line << std::endl;
	}
	catch (const NotPositiveNumber &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const NumberTooLarge &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw(std::runtime_error("invalid argument: ./btc <input_file>"));
		std::ifstream inputFile(argv[1]);
		if (!inputFile)
			throw(std::ios_base::failure("Failed to open file"));
		db data = DbToMap("data.csv");
		std::string line;
		getline(inputFile, line);
		while (getline(inputFile, line))
			check_format(line, data);
		// findBitcoinPrice(line, data);
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
