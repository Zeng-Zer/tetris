/*
** rotate_tetrimino.c for  in /home/zeng_d/rendu/Unix/PSU_2015_tetris/screen
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Mar 18 14:44:45 2016 David Zeng
** Last update Sat Mar 19 11:44:09 2016 Jean PLANCHER
*/

#include "my_fonction.h"

t_mino		*rotate_tetrimino(t_mino *actual)
{
  t_mino	*new;
  int		x;
  int		y;

  if ((new = malloc(sizeof(t_mino) * actual->width * actual->height)) == NULL)
    return (NULL);
  y = -1;
  while (++y < actual->height)
    {
      x = -1;
      while (++x < actual->width)
	new->shape[(actual->width - x - 1) * actual->height + y] = actual->shape[y * actual->width + x];
    }
  new->color = actual->color;
  new->width = actual->height;
  new->height = actual->width;
  return (new);
}
