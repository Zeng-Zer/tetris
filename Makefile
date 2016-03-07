##
## Makefile for Makefile in /home/zeng_d/test/10/test
##
## Made by David Zeng
## Login   <zeng_d@epitech.net>
##
## Started on  Mon Oct 12 13:31:18 2015 David Zeng
## Last update Mon Mar  7 05:43:11 2016 David
##

SRC	= main.c \
	  get_tetrimino/my_get_tetrimino.c \
	  get_tetrimino/my_pos_add.c \
	  get_tetrimino/my_sort_add.c \
	  get_tetrimino/my_get_mino_shape.c \
	  misc/my_aff_help.c \
	  misc/my_aff_debug.c \
	  misc/my_aff_tetrimino.c \
	  parser/parsing.c \
	  parser/my_get_param.c \
	  parser/my_get_keyboard.c \
	  list/my_add_first.c \
	  list/my_add_list.c \
	  list/my_declare_list.c \
	  list/my_del_node.c \
	  list/my_free_all.c \
	  list/my_free_list.c \
	  list/my_show_list.c \

NAME	= tetris

LIB	= libmy.a

CC	= gcc

OBJ	= $(SRC:.c=.o)

CFLAGS	=  -L./lib -lmy -I./include/ -g -W -Werror -Wall -lncurses

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
