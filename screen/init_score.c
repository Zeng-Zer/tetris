/*
** init_score.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon Mar 14 18:55:31 2016 Jean PLANCHER
** Last update Mon Mar 14 22:20:39 2016 Jean PLANCHER
*/

#include "screen.h"

int	init_score(t_setup *setup)
{
  int	fd;

  setup->start_time = time(NULL);
  if ((fd = open("res/.high_score", O_RDONLY)) == -1)
    {
      printf("test\n");
      return (1);
    }
  setup->high_score = my_getnbr(get_next_line(fd));
  return (0);
}
