/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:53:38 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/19 18:03:06 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string &input) : _input(input)
{
	if (this->_input.empty())
		throw IncompleteInput();
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

const char *RPN::InputError::what() const throw()
{
	return ("Input error: have character that is not digit number or math operator");
}

const char *RPN::IncompleteInput::what() const throw()
{
	return ("Incomplete input: No number or operator to calculate RPN");
}

const char *RPN::UndefineResult::what() const throw()
{
	return ("Result is undefined: please check input => maybe divide by 0");
}

const char *RPN::OutOfRange::what() const throw()
{
	return ("Number is out of range: number have to be less than 10");
}

int RPN::ft_stoi(const std::string &s)
{
	double res = atof(s.c_str());
	if (res >= 10)
		throw OutOfRange();
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
	if (this->_stack.empty())
		throw IncompleteInput();
	int second = this->_stack.top();
	this->_stack.pop();
	int first = this->_stack.top();

	if (this->_stack.empty())
		return;
	if (c == '+')
		this->_stack.top() = first + second;
	else if (c == '-')
		this->_stack.top() = first - second;
	else if (c == '*')
		this->_stack.top() = first * second;
	else if (c == '/')
	{
		if (second == 0)
			throw UndefineResult();
		this->_stack.top() = first / second;
	}
}

bool RPN::checkError(char c)
{
	if (c == '\0')
		throw IncompleteInput();
	if (!this->ft_isdigit(c) && !this->isoperator(c) && !this->ft_isspace(c))
		throw InputError();
	return (true);
}

void RPN::readRPN(void)
{
	int tmp = 0;
	int op = 0;
	for (std::string::iterator it = this->_input.begin(); it != this->_input.end(); ++it)
	{
		while (this->checkError(*it) && this->ft_isspace(*it))
			++it;
		if (it == this->_input.end())
			break;
		if (this->issignnum(it, this->_input) || this->ft_isdigit(*it))
		{
			std::string::iterator end = it;
			while (this->checkError(*end) && end != this->_input.end() && !this->ft_isspace(*end))
				++end;
			tmp = this->ft_stoi(this->_input.substr(it - this->_input.begin(), this->_input.begin() - end));
			this->_stack.push(tmp);
			it = end;
			if (it == this->_input.end())
				break;
		}
		else if (this->isoperator(*it))
		{
			op += 1;
			this->calRPN(*it);
			++it;
		}
		if (it == this->_input.end())
			break;
	}
	if (!op)
		throw IncompleteInput();
	std::cout << this->_stack.top() << std::endl;
}
