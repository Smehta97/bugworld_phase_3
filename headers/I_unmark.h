/**
I_unmark.h
*/

#ifndef _I_UNMARK_H
#define _I_UNMARK_H

class I_unmark: public Bug, public Instruction, public tstate{
  private:
    // attributes
    int m;
    tstate z;

    //functions

  public:
    //attributes

    //functions
    void execute(Bug b);
    void parse(string args);
    void unmark(int m, tsate z);
};

#endif
