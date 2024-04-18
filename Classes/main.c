#include <stdio.h>
#include "deck.h"
#include <string.h>
#include <stdlib.h>
#include "Filehandler.h"  // Include the header file for Filehandler.c


void destroyDeck(struct DeckNode* head);
void printInitialView();
void destroyDeck(struct DeckNode* head);
void printInitialView();
void shuffleInterleave(struct DeckNode** head);
void shuffleRandom(struct DeckNode** head);
void saveDeck(struct DeckNode* head, const char* filename);



int main() {
    struct DeckNode *head = NULL;
    char command[10];
    char filename[100];

    printInitialView();

    // Get user input and process commands
    while (1) {
        // Get user command
        printf("\nINPUT > ");
        scanf("%9s", command);

        // Process the command
        if (strcmp(command, "LD") == 0) {
            printf("Enter deck filename: ");
            scanf("%99s", filename);

            loadDeck(&head, filename);  // Call loadDeck function from Filehandler.c

            printf("Deck loaded successfully.\n");
        } else if (strcmp(command, "SW") == 0) {
            // Show deck command
            printList(head);
        } else if (strcmp(command, "SI") == 0) {
            // Shuffle deck (interleave) command
            shuffleInterleave(&head);
            printf("Deck shuffled using interleave.\n");
        } else if (strcmp(command, "SR") == 0) {
            // Shuffle deck (random) command
            shuffleRandom(&head);
            printf("Deck shuffled randomly.\n");
        } else if (strcmp(command, "SD") == 0) {
            // Save deck command
            printf("Enter filename to save the deck: ");
            scanf("%99s", filename);
            saveDeck(head, filename);
            printf("Deck saved successfully.\n");
        } else if (strcmp(command, "QQ") == 0) {
            printf("Quitting game.\n");
            break; // Exit the loop to end the game
        } else {
            printf("Unknown command.\n");
        }
    }

    // Destroy the linked list after the game ends
    destroyDeck(head);

    return 0;
}

// Function to print the initial view
void printInitialView() {
    printf("\tC1\tC2\tC3\tC4\tC5\tC6\tC7\n");
    for (int row = 0; row < 7; ++row) {
        for (int col = 0; col < 7; ++col) {
            printf("\t[ ]");
        }
        printf("\n");
    }
    for (int f = 1; f <= 4; ++f) {
        printf("\t\t\t\t\t\t\tF%d\n", f);
    }
    printf("LAST Command: \n");
    printf("Message: \n");
}

// Function definition for destroying the linked list
void destroyDeck(struct DeckNode* head) {
    struct DeckNode* current = head;
    while (current != NULL) {
        struct DeckNode* next = current->next;
        free(current);
        current = next;
    }
}

// Function to shuffle the deck using interleave method
void shuffleInterleave(struct DeckNode** head) {
    // Implement shuffle logic here
}

// Function to shuffle the deck using random method
void shuffleRandom(struct DeckNode** head) {
    // Implement shuffle logic here
}

// Function to save the deck to a file
void saveDeck(struct DeckNode* head, const char* filename) {
    // Implement save deck logic here
}

