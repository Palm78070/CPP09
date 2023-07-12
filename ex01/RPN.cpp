/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:53:38 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/12 21:00:40 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string &input) : _input(input)
{
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		this->_input = src._input;
		std::stack<int> tmp = src._stack;
		while (!this->_stack.empty())
			this->_stack.pop();
		while (!tmp.empty())
		{
			this->_stack.push(tmp.top());
			tmp.pop();
		}
	}
	return (*this);
}

RPN::~RPN()
{
}

const char *RPN::IstringstreamImpossible::what() const throw()
{
	return ("Can not convert istringstream into integer");
}

const char *RPN::InputError::what() const throw()
{
	return ("Input error: not digit number or math operator");
}

int RPN::ft_stoi(const std::string &s)
{
	std::cout << "s is " << s << std::endl;
	int res = 0;

	std::istringstream iss(s);
	if (!(iss >> res))
		throw IstringstreamImpossible();
	return (res);
}

bool RPN::ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool RPN::ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ');
}

bool RPN::isoperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::issignnum(std::string::iterator &it, std::string &line)
{
	if (!this->isoperator(*it))
		return (false);
	if ((it + 1) == line.end() || !this->ft_isdigit(*(it + 1)))
		return (false);
	return (true);
}

void RPN::printStack(void)
{
	std::stack<int> tmp = this->_stack;
	while (!tmp.empty())
	{
		std::cout << tmp.top() << std::endl;
		tmp.pop();
	}
}

void RPN::calRPN(char c)
{
	int second = this->_stack.top();
	this->_stack.pop();
	int first = this->_stack.top();
	std::cout << "first: " << first << " second: " << second << std::endl;
	if (this->_stack.empty())
		return;
	if (c == '+')
		this->_stack.top() = first + second;
	else if (c == '-')
		this->_stack.top() = first - second;
	else if (c == '*')
		this->_stack.top() = first * second;
	else if (c == '/')
		this->_stack.top() = first / second;
	std::cout << "res is " << this->_stack.top() << std::endl;
}

void RPN::readRPN(void)
{
	int tmp = 0;
	for (std::string::iterator it = this->_input.begin(); it != this->_input.end(); ++it)
	{
		while (this->ft_isspace(*it))
			++it;
		if (it == this->_input.end())
			break;
		if (!this->ft_isdigit(*it) && !this->isoperator(*it))
		{
			std::cout << "error char is " << *it << std::endl;
			throw InputError();
		}
		if (this->issignnum(it, this->_input) || this->ft_isdigit(*it))
		{
			std::string::iterator end = it;
			while (end != this->_input.end() && !this->ft_isspace(*end))
				++end;
			tmp = this->ft_stoi(this->_input.substr(it - this->_input.begin(), this->_input.begin() - end));
			this->_stack.push(tmp);
			it = end;
			if (it == this->_input.end())
				break;
		}
		else if (this->isoperator(*it))
		{
			this->calRPN(*it);
			++it;
		}
		if (it == this->_input.end())
			break;
	}
}
