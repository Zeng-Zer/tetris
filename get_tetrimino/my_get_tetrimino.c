/*
** my_get_tetrimino.c for tetris in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Mar  1 01:53:26 2016 David Zeng
** Last update Tue Mar  1 16:10:49 2016 David Zeng
*/

#include "my_fonction.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

int		my_get_mino_name(char *str, int opt)
{
  int		length;

  if (opt == 1)
    {
      if ((length = my_strlen(str)) < 11 ||
	  my_strcmp(&str[length - 10], ".tetrimino") != 0)
	return (1);
      str[length - 10] = 0;
      return (0);
    }
  while (str[opt] != 0)
    {
      if (str[opt] != ' ' && str[opt] != '*')
	return (1);
      opt = opt + 1;
    }
  return (0);
}

void		my_check_mino_shape(t_mino *mino, int *size, int fd, int len)
{
  char		*tmp;
  int		i;
  int		j;

  i = -1;
  while ((tmp = get_next_line(fd)) != NULL)
    {
      if (mino->error != 1)
	{
	  j = 0;
	  if (++i >= (mino->height = size[1]))
	    mino->error = 1;
	  if (my_get_mino_name(tmp, 0) == 1)
	    mino->error = 1;
	  while (tmp[my_strlen(tmp) - ++j] == ' ' && j + 1 < my_strlen(tmp));
	  tmp[my_strlen(tmp) - (j - 1)] = 0;
	  if (my_strlen(tmp) == 0)
	    mino->error = 1;
	  if (my_strlen(tmp) > len)
	    len = my_strlen(tmp);
	}
      free(tmp);
    }
  if (mino->error != 1 && len != (mino->width = size[0]))
    mino->error = 1;
}

int		my_check_mino_error(t_mino *mino, int i, int debut, int j)
{
  int		fd;
  char		path[512];
  char		*tmp;
  int		size[3];
  int		length;

  if (my_strcpy(path, "tetriminos/") && my_strcat(path, mino->name) &&
      ((fd = open(path, O_RDONLY)) == -1 || (tmp = get_next_line(fd)) == NULL))
    return (-1);
  length = my_strlen(tmp) + 1;
  while (++i < length)
    {
      if ((tmp[i] == ' ' && j < 2) || (tmp[i] == '\0' && j == 1))
	{
	  tmp[i] = 0;
	  size[++j] = my_getnbr_err(&tmp[debut]);
	  debut = i + 1;
	}
      else if (tmp[i] == '\0' && j != 1)
	mino->error = 1;
    }
  free(tmp);
  my_check_mino_shape(mino, size, fd, 0);
  return (close(fd));
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
  if (my_check_mino_error(mino, -1, 0, -1) == -1)
    {
      free(mino);
      return (1);
    }
  if (my_get_mino_name(mino->name, 1) == 1)
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
