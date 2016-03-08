/*
** aff_screen.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar  8 16:08:40 2016 Jean PLANCHER
** Last update Tue Mar  8 18:08:03 2016 Jean PLANCHER
*/

#include <ncurses/curses.h>
#include "my_fonction.h"
#include "screen.h"

char	*get_input()
{
  return ("test");
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
  char		*touch;

  (void)tetrimino;
  (void)setup;
  (void)my_win;
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  printw("Press ESC to exit");
  refresh();
  my_win = create_newwin(HEIGHT, WIDTH, STARTX, STARTY);
  while (my_strcmp((touch = get_input()), setup->quit));
  endwin();
}
