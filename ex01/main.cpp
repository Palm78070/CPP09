/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:07:02 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/12 20:45:41 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void dummy(std::string &s)
{
	RPN dummy(s);
	std::string::iterator end = s.begin();
	while (end != s.end() && !isspace(*end))
		++end;
	std::cout << dummy.ft_stoi(s.substr(0, s.begin() - end)) << std::endl;
}

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw(std::runtime_error("invalid argument: ./RPN <input_file>"));
		RPN rpn(argv[1]);
		std::cout << "Test dummy" << std::endl;
		rpn.readRPN();
		std::cout << "try print stack" << std::endl;
		rpn.printStack();
		std::cout << "try print stack again" << std::endl;
		rpn.printStack();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
