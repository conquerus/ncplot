#include <ncurses.h>
#include "colors.h"

class Frame
{
 public:
  Frame(int start_x, int start_y, int size_x, int size_y);
  WINDOW *CreateNewWin();

  void SetChar(int x, int y, int character, Colors color);
  void SetPixel(int x, int y, int intensity);
  void Test();
  void UpdateWin();
  WINDOW * GetWin();

 private:
  int start_x_, start_y_, size_x_, size_y_;
  WINDOW * win_;
};

