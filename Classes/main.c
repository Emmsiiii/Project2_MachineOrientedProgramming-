//
#include <stdio.h>
#include "deck.h"

int main() {

    // opretter ny liste
    List* myList = createList();

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
    Node* foundNode = findCard(myList, card2);
    if (foundNode != NULL) {
        printf("Found card: %s%c\n", foundNode->card.rank, foundNode->card.suit);
    } else {
        printf("Card not found.\n");
    }

    // sletter listen
    destroyList(myList);

    return 0;
}

// Created by Emma Rebner on 03/04/2024.
//
