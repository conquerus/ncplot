#include <ncurses.h>
#include <string.h>
#include <sstream>
#include <math.h>

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>


#include "prompt.h"
#include "frame.h"
#include "data_pre.h"
#include "utils.h"
//#include "colors.h"

int main(int argc, char *argv[]){
  
  InitCurses();

  int row,col;
  getmaxyx(stdscr, row, col);

  //init main menu with prompt and border
  StrPrompt main_input;
  box(stdscr,0,0);
  refresh();


  //make these realtive to the console size
  Frame main_plot(5, 3, 96, 48);
  main_plot.CreateNewWin();

  Frame legend(115, 8, 15, 15 );
  legend.CreateNewWin();

  //load the data
  DataSet public_data;

  //main program loop
  while (true) {
    
    int c = getch();
    //activate the prompt
    if ((char)c=='i'){
      main_input.Draw();
      refresh();
      main_input.GetInput();
    }

    //check for exit input, strcmp returns 0 if they are the same :/
    if (!strcmp(main_input.str, "exit")){
      break;
    }
    else if (!strcmp(main_input.str, "load")){
      //mvwaddstr(stdscr, row-2, 1,"enter file name:");
      //refresh();
      //main_input.GetInput();
      //char *filename[128] = main_input.str;
      //move(row-2, 1);                //move to the begining of the line
      //clrtoeol();                    //clear the line
      //refresh();
      mvwaddstr(stdscr, row-2, 1,"enter number of variables:");
      main_input.GetInput();
      int num_vars_t = atoi(main_input.str);
      public_data.num_colums_= num_vars_t;
      public_data.LoadData("./test_data/test.dat", num_vars_t);
      move(row-2, 1);                //move to the begining of the line
      clrtoeol();                    //clear the line
      refresh();
    }
    
    else if (!strcmp(main_input.str, "plot")){
      //make these functions
      mvwaddstr(stdscr, row-2, 1,"enter number of variables:");
      refresh();
      main_input.GetInput();
      const int num_vars= atoi(main_input.str);
      move(row-2, 1);                //move to the begining of the line
      clrtoeol();                    //clear the line
      mvwaddstr(stdscr, row-2, 1,"enter x column:");
      refresh();
      main_input.GetInput();
      const int x_col= atoi(main_input.str);
      move(row-2, 1);                //move to the begining of the line
      clrtoeol();                    //clear the line
      mvwaddstr(stdscr, row-2, 1,"enter y column:");
      refresh();
      main_input.GetInput();
      const int y_col= atoi(main_input.str);
      move(row-2, 1);                //move to the begining of the line
      clrtoeol();                    //clear the line
      mvwaddstr(stdscr, row-2, 1,"enter data column:");
      refresh();
      main_input.GetInput();
      const int data_col= atoi(main_input.str);

      //plot
      Plot(main_plot,
           (public_data.data_storage_array[x_col]),
           (public_data.data_storage_array[y_col]),
           (public_data.data_storage_array[data_col]));
      
      main_plot.UpdateWin();

      Legend(legend, public_data.data_storage_array[data_col]);
      legend.UpdateWin();

    }
    else
    {
      mvwaddstr(stdscr, row-2, 1,"invalid command, accepted command are: load, plot and exit");
      
    }
      
    //refresh the plot window
    main_plot.UpdateWin();
    legend.UpdateWin();
  }
  
  EndCurses();
}
