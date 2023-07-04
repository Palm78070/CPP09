/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:17:10 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/04 22:59:19 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char *IstringstreamImpossible::what() const throw()
{
	return ("Can not convert istringstream into integer");
}

int getYear(std::string s, char mode)
{
	std::string year;
	int res = 0;
	int start = 0;
	std::size_t pos = 0;
	if (mode == 'M' || mode == 'D')
	{
		int occ = (mode == 'M') ? 1 : 2;
		for (int i = 0; i < occ; ++i)
		{
			++start;
			pos = s.find("-");
		}
	}
	else
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

//int getMon()
//{}

//int getDay()
//{}

//db DbToMap(const std::string filename)
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
//}
