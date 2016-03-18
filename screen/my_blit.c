/*
** my_blit.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Mar 18 16:15:01 2016 Jean PLANCHER
** Last update Fri Mar 18 17:12:59 2016 Jean PLANCHER
*/

#include "screen.h"

void	my_blit(t_screen *win)
{
  int	i;

  i = -1;
  while (win->actual->shape[++i])
    if (win->actual->shape[i] == '*')
	{
	  win->screen[win->y + i / win->actual->width]
	  [win->x + i % win->actual->width].pix = '*';
	  win->screen[win->y + i / win->actual->width]
	  [win->x + i % win->actual->width].color = win->actual->color;
	}
}
