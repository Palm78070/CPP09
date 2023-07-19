/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:39:59 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/20 02:50:57 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv) : _len(argc - 1)
{
	for (int i = 1; i <= this->_len; ++i)
	{
		this->_vec.push_back(ft_stoi(argv[i]));
		this->_deq.push_back(this->_vec[i - 1]);
	}
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		this->_len = src._len;
		if (!this->_vec.empty())
			this->_vec.clear();
		for (int i = 0; i < src._len; ++i)
			this->_vec.push_back(src._vec[i]);

		if (!this->_deq.empty())
			this->_deq.clear();
		std::deque<int> tmp = src._deq;
		for (std::deque<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
			this->_deq.push_back(*it);
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

bool PmergeMe::isNum(const std::string &input)
{
	if (input.empty())
	{
		throw NotInteger();
	}
	std::string::size_type i = 0;
	while (i != input.length() && (input[i] == '+' || input[i] == '-'))
		++i;
	while (i != input.length())
	{
		if (!(input[i] >= '0' && input[i] <= '9'))
			return (false);
		++i;
	}
	return (true);
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
	if (!this->isNum(s))
		throw NotInteger();
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

int PmergeMe::jacobsthal(int n)
{
	int x = 0;
	int y = 1;

	if (n == 0)
		return (0);
	int pos = 1;
	while (y < n)
	{
		unsigned int next = y + (2 * x);
		x = y;
		y = next;
		++pos;
	}
	if (y >= n)
		return (pos);
	else
		return (-1);
}

double PmergeMe::ft_time(time_t start, time_t end)
{
	double elasp_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	return (elasp_time * 1000000);
}

void PmergeMe::merge_insert_sort(void)
{
	std::vector<int> mainV;
	std::vector<int> subV;
	std::deque<int> mainD;
	std::deque<int> subD;

	try
	{
		std::cout << "Before: ";
		this->printContainer(this->_vec);
		int i = 0;
		clock_t start = clock();
		while (i < this->_len)
		{
			if (this->_len % 2 != 0 && i == this->_len - 1)
			{
				this->addSubChain(subV, this->_vec[i]);
				++i;
			}
			else
			{
				this->ft_pairing(this->_vec, mainV, subV, i, i + 1);
				i += 2;
			}
		}
		int len2 = subV.size();
		for (int i = 0; i < len2; ++i)
			this->addMainChain(mainV, subV[i]);
		clock_t end = clock();
		double timeV = this->ft_time(start, end);
		std::cout << "After (vector) ";
		this->printContainer(mainV);
		i = 0;
		start = clock();
		while (i < this->_len)
		{
			if (this->_len % 2 != 0 && i == this->_len - 1)
			{
				this->addSubChain(subD, this->_deq[i]);
				++i;
			}
			else
			{
				this->ft_pairing(this->_deq, mainD, subD, i, i + 1);
				i += 2;
			}
		}
		len2 = subD.size();
		for (int i = 0; i < len2; ++i)
			this->addMainChain(mainD, subD[i]);
		end = clock();
		double timeD = this->ft_time(start, end);
		std::cout << "After (deque) ";
		this->printContainer(mainD);
		std::cout << "time to process a range of " << this->_vec.size() << " elements with std::vector : " << timeV << "us" << std::endl;
		std::cout << "time to process a range of " << this->_deq.size() << " elements with std::vector : " << timeD << "us" << std::endl;
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
