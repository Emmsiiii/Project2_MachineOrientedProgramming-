//
// Created by Setare Izadi on 03/04/2024.
//
#include "FileHandler.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <libc.h>
#include "deck.h"


// Forward declarations
int getRankIndex(const char *rank);

int getSuitIndex(char suit);

bool isValidRank(const char *rank);

bool isValidSuit(char suit);


bool isValidRank(const char *rank) {
    const char *validRanks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int numValidRanks = sizeof(validRanks) / sizeof(validRanks[0]);
    for (int i = 0; i < numValidRanks; i++) {
        if (strcmp(rank, validRanks[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isValidSuit(char suit) {
    return suit == 'H' || suit == 'D' || suit == 'C' || suit == 'S';
}

bool isValidCard(struct Card *card) {
    return isValidRank(card->rank) && isValidSuit(card->suit);
}

bool validateDeck(struct DeckNode *head) {
    int cardCount = 0;
    bool seenCards[4][13] = {false};  // For all suits and ranks
    struct DeckNode *current = head;

    while (current != NULL) {
        int rankIndex = getRankIndex(current->card.rank);
        int suitIndex = getSuitIndex(current->card.suit);

        // If the suit index is invalid, handle it accordingly
        if (suitIndex == -1) {
            // Handle the error, such as skipping the card or breaking out of the loop
            // For example:
            fprintf(stderr, "Invalid suit encountered.\n");
            break;
        }

        // If we've already seen this card, it's a duplicate
        if (seenCards[suitIndex][rankIndex]) {
            return false;
        }
        seenCards[suitIndex][rankIndex] = true;
        cardCount++;
        current = current->next;
    }

    // Check if the deck has exactly 52 cards
    return cardCount == 52;
}

bool loadDeck(struct DeckNode **head, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        // Handle file not found
        return false;
    }

    char rank[3];
    char suit;
    struct DeckNode *tempHead = NULL; // Temporary head to hold the new list

    while (fscanf(file, "%2s %c\n", rank, &suit) == 2) {
        struct DeckNode *newNode = malloc(sizeof(struct DeckNode));
        if (newNode == NULL) {
            fclose(file);
            // Free the partially created list before returning
            while (tempHead != NULL) {
                struct DeckNode *temp = tempHead;
                tempHead = tempHead->next;
                free(temp);
            }
            return false;
        }

        strcpy(newNode->card.rank, rank);
        newNode->card.suit = suit;
        newNode->card.isVisible = false;

        if (!isValidCard(&newNode->card)) {
            free(newNode);
            fclose(file);
            return false;
        }

        newNode->next = tempHead;
        tempHead = newNode;
    }

    if (!validateDeck(tempHead)) {
        fclose(file);
        return false;
    }

    *head = tempHead; // Set the real head to the new list
    fclose(file);
    return true;
}

int getRankIndex(const char *rank) {
    // Returns a unique index for each valid rank
    const char *validRanks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int numValidRanks = sizeof(validRanks) / sizeof(validRanks[0]);
    for (int i = 0; i < numValidRanks; i++) {
        if (strcmp(rank, validRanks[i]) == 0) {
            return i;
        }
    }
    return -1;  // Invalid rank
}

int getSuitIndex(char suit) {
    // Returns a unique index for each valid suit
    switch (suit) {
        case 'H':
            return 0;
        case 'D':
            return 1;
        case 'C':
            return 2;
        case 'S':
            return 3;
        default:
            return -1;  // Invalid suit
    }
}
