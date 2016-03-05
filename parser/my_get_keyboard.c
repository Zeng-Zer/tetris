/*
** my_get_keyboard.c for tetris in /home/zeng_d/.emacs.d/private/tabbar
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Mar  4 17:59:59 2016 David Zeng
** Last update Fri Mar  4 18:21:02 2016 David Zeng
*/

#include "my_fonction.h"

int		my_get_key_with_ref(int argc, char **argv, t_ref *ref)
{
  char		*tmp;
  char		key;

  if ((tmp = my_get_param(argc, argv, ref->ref1)) != NULL)
    {
      if (my_strlen(tmp) == 1)
	{
	  key = tmp[0];
	  free(tmp);
	  return (key);
	}
    }
  else if ((tmp = my_get_long_param(argc, argv, ref->ref2)) != NULL)
    {
      if (my_strlen(tmp) == 1)
	{
	  key = tmp[0];
	  free(tmp);
	  return (key);
	}
    }
  return (0);
}

int		my_get_keypause(int argc, char **argv, t_setup *new)
{
  t_ref		ref;
  int		tmp;

  my_strcpy(ref.ref1, "-kp");
  my_strcpy(ref.ref2, "--key-pause=");
  if ((tmp = my_get_key_with_ref(argc, argv, &ref)) != 0)
    new->pause = tmp;
  return (0);
}

int		my_get_keyboard(int argc, char **argv, t_setup *new)
{
  t_ref		ref;
  int		tmp;

  my_strcpy(ref.ref1, "-kl");
  my_strcpy(ref.ref2, "--key-left=");
  if ((tmp = my_get_key_with_ref(argc, argv, &ref)) != 0)
    new->left = tmp;
  my_strcpy(ref.ref1, "-kr");
  my_strcpy(ref.ref2, "--key-right=");
  if ((tmp = my_get_key_with_ref(argc, argv, &ref)) != 0)
    new->right = tmp;
  my_strcpy(ref.ref1, "-kt");
  my_strcpy(ref.ref2, "--key-turn=");
  if ((tmp = my_get_key_with_ref(argc, argv, &ref)) != 0)
    new->turn = tmp;
  my_strcpy(ref.ref1, "-kd");
  my_strcpy(ref.ref2, "--key-drop=");
  if ((tmp = my_get_key_with_ref(argc, argv, &ref)) != 0)
    new->drop = tmp;
  my_strcpy(ref.ref1, "-kq");
  my_strcpy(ref.ref2, "--key-quit=");
  if ((tmp = my_get_key_with_ref(argc, argv, &ref)) != 0)
    new->quit = tmp;
  my_get_keypause(argc, argv, new);
  return (0);
}
