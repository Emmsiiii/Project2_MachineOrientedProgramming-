#include <stdbool.h>
#include "move.h"
#include "deck.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void displayColumns(column *deck[]) {
    printf("\n\tC1\tC2\tC3\tC4\tC5\tC6\tC7\n");
    for (int row = 0; row < 20; ++row) {
        for (int col = 0; col < 7; ++col) {
            if (row < deck[col]->size) {
                card *currentCard = deck[col]->cards[row];
                if (currentCard->hidden) {
                    printf("\t[**]");
                } else {
                    printf("\t[%c%c]", currentCard->rank, currentCard->suit);
                }
            } else {
                printf("\t   ");
            }
        }
        printf("\n");
    }
    for (int f = 1; f <= 4; ++f) {
        printf("\t\t\t\t\t\t\tF%d\n", f);
    }
    printf("LAST Command: \n");
    printf("Message: \n");
}


void moveCard(column *from, column *to, int cardIndex) {
    if (from->size > cardIndex) {
        card *movingCard = from->cards[cardIndex];
        if (to->size == 0 && movingCard->rank == 'K') {
            to->cards[to->size++] = movingCard;
            from->cards[cardIndex] = NULL;
            from->size--;
        } else if (to->size > 0 && checkValidMove(from, to)) {
            to->cards[to->size++] = movingCard;
            from->cards[cardIndex] = NULL;
            from->size--;
        } else {
            printf("Invalid move!\n");
        }
    } else {
        printf("Invalid move!\n");
    }
}

void moveCardToFoundation(column *from, column *to) {
    card *movingCard = from->cards[from->size - 1];
    if (to->size == 0 && movingCard->rank == 'A') {
        to->cards[to->size++] = movingCard;
        from->cards[from->size - 1] = NULL;
        from->size--;
    } else if (to->size > 0 && movingCard->rank - 1 == to->cards[to->size - 1]->rank && movingCard->suit == to->cards[to->size - 1]->suit) {
        to->cards[to->size++] = movingCard;
        from->cards[from->size - 1] = NULL;
        from->size--;
    } else {
        printf("Invalid move!\n");
    }
}

int checkValidMove(column *from, column *to) {
    card *movingCard = from->cards[from->size - 1];
    card *topCardTo = to->cards[to->size - 1];
    return (movingCard->rank + 1 == topCardTo->rank) && (movingCard->suit % 2 != topCardTo->suit % 2);
}
