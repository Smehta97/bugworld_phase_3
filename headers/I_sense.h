#ifndef _I_SENSE_H
#define _I_SENSE_H
#include "attribute.h"
#include "Bug.h"

class I_sense: public Bug, public Instruction, public tsensedir, public tstate, public tcondition{
private:
  tsensedir dir;
  tstate x;
  tstate y;
  tcondition condition;
public:
  void execute(Bug b);
  void parse(std::string args);
  void sense(tsensedir sensedir, tstate x, tstate y, tcondition c);
};

#endif
