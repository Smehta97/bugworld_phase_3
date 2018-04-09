/*
 * I_mark Implementation
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <exception>
#include <vector>
#include <cstring>

#include "I_mark.h"
#include "World.h"

void I_mark::execute(Bug& b){
    //set mark m and go to state z
    position_t p = b.get_position();
    Cell *x = this->w.get_cell(p);
    mark_t newmark;
    newmark.val = m;
    x->mark.set_marker(newmark, b.get_color());
    b.set_state(z);
}

void I_mark::parse(std::string& args){
    std::vector<std::string> v;

    char * token;

    token = strtok ( (char*) args.c_str()," ,.-");
    while (token!= NULL)
    {
        std::string str(token);
        v.push_back(str);
        token= strtok (NULL, " ,.-");
    }
    if(v[0] != "mark")
        throw std::runtime_error("Wrong instruction called!");
    int m= std::stoi (v[1],nullptr,10);
    this->z.val = std::stoi (v[2],nullptr,10);
    
}
