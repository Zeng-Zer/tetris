/*
** aff_game.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Wed Mar 16 22:42:38 2016 Jean PLANCHER
** Last update Thu Mar 17 16:43:06 2016 Jean PLANCHER
*/

#include "screen.h"

void	aff_game(t_screen *win, t_setup *setup)
{
  int	color;
  int	i;
  int	j;

  i = -1;
  while (++i < setup->height)
    {
      j = -1;
      while (++j < setup->width)
	{
	  color = (win->screen[i][++j].color < 8 && win->screen[i][++j].color > 0)
	      ? win->screen[i][++j].color : 0;
	  if (win->screen[i][j].pix == '*')
	    {
	      printw("[%d;%d]:%d ", i, j, color);
	      wattroff(win->game, COLOR_PAIR(color));
	      mvwprintw(win->game, i + 1, j * 2 + 1, "  ");
	      wattroff(win->game, COLOR_PAIR(color));
	    }
	}
    }
}
