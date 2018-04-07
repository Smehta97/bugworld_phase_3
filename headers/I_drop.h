/**
I_drop.h
*/

#ifndef _I_DROP_H
#define _I_DROP_H

class I_drop: public Bug, public Instruction, public tstate{
  private:
    // attributes
    tstate z;

    //functions

  public:
    //attributes

    //functions
    void execute(Bug b);
    void parse(string args);

    void drop(tstate z);
};

#endif
