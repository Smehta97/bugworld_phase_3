#include "attribute.h"
#include "Cell.h"

/*
  Character - Cell mapping:
    '#' Obstacle
    '.'
    '+' Red bug home area
    '-' Black bug home area
    'n' n is an integer - clear cell containing n food particles
*/

Cell::Cell (char c) {
  // Check for character validity
  bool invalid_flag = false;
  if (c != '#' &&
      c != '.' &&
      c != '+' &&
      c != '-' &&)
      invalid_flag = true;
  // Later check if c is an integer, if also not, then throw an exception

  occupant = NULL;

  if (c == '#') obstructed = true;
  else {obstructed = false;}

  // If the cell contains food:
  // (isdigit and (int) casting could be used as well,
  // but explicit implementation is better)
  switch (c) {
    case '1':
      food = 1;
      break;

    case '2':
      food = 2;
      break;

    case '3':
      food = 3;
      break;

    case '4':
      food = 4;
      break;

    case '5':
      food = 5;
      break;

    case '6':
      food = 6;
      break;

    case '7':
      food = 7;
      break;

    case '8':
      food = 8;
      break;

    case '9':
      food = 9;
      break;

    case '0':
    default:
      if(invalid_flag) // c is not a valid character or integer
        throw "Invalid character while creating a Cell instance";
      food = 0;
      break;
  } // End of switch

  if (c == '+') home_red_bug = true;
  else {home_red_bug = false;}

  if (c == '-') home_black_bug = true;
  else {home_black_bug = false;}

}

Bug* Cell::get_occupant () {
  return occupant;
}

void Cell::set_occupant (Bug* occupant_bug) {
  occupant = occupant_bug;
}

int Cell::get_food () {
  return food;
}

void Cell:set_food (int food_number) {
  food = food_number;
}

bool Cell::get_obstructed () {
  return obstructed;
}

bool Cell::is_red_home_area () {
  return home_red_bug;
}

bool Cell::is_black_home_area () {
  return home_black_bug;
}
