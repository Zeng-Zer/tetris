/*
** aff_game.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Wed Mar 16 22:42:38 2016 Jean PLANCHER
** Last update Fri Mar 18 01:44:43 2016 Jean PLANCHER
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
	  color = (win->screen[i][j].color < 8 && win->screen[i][j].color > 0)
	      ? win->screen[i][j].color : 0;
	  if (win->screen[i][j].pix == '*')
	    {
	      wattron(win->game, COLOR_PAIR(color));
	      mvwprintw(win->game, i + 1, j * 2 + 1, "  ");
	      wattroff(win->game, COLOR_PAIR(color));
	    }
	}
    }
}

void	move_actual(t_screen *win, char key)
{
  if (key == 'r')
    win->x++;
  else if (key == 'l')
    win->x--;
}

void	aff_tetrimino(t_screen *win)
{
  int	i;
  int	color;

  i = -1;
  win->y++;
  color = (win->actual->color < 8 && win->actual->color > 0)
      ? win->actual->color : 0;
  printw("%d %d", win->y, win->x);
  while (win->actual->shape[++i])
    if (win->actual->shape[i] == '*')
	{
	  wattron(win->game, COLOR_PAIR(color));
	  mvwprintw(win->game, win->y + i / win->actual->width,
		    (win->x + i % win->actual->width) * 2 + 1, "  ");
	  wattroff(win->game, COLOR_PAIR(color));
	}
}
