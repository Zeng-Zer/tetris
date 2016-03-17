/*
** aff_next.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 15 23:23:59 2016 Jean PLANCHER
** Last update Thu Mar 17 16:41:42 2016 Jean PLANCHER
*/

#include "screen.h"

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
      while (mino->shape[++i])
	if (mino->shape[i] == '*')
	    {
	      wattron(next, COLOR_PAIR(color));
	      mvwprintw(next, i / mino->width + 1, i % mino->width * 2 + 1, "  ");
	      wattroff(next, COLOR_PAIR(color));
	    }
    }
}
