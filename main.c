/*
** main.c for main in /home/zeng_d/usefull
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Dec 14 14:07:51 2015 David Zeng
** Last update Tue Mar  1 14:50:21 2016 David Zeng
*/

#include "my_fonction.h"
#include <ncurses/curses.h>

int		main(int argc, char **argv)
{
  t_list	*tetrimino;
  t_node	*tmp;

  (void)argc;
  (void)argv;
  if ((tetrimino = my_get_tetrimino()) == NULL)
    return (1);
  tmp = tetrimino->debut;
  while (tmp != NULL)
    {
      if (((t_mino*)tmp->data)->error == 0)
	{
	  my_putstr(((t_mino*)tmp->data)->name);
	  my_putchar('\n');
	}
      tmp = tmp->next;
    }
  my_free_all(&tetrimino);
  return (0);
}
