/*
** rotate_tetrimino.c for  in /home/zeng_d/rendu/Unix/PSU_2015_tetris/screen
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Mar 18 14:44:45 2016 David Zeng
** Last update Fri Mar 18 15:23:28 2016 David Zeng
*/

#include "my_fonction.h"

void		rotate_tetrimino(t_mino *mino)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y < mino->height)
    {
      while (x < mino->width)
	{

	  x = x + 1;
	}
      x = 0;
      y = y + 1;
    }
}
