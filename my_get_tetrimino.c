/*
** my_get_tetrimino.c for tetris in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Mar  1 01:53:26 2016 David Zeng
** Last update Tue Mar  1 03:34:23 2016 David Zeng
*/

#include "my_fonction.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

int		my_check_mino_error(t_mino *mino)
{
  int		fd;
  char		tmp[512];

  my_strcpy(tmp, "tetriminos/");
  my_strcat(tmp, mino->name);
  if ((fd = open(tmp, O_RDONLY)) == -1)
    {
      free(mino);
      return (1);
    }
  close(fd);
  return (0);
}

int		my_get_mino_name(char *str)
{
  int		length;

  if ((length = my_strlen(str)) < 11 ||
      my_strcmp(&str[length - 10], ".tetrimino") != 0)
    return (1);
  str[length - 10] = 0;
  return (0);
}

int		my_add_mino(t_list *tetrimino, struct dirent *dirent)
{
  t_mino	*mino;

  if ((mino = malloc(sizeof(t_mino))) == NULL)
    return (1);
  mino->width = 0;
  mino->height = 0;
  mino->color = 0;
  mino->error = 0;
  my_strcpy(mino->name, dirent->d_name);
  if (my_check_mino_error(mino) == 1)
    return (1);
  if (my_get_mino_name(mino->name) == 1)
    {
      free(mino);
      return (0);
    }
  my_add_list(tetrimino, mino);
  return (0);
}

t_list		*my_get_tetrimino()
{
  t_list	*tetrimino;
  DIR		*directory;
  struct dirent	*dirent;
  DIR		*tmp;
  char		path[256];

  if ((tetrimino = my_declare_list()) == NULL ||
      (directory = opendir("./tetriminos/")) == NULL)
    return (NULL);
  while ((dirent = readdir(directory)) != NULL)
    {
      if (my_strcpy(path, "tetriminos/") && my_strcat(path, dirent->d_name) &&
	  (tmp = opendir(path)) == NULL)
	{
	  if (my_add_mino(tetrimino, dirent) == 1)
	    {
	      my_free_all(&tetrimino);
	      return (NULL);
	    }
	}
      else
	closedir(tmp);
    }
  closedir(directory);
  return (tetrimino);
}
