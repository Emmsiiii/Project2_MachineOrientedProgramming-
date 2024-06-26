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

    // Print the initial view when the game starts
    printInitialView();

    struct DeckNode **head = NULL; // Start with an empty list

    // opretter kort
    struct Card card1 = {"A", 'H', true};  // Rank is a string, so use double quotes
    struct Card card2 = {"2", 'D', false}; // Same as above, use double quotes
    struct Card card3 = {"K", 'S', true};  // Same as above

    // indsætter kort i liste
    insertAtHead(myList, card1);
    insertAtTail(myList, card2);
    insertAtTail(myList, card3);

    /*
    // udskriver listen
    printf("List contents: ");
    printList(myList);
    */

    /*
    // finder og fjerner et kort
    Node *foundNode = findCard(myList, card2);
    if (foundNode != NULL) {
        printf("Removing card: %s%c\n", foundNode->card.rank, foundNode->card.suit);
        removeNode(myList, foundNode);
    } else {
        printf("Card not found.\n");
    }
     */

    /*
    // Printer listen efter sletningen
    printf("List contents after deletion: ");
    printList(myList);
    */

    /*
    // sletter listen
    destroyList(myList);
    */

    // Now enter into the game loop or the rest of your game logic
    char command[10];
    while (1) {
        // Get user command
        printf("\nINPUT > ");
        scanf("%9s", command);

        // Process the command
        if (strcmp(command, "LD") == 0) {
            char filename[100];
            printf("Enter deck filename: ");
            scanf("%99s", filename);

            if (!loadDeck((struct DeckNode **) &head, filename)) {
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
    if (!loadDeck((struct DeckNode **) &head, "deck.txt")) {
        fprintf(stderr, "Failed to load the deck.\n");
        // Handle error
    }

    destroyList((List *) head);

    return 0;
}