/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:33:44 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/06 22:03:21 by rthammat         ###   ########.fr       */
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
#include <vector>
#include <limits>
#include <iomanip>
#include <cfloat>

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

double ft_stod(const std::string &s);
int ft_stoi(const std::string &s);
time_t ft_stoepoc(const std::string &input);
std::vector<std::string> ft_split(const std::string &s, char delim);

typedef std::map<std::time_t, double> db;

db DbToMap(const std::string &filename);
void findBitcoinPrice(const std::string &line, db &data);

#endif
