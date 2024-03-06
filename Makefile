##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## emacs
##

SRC     	=       src/main.c					\
					src/player_one_engine.c		\
					src/player_two_engine.c		\
					src/signals.c				\
					src/file_managment.c		\
					src/draw_output.c			\
					src/check_boat_conformity.c	\

OBJ			=		$(SRC:.c=.o)

CFLAGS		+=		-Wall -Wextra

LIBFLAGS	=		-I src/lib/include/my_lib.h	\
					-L .						\
					-l reworked					\


NAME		=		my_navy

NAME_LIB	=		libreworked.a

TEST		=		unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME_LIB) $(OBJ)
	$(MAKE) -C src/lib
	mv src/lib/libreworked.a .
	gcc -o $(NAME) $(OBJ) $(LIBFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f main.o
	make clean -C src/lib
	rm -f */*~
	rm -f *~

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_LIB)
	rm -f *.a
	rm -f $(TEST)*

debug:	WARNFLAGS += -g3
debug:	re

re:
	$(MAKE) fclean
	$(MAKE) all

$(TEST):	clean all
	gcc tests/test.c -o $(TEST) --coverage -lcriterion $(WARNFLAGS)

test:	$(TEST)
	./$(TEST)

cov:	test
	gcovr --exclude tests/
