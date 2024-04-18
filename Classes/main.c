#include <stdio.h>
#include "deck.h"
#include <string.h>



bool loadDeck(struct DeckNode **pNode, char filename[100]);

void printInitialView() {
    // Function to print the initial view - Prints column headers for C1 to C7
        printf("\tC1\tC2\tC3\tC4\tC5\tC6\tC7\n");

        // Print the empty slots for the columns
        for (int row = 0; row < 7; ++row) { // 7 rows as an example, adjust if needed
            for (int col = 0; col < 7; ++col) {
                printf("\t[ ]");
            }
            printf("\n");
        }

        // Print the foundations F1 to F4
        for (int f = 1; f <= 4; ++f) {
            printf("\t\t\t\t\t\t\tF%d\n", f);
        }

        // Placeholder for the last command and message
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

                if (!loadDeck(&head, filename)) {
                    fprintf(stderr, "Failed to load the deck from '%s'.\n", filename);
                    // Decide whether to continue or not, possibly with a default deck
                } else {
                    printf("Deck loaded successfully.\n");
                    // Proceed with game using the loaded deck
                }
            } else if (strcmp(command, "SW") == 0) {
                // Show deck command
                // (Assuming printList is modified to handle a DeckNode)
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

        // Load the deck
        if (!loadDeck(&head, "deck.txt")) {
            fprintf(stderr, "Failed to load the deck.\n");
            // Handle error
        }

        // Destroy the linked
    }