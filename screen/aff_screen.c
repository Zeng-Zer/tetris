/*
** aff_screen.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar  8 16:08:40 2016 Jean PLANCHER
** Last update Mon Mar 14 22:43:58 2016 Jean PLANCHER
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
    mvprintw(STARTY + 20, STARTX * 2 - 10, "left : [%s]   ", setup->left);
  else if (!my_strcmp(touch, setup->right))
    mvprintw(STARTY + 20, STARTX * 2 - 10, "right : [%s]   ", setup->right);
  else if (!my_strcmp(touch, setup->turn))
    mvprintw(STARTY + 20, STARTX * 2 - 10, "turn : [%s]   ", setup->turn);
  else if (!my_strcmp(touch, setup->drop))
    mvprintw(STARTY + 20, STARTX * 2 - 10, "drop : [%s]   ", setup->drop);
  else if (!my_strcmp(touch, setup->pause))
    mvprintw(STARTY + 20, STARTX * 2 - 10, "pause : [%s]   ", setup->pause);
  return (1);
}

static void	destroy_win(t_screen *win)
{
  delwin(win->game);
  delwin(win->next);
  delwin(win->score);
}

static void	my_refresh(t_screen *win, t_setup *setup)
{
  time_t	my_time;

  my_time = time(NULL) - setup->start_time;
  refresh();
  mvwprintw(win->score, 2, 2, "High Score\t%d", setup->high_score);
  mvwprintw(win->score, 3, 2, "Score\t\t%d", setup->score);
  mvwprintw(win->score, 5, 2, "Lines\t\t%02d", setup->line);
  mvwprintw(win->score, 6, 2, "Level\t\t%02d", setup->level);
  mvwprintw(win->score, 8, 2, "Timer:\t%02d:%02d", my_time / 60, my_time % 60);
  wrefresh(win->game);
  wrefresh(win->next);
  wrefresh(win->score);
}
static WINDOW	*create_newwin(int width, int height, int startx, int starty)
{
  WINDOW	*local_win;

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
  if (init_score(setup))
    return ;
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  mvprintw(1, 5, "Press Q to exit");
  refresh();
  win.game = create_newwin(GWIDTH, GHEIGHT, STARTX, STARTY);
  win.next = create_newwin(GWIDTH - 2, GHEIGHT / 5, STARTX * 2, STARTY);
  win.score = create_newwin(GWIDTH * 2, GHEIGHT / 2, STARTX / 6, STARTY + 10);
  my_refresh(&win, setup);
  while (get_input(setup))
    my_refresh(&win, setup);
  destroy_win(&win);
  endwin();
}
