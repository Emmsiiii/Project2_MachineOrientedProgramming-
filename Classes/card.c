#include <stdlib.h>
#include "card.h"


Card* createCard(int value, SuitType suit, bool visible) {
    Card* card = (Card*)malloc(sizeof(Card));
    if (card != NULL) {
        card->value = value;
        card->suit = suit;
        card->visible = visible;
    }
    return card;
}

void destroyCard(Card* card) {
    if (card != NULL) {
        free(card);
    }
}