/*
** aff_next.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 15 23:23:59 2016 Jean PLANCHER
** Last update Wed Mar 16 00:07:33 2016 Jean PLANCHER
*/

#include "my_fonction.h"

void	aff_next(WINDOW *next, t_setup *setup, t_list *tetriminos)
{
  srand(time(NULL));
  if (setup->aff_next == 0)
    setup->aff_next = rand() % tetriminos->length + 1;
  if (setup->next == true)
    mvwprintw(next, 1, 1, "%d", setup->aff_next);
}
