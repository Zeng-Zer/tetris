/*
** aff_screen.c for  in /home/planch_j/rendu/PSU/PSU_2015_tetris/screen/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar  8 16:08:40 2016 Jean PLANCHER
** Last update Wed Mar 16 00:02:56 2016 Jean PLANCHER
*/

#include "screen.h"

static int	get_input(t_setup *setup)
{
  char	touch[SIZE_READ];
  int	ret;

  if (STARTX < 27 || STARTY < 3)
    return (0);
  ret = read(0, touch, SIZE_READ);
  touch[ret] = 0;
  if (!my_strcmp(touch, setup->quit))
    return (0);
  else if (!my_strcmp(touch, setup->left))
    mvprintw(LINES - 1, COLS - 20, "left : [%s]   ", setup->left);
  else if (!my_strcmp(touch, setup->right))
    mvprintw(LINES - 1, COLS - 20, "right : [%s]   ", setup->right);
  else if (!my_strcmp(touch, setup->turn))
    mvprintw(LINES - 1, COLS - 20, "turn : [%s]   ", setup->turn);
  else if (!my_strcmp(touch, setup->drop))
    mvprintw(LINES - 1, COLS - 20, "drop : [%s]   ", setup->drop);
  else if (!my_strcmp(touch, setup->pause))
    mvprintw(LINES - 1, COLS - 20, "pause : [%s]   ", setup->pause);
  else if (!my_strcmp(touch, "e"))
    setup->score += 10;
  else if (!my_strcmp(touch, "n"))
    setup->aff_next = 0;
  return (1);
}

static WINDOW	*create_newwin(int width, int height, int startx, int starty)
{
  WINDOW	*local_win;

  local_win = newwin(height, width, starty, startx);
  box(local_win, 0 , 0);
  wborder(local_win, BORDER_GAME);
  return (local_win);
}

static void	destroy_win(t_screen *win)
{
  delwin(win->game);
  delwin(win->next);
  delwin(win->score);
}

static void	my_refresh(t_screen *win, t_setup *setup, t_list *tetrimino)
{
  time_t	my_time;

  my_time = time(NULL) - setup->start_time;
  win->game = create_newwin(GWIDTH, GHEIGHT, STARTX, STARTY);
  win->next = create_newwin(NWIDTH + 2, NHEIGHT + 2, STARTX * 1.7, STARTY);
  win->score = create_newwin(SWIDTH, SHEIGHT, STARTX * 0.1, STARTY * 2);
  erase();
  refresh();
  mvwprintw(win->next, 0, 1, "%s", "Next");
  aff_next(win->next, setup, tetrimino);
  mvwprintw(win->score, 2, 2, "High Score\t%d", setup->high_score);
  mvwprintw(win->score, 3, 2, "Score\t\t%d", setup->score);
  mvwprintw(win->score, 5, 2, "Lines\t\t%02d", setup->line);
  mvwprintw(win->score, 6, 2, "Level\t\t%02d", setup->level);
  mvwprintw(win->score, 8, 2, "Timer:\t%02d:%02d", my_time / 60, my_time % 60);
  wrefresh(win->game);
  wrefresh(win->next);
  wrefresh(win->score);
  usleep(100000);
  destroy_win(win);
}

void		aff_screen(t_list *tetrimino, t_setup *setup)
{
  SCREEN	*screen;
  t_screen	win;

  setup->aff_next = 0;
  screen = newterm(NULL, stderr, stdin);
  set_term(screen);
  cbreak();
  keypad(stdscr, TRUE);
  raw();
  noecho();
  curs_set(0);
  ch_read_state(0);
  if (init_score(setup))
    return ;
  while (get_input(setup))
    my_refresh(&win, setup, tetrimino);
  destroy_win(&win);
  if (setup->high_score < setup->score)
    write_hs(setup->score);
  ch_read_state(1);
  endwin();
  delscreen(screen);
}
