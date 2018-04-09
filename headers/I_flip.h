/**
I_flip.h
*/

#ifndef _I_FLIP_H
#define _I_FLIP_H

#include "attribute.h"
#include "Instruction.h"

class I_flip: public Bug, public Instruction, public tstate{
  private:
    // attributes
    int p;
    tstate x;
    tstate y;
    int seed;

    //functions
    int randomint(){
      srand(time(NULL));
      return rand() % (p - 1);
    }

  public:
    //attributes

    //functions
    void execute(Bug b);
    void parse(std::string args);

    void flip(int p, tstate x, tstate y);
};

#endif
