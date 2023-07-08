/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:33:44 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/08 01:41:29 by rthammat         ###   ########.fr       */
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
time_t ft_stoepoc(const std::string &input);
std::string *ft_split(const std::string &s, char delim);

typedef std::map<std::time_t, double> db;

db DbToMap(const std::string &filename);
void findBitcoinPrice(std::string *format, double value, const db &data);

#endif
