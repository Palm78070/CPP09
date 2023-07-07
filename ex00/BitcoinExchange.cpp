/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:17:10 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/07 22:49:14 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char *IstringstreamImpossible::what() const throw()
{
	return ("Can not convert istringstream into integer");
}

const char *BadInput::what() const throw()
{
	return ("Error: bad input");
}

const char *NotPositiveNumber::what() const throw()
{
	return ("Error: not a positive number.");
}

const char *NumberTooLarge::what() const throw()
{
	return ("Error: too large a number.");
}

bool isNum(const std::string &input)
{
	for (std::string::size_type i = 0; i != input.length(); ++i)
	{
		if (input[i] == '.')
		{
			if (i - 1 >= 0 && !(input[i - 1] >= '0' && input[i - 1] <= '9'))
				return (false);
			if (i + 1 != input.length() && !(input[i - 1] >= '0' && input[i - 1] <= '9'))
				return (false);
		}
		else if (!isalpha(input[i]))
			return (false);
	}
	return (true);
}

int ft_stoi(const std::string &s)
{
	int res = 0;

	std::istringstream iss(s);
	if (!(iss >> res))
		throw BadInput();
	return (res);
}

double ft_stod(const std::string &s)
{
	double res = 0;

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

	std::vector<std::string> date = ft_split(input, '-');
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
	getline(dbFile, line);
	while (getline(dbFile, line))
	{
		std::vector<std::string> format = ft_split(line, ',');
		data[ft_stoepoc(format[0])] = ft_stod(format[1]);
	}
	dbFile.close();
	return (data);
}

bool input_error(const time_t &epoc, const double &value, const std::string &date)
{
	try
	{
		if (epoc < 0)
		{
			throw BadInput();
		}
		else if (value < 0)
		{
			throw NotPositiveNumber();
		}
		else if (value > 1000)
		{
			throw NumberTooLarge();
		}
		else if (epoc < ft_stoepoc("2009-01-02"))
		{
			throw BadInput();
		}
	}
	catch (const BadInput &e)
	{
		std::cout << e.what() << " => " << date << std::endl;
		return (true);
	}
	catch (const NotPositiveNumber &e)
	{
		std::cout << e.what() << std::endl;
		return (true);
	}
	catch (const NumberTooLarge &e)
	{
		std::cout << e.what() << std::endl;
		return (true);
	}
	return (false);
}

void findBitcoinPrice(const std::string &line, const db &data)
{
	std::vector<std::string> format = ft_split(line, '|');
	std::cout << std::flush;
	double value = ft_stod(format[1]);
	time_t date_epoc;
	try
	{
		date_epoc = ft_stoepoc(format[0]);
	}
	catch (BadInput &e)
	{
		std::cout << e.what() << " => " << format[0] << std::endl;
		return;
	}
	if (input_error(date_epoc, value, format[0]))
		return;
	for (db::const_iterator it = data.begin(); it != data.end(); ++it)
	{
		if (date_epoc > it->first)
			continue;
		else if (date_epoc == it->first)
		{
			std::cout << format[0] << " => " << value << " = " << value * it->second << std::endl;
			break;
		}
		else if (date_epoc < it->first)
		{
			--it;
			std::cout << format[0] << " => " << value << " = " << value * it->second << std::endl;
			break;
		}
	}
}
