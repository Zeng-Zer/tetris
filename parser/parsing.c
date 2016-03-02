/*
** parsing.c for tetris in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Mar  1 22:30:32 2016 David Zeng
** Last update Tue Mar  1 23:40:32 2016 David Zeng
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

t_setup		*my_get_setup(char **argv)
{
  t_setup	*new;

  if ((new = my_init_setup()) == NULL)
    return (NULL);
  if (argv == NULL)
    return (new);
  return (new);
}
