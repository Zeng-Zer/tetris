/*
** parsing.c for tetris in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Mar  1 22:30:32 2016 David Zeng
** Last update Fri Mar  4 18:11:02 2016 David Zeng
*/

#include "my_fonction.h"

t_setup		*my_init_setup()
{
  t_setup	*new;

  if ((new = malloc(sizeof(t_setup))) == NULL)
    return (NULL);
  new->level = 1;
  new->left = KEY_LEFT;
  new->right = KEY_RIGHT;
  new->turn = KEY_UP;
  new->drop = KEY_DOWN;
  new->quit = 27;
  new->pause = ' ';
  new->width = 10;
  new->height = 20;
  new->next = true;
  new->debug = false;
  return (new);
}

int		my_get_map_size(int argc, char **argv, t_setup *new)
{
  char		*tmp;
  int		i;
  int		debut;

  i = -1;
  if ((tmp = my_get_long_param(argc, argv, "--map-size=")) != NULL)
    {
      while (tmp[++i] >= '0' && tmp[i] <= '9');
      if (tmp[i] == ',')
	tmp[i] = 0;
      debut = i;
      while ((tmp[++debut] == ' ') && tmp[debut] != 0);
      if ((new->height = my_getnbr_err(tmp)) == -1 || new->height == 0)
	new->height = 20;
      if ((new->width = my_getnbr_err(&tmp[debut])) == -1 || new->width == 0)
	new->width = 10;
      free(tmp);
    }
 return (0);
}

int		my_get_other_setup(int argc, char **argv, t_setup *new)
{
  char		*tmp;

  if ((tmp = my_get_param(argc, argv, "-l")) != NULL)
    {
      if ((new->level = my_getnbr_err(tmp)) == -1 || new->level == 0)
	new->level = 1;
      if (new->level > 10)
	new->level = 10;
      free(tmp);
    }
  else if ((tmp = my_get_long_param(argc, argv, "--level=")) != NULL)
    {
      if ((new->level = my_getnbr_err(tmp)) == -1 || new->level == 0)
	new->level = 1;
      if (new->level > 10)
	new->level = 10;
      free(tmp);
    }
  my_get_keyboard(argc, argv, new);
  my_get_map_size(argc, argv, new);
  return (0);
}

t_setup		*my_get_setup(int ac, char **av)
{
  t_setup	*new;
  int		i;

  if ((new = my_init_setup()) == NULL)
    return (NULL);
  if (av == NULL)
    return (new);
  i = -1;
  while (++i < ac)
    {
      if (my_strcmp(av[i], "--help") == 0)
	{
	  my_aff_help();
	  free(new);
	  return (NULL);
	}
      else if (my_strcmp(av[i], "-W") == 0 ||
	       my_strcmp(av[i], "--without-next") == 0)
	new->next = false;
      else if (my_strcmp(av[i], "-d") == 0 || my_strcmp(av[i], "--debug") == 0)
	new->debug = true;
    }
  if (my_get_other_setup(ac, av, new) == 1)
    return (NULL);
  return (new);
}
