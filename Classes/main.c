#include <stdio.h>
#include "deck.h"
#include <string.h>
#include "FileHandler.h"


void printInitialView() {
    // Print column headers for C1 to C7
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

    // opretter ny liste
    List *myList = createList();

    // opretter kort
    struct Card card1 = {"A", 'H', true};  // Rank is a string, so use double quotes
    struct Card card2 = {"2", 'D', false}; // Same as above, use double quotes
    struct Card card3 = {"K", 'S', true};  // Same as above

    // indsætter kort i liste
    insertAtHead(myList, card1);
    insertAtTail(myList, card2);
    insertAtTail(myList, card3);

    // udskriver listen
    printf("List contents: ");
    printList(myList);

    // finder og fjerner et kort
    Node *foundNode = findCard(myList, card2);
    if (foundNode != NULL) {
        printf("Removing card: %s%c\n", foundNode->card.rank, foundNode->card.suit);
        removeNode(myList, foundNode);
    } else {
        printf("Card not found.\n");
    }

    // Printer listen efter sletningen
    printf("List contents after deletion: ");
    printList(myList);

    // sletter listen
    destroyList(myList);

    // Print the initial view when the game starts
    printInitialView();

    // Now enter into the game loop or the rest of your game logic
    char command[10];
    while (1) {
        // Get user command
        printf("\nINPUT > ");
        scanf("%9s", command);

        // Process the command
        if (strcmp(command, "LD") == 0) {
            // Load deck command
            // Call a function to load the deck from a file
        } else if (strcmp(command, "SW") == 0) {
            // Show deck command
            printList(myList);
        } else if (strcmp(command, "SI") == 0) {
            // Shuffle deck (interleave) command
            // Call a function to shuffle the deck using interleaving
        } else if (strcmp(command, "SR") == 0) {
            // Shuffle deck (random) command
            // Call a function to shuffle the deck randomly
        } else if (strcmp(command, "SD") == 0) {
            // Save deck command
            // Call a function to save the current deck to a file
        } else if (strcmp(command, "QQ") == 0) {
            // Quit command
            printf("Quitting game.\n");
            break; // Exit the loop to end the game
        } else {
            printf("Unknown command.\n");
        }
    }

    // Clean up resources such as freeing memory
    destroyList(myList);

    struct DeckNode* head = NULL; // Start with an empty list

    // Load the deck
    if (!loadDeck(head, "path_to_deck_file.txt")) {
        fprintf(stderr, "Failed to load the deck.\n");
        // Handle error
    }
    return 0;
}