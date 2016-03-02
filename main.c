/*
** main.c for main in /home/zeng_d/usefull
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Dec 14 14:07:51 2015 David Zeng
** Last update Wed Mar  2 01:34:57 2016 David Zeng
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
  t_node	*tmp;

  if (argc == 2)
    {
      my_aff_help();
      return (0);
    }
  (void)argv;
  if ((tetrimino = my_get_tetrimino()) == NULL)
    return (1);
  tmp = tetrimino->debut;
  while (tmp != NULL)
    {
      if (((t_mino*)tmp->data)->error == 0)
	{
	  my_putstr(((t_mino*)tmp->data)->name);
	  my_printf(", %s\n", ((t_mino*)tmp->data)->shape);
	}
      tmp = tmp->next;
    }
  my_free_all(&tetrimino, &my_free_node_data);
  return (0);
}
