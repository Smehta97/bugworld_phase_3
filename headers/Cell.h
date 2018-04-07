#ifndef _CELL_H
#define _CELL_H

#include "Bug.h"
#include "Marker.h"

class Cell{
private:
    Bug* occupant;
    bool obstructed;
    int food;
    bool home_red_bug;
    bool home_black_bug;
public:
  Cell(char);
  //~Cell();
  Marker marker;
  Bug* get_occupant();
  void set_occupant(Bug*);
  int get_food();
  void set_food(int);
  bool get_obstructed();
  bool is_red_home_area();
  bool is_black_home_area();
};

#endif
