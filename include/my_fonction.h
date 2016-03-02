/*
** my_fonction.h :D
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov 30 15:49:28 2015 David Zeng
** Last update Wed Mar  2 01:37:01 2016 David Zeng
*/

#include "my.h"
#include "my_list.h"
#include <stdlib.h>
#include <ncurses/curses.h>

#ifndef MY_FONCTION_H_
# define MY_FONCTION_H_

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
  int			left;
  int			right;
  int			turn;
  int			drop;
  int			quit;
  int			pause;
  int			width;
  int			height;
  int			next;
  int			debug;
}			t_setup;

t_setup			*my_get_setup(char **argv);
/* PARSING END */


void			my_free_node_data(t_mino *mino);
void			my_aff_help();

#endif /* !MY_FONCTION_H_ */
