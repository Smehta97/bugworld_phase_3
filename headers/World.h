#ifndef _WORLD_H
#define _WORLD_H

#include "attribute.h"
#include "Instruction.h"
#include "Program.h"
#include "Bug.h"
#include "Marker.h"
#include "Cell.h"

class World {
private:
  int Width;
  int Length;
  int totalCycles;
  int currentCycle;
  Cell** cells;
  Bug** bugs;
  std::vector<Bug> redbugs;
  std::vector<Bug> blackbugs;
public:
  World();
  ~World();
  void load(std::String);
  int execute_cycle();
  Cell* get_cell(tposition);
  tposition adjacent(tdirection, tposition);
  tcolor other_color(tcolor);
  tcolor winner();
  int red_food();
  int black_food();
  int red_count();
  int black_count();
  void error(std::String);
  void log(std::String);
};

#endif
