/*
** aff_screen.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar  8 16:08:40 2016 Jean PLANCHER
** Last update Tue Mar  8 19:16:46 2016 Jean PLANCHER
*/

#include "my_fonction.h"
#include "screen.h"

int	get_input(t_setup *setup)
{
  char	touch[SIZE_READ];
  int	ret;

  ret = read(0, touch, SIZE_READ);
  touch[ret] = 0;
  if (!my_strcmp(touch, setup->quit))
    return (0);
  else if (!my_strcmp(touch, setup->left))
    printw("left");
  else if (!my_strcmp(touch, setup->right))
    printw("right");
  else if (!my_strcmp(touch, setup->turn))
    printw("turn");
  else if (!my_strcmp(touch, setup->drop))
    printw("drop");
  else if (!my_strcmp(touch, setup->pause))
    printw("pause");
  return (1);
}

static WINDOW *create_newwin(int height, int width, int starty, int startx)
{
  WINDOW *local_win;

  local_win = newwin(height, width, starty, startx);
  box(local_win, 0 , 0);
  wborder(local_win, BORDER_GAME);
  wrefresh(local_win);
  return (local_win);
}

void		aff_screen(t_list *tetrimino, t_setup *setup)
{
  WINDOW	*my_win;

  (void)tetrimino;
  (void)setup;
  (void)my_win;
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  printw("Press ESC to exit");
  refresh();
  my_win = create_newwin(HEIGHT, WIDTH, STARTX, STARTY);
  while (get_input(setup))
    refresh();
  endwin();
}
