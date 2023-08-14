NAME = main

CC = g++

CXXFLAGS = -Wall -Wextra -Werror -g

SRCS = main.cpp Harl.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME) $(TESTFILE)

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
