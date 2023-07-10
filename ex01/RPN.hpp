/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:47:24 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/10 23:55:17 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>

class RPN
{
public:
	RPN(const std::string &input);
	RPN(const RPN &src);
	RPN &operator=(const RPN &src);
	~RPN();

private:
	std::string _input;
};

#endif
