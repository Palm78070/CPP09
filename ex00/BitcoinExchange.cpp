/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:17:10 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/05 01:31:17 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char *IstringstreamImpossible::what() const throw()
{
	return ("Can not convert istringstream into integer");
}

int getYear(std::string s)
{
	std::string year;
	int res = 0;
	int start = 0;
	std::size_t pos = 0;

	pos = s.find("-");
	if (pos != std::string::npos)
		year = s.substr(start, pos);
	std::istringstream iss(year);
	try
	{
		if (!(iss >> res))
			throw IstringstreamImpossible();
	}
	catch (IstringstreamImpossible &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (res);
}

int getMonth(std::string s)
{
	std::string month;
	int start = 0;
	std::size_t pos = 0;
	int res = 0;

	for (int i = 0; i < 2; ++i)
	{
		start = pos + 1;
		pos = s.find("-");
	}
	if (pos != std::string::npos)
		month = s.substr(start, pos);
	std::istringstream iss(month);
	try
	{
		if (!(iss >> res))
			throw IstringstreamImpossible();
	}
	catch (IstringstreamImpossible &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (res);
}

int getDay(std::string s)
{
	std::string day;
	int start = 0;
	std::size_t pos = 0;
	int res = 0;

	start = s.rfind("-") + 1;
	pos = s.back();
	if (pos != std::string::npos)
		day = s.substr(start, pos);
	std::istringstream iss(day);
	try
	{
		if (!(iss >> res))
			throw IstringstreamImpossible();
	}
	catch (IstringstreamImpossible &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (res);
}

// db DbToMap(const std::string filename)
//{
//	std::ifstream dbFile(filename);
//	try
//	{
//		if (!dbFile)
//			throw (std::ios_base::failure("Failed to open database file"));
//	}
//	catch (const std::ios_base::failure &e)
//	{
//		std::cout << e.what() << std::endl;
//		exit(1);
//	}
//	std::string line;
//	db data;
//	struct tm t = {0};
//	while (getline(dbFile, line))
//	{
//		t.tm_year = ;
//		t.tm_mon =;
//		t.tm_mday =;
//		data[] =
//	}
//	dbFile.close();
// }
