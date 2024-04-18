
#ifndef PROJECT2_MACHINEORIENTEDPROGRAMMING__MOVE_H
#define PROJECT2_MACHINEORIENTEDPROGRAMMING__MOVE_H
#include <stdbool.h>
#include "deck.h"
#include "move.h"


typedef struct ListElement ListElement;
typedef struct column {
    ListElement *node;
    struct column *next;
} column;

typedef struct ListElement {
    card *card;
    struct ListElement *next;
} ListElement;

int convertFromLetter(char letter);
int legalMove(column *col, int colStart, char type, char number, int colEnd);
int legalPileMove(column *col, int colStart, int colEnd);
bool moveFromPileToC(column *col, int colStart, int colEnd);


#endif //PROJECT2_MACHINEORIENTEDPROGRAMMING__MOVE_H