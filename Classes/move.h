
#ifndef PROJECT2_MACHINEORIENTEDPROGRAMMING__MOVE_H
#define PROJECT2_MACHINEORIENTEDPROGRAMMING__MOVE_H
#include <stdbool.h>
#include "deck.h"


// Assuming column and ListElement are defined
typedef struct column {
    struct ListElement *node; // Sample field
    struct column *next; // Sample field
} column;

typedef struct ListElement {
    struct card *card; // Sample field
    struct ListElement *next; // Sample field
} ListElement;





#endif //PROJECT2_MACHINEORIENTEDPROGRAMMING__MOVE_H