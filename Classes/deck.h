//
// Created by Emma Rebner on 27/04/2024.
//

#ifndef PROJECT2_MACHINEORIENTEDPROGRAMMING__DECK_H
#define PROJECT2_MACHINEORIENTEDPROGRAMMING__DECK_H

#include "card.h"

#define DECK_SIZE 52

typedef struct {
    Card* cards[DECK_SIZE];
    int count;
} Deck;

Deck* createDeck();
void destroyDeck(Deck* deck);
void shuffleDeck(Deck* deck);
void printDeck(Deck* deck);


#endif //PROJECT2_MACHINEORIENTEDPROGRAMMING__DECK_H
