/*
** screen.h for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/include/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar  8 16:26:29 2016 Jean PLANCHER
** Last update Tue Mar  8 23:25:06 2016 Jean PLANCHER
*/

#ifndef SCREEN_H_
# define SCREEN_H_

# include "my_fonction.h"

# define BORDER_GAME '|', '|', '=', '=', '/', '\\', '\\', '/'
# define GHEIGHT setup->height
# define GWIDTH setup->width
# define STARTX (COLS - GWIDTH) / 2
# define STARTY (LINES - GHEIGHT) / 2

typedef struct	s_screen
{
  WINDOW	*game;
  WINDOW	*next;
  WINDOW	*score;
}		t_screen;

#endif /* !SCREEN_H_ */
