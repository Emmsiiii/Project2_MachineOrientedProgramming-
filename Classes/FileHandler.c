
#include <stdio.h>
#include "deck.h"
#include <string.h>
#include <stdlib.h>


void loadDeck(deckNode** head, const char* filename) {
    // Print the file path to check if it's correct
    printf("Attempting to load deck from file: %s\n", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    char rank, suit;
    while (fscanf(fp, " %c%c", &rank, &suit) == 2) {
        deckNode* newNode = (deckNode*)malloc(sizeof(deckNode));
        if (newNode == NULL) {
            printf("Error: memory allocation failed.\n");
            fclose(fp);
            return;
        }
        newNode->card.rank = rank;
        newNode->card.suit = suit;
        newNode->next = *head;
        *head = newNode;
    }

    fclose(fp);
}




