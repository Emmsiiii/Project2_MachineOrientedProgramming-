// deck.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"

column *createDeck() {
    column *deck = (column *)malloc(sizeof(column));
    deck->size = 0;
    deck->capacity = 52;
    deck->cards = (card **)malloc(deck->capacity * sizeof(card *));
    for (int i = 0; i < deck->capacity; i++) {
        deck->cards[i] = (card *)malloc(sizeof(card));
        deck->cards[i]->rank = ' ';
        deck->cards[i]->suit = ' ';
        deck->cards[i]->hidden = 1;
    }
    int index = 0;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 2; rank <= 14; rank++) {
            deck->cards[index]->rank = rank < 11 ? (char)(rank + '0') : (char)((rank - 10) + '0');
            switch (suit) {
                case 0:
                    deck->cards[index]->suit = 'H';
                    break;
                case 1:
                    deck->cards[index]->suit = 'D';
                    break;
                case 2:
                    deck->cards[index]->suit = 'C';
                    break;
                case 3:
                    deck->cards[index]->suit = 'S';
                    break;
            }
            index++;
        }
    }
    srand(time(NULL));
    for (int i = 0; i < deck->capacity; i++) {
        int j = rand() % deck->capacity;
        card *temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
    return deck;
}

void destroyColumn(column *deck) {
    for (int i = 0; i < deck->capacity; i++) {
        free(deck->cards[i]);
    }
    free(deck->cards);
    free(deck);
}
