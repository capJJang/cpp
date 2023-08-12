NAME = main

CC = g++

CXXFLAGS = -Wall -Wextra -Werror -g

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

TESTFILE = test.txt

all : $(NAME) $(TESTFILE)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TESTFILE) :
	@echo "qwer" > $(TESTFILE)
	@echo "asdf" >> $(TESTFILE)
	@echo "zxcv" >> $(TESTFILE)

clean :
	rm -f $(OBJS)
	rm -f $(TESTFILE)

fclean :
	make clean
	rm -f $(NAME)
	rm -r $(TESTFILE).replace

re :
	make fclean
	make all

.PHONY : all clean fclean re
