# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 19:19:19 by rthammat          #+#    #+#              #
#    Updated: 2023/07/10 22:35:13 by rthammat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ./btc

CXX := c++

#CXXFLAGS := -Wall -Werror -Wextra -fsanitize=address --std=c++98 -g
CXXFLAGS := -Wall -Werror -Wextra --std=c++98 -g

SRCS := main.cpp \
		BitcoinExchange.cpp \

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf *.o *.dSYM

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
