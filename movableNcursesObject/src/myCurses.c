#include <ncurses.h>

#include "../headers/myCurses.h"

//Swap 2 numbers using pointers
void swapper(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

//Fill a section of the ncurses window with a color/character
void fill_section(int width_start, int height_start, int width_end, int height_end, char character, int color_pair){

   //swap widths if nessecary
  if(width_start > width_end)
    swapper(&width_start, &width_end);

  //swap heights if nessecary
  if(height_start > height_end)
    swapper(&height_start, &height_end);

  //Turn on color
  attron(color_pair);

  //Fill section
  for(int i = width_start; i < width_end; i++){
    for(int j = height_start; j < height_end; j++){
      mvaddch(j, i, character);
    }
  }

  //turn off color
  attroff(color_pair);
}
