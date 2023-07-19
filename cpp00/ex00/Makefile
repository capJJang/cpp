# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segan <segan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 03:57:56 by segan             #+#    #+#              #
#    Updated: 2023/07/20 04:37:34 by segan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megahone

CC = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megahone.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OJBS)
	$(CC) $(CXXFLAGS) -O $(NAME) $(OBJS)

%.o : %.cpp
	$(CC) $(DEBUG) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.Phony : all clean fclean re
