#include <ncurses.h>
#include "prompt.h"

Prompt::Prompt(void)
{
  getmaxyx(stdscr, y_, x_);
}

void Prompt::Draw()
{
  //refresh
  move(y_-2, 1);                //move to the begining of the line
  clrtoeol();                    //clear the line
  mvprintw(y_-2, 1, ">> ");     //redraw the prompt
  refresh();
}

void StrPrompt::GetInput()
{
  //turn on the echo and get an input string from the user
  echo();
  getstr(str);
  noecho();
}

void StrPrompt::Parser()
{
  //organize input

}
