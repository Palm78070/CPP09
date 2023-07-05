/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:33:44 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/05 12:45:30 by rthammat         ###   ########.fr       */
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

class IstringstreamImpossible : public std::exception
{
public:
	virtual const char *what() const throw();
};

float ft_stof(const std::string &s);
int ft_stoi(const std::string &s);
int getYear(std::string s);
int getMonth(std::string s);
int getDay(std::string s);
std::vector<std::string> ft_split(const std::string &s, char delim);

typedef std::map<std::time_t, double> db;

db DbToMap(const std::string &filename);

#endif
