/*
** init_score.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon Mar 14 18:55:31 2016 Jean PLANCHER
** Last update Wed Mar 16 16:33:11 2016 Jean PLANCHER
*/

#include "screen.h"

int	init_score(t_setup *setup)
{
  int	fd;

  setup->start_time = time(NULL);
  if ((fd = open(".high_score", O_RDONLY)) == -1)
    {
      if ((fd = open(".high_score", O_CREAT, 0644)) == -1)
	{
	  endwin();
	  return (1);
	}
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

int	my_init_color()
{
  start_color();
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
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
