/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:39:59 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/16 23:02:28 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::string &input) : _input(input), _len(0)
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		this->_input = src._input;
		this->_len = src._len;
		if (!this->_vec.empty())
		{
			this->_vec.clear();
			for (size_t i = 0; i < this->_vec.size(); ++i)
				this->_vec.push_back(src._vec[i]);
		}
		if (!this->_lst.empty())
		{
			this->_lst.clear();
			std::list<int> tmp = src._lst;
			for (std::list<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
				this->_lst.push_back(*it);
			this->_lst = src._lst;
		}
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

const char *PmergeMe::NegativeNumber::what() const throw()
{
	return ("Error: Negative number");
}

const char *PmergeMe::NotInteger::what() const throw()
{
	return ("Error: Not integer");
}

std::string *PmergeMe::ft_split(const std::string &s, char delim)
{
	std::string *res;
	std::string str = s;
	std::string::size_type start = 0;
	std::string::size_type end = str.find(delim);

	for (std::string::iterator i = str.begin(); i != str.end(); ++i)
	{
		if (*i == delim)
			this->_len += 1;
	}
	if (this->_len == 0)
		return (NULL);
	res = new std::string[this->_len + 1];
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

int PmergeMe::ft_stoi(const std::string &s)
{
	double res = atof(s.c_str());
	std::istringstream iss(s);

	if (!(iss >> res))
		throw NotInteger();

	if (res < 0)
		throw NegativeNumber();
	if (res < -2147483648 || res > 2147483647)
		throw NotInteger();
	return (res);
}

void PmergeMe::merge_insert_sort(void)
{
	try
	{
		std::string *line = this->ft_split(this->_input, ' ');
		this->_len += 1;
		if (line == NULL)
		{
			ft_stoi(this->_input);
			////Only 1 number
		}
		for (int i = 0; i < this->_len; ++i)
		{
			this->_vec.push_back(ft_stoi(line[i]));
			this->_lst.push_back(this->_vec[i]);
		}
		for (int i = 0; i < this->_len; ++i)
			std::cout << this->_vec[i] << std::endl;
		for (std::list<int>::iterator it = this->_lst.begin(); it != this->_lst.end(); ++it)
			std::cout << *it << std::endl;
	}
	catch (const NegativeNumber &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const NotInteger &e)
	{
		std::cout << e.what() << std::endl;
	}
}
