#ifndef _ATTRIBUTE_H
#define _ATTRIBUTE_H

#include <exception>

typedef enum _tcolor {red=0, black=1} tcolor;

/*
           NW     NE


       W     (HERE)    E


           SW     SE

*/
//Hexagonal directions starting from NE to E in CCW
typedef enum _tdirection {NE=0, NW=1, W=2, SW=3, SE=4, E=5} tdirection;

typedef enum _tsensedir {Here=0, LeftAhead=1, RightAhead=2, Ahead=3} tsensedir;

typedef enum _tleftright {left=0, right=1} tleftright;

typedef enum _tmark {zero=0, one=1, two=2, three=3, four=4, five=5} tmark;

typedef unsigned int tstate;

typedef int tcondition;

typedef struct _tposition {int x, int y} tposition;

#endif
