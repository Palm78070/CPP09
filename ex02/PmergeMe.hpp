/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:32:25 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/19 18:18:43 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <algorithm>

class PmergeMe
{
public:
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	~PmergeMe();

	void merge_insert_sort(void);
	std::string *ft_split(const std::string &s, char delim);
	bool isNum(const std::string &input);
	int ft_stoi(const std::string &s);
	int jacobsthal(int n);
	double ft_time(time_t start, time_t end);

	template <typename T>
	int binarySearch(T &c, int n, int l, int h)
	{
		if (h <= l)
			return ((n > c[l]) ? (l + 1) : l);
		int mid = (l + h) / 2;
		if (n == c[mid])
			return (mid + 1);
		if (n > c[mid])
			return (binarySearch(c, n, mid + 1, h));
		return (binarySearch(c, n, l, mid - 1));
	}

	template <typename T>
	int jacobsthalSearch(T &c, int n, int l, int h)
	{
		int jn = jacobsthal(n);
		if (h <= l)
			return ((jn > jacobsthal(c[l])) ? (l + 1) : l);
		int mid = (l + h) / 2;
		if (jn == jacobsthal(c[mid]))
			return (mid + 1);
		if (jn > jacobsthal(c[mid]))
			return (jacobsthalSearch(c, n, mid + 1, h));
		return (jacobsthalSearch(c, n, l, mid - 1));
	}

	template <typename T>
	void addMainChain(T &c, int n)
	{
		if (c.empty())
		{
			c.push_back(n);
			return;
		}
		int len = c.size();
		int end = len - 1;
		int loc = binarySearch(c, n, 0, end);
		c.insert(c.begin() + loc, n);
	}

	template <typename T>
	void addSubChain(T &c, int n)
	{
		if (c.empty())
		{
			c.push_back(n);
			return;
		}
		int len = c.size();
		int end = len - 1;
		int loc = jacobsthalSearch(c, n, 0, end);
		c.insert(c.begin() + loc, n);
	}

	template <typename T>
	void ft_pairing(T &c, T &main, T &sub, int i1, int i2)
	{
		if (c[i2] < c[i1])
		{
			addMainChain(main, c[i2]);
			addSubChain(sub, c[i1]);
		}
		else
		{
			addMainChain(main, c[i1]);
			addSubChain(sub, c[i2]);
		}
	}

	template <typename T>
	void printContainer(T &c)
	{
		int end = c.size();
		int flag = 0;
		if (end > 20)
		{
			end = 4;
			flag = 1;
		}
		for (int i = 0; i < end; i++)
			std::cout << c[i] << " ";
		if (flag)
			std::cout << "[...]";
		std::cout << std::endl;
	}

	class NegativeNumber : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NotInteger : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	std::vector<int> _vec;
	std::deque<int> _deq;
	int _len;
};

#endif
