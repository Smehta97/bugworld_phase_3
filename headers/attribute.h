#ifndef EXPOSEDTYPES_H
#define EXPOSEDTYPES_H

//color of bug, range= 0,1
typedef struct tcolor{
    int val; // 0 = black, 1 = red
} color_t;

//state of bug's brain, range = 0..9999
typedef struct tstate{
    int val;
} state_t;

/*direction in hexagonal world, range = 0....5
* 0 = east
* 1 = south east
* 2 = south west
* 3 = west
* 4 = north west
* 5 = north east
*/
typedef struct tDirection{
    int val;
} tdirection;

//coordinate of cell (int x, int y)
typedef struct tPosition{
    int x;
    int y;
} tposition;

/*direction of sensing, range = 0..3
 * 0 = here 
 * 1 = leftahead
 * 2 = ahead
 * 3 = rightahead
 */
typedef struct tsensedir{
    int val; 
}tsensedir;

//left or right, range = 0,1
typedef struct tleftright{
    int val; // 0 = left, 1 = right
} tleftright;

// chemcial marks, range = 0...5 
typedef struct tmark{
    int val;
} tmark;

/**
 * condition of a Cell, range = 0..9 
 * 0 = Friend (cell contains a bug of the same color)
 * 1 = Foe (cell contains a bug of the other color)
 * 2 = FriendWithFood (cell contains a bug of the same color carrying food)
 * 3 = FoeWithFood (cell contains a bug of the other color carrying food)
 * 4 = Food (cell contains food (not being carried by a bug))
 * 5 = Rock (cell is rocky (an obstacle))
 * 6 = Marker    of int (cell is marked with a marker of this bug's color)
 * 7 = FoeMarker (cell is marked with 'some' marker of the other color)
 * 8 = Home (cell belongs to this bug's home area)
 * 9 = FoeHome (cell belongs to the other home area)
 */

typedef struct tcondition{
    int val;
} tcondition;

#endif /* EXPOSEDTYPES_H */

