/**
I_mark.h
*/

#ifndef _I_MARK_H
#define _I_MARK_H

class I_mark: public Bug, public Instruction, public tstate{
  private:
    // attributes
    int m;
    tstate z;
  public:
    //functions
    void execute(Bug b);
    void parse(string args);
};

#endif
