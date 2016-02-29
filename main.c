/*
** main.c for main in /home/zeng_d/usefull
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Dec 14 14:07:51 2015 David Zeng
** Last update Thu Feb  4 00:47:39 2016 David Zeng
*/

#include "my_fonction.h"

int	main(int argc, char **argv)
{
  if (argc != 2)
    {
      my_printf("USAGE: %s [ARGS]\n", argv[0]);
      return (1);
    }
  return (0);
}
