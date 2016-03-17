/*
** screen.h for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/include/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar  8 16:26:29 2016 Jean PLANCHER
** Last update Thu Mar 17 16:22:22 2016 Jean PLANCHER
*/

#ifndef SCREEN_H_
# define SCREEN_H_

# include "my_fonction.h"

# define BORDER_GAME '|', '|', '-', '-', '/', '\\', '\\', '/'
# define GHEIGHT (setup->height + 2)
# define GWIDTH ((setup->width + 2) << 1)
# define SHEIGHT 11
# define SWIDTH 25
# define NHEIGHT ((tetrimino->max_h > 2) ? tetrimino->max_h : 2)
# define NWIDTH ((tetrimino->max_w * 2 > 6) ? tetrimino->max_w * 2 : 6)
# define STARTX ((COLS - setup->width) >> 1)
# define STARTY ((LINES - setup->height) >> 1)

typedef struct	s_pix
{
  char		pix;
  int		color;
}		t_pix;

typedef struct	s_screen
{
  WINDOW	*game;
  WINDOW	*next;
  WINDOW	*score;
  t_pix		**screen;
}		t_screen;

int	init_score(t_setup *setup, t_screen *win);
void	write_hs(int score);
void	aff_next(WINDOW *next, t_setup *setup, t_list *tetriminos);
void	aff_game(t_screen *win, t_setup *setup);
void	my_pause(t_setup *setup);
int	my_init_color();

#endif /* !SCREEN_H_ */
