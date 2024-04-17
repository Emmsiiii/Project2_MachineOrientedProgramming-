#include "FileHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Forward declarations for helper functions
int getRankIndex(const char *rank);
int getSuitIndex(char suit);
bool isValidRank(const char *rank);
bool isValidSuit(char suit);

// Check if a rank is valid
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

// Check if a suit is valid
bool isValidSuit(char suit) {
    return suit == 'H' || suit == 'D' || suit == 'C' || suit == 'S';
}

// Validate a single card
bool isValidCard(struct Card *card) {
    return isValidRank(card->rank) && isValidSuit(card->suit);
}

// Validate the entire deck
bool validateDeck(struct DeckNode *head) {
    bool seenCards[4][13] = {false};
    int cardCount = 0;
    while (head != NULL) {
        int rankIndex = getRankIndex(head->card.rank);
        int suitIndex = getSuitIndex(head->card.suit);
        if (suitIndex == -1 || rankIndex == -1 || seenCards[suitIndex][rankIndex]) {
            return false;
        }
        seenCards[suitIndex][rankIndex] = true;
        cardCount++;
        head = head->next;
    }
    return cardCount == 52;
}

// Load a deck from a file
bool loadDeck(struct DeckNode **head, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) return false;

    char rank[3], suit;
    struct DeckNode *temp = NULL;

    while (fscanf(file, "%c %c", rank, &suit) == 2) {
        if (!isValidRank(rank) || !isValidSuit(suit)) {
            fclose(file);
            while (temp != NULL) {
                struct DeckNode *next = temp->next;
                free(temp);
                temp = next;
            }
            return false;
        }

        struct DeckNode *newNode = malloc(sizeof(struct DeckNode));
        if (newNode == NULL) {
            fclose(file);
            return false;  // Memory allocation failed
        }

        strcpy(newNode->card.rank, rank);
        newNode->card.suit = suit;
        newNode->next = temp;
        temp = newNode;
    }
    fclose(file);

    if (!validateDeck(temp)) {
        while (temp != NULL) {
            struct DeckNode *next = temp->next;
            free(temp);
            temp = next;
        }
        return false;
    }

    // Reverse the linked list to maintain the original order
    struct DeckNode *reversed = NULL;
    while (temp != NULL) {
        struct DeckNode *next = temp->next;
        temp->next = reversed;
        reversed = temp;
        temp = next;
    }
    *head = reversed;
    return true;
}

// Helper functions to get indexes
int getRankIndex(const char *rank) {
    const char *validRanks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int numValidRanks = sizeof(validRanks) / sizeof(validRanks[0]);
    for (int i = 0; i < numValidRanks; i++) {
        if (strcmp(rank, validRanks[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int getSuitIndex(char suit) {
    switch (suit) {
        case 'H': return 0;
        case 'D': return 1;
        case 'C': return 2;
        case 'S': return 3;
        default: return -1;
    }
}