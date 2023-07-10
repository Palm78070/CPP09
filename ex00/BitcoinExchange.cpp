/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:17:10 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/11 02:24:17 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char delim) : _delim(delim), _minDate(LONG_MAX), _maxDate(0), _badInput(0)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{
		this->_delim = src._delim;
		db tmp(src._data);
		this->_data = tmp;
		this->_minDate = src._minDate;
		this->_maxDate = src._maxDate;
		this->_badInput = src._badInput;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

const char *BitcoinExchange::IstringstreamImpossible::what() const throw()
{
	return ("Can not convert istringstream into integer");
}

const char *BitcoinExchange::BadInput::what() const throw()
{
	return ("Error: bad input ");
}

const char *BitcoinExchange::NotPositiveNumber::what() const throw()
{
	return ("Error: not a positive number.");
}

const char *BitcoinExchange::NumberTooLarge::what() const throw()
{
	return ("Error: too large a number.");
}

bool BitcoinExchange::isNum(const std::string &input)
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
				throw BadInput();
		}
		else if (!isdigit(input[i]) && input[i] != '.' && input[i] != ' ')
			throw BadInput();
	}
	return (true);
}

int BitcoinExchange::ft_stoi(const std::string &s)
{
	int res = 0;

	std::istringstream iss(s);
	if (!(iss >> res))
		throw BadInput();
	return (res);
}

double BitcoinExchange::ft_stod(const std::string &s)
{
	double res = 0;

	res = atof(s.c_str());
	return (res);
}

void BitcoinExchange::checkDateValid(char delim, int size, std::string &s)
{
	if (delim == '-')
	{
		if (size + 1 != 3)
		{
			this->_badInput = 0;
			throw BadInput();
		}
		int count_delim = 0;
		for (std::string::iterator i = s.begin(); i != s.end(); ++i)
		{
			if (count_delim >= 2)
				break;
			if (*i == '-')
				++count_delim;
			if (!(*i >= '0' && *i <= '9') && *i != '-')
			{
				this->_badInput = 0;
				throw BadInput();
			}
		}
	}
	if (size == 0)
	{
		this->_badInput = 0;
		throw BadInput();
	}
}

std::string *BitcoinExchange::ft_split(const std::string &s, char delim)
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
	checkDateValid(delim, size, str);
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

long long BitcoinExchange::ft_stoepoc(const std::string &input)
{
	std::string *date = this->ft_split(input, '-');
	this->_t.tm_year = this->ft_stoi(date[0]) - 1900;
	this->_t.tm_mon = this->ft_stoi(date[1]) - 1;
	this->_t.tm_mday = this->ft_stoi(date[2]);
	this->_t.tm_hour = 0;
	this->_t.tm_min = 0;
	this->_t.tm_sec = 0;
	delete[] date;
	return (mktime(&this->_t));
}

void BitcoinExchange::DbToMap(const std::string &filename)
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
		std::string *format = this->ft_split(line, ',');
		long long date = this->ft_stoepoc(format[0]);
		this->_minDate = (this->_minDate > date && date >= 0) ? date : this->_minDate;
		this->_maxDate = (this->_maxDate < date && date >= 0) ? date : this->_maxDate;
		data[date] = this->ft_stod(format[1]);
		delete[] format;
	}
	dbFile.close();
	this->_data = data;
}

void BitcoinExchange::check_input_error(const long long &epoc, const double &value)
{
	if (epoc < 0)
	{
		this->_badInput = 1;
		throw BadInput();
	}
	else if (value < 0)
		throw NotPositiveNumber();
	else if (value > 1000)
		throw NumberTooLarge();
	else if (epoc < this->_minDate)
	{
		this->_badInput = -1;
		throw BadInput();
	}
	else if (epoc > this->_maxDate)
	{
		this->_badInput = 2;
		throw BadInput();
	}
}

void BitcoinExchange::findBitcoinPrice(std::string *format, double value)
{
	long long date_epoc = this->ft_stoepoc(format[0]);
	this->check_input_error(date_epoc, value);
	for (db::const_iterator it = this->_data.begin(); it != this->_data.end(); ++it)
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

void BitcoinExchange::check_format(const std::string &line)
{
	std::string *format = NULL;
	double value;
	try
	{
		format = this->ft_split(line, '|');
		value = this->ft_stod(format[1]);
		this->isNum(format[1]);
		this->findBitcoinPrice(format, value);
		if (format)
			delete[] format;
	}
	catch (BadInput &e)
	{
		std::cout << e.what();
		if (this->_badInput == -1)
			std::cout << "(Date out of range, too old) => " << line << std::endl;
		else if (this->_badInput == 1)
			std::cout << "(Invalid date format) => " << line << std::endl;
		else if (this->_badInput == 2)
			std::cout << "(Date out of range, too late) => " << line << std::endl;
		else
			std::cout << "correct format is [Year-Month-Day | float/positive integer] => " << line << std::endl;
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
