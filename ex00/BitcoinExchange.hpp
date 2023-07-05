/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:33:44 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/05 20:53:14 by rthammat         ###   ########.fr       */
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

double ft_stod(const std::string &s);
int ft_stoi(const std::string &s);
time_t ft_stoepoc(const std::string &input);
std::vector<std::string> ft_split(const std::string &s, char delim);
void printDouble(double d);

typedef std::map<std::time_t, double> db;

db DbToMap(const std::string &filename);

#endif
