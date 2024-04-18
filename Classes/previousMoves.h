
#ifndef PROJECT2_MACHINEORIENTEDPROGRAMMING__PREVIOUSMOVES_H
#define PROJECT2_MACHINEORIENTEDPROGRAMMING__PREVIOUSMOVES_H

#include <stdbool.h>
#include "deck.h"
#include "move.h"

typedef struct moves {
    int startCol;
    char cardNum;
    char cardType;
    int endColumn;
    bool was_visible;
    struct moves* next;
} moves;

moves* createMove(int start, char num, char type, int end, bool wasVis);
moves* instantiateMovesList();
bool isInitialState(moves* move);
moves* addPreviousMoves(moves* playerMoves, int colStart, char cardNum, char cardType, int colEnd, bool wasVisible);
moves* addRedoToUndo(moves* lastMoves, column* col, moves* undoMove);
moves* undoLastMove(moves* lastMoves, column* col, moves* undoMove);

#endif //PROJECT2_MACHINEORIENTEDPROGRAMMING__PREVIOUSMOVES_H



