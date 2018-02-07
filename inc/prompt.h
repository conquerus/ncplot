#include <ncurses.h>

//main class for setting up the prompt
class Prompt
{
 public:
  Prompt();  //constructor
  void Draw();
 private:
  int x_, y_;
};

//main class for getting string info from the prompt
class StrPrompt : public Prompt
{
 public:
  char str[120];
  
  void GetInput();
  void Parser();

 private:

};
