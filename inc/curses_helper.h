void InitCurses()
{
  initscr(); //initialize
  cbreak();  //accept ctrl command
  noecho();
  keypad(stdscr, TRUE);

  //colors
  if(has_colors() == FALSE)
    {	endwin();
      printf("Your terminal does not support color\n");
    }
  start_color();
  use_default_colors();
  InitColors();
}
  
void EndCurses()
{
  endwin();
}
