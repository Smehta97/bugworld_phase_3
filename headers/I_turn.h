/**
I_turn.h
*/

#ifndef _I_TURN_H
#define _I_TURN_H

class I_turn: public Bug, public Instruction, public tstate, public tleftright{
  private:
    // attributes
    tleftright lr;
    tstate z;

    //functions

  public:
    //attributes

    //functions
    void execute(Bug b);
    void parse(string args);
    void turn(tleftright lr, tstate z);
};

#endif
