#include "attribute.h"
#include "Marker.h"

Marker::Marker () {
  int i;
  for (i = 0; i < 6; i++) {
    red_bits[i] = false;
    black_bits[i] = false;
  }
}

void Marker::set_marker (tmark mark, tcolor color) {
  if ((int)mark < 0 or (int)mark > 5) throw "Invalid mark";

  if (tcolor == red) // red == 0
    red_bits[(int) mark] = true;

  else if (tcolor == black) // black == 1
    black_bits[(int) mark] = true;

  else
    {throw "Invalid color";}
}

void Marker::clear_marker (tmark mark, tcolor color) {
  if ((int)mark < 0 or (int)mark > 5) throw "Invalid mark";

  if (tcolor == red) // red == 0
    red_bits[(int) mark] = false;

  else if (tcolor == black) // black == 1
    black_bits[(int) mark] = false;

  else
    {throw "Invalid color";}
}

bool check_mark (tmark mark, tcolor color) {
  // tmark = {0, 1, 2, 3, 4, 5}
  if ((int)mark < 0 or (int)mark > 5) throw "Invalid mark";

  if (tcolor == red) // red == 0
    return red_bits[(int) mark];

  else if (tcolor == black) // black == 1
    return black_bits[(int) mark];

  else
    {throw "Invalid color";} // Impossible branch, just in case.
}

bool check_other_mark (tmark mark, tcolor color) {
  // tmark = {0, 1, 2, 3, 4, 5}
  if ((int)mark < 0 or (int)mark > 5) throw "Invalid mark";

  // opposite colors
  if (tcolor == red) // red == 0
    return black_bits[(int) mark];

  // opposite colors
  else if (tcolor == black) // black == 1
    return red_bits[(int) mark];

  else
    {throw "Invalid color";} // Impossible branch, just in case.
}
