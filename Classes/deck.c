#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Deck* createDeck() {
    Deck* deck = (Deck*)malloc(sizeof(Deck));
    if (deck != NULL) {
        deck->count = DECK_SIZE;
        int index = 0;
        for (int value = 1; value <= 13; ++value) {
            for (int suit = hearts; suit <= clubs; ++suit) {
                deck->cards[index++] = createCard(value, (SuitType)suit, false);
            }
        }
    }
    return deck;
}

void destroyDeck(Deck* deck) {
    if (deck != NULL) {
        for (int i = 0; i < DECK_SIZE; ++i) {
            destroyCard(deck->cards[i]);
        }
        free(deck);
    }
}

void shuffleDeck(Deck* deck) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; ++i) {
        int randomIndex = rand() % DECK_SIZE;
        Card* temp = deck->cards[i];
        deck->cards[i] = deck->cards[randomIndex];
        deck->cards[randomIndex] = temp;
    }
}

void printDeck(Deck* deck) {
    for (int i = 0; i < DECK_SIZE; ++i) {
        printf("%d of ", deck->cards[i]->value);
        switch (deck->cards[i]->suit) {
            case hearts:
                printf("Hearts");
                break;
            case diamonds:
                printf("Diamonds");
                break;
            case spades:
                printf("Spades");
                break;
            case clubs:
                printf("Clubs");
                break;
        }
        printf("\n");
    }
}