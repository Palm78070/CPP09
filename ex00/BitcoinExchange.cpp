/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:17:10 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/09 01:23:05 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char *IstringstreamImpossible::what() const throw()
{
	return ("Can not convert istringstream into integer");
}

const char *BadInput::what() const throw()
{
	return ("Error: bad input => ");
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
		while (i != input.length() && (input[i] == '-' || input[i] == '+'))
			++i;
		if (input[i] == '.')
		{
			int head_tail = (i == 0 || i == input.length() - 1);
			int front = i - 1 >= 0 && !(input[i - 1] >= '0' && input[i - 1] <= '9');
			int back = i + 1 != input.length() && !(input[i - 1] >= '0' && input[i - 1] <= '9');
			if (head_tail || front || back)
			{
				throw BadInput();
				return (false);
			}
		}
		else if (!isdigit(input[i]) && input[i] != '.' && input[i] != ' ')
		{
			throw BadInput();
			return (false);
		}
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

std::string *ft_split(const std::string &s, char delim)
{
	std::string *res;
	std::string str = s;
	int size = 0;
	std::string::size_type start = 0;
	std::string::size_type end = str.find(delim);

	for (std::string::iterator i = str.begin(); i != str.end(); ++i)
	{
		if (*i == delim)
			++size;
	}
	if (size == 0 || (delim == '-' && size + 1 != 3))
	{
		throw BadInput();
		// return (NULL);
	}
	res = new std::string[size + 1];
	int i = 0;
	while (end != std::string::npos)
	{
		res[i++] = str.substr(start, end - start);
		start = end + 1;
		end = str.find(delim, start);
	}
	res[i] = str.substr(start);
	return (res);
}

time_t ft_stoepoc(const std::string &input)
{
	struct tm t;

	std::string *date = ft_split(input, '-');
	t.tm_year = ft_stoi(date[0]) - 1900;
	t.tm_mon = ft_stoi(date[1]) - 1;
	t.tm_mday = ft_stoi(date[2]);
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;
	delete[] date;
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
		std::string *format = ft_split(line, ',');
		data[ft_stoepoc(format[0])] = ft_stod(format[1]);
		delete[] format;
	}
	dbFile.close();
	return (data);
}

void check_input_error(const time_t &epoc, const double &value)
{
	if (epoc < 0)
		throw BadInput();
	else if (value < 0)
		throw NotPositiveNumber();
	else if (value > 1000)
		throw NumberTooLarge();
	else if (epoc < ft_stoepoc("2009-01-02"))
		throw BadInput();
}

void findBitcoinPrice(std::string *format, double value, const db &data)
{
	std::cout << std::flush;
	time_t date_epoc = ft_stoepoc(format[0]);
	// date_epoc = 1293987600;
	check_input_error(date_epoc, value);
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
