/*
** my_fonction.h :D
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov 30 15:49:28 2015 David Zeng
** Last update Tue Mar  8 14:37:12 2016 David
*/

#include "my.h"
#include "my_list.h"
#include <stdlib.h>
#include <ncurses/curses.h>

#ifndef MY_FONCTION_H_
# define MY_FONCTION_H_

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

/* GET TETRIMINOS */
typedef struct		s_mino
{
  int			width;
  int			height;
  int			color;
  int			error;
  char			*shape;
  char			name[256];
}			t_mino;

t_list			*my_get_tetrimino();
int			my_pos_add(t_list *list, void *data, int position);
void			my_sort_add(t_list *list, void *data);
int			my_get_mino_shape(t_mino *mino, char *str);
/* GET TETRIMINOS END */

/* PARSING */
typedef struct		s_setup
{
  int			level;
  char			left[100];
  char			right[100];
  char			turn[100];
  char			drop[100];
  char			quit[100];
  char			pause[100];
  int			width;
  int			height;
  int			next;
  int			debug;
}			t_setup;

typedef struct		s_ref
{
  char			ref1[4];
  char			ref2[16];
}			t_ref;

t_setup			*my_get_setup(int argc, char **argv);
char			*my_get_param(int argc, char **argv, char *ref);
char			*my_get_long_param(int argc, char **argv, char *ref);
int			my_get_keyboard(int argc, char **argv, t_setup *new);
/* PARSING END */

/* OTHER */
void			my_free_node_data(t_mino *mino);
void			my_aff_help(char *str);
void			my_aff_tetrimino(t_list *tetrimino);
void			my_aff_debug(t_setup *setup, t_list *tetrimino);
/* OTHER END */

/* SCREEN */
void	aff_screen(t_list *tetrimino, t_setup *setup);
/* SCREEN END */

#endif /* !MY_FONCTION_H_ */
