#include <ncurses.h>
#include <string.h>
#include <sstream>
#include <math.h>

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

double Round(double num)
{
  return floor(num+0.5);
}

std::string ConvertToString(double input_double)
{
  std::string output_string;
  std::ostringstream convert;
  convert<<input_double;
  output_string = convert.str();

  return output_string;
}

//generate a legend in a frame
void Legend(Frame legend_frame, std::vector<float> const &datum_vec){

  WINDOW * w_legend_frame = legend_frame.GetWin();

  double min_datum = *std::min_element(datum_vec.begin(), datum_vec.end());
  double max_datum = *std::max_element(datum_vec.begin(), datum_vec.end());

  float delta = (max_datum - min_datum)/12.0;

  int x = 1;
  int y = 1;
  int intensity = 0;

  std::string s_val;
  
  for (float val = min_datum; val<= max_datum+delta/10.0; val=val+delta){

    s_val = ConvertToString(val);
    
    //move to the begining of the line
    wmove(w_legend_frame, y, x);
    //clear the line
    clrtoeol();
    mvwprintw(w_legend_frame, y, x, s_val.c_str());
    legend_frame.SetPixel(x+13, y, intensity);
    y = y+1;
    intensity=intensity+1;
    
    legend_frame.UpdateWin();
  }
}

//generate a plot in a frame
double Plot(Frame plot_frame, std::vector<float> const &x_vec, std::vector<float> const &y_vec, std::vector<float> const &datum_vec)
{

  WINDOW * w_plot_frame = plot_frame.GetWin();
    
  //clear
  for (int i=1;i<w_plot_frame->_maxx;i++){
    for (int j=1;j<w_plot_frame->_maxy;j++){
      mvwaddch(w_plot_frame,j,i,' ');
    }
  }

  //plot
      
  double min_x = *std::min_element(x_vec.begin(), x_vec.end());
  double max_x = *std::max_element(x_vec.begin(), x_vec.end());
  double min_y = *std::min_element(y_vec.begin(), y_vec.end());
  double max_y = *std::max_element(y_vec.begin(), y_vec.end());
  double min_datum = *std::min_element(datum_vec.begin(), datum_vec.end());
  double max_datum = *std::max_element(datum_vec.begin(), datum_vec.end());

  double pixel_x;
  double pixel_y;
  double pixel_intensity;

  //calculate the intensities to cover the whole range of colours
  for (unsigned int i = 0; i<x_vec.size(); i++){
    pixel_x = Round(1.0 + 1.0*( ((w_plot_frame->_maxx-1.0) - 1.0) / (max_x - min_x) )*( x_vec[i] - min_x ));
    pixel_y = Round(w_plot_frame->_maxy - (1.0 + 1.0*( ((w_plot_frame->_maxy-1.0) - 1.0) / (max_y - min_y) )*( y_vec[i] - min_y )));
    pixel_intensity = Round( (datum_vec[i]-min_datum)*( (12.0) / (max_datum - min_datum) ));
    plot_frame.SetPixel(pixel_x, pixel_y, pixel_intensity);
  }

  plot_frame.UpdateWin();

  char ctemp;
  long int itemp;
  
  //extrapolate
  for (int i=1;i<w_plot_frame->_maxx;i++){
    for (int j=1;j<w_plot_frame->_maxy;j++){
      ctemp = (mvwinch(w_plot_frame,j, i) & A_CHARTEXT);
      if (ctemp==' '){
        ctemp = (mvwinch(w_plot_frame,j-1, i) & A_CHARTEXT);
        if (ctemp!=' '){
          itemp = (mvwinch(w_plot_frame,j-1, i) & A_ATTRIBUTES);
          attron(itemp);
          mvwaddch(w_plot_frame,j,i,ACS_CKBOARD);
          attroff(itemp);
        }
        ctemp = (mvwinch(w_plot_frame,j, i-1) & A_CHARTEXT);
        if (ctemp!=' '){
          long int itemp;
          itemp = (mvwinch(w_plot_frame,j, i-1) & A_ATTRIBUTES);
          wattron(w_plot_frame,itemp);
          mvwaddch(w_plot_frame,j,i,ACS_CKBOARD);
          wattroff(w_plot_frame,itemp);
        }

      }
    }
  }
        
  return 0;
}

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
