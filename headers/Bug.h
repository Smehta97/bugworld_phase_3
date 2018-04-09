#ifndef _BUG_H
#define _BUG_H
#include "attribute.h"
class Bug{
    private:
        tcolor color;
        tstate state;
        int prog_id;
        tposition pos;
        tdirection direction;
        int resting;
        int remaining_rest;
        bool food;
        bool dead;
    public:
        Bug(tcolor; int; int);
        ~Bug();
        void star_resting();
        bool rested();
        int get_progid();
        tcolor getcolor();
        tstate get_state();
        void set_state(tstate);
        tdirection get_direction();
        void set_direction(tdirection);
        tposition get_position();
        void set_position(tposition);
        bool get_food();
        void set_food(bool);
        bool is_dead();
        void kill();
};

#endif
