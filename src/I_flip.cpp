/*
 * I_flip Implementation
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <vector>
#include <cstring>

#include "I_flip.h"
#include "Bug.h"

void I_flip::execute(Bug& b) {
    int randomI =randomint();
    if(randomI == 0)
        b.set_state(x);
    else 
        b.set_state(y);
}

void I_flip::parse(std::string& args){
    std::vector<std::string> v;

    char * token;

    token = strtok ( (char*) args.c_str()," ,.-");
    while (token!= NULL)
    {
        std::string str(token);
        v.push_back(str);
        token= strtok (NULL, " ,.-");
    }
    if(v[0] != "flip")
        throw std::runtime_error("Wrong instruction called!");
	int p = std::stoi(v[1],nullptr,10);
	this->x.val = std::stoi(v[1],nullptr,10);
	this->y.val = std::stoi(v[1],nullptr,10);
}

int I_flip::randomint() {
    srand(time(NULL));
    return rand() % (this->p - 1);
}
