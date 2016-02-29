##
## Makefile for Makefile in /home/zeng_d/test/10/test
##
## Made by David Zeng
## Login   <zeng_d@epitech.net>
##
## Started on  Mon Oct 12 13:31:18 2015 David Zeng
## Last update Sun Feb 28 14:10:08 2016 David Zeng
##

SRC	= main.c \

NAME	= a.out

LIB	= libmy.a

CC	= gcc

OBJ	= $(SRC:.c=.o)

CFLAGS	=  -L./lib -lmy -I./include/ -g -W -Werror -Wall

PATHS	= ./lib/my/

all: 	  ./lib/$(LIB) $(NAME)

$(NAME):  $(OBJ)
	  @$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

./lib/$(LIB):
	  @$(MAKE) -C $(PATHS) yo

clean:
	  @rm -f $(OBJ)

fclean:	  clean
	  @rm -f $(NAME)

re:	  fclean all

.PHONY:	  all clean fclean re

yo:	  all clean

.c.o:
	  @$(CC) -c $< -o $@ $(CFLAGS)
