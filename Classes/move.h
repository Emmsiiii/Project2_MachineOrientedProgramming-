#ifndef PROJECT2_MACHINEORIENTEDPROGRAMMING__MOVE_H
#define PROJECT2_MACHINEORIENTEDPROGRAMMING__MOVE_H
#include <stdbool.h>
#include "deck.h"

void displayColumns(column *deck[]);
void moveCard(column *from, column *to, int cardIndex);
void moveCardToFoundation(column *from, column *to);
int checkValidMove(column *from, column *to);

#endif //PROJECT2_MACHINEORIENTEDPROGRAMMING__MOVE_H