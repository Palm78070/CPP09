/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:39:59 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/16 20:34:10 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::string &input) : _input(input)
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	if (this != &src)
	{
		this->_input = src._input;
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
}

PmergeMe::~PmergeMe()
{
}
