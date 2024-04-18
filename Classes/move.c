#include <stdbool.h>
#include "move.h"
#include <stdlib.h>
#include <string.h> // Include for strcmp


// Function to convert a card rank from a letter to an integer
int convertFrokLetter(char letter) {
    const char *ranks = "AKQJT98765432";
    const char *pos = strchr(ranks, letter);
    if (pos != NULL) {
        return 14 - (int)(pos - ranks);
    } else {
        return strtol(&letter, NULL, 10);
    }
}

// Function to check if a move from one column to another is legal
int legalMove(column *col, int colStart, char type, char number, int colEnd) {
    column *fromCol = col;
    column *toCol = col;
    ListElement *currNode;
    ListElement *prev;

    for (int i = 0; i < colStart-1; ++i) {
        fromCol = fromCol->next;
    }
    currNode = fromCol->node;

    if (number != 'F' && type != 'F') {
        while (currNode->card->rank != number || currNode->card->suit != type) {
            if (currNode->next == NULL) {
                return 0;
            }
            prev = currNode;
            currNode = currNode->next;
        }
    } else {
        while (currNode->next != NULL) {
            prev = currNode;
            currNode = currNode->next;
        }
    }

    for (int i = 0; i < colEnd-1; ++i) {
        toCol = toCol->next;
    }

    int checkerNumberFirst = convertFrokLetter(currNode->card->suit);

    if (toCol->node == NULL && checkerNumberFirst == 13) {
        int turned = 1;
        if (!prev->card->isVisible) {
            prev->card->isVisible = true;
            turned = 2;
        }
        prev->next = NULL;
        toCol->node = currNode;
        return turned;
    }

    ListElement *lastElementInRow = toCol->node;

    while (lastElementInRow->next != NULL) {
        lastElementInRow = lastElementInRow->next;
    }

    int checkerNumberLast = convertFrokLetter(lastElementInRow->card->suit);

    if (checkerNumberLast == checkerNumberFirst + 1 && lastElementInRow->card->rank != currNode->card->rank) {
        int turned = 1;
        lastElementInRow->next = currNode;
        if (!prev->card->isVisible) {
            prev->card->isVisible = true;
            turned = 2;
        }
        prev->next = NULL;

        return turned;
    } else {
        return 0;
    }
}

// Function to check if a move from a column to a pile is legal
int legalPileMove(column *col, int colStart, int colEnd) {
    column *fromCol = col;
    column *toCol = col;
    ListElement *currNode;
    ListElement *prev;
    ListElement *pileNode;

    for (int i = 0; i < colStart-1; ++i) {
        fromCol = fromCol->next;
    }

    if (fromCol->node == NULL) {
        return 0;
    }

    currNode = fromCol->node;

    bool firstCard = true;
    while (currNode->next != NULL) {
        prev = currNode;
        currNode = currNode->next;
        firstCard = false;
    }

    for (int i = 0; i < colEnd+6; ++i) {
        toCol = toCol->next;
    }
    int cardFrom = convertFrokLetter(currNode->card->suit);

    if (toCol->node == NULL && cardFrom == 1) {
        int turned = 1;
        if (firstCard) {
            fromCol->node = NULL;
        } else {
            if (!prev->card->isVisible) {
                prev->card->isVisible = true;
                turned = 2;
            }
            prev->next = NULL;
        }
        toCol->node = currNode;
        return turned;
    }

    int cardPile;

    if (toCol->node != NULL) {
        pileNode = toCol->node;
        while (pileNode->next != NULL) {
            pileNode = pileNode->next;
        }
        cardPile = convertFrokLetter(pileNode->card->suit);
    }

    if (toCol->node != NULL && cardPile + 1 == cardFrom && currNode->card->rank == pileNode->card->rank) {
        int turned = 1;
        if (firstCard) {
            fromCol->node = NULL;
        } else {
            if (!prev->card->isVisible) {
                prev->card->isVisible = true;
                turned = 2;
            }
            prev->next = NULL;
        }
        pileNode->next = currNode;
        return turned;
    } else {
        return 0;
    }
}

// Function to move a card from a pile to a column
bool moveFromPileToC(column *col, int colStart, int colEnd) {
    column *fromCol = col;
    column *toCol = col;
    ListElement *currNode;
    ListElement *prev;
    ListElement *columnNode;

    for (int i = 0; i < colStart + 6; ++i) {
        fromCol = fromCol->next;
    }

    if (fromCol->node == NULL) {
        return false;
    }

    currNode = fromCol->node;

    bool firstCard = true;
    while (currNode->next != NULL) {
        prev = currNode;
        currNode = currNode->next;
        firstCard = false;
    }

    for (int i = 0; i < colEnd - 1; ++i) {
        toCol = toCol->next;
    }

    int cardFrom = convertFrokLetter(currNode->card->suit);

    if (toCol->node == NULL && cardFrom == 13) {
        if (firstCard) {
            fromCol->node = NULL;
        } else {
            prev->next = NULL;
        }
        toCol->node = currNode;
        return true;
    }

    if (toCol->node == NULL) {
        return false;
    }

    columnNode = toCol->node;
    while (columnNode->next != NULL) {
        columnNode = columnNode->next;
    }
    int columnNodeNumber = convertFrokLetter(columnNode->card->suit);

    if (columnNodeNumber == cardFrom + 1 && columnNode->card->rank != currNode->card->rank) {
        if (firstCard) {
            fromCol->node = NULL;
        } else {
            prev->next = NULL;
        }
        columnNode->next = currNode;
        return true;
    } else {
        return false;
    }
}

