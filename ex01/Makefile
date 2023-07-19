# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 22:34:37 by rthammat          #+#    #+#              #
#    Updated: 2023/07/20 02:56:08 by rthammat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ./RPN

CXX := c++

# CXXFLAGS := -Wall -Werror -Wextra -fsanitize=address --std=c++98 -g
CXXFLAGS := -Wall -Werror -Wextra --std=c++98 -g

SRCS := main.cpp \
		RPN.cpp \

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
