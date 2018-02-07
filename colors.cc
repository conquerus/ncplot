#include "colors.h"
#include <ncurses.h>

void InitColors()
{
  init_pair(0,  COLOR_WHITE,   COLOR_WHITE);
  init_pair(1,  COLOR_WHITE,   COLOR_MAGENTA);
  init_pair(2,  COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(3,  COLOR_MAGENTA, COLOR_RED);
  init_pair(4,  COLOR_RED,     COLOR_RED);
  init_pair(5,  COLOR_RED,     COLOR_YELLOW);
  init_pair(6,  COLOR_YELLOW,  COLOR_YELLOW);
  init_pair(7,  COLOR_YELLOW,  COLOR_GREEN);
  init_pair(8,  COLOR_GREEN,   COLOR_GREEN);
  init_pair(9,  COLOR_GREEN,   COLOR_CYAN);
  init_pair(10, COLOR_CYAN,    COLOR_CYAN);
  init_pair(11, COLOR_CYAN,    COLOR_BLUE);
  init_pair(12, COLOR_BLUE,    COLOR_BLUE);
}
