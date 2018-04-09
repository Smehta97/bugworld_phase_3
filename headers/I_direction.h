#ifndef _I_DIRECTION_H
#define _I_DIRECTION_H
#include "attribute.h"

class I_direction: public Bug, public Instruction, public tdirection, public tstate{
private:
  tdirection d;
  tstate x;
  tstate y;
public:
  void execute(Bug b);
  void parse(string args);

  void direction(tdirection dir, tstate dir_x, tstate dir_y);
};

#endif
