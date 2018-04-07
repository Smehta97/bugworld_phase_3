#include "Bug.h"

Bug::Bug(tcolor i_color, int i_progid, int i_resting)
{
    color=i_color;
    if(color==tcolor(1))
        state=1;
    else
        state=2;
    prog_id=i_progid;
    remaining_rest=0;
    if(i_resting<0)
        throw "There can't be a negative value as the resting time.\n";
    resting=i_resting;
    direction=0;
    dead=0;
    has_food=0;
    
}

void Bug::start_resting(){
    remaining_rest=resting;
}

bool Bug::rested(){
    if(remaining_rest>0)
    {
        remaining_rest--;
        return 0;
    }
    else
        return 1;
}

int Bug::get_progid()
{
    return prog_id;
}

tcolor Bug::get_color(){
    return color;
}

tstate Bug::get_state(){
    return state;
}

void Bug::set_state(tstate new_state)
{
    state=new_state;
}

tdir Bug::get_direction(){
    return direction;
}
    
void Bug::set_direction(tdir new_direction)
{
    direction=new_direction;
}

tposition Bug::get_position()
{
    return pos;
}

void Bug::set_position(tposition new_position)
{
    pos=new_position;
}

bool Bug::get_food(){
    return has_food;
}
    
void Bug::set_food(bool new_food)
{
    if(new_food<0)
        throw "There can't be a negative value as the resting time.\n";
    has_food=new_food;
}
   
bool Bug::is_dead()
{
    return (dead==1);
}

void Bug::kill()
{
    if(dead==1)
    {
        throw "Bug cannot be killed again\n";
    }
    dead=1;
}
