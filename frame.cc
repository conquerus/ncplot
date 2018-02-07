#include<ncurses.h>
#include "frame.h"

Frame::Frame(int start_x, int start_y, int size_x, int size_y)
  : start_x_(start_x), start_y_(start_y), size_x_(size_x), size_y_(size_y) // member init list  
{}

WINDOW * Frame::CreateNewWin()
{
  win_ = newwin(size_y_, size_x_, start_y_, start_x_);
  //add border
  box(win_,0,0);
  UpdateWin();

  return win_;
}

WINDOW * Frame::GetWin()
{
  return win_;
}

void Frame::UpdateWin()
{
  wrefresh(win_);
}

void Frame::SetChar(int x, int y, int character, Colors color)
{
  wattron(win_, COLOR_PAIR(color));
  mvwaddch(win_, y, x, character);
  wattroff(win_, COLOR_PAIR(color));
}

void Frame::SetPixel(int x, int y, int intensity)
{
  if (0<=intensity && intensity<=12){
    Colors in_color= (Colors)(12-intensity);
    SetChar(x, y, ACS_CKBOARD, in_color);
  }
  else {
    wprintw(win_, "INVALID INTENSITY %i", intensity);
  }
}

//generate a test graph with all the colors
void Frame::Test()
{
    for (int y = 1; y<win_->_maxy; y++){
    for (int x = 1; x<win_->_maxx; x++){
      if ((y/2+x/4+1)<14)
        {
          SetPixel(x, y, (y/2+x/4));
        }
      else
        {
          SetPixel(x, y, (y/2+x/4)-12);
        }
    }
  }
}
