
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

//int convertFrokLetter(char letter);
//int legalMove(column *col, int colStart, char type, char number, int colEnd);
//int legalPileMove(column *col, int colStart, int colEnd);
//bool moveFromPileToC(column *col, int colStart, int colEnd);



#endif //PROJECT2_MACHINEORIENTEDPROGRAMMING__MOVE_H