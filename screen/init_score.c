/*
** init_score.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon Mar 14 18:55:31 2016 Jean PLANCHER
** Last update Tue Mar 15 21:07:31 2016 Jean PLANCHER
*/

#include "screen.h"

int	init_score(t_setup *setup)
{
  int	fd;

  setup->start_time = time(NULL);
  if ((fd = open(".high_score", O_RDONLY)) == -1)
    {
      if ((fd = open(".high_score", O_CREAT, 0644)) == -1)
	return (1);
      setup->high_score = 0;
      close (fd);
      return (0);
    }
  setup->high_score = my_getnbr(get_next_line(fd));
  if (setup->high_score == -1)
    setup->high_score++;
  close(fd);
  return (0);
}

void	write_hs(int score)
{
  int	fd;

  if ((fd = open(".high_score", O_WRONLY)) == -1)
      return ;
  my_putnbr_base("0123456789", score, fd);
  close(fd);
}
