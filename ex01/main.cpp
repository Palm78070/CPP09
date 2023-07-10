/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:07:02 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/10 23:50:16 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw(std::runtime_error("invalid argument: ./RPN <input_file>"));
		std::string tmp(argv[1]);
		for (std::string::iterator it = tmp.begin(); it != tmp.end(); ++it)
			std::cout << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
