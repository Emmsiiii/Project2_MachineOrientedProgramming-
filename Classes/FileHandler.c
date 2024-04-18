
#include <stdio.h>
#include "deck.h"
#include <string.h>
#include <stdlib.h>


void loadDeck(deckNode** head, const char* filename) {
    char file_path[100];
    sprintf(file_path, "Files/%s", filename);

    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error: unable to open file for reading.\n");
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




