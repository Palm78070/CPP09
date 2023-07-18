/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:32:25 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/18 01:37:09 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <sstream>
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
	void addMainChain(int n);
	void addSubChain(int n);

	template <typename T>
	void ft_pairing(T &c, int i1, int i2)
	{
		if (c[i2] < c[i1])
			std::swap(c[i1], c[i2]);
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
	// std::string _input;
	std::vector<int> _vec;
	std::list<int> _lst;
	int _len;
};

#endif
