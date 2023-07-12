/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:47:24 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/12 22:24:48 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

class RPN
{
public:
	RPN(const std::string &input);
	RPN(const RPN &src);
	RPN &operator=(const RPN &src);
	~RPN();

	int ft_stoi(const std::string &s);
	bool ft_isdigit(char c);
	bool ft_isspace(char c);
	bool isoperator(char c);
	bool issignnum(std::string::iterator &it, std::string &line);
	void printStack();
	void readRPN(void);
	void calRPN(char cs);
	bool checkError(char c);

	class OutOfRange : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class InputError : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class UndefineResult : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NoNumber : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	std::string _input;
	std::stack<int> _stack;
};

#endif
