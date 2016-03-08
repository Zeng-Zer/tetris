/*
** my_get_keyboard.c for tetris in /home/zeng_d/.emacs.d/private/tabbar
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Mar  4 17:59:59 2016 David Zeng
** Last update Tue Mar  8 15:06:53 2016 David
*/

#include "my_fonction.h"

int		my_get_key_with_ref(int argc, char **argv, t_ref *ref, char *k)
{
  char		*tmp;

  if ((tmp = my_get_param(argc, argv, ref->ref1)) != NULL)
    {
      my_strcpy(k, tmp);
      free(tmp);
    }
  else if ((tmp = my_get_long_param(argc, argv, ref->ref2)) != NULL)
    {
      my_strcpy(k, tmp);
      free(tmp);
    }
  return (0);
}

int		my_get_keypause(int argc, char **argv, t_setup *new)
{
  t_ref		ref;

  my_strcpy(ref.ref1, "-kp");
  my_strcpy(ref.ref2, "--key-pause=");
  my_get_key_with_ref(argc, argv, &ref, new->pause);
  return (0);
}

int		my_get_keyboard(int argc, char **argv, t_setup *new)
{
  t_ref		ref;

  my_strcpy(ref.ref1, "-kl");
  my_strcpy(ref.ref2, "--key-left=");
  my_get_key_with_ref(argc, argv, &ref, new->left);
  my_strcpy(ref.ref1, "-kr");
  my_strcpy(ref.ref2, "--key-right=");
  my_get_key_with_ref(argc, argv, &ref, new->right);
  my_strcpy(ref.ref1, "-kt");
  my_strcpy(ref.ref2, "--key-turn=");
  my_get_key_with_ref(argc, argv, &ref, new->turn);
  my_strcpy(ref.ref1, "-kd");
  my_strcpy(ref.ref2, "--key-drop=");
  my_get_key_with_ref(argc, argv, &ref, new->drop);
  my_strcpy(ref.ref1, "-kq");
  my_strcpy(ref.ref2, "--key-quit=");
  my_get_key_with_ref(argc, argv, &ref, new->quit);
  my_get_keypause(argc, argv, new);
  my_printf("%s right", new->right);
  return (0);
}
