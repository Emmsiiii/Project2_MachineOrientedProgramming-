#include <stdbool.h>
#include <stdlib.h>
#include "previousMoves.h"
#include "move.h"


moves* createMove(int start, char num, char type, int end, bool wasVis) {
    moves* moves1 = (moves*)malloc(sizeof(moves));
    if (moves1 == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    moves1->startCol = start;
    moves1->cardNum = num;
    moves1->cardType = type;
    moves1->endColumn = end;
    moves1->was_visible = wasVis;
    moves1->next = NULL;

    return moves1;
}

moves* instantiateMovesList() {
    moves* playerMoves = (moves*)malloc(sizeof(moves));
    if (playerMoves == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    playerMoves->startCol = -1;
    playerMoves->cardType = 0;
    playerMoves->cardNum = 0;
    playerMoves->was_visible = false;
    playerMoves->endColumn = -1;
    playerMoves->next = NULL;
    return playerMoves;
}

bool isInitialState(moves* move) {
    return move->startCol == -1 && move->cardType == 0 && move->cardNum == 0
           && move->was_visible == false && move->endColumn == -1 && move->next == NULL;
}

moves* addPreviousMoves(moves* playerMoves, int colStart, char cardNum, char cardType, int colEnd, bool wasVisible) {
    moves* temp = playerMoves;
    if (playerMoves->startCol == -1) {
        playerMoves->startCol = colStart;
        playerMoves->cardNum = cardNum;
        playerMoves->cardType = cardType;
        playerMoves->endColumn = colEnd;
        playerMoves->was_visible = wasVisible;
        return playerMoves;
    }
    moves* currMove = createMove(colStart, cardNum, cardType, colEnd, wasVisible);
    if (currMove == NULL) {
        // Handle memory allocation failure
        return playerMoves;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = currMove;
    return playerMoves;
}

moves* addRedoToUndo(moves* lastMoves, column* col, moves* undoMove) {
    if (undoMove->was_visible) {
        column *temp = col;
        ListElement* element;
        for (int i = 0; i < undoMove->startCol; ++i) {
            temp = temp->next;
        }
        element = temp->node;
        while (element->next->card->rank != undoMove->cardType || element->next->card->suit != undoMove->cardNum) {
            element = element->next;
        }
        element->card->isVisible = true;
    }
    addPreviousMoves(lastMoves, undoMove->startCol, undoMove->cardNum, undoMove->cardType, undoMove->endColumn, false);
    free(undoMove);
    return NULL;
}

moves* undoLastMove(moves* lastMoves, column* col, moves* undoMove) {
    if (isInitialState(lastMoves)) {
        return NULL;
    }
    moves* temp = lastMoves;
    moves* prevTemp = lastMoves;
    column* first = col;
    column *second = col;
    ListElement* node1;
    ListElement* node2;
    ListElement* prev = NULL;
    while (temp->next != NULL) {
        prevTemp = temp;
        temp = temp->next;
    }
    int startColumn = temp->startCol;
    int endColumn = temp->endColumn;
    for (int i = 0; i < endColumn - 1; ++i) {
        first = first->next;
    }
    node1 = first->node;
    for (int i = 0; i < startColumn - 1; ++i) {
        second = second->next;
    }
    node2 = second->node;
    if (temp->cardType != 0) {
        char cardNum = temp->cardNum;
        char cardType = temp->cardType;
        while (node1->card->suit != cardType || node1->card->suit != cardNum) {
            prev = node1;
            node1 = node1->next;
        }
    } else {
        while (node1->next != NULL) {
            prev = node1;
            node1 = node1->next;
        }
    }
    if (node2 != NULL) {
        while (node2->next != NULL) {
            node2 = node2->next;
        }
        if (temp->was_visible) {
            node2->card->isVisible = false;
        }
        node2->next = node1;
    } else {
        second->node = node1;
    }
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        first->node = NULL;
    }
    moves* newUndoMove = createMove(temp->endColumn, temp->cardNum, temp->cardType, temp->startCol, temp->was_visible);
    if (newUndoMove == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    free(temp);
    prevTemp->next = NULL;
    return newUndoMove;
}
