#ifndef _I_PICKUP_H
#define _I_PICKUP_H
#include "attribute.h"

class I_pickup: public Bug, public Instruction, public tstate{
private:
  tstate x;
  tstate y;
public:
  void execute(Bug b);
  void parse(string args);
  void pickup(tstate x, tstate y);
};

#endif
