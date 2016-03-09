/*
** main.c for tetris in /home/zeng_d/rendu/Unix/PSU_2015_tetris
**
** Made by David Zeng
** Login   <David@epitech.net>
**
** Started on  Tue Mar  8 18:03:47 2016 David Zeng
** Last update Wed Mar  9 01:58:53 2016 David Zeng
*/

#include "my_fonction.h"

void		my_free_node_data(t_mino *mino)
{
  free(mino->shape);
  free(mino);
}

void		my_remove_error_mino(t_list *tetrimino)
{
  t_node	*node;
  t_node	*tmp;

  node = tetrimino->debut;
  while (node != NULL)
    {
      tmp = node;
      node = node->next;
      if (((t_mino *)tmp->data)->error == 1)
	{
	  free(((t_mino *)tmp->data)->shape);
	  free(tmp->data);
	  my_del_node(tetrimino, tmp);
	}
    }
}

int		main(int argc, char **argv, char **env)
{
  t_list	*tetrimino;
  t_setup	*setup;

  if ((setup = my_get_setup(argc, argv, env)) == NULL ||
      (tetrimino = my_get_tetrimino()) == NULL)
    return (1);
  if (setup->debug == true)
    my_aff_debug(setup, tetrimino);
  my_init_term(NULL, 1);
  my_remove_error_mino(tetrimino);
  aff_screen(tetrimino, setup);
  free(setup);
  my_free_all(&tetrimino, &my_free_node_data);
  return (0);
}
