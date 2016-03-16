/*
** aff_next.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 15 23:23:59 2016 Jean PLANCHER
** Last update Wed Mar 16 16:36:38 2016 Jean PLANCHER
*/

#include "my_fonction.h"

void		aff_next(WINDOW *next, t_setup *setup, t_list *tetriminos)
{
  t_mino	*mino;
  t_node	*elem;
  int		i;
  int		color;

  elem = tetriminos->debut;
  if (setup->aff_next == 0)
    setup->aff_next = rand() % tetriminos->length + 1;
  if (setup->next == true)
    {
      i &= ~i;
      while (++i < setup->aff_next)
	elem = elem->next;
      mino = (t_mino *)elem->data;
      i = -1;
      color = (mino->color < 8 && mino->color > 0) ? mino->color : 0;
      wattron(next, COLOR_PAIR(color));
      while (mino->shape[++i])
	mvwprintw(next, i / mino->width + 1, i % mino->width + 1,
		  "%c", mino->shape[i]);
	wattroff(next, COLOR_PAIR(color));
    }
}
