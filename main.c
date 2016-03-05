/*
** main.c for main in /home/zeng_d/usefull
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Dec 14 14:07:51 2015 David Zeng
** Last update Fri Mar  4 23:24:37 2016 David Zeng
*/

#include "my_fonction.h"
#include <ncurses/curses.h>

void		my_free_node_data(t_mino *mino)
{
  free(mino->shape);
  free(mino);
}

int		main(int argc, char **argv)
{
  t_list	*tetrimino;
  t_setup	*setup;

  if ((setup = my_get_setup(argc, argv)) == NULL ||
      (tetrimino = my_get_tetrimino()) == NULL)
    return (1);
  if (setup->debug == true)
    my_aff_debug(setup, tetrimino);
  free(setup);
  my_free_all(&tetrimino, &my_free_node_data);
  return (0);
}
