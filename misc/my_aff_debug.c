/*
** my_aff_debug.c for tetris in /home/zeng_d/.emacs.d/private/tabbar
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Mar  4 18:27:53 2016 David Zeng
** Last update Fri Mar  4 23:25:55 2016 David Zeng
*/

#include "my_fonction.h"

void		my_aff_debug(t_setup *setup, t_list *tetrimino)
{
  my_printf("*** DEBUG MODE ***\n");
  my_printf("Next : ");
  if (setup->next == true)
    my_printf("Yes\n");
  else
    my_printf("No\n");
  my_printf("Level : %d\nSize : %d*%d\n", setup->level,
	    setup->height, setup->width);
  my_aff_tetrimino(tetrimino);
  my_printf("Press a key to start Tetris\n");
}
