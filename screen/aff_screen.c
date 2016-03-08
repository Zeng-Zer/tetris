/*
** aff_screen.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar  8 16:08:40 2016 Jean PLANCHER
** Last update Tue Mar  8 23:30:13 2016 Jean PLANCHER
*/

#include "screen.h"

static int	get_input(t_setup *setup)
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

static WINDOW *create_newwin(int width, int height, int startx, int starty)
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
  t_screen	win;

  (void)tetrimino;
  (void)win;
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  printw("Press ESC to exit");
  refresh();
  win.game = create_newwin(GWIDTH, GHEIGHT, STARTX, STARTY);
  win.score = create_newwin(10, 20, 0, 10);
  wprintw(win.score, "High Score 100");
  refresh();
  while (get_input(setup));
    refresh();
  endwin();
}
