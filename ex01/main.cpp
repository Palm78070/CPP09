/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:07:02 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/12 22:26:37 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw(std::runtime_error("invalid argument: ./RPN <input_file>"));
		RPN rpn(argv[1]);
		rpn.readRPN();
	}
	catch (const RPN::UndefineResult &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	catch (const RPN::InputError &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	catch (const RPN::OutOfRange &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
