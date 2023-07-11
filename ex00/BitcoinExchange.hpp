/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:33:44 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/11 02:52:20 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <string>
#include <limits>
#include <iomanip>
#include <cfloat>
#include <ctype.h>

typedef std::map<long long, double> db;

class BitcoinExchange
{
public:
	BitcoinExchange(char delim);
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();
	class IstringstreamImpossible : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class BadInput : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NotPositiveNumber : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NumberTooLarge : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	bool isNum(const std::string &input);
	double ft_stod(const std::string &s);
	int ft_stoi(const std::string &s);
	long long ft_stoepoc(const std::string &input);
	std::string *ft_split(const std::string &s, char delim);
	void check_input_error(const long long &epoc, const double &value);

	void DbToMap(const std::string &filename);
	void findBitcoinPrice(std::string *format, double value);
	void check_format(const std::string &line);
	void checkDateValid(char delim, int size, std::string &s);
	// void checkDateValid(char delim, std::string &s);

private:
	char _delim;
	db _data;
	long long _minDate;
	long long _maxDate;
	int _badInput;
	struct tm _t;
};

#endif
