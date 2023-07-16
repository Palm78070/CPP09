/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:39:59 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/16 18:55:30 by rthammat         ###   ########.fr       */
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
		if ()
		this->_vec = src._vec;
		this->_lst = src._lst;
	}
}

PmergeMe::~PmergeMe()
{
}
