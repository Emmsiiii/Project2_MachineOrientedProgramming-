//
#include <stdio.h>
#include "deck.c"

int main() {
    List* myList = createList();

    struct Card card1 = {'A', 'H', 1};
    struct Card card2 = {'2', 'D', 0};
    struct Card card3 = {'K', 'S', 1};

    insertAtHead(myList, card1);
    insertAtTail(myList, card2);
    insertAtTail(myList, card3);

    printf("List contents: ");
    printList(myList);

    Node* foundNode = findCard(myList, card2);
    if (foundNode != NULL) {
        printf("Found card: %c%c\n", foundNode->card.rank, foundNode->card.suit);
    } else {
        printf("Card not found.\n");
    }

    destroyList(myList);

    return 0;
}

// Created by Emma Rebner on 03/04/2024.
//
