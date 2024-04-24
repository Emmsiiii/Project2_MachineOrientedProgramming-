
// filehandler.c
#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"

void saveDeck(const char *filename, column *deck[]) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        for (int col = 0; col < 1; col++) {
            for (int i = 0; i < deck[col]->size; i++) {
                fprintf(file, "%c%c%d\n", deck[col]->cards[i]->rank, deck[col]->cards[i]->suit, deck[col]->cards[i]->hidden);
            }
            fprintf(file, "-\n");
        }
        fclose(file);
        printf("Deck saved successfully!\n");
    } else {
        printf("Error saving deck to file.\n");
    }
}

void loadDeck(const char *filename, column *deck[]) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        char rank, suit;
        int hidden;
        int colIndex = 0;
        int cardIndex = 0;
        while (fscanf(file, "%c%c%d", &rank, &suit, &hidden) != EOF) {
            if (rank == '-') {
                colIndex++;
                cardIndex = 0;
            } else {
                deck[colIndex]->cards[cardIndex]->rank = rank;
                deck[colIndex]->cards[cardIndex]->suit = suit;
                deck[colIndex]->cards[cardIndex]->hidden = hidden;
                deck[colIndex]->size++;
                cardIndex++;
            }
        }
        fclose(file);
        printf("Deck loaded successfully!\n");
    } else {
        printf("Error loading deck from file.\n");
    }
}
