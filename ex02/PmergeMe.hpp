/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:32:25 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/16 22:55:03 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <sstream>

class PmergeMe
{
	public:
		PmergeMe(const std::string &input);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void merge_insert_sort(void);
		std::string *ft_split(const std::string &s, char delim);
		bool isNum(const std::string &input);
		int ft_stoi(const std::string &s);

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
		std::string _input;
		std::vector<int> _vec;
		std::list<int> _lst;
		int _len;
};

#endif
