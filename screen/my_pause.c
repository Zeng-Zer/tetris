/*
** my_pause.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Wed Mar 16 02:32:07 2016 Jean PLANCHER
** Last update Wed Mar 16 02:40:05 2016 Jean PLANCHER
*/

#include "my_fonction.h"

void		my_pause(t_setup *setup)
{
  char		buffer[SIZE_READ];
  time_t	my_time;
  int		ret;

  my_time = time(NULL);
  ret = read(0, buffer, SIZE_READ);
  buffer[0] = 0;
  usleep(10000);
  while (!my_strcmp(buffer, setup->pause))
    {
      ret = read(0, buffer, SIZE_READ);
      buffer[ret] = 0;
    }
  my_time = time(NULL) - my_time;
  setup->start_time += my_time;
}
