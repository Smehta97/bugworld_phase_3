/**
program.h
*/

#ifndef _PROGRAM_H
#define _PROGRAM_H

class Program: public Bug{
  private:
    // attributes
    int id;

    //functions

  public:
    //attributes

    //functions
    Program(string filename);
    void step(Bug b);
};

#endif
