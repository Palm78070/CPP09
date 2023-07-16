# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 18:29:26 by rthammat          #+#    #+#              #
#    Updated: 2023/07/16 22:44:51 by rthammat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ./PmergeMe

CXX := c++

CXXFLAGS := -Wall -Werror -Wextra -fsanitize=address --std=c++98 -g
#CXXFLAGS := -Wall -Werror -Wextra --std=c++98 -g

SRCS := main.cpp \
		PmergeMe.cpp \

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
