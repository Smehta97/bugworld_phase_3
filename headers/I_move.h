#ifndef _I_MOVE_H
#define _I_MOVE_H

#include "attribute.h"

class I_move: public Bug, public Instruction, public tstate{
private:
  tstate x;
  tstate y;
public:
  void execute(Bug b);
  void parse(string args);
  void move(tstate x, tstate y);
};

#endif
