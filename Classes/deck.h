#ifndef DECK_H
#define DECK_H
#include <stdbool.h>
#include "card.h"

typedef struct {
    char rank;
    char suit;
    int hidden; // 1 if the card is hidden, 0 if it's visible
} card;

typedef struct {
    int size;
    int capacity;
    card **cards;
} column;

column *createDeck();
void destroyColumn(column *deck);

#endif



// End if directive for DECK_H
