/*
** my_aff_help.c for tetris in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Mar  1 22:19:24 2016 David Zeng
** Last update Tue Mar  1 22:29:31 2016 David Zeng
*/

#include "my_fonction.h"
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void		my_aff_help()
{
  int		fd;
  int		ret;
  char		buffer[1024];

  if ((fd = open("res/help.tetris", O_RDONLY)) == -1)
    return;
  if ((ret = read(fd, buffer, 1024)) == -1)
    return;
  buffer[ret] = 0;
  my_printf("%s\n", buffer);
  close(fd);
}
