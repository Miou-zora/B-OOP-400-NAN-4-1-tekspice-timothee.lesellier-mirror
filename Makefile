##
## EPITECH PROJECT, 2023
## B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
## File description:
## Makefile
##

SRC			=

MAIN		=	src/main.cpp

OBJ			=	$(SRC:%.cpp=%.o)

OBJ_MAIN	=	$(MAIN:%.cpp=%.o)

TESTS		=

TESTS_OBJ	=	$(TESTS:%.cpp=%.o)

CC			=	g++

CFALGS		=	-Wall -Wextra -std=c++20

TESTS_FLAGS	=	--coverage -lcriterion

INCLUDE		=	-I./include

TEST_BINARY	=	test_bin

NAME		=	nanotekspice

RM			=	rm -rf

%.o:	%.cpp
		$(CC) $(CFALGS) $(INCLUDE) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
		$(CC) -o $(NAME) $(OBJ_MAIN) $(OBJ) $(CFALGS) $(INCLUDE)

tests_run:	tclean $(TESTS_OBJ)
		$(CC) $(SRC) $(TESTS_OBJ) $(TESTS_FLAGS) $(LBFLAGS) \
		-o $(TEST_BINARY) $(CFALGS) $(INCLUDE)
		./$(TEST_BINARY)
		mv *.gcno tests/
		mv *.gcda tests/
		gcovr -e tests -u
		gcovr -e tests -bu
		./tests/memory_tests/memory_tests.sh
		gcovr --html-details -o tests/html/index.html -e tests -bu \
			--html-theme=blue

clean:
		$(RM) tests/html/*
		$(RM) tests/criterion_tests/$(TEST_BINARY)
		$(RM) $(OBJ)
		$(RM) $(OBJ_MAIN)
		$(RM) $(TESTS_OBJ)

tclean:
		$(RM) tests/*.gcno
		$(RM) tests/*.gcda

fclean:	clean
		$(RM) $(TEST_BINARY)
		$(RM) $(NAME)

re:		fclean all

debug:	CFLAGS += -g
debug:	re

.PHONY:	all clean fclean re tclean debug tests_run $(NAME) %.o
