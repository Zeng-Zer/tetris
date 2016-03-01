/*
** my_free_all.c for free all in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jan  5 03:02:32 2016 David Zeng
** Last update Tue Jan  5 03:13:58 2016 David Zeng
*/

#include <stdlib.h>
#include "my_list.h"

void		my_free_all(t_list **list)
{
  t_node	*tmp;
  t_node	*node;

  node = (*list)->debut;
  while (node != NULL)
    {
      tmp = node;
      node = node->next;
      free(tmp->data);
      free(tmp);
    }
  free(*list);
}
