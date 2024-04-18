#include <stdio.h>
#include "deck.h"
#include <string.h>
#include <stdlib.h>

bool loadDeck(struct DeckNode **pNode, char filename[100]);
void destroyDeck(struct DeckNode* head);


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
    printf("INPUT > ");
}

int main() {
    // Initialize variables
    struct DeckNode *head = NULL;
    char command[10];

    // Print the initial view when the game starts
    printInitialView();

    // Get user input and process commands
    while (1) {
        // Get user command
        printf("\nINPUT > ");
        scanf("%9s", command);

        // Process the command
        if (strcmp(command, "LD") == 0) {
            char filename[100];
            printf("Enter deck filename: ");
            scanf("%99s", filename);

            // Check if the file exists before attempting to load
            // (Implement fileExists function or remove this check)
            // if (!fileExists(filename)) {
            //     fprintf(stderr, "File '%s' does not exist.\n", filename);
            //     continue; // Prompt for input again
            // }

            if (!loadDeck(&head, filename)) {
                fprintf(stderr, "Failed to load the deck from '%s'.\n", filename);
                // Decide whether to continue or not, possibly with a default deck
            } else {
                printf("Deck loaded successfully.\n");
                // Proceed with game using the loaded deck
            }
        } else if (strcmp(command, "SW") == 0) {
            // Show deck command
            printList(head);
        } else if (strcmp(command, "SI") == 0) {
            // Shuffle deck (interleave) command
            // Implement shuffle logic here
        } else if (strcmp(command, "SR") == 0) {
            // Shuffle deck (random) command
            // Implement shuffle logic here
        } else if (strcmp(command, "SD") == 0) {
            // Save deck command
            // Implement save deck logic here
        } else if (strcmp(command, "QQ") == 0) {
            printf("Quitting game.\n");
            break; // Exit the loop to end the game
        } else {
            printf("Unknown command.\n");
        }
    }

    // Destroy the linked list after the game ends
    destroyDeck(head);
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

