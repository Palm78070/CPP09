/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:17:10 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/05 12:47:40 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char *IstringstreamImpossible::what() const throw()
{
	return ("Can not convert istringstream into integer");
}

int ft_stoi(const std::string &s)
{
	int res = 0;

	std::istringstream iss(s);
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

float ft_stof(const std::string &s)
{
	float res = 0;

	std::istringstream iss(s);
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

// int getYear(std::string s)
// {
// 	std::string year;
// 	int start = 0;
// 	std::size_t pos = 0;

// 	pos = s.find("-");
// 	if (pos != std::string::npos)
// 		year = s.substr(start, pos);
// 	return (ft_stoi(year));
// }

// int getMonth(std::string s)
// {
// 	std::string month;
// 	int start = 0;
// 	std::size_t pos = 0;

// 	for (int i = 0; i < 2; ++i)
// 	{
// 		start = pos + 1;
// 		pos = s.find("-");
// 	}
// 	if (pos != std::string::npos)
// 		month = s.substr(start, pos);
// 	return (ft_stoi(month));
// }

// int getDay(std::string s)
// {
// 	std::string day;
// 	int start = 0;
// 	std::size_t pos = 0;

// 	start = s.rfind("-") + 1;
// 	pos = s.back();
// 	if (pos != std::string::npos)
// 		day = s.substr(start, pos);
// 	return (ft_stoi(day));
// }

std::vector<std::string> ft_split(const std::string &s, char delim)
{
	std::vector<std::string> res;
	std::string::size_type start = 0;
	std::string::size_type end = s.find(delim);

	while (end != std::string::npos)
	{
		res.push_back(s.substr(start, end - start));
		start = end + 1;
		end = s.find(delim, start);
	}
	res.push_back(s.substr(start));
	return (res);
}

db DbToMap(const std::string filename)
{
	std::ifstream dbFile(filename);
	try
	{
		if (!dbFile)
			throw(std::ios_base::failure("Failed to open database file"));
	}
	catch (const std::ios_base::failure &e)
	{
		std::cout << e.what() << std::endl;
		exit(1);
	}
	std::string line;
	db data;
	struct tm t = {0};
	while (getline(dbFile, line))
	{
		std::vector<std::string> format = ft_split(line, '|');
		std::vector<std::string> date = ft_split(format[0], '-');
		t.tm_year = ft_stoi(date[0]);
		t.tm_mon = ft_stoi(date[1]);
		t.tm_mday = ft_stoi(date[2]);
		data[mktime(&t)] = ft_stof(format[1]);
	}
	dbFile.close();
	return (data);
}
