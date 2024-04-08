#include "FileHandler.h"
#include <stdio.h>
#include <stdbool.h>
#include "deck.h"

bool loadDeck(struct DeckNode* head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        // Handle file not found
        return false;
    }

    char rank[3];
    char suit;
    while (fscanf(file, "%2s %c\n", rank, &suit) == 2) {
        // Create a new DeckNode and add it to the list
        // Make sure to set the 'next' pointer of the new node to NULL
        // Update the 'head' pointer if this is the first node
    }
    fclose(file);
    return true; // Return true if the deck was loaded successfully
}

