#include "deck.h"
#include "fileHandler.h"
#include <stdio.h>
#include <stdbool.h>

bool loadCardDeckFromFile(Deck* deck, const char* filename) {
    FILE* filePointer = fopen(filename, "r");
    if (filePointer == NULL) {
        return false; // Failed to open file
    }

    int index = 0;
    while (index < DECK_SIZE && fscanf(filePointer, "%d", &deck->cards[index]->value) == 1) {
        char suit;
        fscanf(filePointer, " %c", &suit);
        switch (suit) {
            case 'H':
                deck->cards[index]->suit = hearts;
                break;
            case 'D':
                deck->cards[index]->suit = diamonds;
                break;
            case 'S':
                deck->cards[index]->suit = spades;
                break;
            case 'C':
                deck->cards[index]->suit = clubs;
                break;
            default:
                fclose(filePointer);
                return false; // Invalid suit
        }
        deck->cards[index]->visible = false;
        ++index;
    }

    fclose(filePointer);
    return true;
}
bool saveCardDeckToFile(Deck* deck, const char* filename) {
    // Default to "deck.txt" if no filename is provided or if the filename is an empty string
    const char* outputFilename = (filename == NULL || filename[0] == '\0') ? "deck.txt" : filename;

    FILE* filePointer = fopen(outputFilename, "w");
    if (filePointer == NULL) {
        return false; // Failed to open file
    }

    for (int i = 0; i < DECK_SIZE; ++i) {
        fprintf(filePointer, "%d ", deck->cards[i]->value);
        switch (deck->cards[i]->suit) {
            case hearts:
                fprintf(filePointer, "H\n");
                break;
            case diamonds:
                fprintf(filePointer, "D\n");
                break;
            case spades:
                fprintf(filePointer, "S\n");
                break;
            case clubs:
                fprintf(filePointer, "C\n");
                break;
        }
    }

    fclose(filePointer);
    return true;
}


