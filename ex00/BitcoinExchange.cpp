/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:17:10 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/05 20:54:16 by rthammat         ###   ########.fr       */
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

double ft_stod(const std::string &s)
{
	double res = 0;

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
	res = atof(s.c_str());
	return (res);
}

int countDecimalPoint(double d)
{
	std::ostringstream oss;
	int count = 0;
	std::string::size_type pos = 0;

	oss << d;
	std::string s = oss.str();
	pos = s.find(".");
	while (pos < s.length())
	{
		++count;
		++pos;
	}
	return (count);
}

void printDouble(double d)
{
	std::cout << std::fixed << std::setprecision(countDecimalPoint(d)) << d;
}

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

time_t ft_stoepoc(const std::string &input)
{
	struct tm t;

	std::vector<std::string> format = ft_split(input, '|');
	std::vector<std::string> date = ft_split(format[0], '-');
	t.tm_year = ft_stoi(date[0]) - 1900;
	t.tm_mon = ft_stoi(date[1]) - 1;
	t.tm_mday = ft_stoi(date[2]);
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;
	return (mktime(&t));
}

db DbToMap(const std::string &filename)
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
	struct tm t;
	/////////////////
	getline(dbFile, line);
	/////////////////
	while (getline(dbFile, line))
	{
		std::vector<std::string> format = ft_split(line, ',');
		std::vector<std::string> date = ft_split(format[0], '-');
		t.tm_year = ft_stoi(date[0]) - 1900;
		t.tm_mon = ft_stoi(date[1]) - 1;
		t.tm_mday = ft_stoi(date[2]);
		t.tm_hour = 0;
		t.tm_min = 0;
		t.tm_sec = 0;
		data[mktime(&t)] = ft_stod(format[1]);
		if (line == "2022-03-29,47115.93")
		{
			std::cout << "time_t in function " << ft_stoepoc("2022-03-29,47115.93") << std::endl;
			std::cout << "map value in str is " << format[1] << std::endl;
			std::cout << "printDouble() => ";
			printDouble(ft_stod(format[1]));
			std::cout << std::endl;
			std::cout << "1 " << mktime(&t) << std::endl;
			std::cout << "2 " << mktime(&t) << std::endl;
		}
	}
	dbFile.close();
	return (data);
}
