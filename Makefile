##
## EPITECH PROJECT, 2023
## B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
## File description:
## Makefile
##

SRC_NTS_DIR	=	src/nts

SRC			=	Component/AComponent.cpp					\
				Builder.cpp									\
				Component/Chip/AndComponent.cpp				\
				Component/Circuit.cpp						\
				Shell.cpp									\
				Component/IO/Input.cpp						\
				Component/IO/Output.cpp						\
				Component/IO/Clock.cpp						\
				Component/Boolean/UndefinedComponent.cpp	\
				Component/Chip/Component4081.cpp			\
				Component/Chip/OrComponent.cpp				\
				Component/Chip/NotComponent.cpp				\
				Component/Chip/XorComponent.cpp				\
				Component/Chip/NandComponent.cpp			\
				Component/Chip/NorComponent.cpp				\
				Component/Chip/Component4071.cpp			\
				Component/Chip/Component4069.cpp			\
				Component/Chip/Component4030.cpp			\
				Component/Chip/Component4001.cpp			\
				Component/Chip/Component4011.cpp			\
				Component/Chip/DLatchComponent.cpp			\
				Component/Chip/SRLatchComponent.cpp			\
				Component/Chip/SAdder.cpp					\
				Component/Chip/Component4008.cpp			\
				Component/Chip/InvSRNLatchComponent.cpp		\

SRC			:=	$(addprefix $(SRC_NTS_DIR)/, $(SRC))

MAIN		=	src/main.cpp

OBJ			=	$(SRC:%.cpp=%.o)

OBJ_MAIN	=	$(MAIN:%.cpp=%.o)

TESTS		=	ComponentFactoryTests.cpp						\
				Component/LinkTests.cpp							\
				BuilderTests.cpp								\
				Shell.cpp										\
				Component/Chip/AndComponentTests.cpp			\
				Component/IO/OutputTests.cpp					\
				Component/IO/InputTests.cpp						\
				Component/IO/ClockTests.cpp						\
				Component/Boolean/UndefinedComponentTests.cpp	\
				Component/AComponentTests.cpp					\
				Component/CircuitTests.cpp						\
				Component/Chip/Component4081.cpp				\
				Component/Chip/OrComponentTests.cpp 			\
				Component/Chip/NotComponentTests.cpp			\
				Component/Chip/XorComponentTests.cpp			\
				Component/Chip/NandComponentTests.cpp			\
				Component/Chip/NorComponentTests.cpp			\
				Component/Chip/Component4071.cpp				\
				Component/Chip/Component4069.cpp				\
				Component/Chip/Component4030.cpp				\
				Component/Chip/Component4001.cpp				\
				Component/Chip/Component4011.cpp				\
				Component/Chip/DLatchComponentTests.cpp			\
				Component/Chip/SRLatchComponentTests.cpp		\
				Component/Chip/SAdderTests.cpp				    \
				Component/Chip/Component4008.cpp				\
				Component/Chip/InvSRNLatchComponentTests.cpp	\

TESTS		:=	$(addprefix tests/, $(TESTS))

TESTS_OBJ	=	$(TESTS:%.cpp=%.o)

CC			=	g++

CFALGS		=	-Wall -Wextra -std=c++20 -Wshadow -Wpedantic

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

debug:	CFALGS += -g
debug:	re

tests_run: $(TESTS_OBJ)
		$(CC) $(SRC) $(TESTS_OBJ) $(TESTS_FLAGS) $(LBFLAGS) \
		-o $(TEST_BINARY) $(CFALGS) $(INCLUDE)
		./$(TEST_BINARY)
		mv *.gcno tests/
		mv *.gcda tests/
		gcovr -e tests -u
		gcovr -e tests -bu
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
