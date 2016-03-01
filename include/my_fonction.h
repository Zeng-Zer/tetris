/*
** my_fonction.h :D
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov 30 15:49:28 2015 David Zeng
** Last update Tue Mar  1 03:45:51 2016 David Zeng
*/

#include "my.h"
#include "my_list.h"
#include <stdlib.h>

#ifndef MY_FONCTION_H_
# define MY_FONCTION_H_

/* GET TETRIMINOS */

typedef struct		s_mino
{
  int			width;
  int			height;
  int			color;
  int			error;
  char			**shape;
  char			name[256];
}			t_mino;

t_list	*my_get_tetrimino();

#endif /* !MY_FONCTION_H_ */
