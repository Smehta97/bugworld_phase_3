/**
instruction.h
*/

#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

class Instruction: public World, public Bug{
  protected:
    //attributes
    World w;
    //functions

  private:
    // attributes

    //functions

  public:
    //attributes

    //functions
    void execute(Bug b);
    void parse(string str_command);
};

#endif
