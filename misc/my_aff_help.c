/*
** my_aff_help.c for tetris in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Mar  1 22:19:24 2016 David Zeng
** Last update Sun Mar  6 23:02:19 2016 Jean PLANCHER
*/

#include "my_fonction.h"
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void		my_aff_help(char *str)
{
  int		fd;
  int		ret;
  char		buffer[1024];

  if ((fd = open("res/help.tetris", O_RDONLY)) == -1)
    return;
  if ((ret = read(fd, buffer, 1024)) == -1)
    return;
  buffer[ret] = 0;
  my_printf("Usage: %s [options]\n%s\n", str, buffer);
  close(fd);
}
