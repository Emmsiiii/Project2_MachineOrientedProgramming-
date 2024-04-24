#include "card.h"
#include <stdio.h>
#include <stdlib.h>

void printCard(Card *card) {
    if (card->isVisible) {
        switch (card->rank) {
            case 1:
                printf("A%c ", card->suit);
                break;
            case 11:
                printf("J%c ", card->suit);
                break;
            case 12:
                printf("Q%c ", card->suit);
                break;
            case 13:
                printf("K%c ", card->suit);
                break;
            default:
                printf("%d%c ", card->rank, card->suit);
        }
    } else {
        printf("## ");
    }
}

Card* createCard(char suit, int rank, bool isVisible) {
    Card *card = (Card *)malloc(sizeof(Card));
    if (card == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    card->suit = suit;
    card->rank = rank;
    card->isVisible = isVisible;
    return card;
}
