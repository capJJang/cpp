# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: segan <segan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 03:57:56 by segan             #+#    #+#              #
#    Updated: 2023/07/21 03:08:47 by segan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp phoneBook.cpp contact.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
