/*
** my_get_level.c for tetris in /home/zeng_d/rendu/Unix/PSU_2015_tetris
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Mar  2 22:56:05 2016 David Zeng
** Last update Fri Mar  4 03:04:15 2016 David Zeng
*/

#include "my_fonction.h"

void		my_get_level(int argc, char **argv, t_setup *new)
{
  char		*littlep;
  char		*longp;

  if ((littlep = my_get_param(argc, argv, "-l")) != NULL)
    {
      if ((new->level = my_getnbr_err(littlep)) == -1)
	new->level = 1;
      return;
    }
  if ((longp = my_get_long_param(argc, argv, "--level=")) != NULL)
    {
      return;
    }
}
