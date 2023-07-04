/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:33:44 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/05 01:31:23 by rthammat         ###   ########.fr       */
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

class IstringstreamImpossible : public std::exception
{
public:
	virtual const char *what() const throw();
};

int getYear(std::string s);
int getMonth(std::string s);
int getDay(std::string s);

typedef std::map<std::time_t, double> db;

db DbToMap(const std::string &filename);

#endif
