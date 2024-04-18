#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"


// Double linked list
deckNode* createDeckNode(char rank, char suit) {
    deckNode* newNode = (deckNode*)malloc(sizeof(deckNode));
    newNode->card.rank = rank;
    newNode->card.suit = suit;
    newNode->next = NULL;
    return newNode;
}

// Implementation of the printList function
void printList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->card.isVisible) {
            printf("%c%c ", current->card.rank, current->card.suit);
        } else {
            printf("[] ");
        }
        current = current->next;
    }
    printf("\n");
}

// Function to load deck from a file
//struct DeckNode* loadDeck(const char* filename) {
    // Implementation goes here


// Subtask 2.1: Create and Destroy
/*List* createList() {
    List* newList = (List*)malloc(sizeof(List));
    if (newList != NULL) {
        newList->head = NULL;
        newList->size = 0;
    }
    return newList;
}

void destroyList(List* list) {
    if (list != NULL) {
        Node* current = list->head;
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
        free(list);
    }
}

// Subtask 2.2: Insertion and Deletion
void insertAtHead(List* list, struct card card) {
    Node* newNode = createNode(card);
    if (newNode != NULL) {
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
    }
}

void insertAtTail(List* list, struct card card) {
    Node* newNode = createNode(card);
    if (newNode != NULL) {
        if (list->head == NULL) {
            list->head = newNode;
        } else {
            Node* current = list->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        list->size++;
    }
}

void removeNode(List* list, Node* nodeToRemove) {
    if (list->head == NULL || nodeToRemove == NULL) {
        return;
    }

    if (list->head == nodeToRemove) {
        list->head = nodeToRemove->next;
    } else {
        Node* current = list->head;
        while (current != NULL && current->next != nodeToRemove) {
            current = current->next;
        }
        if (current != NULL) {
            current->next = nodeToRemove->next;
        }
    }
    free(nodeToRemove);
    list->size--;
}

// Subtask 2.3: Searching and Traversal
void printList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->card.isVisible) {
            printf("%c%c ", current->card.rank, current->card.suit);
        } else {
            printf("[] ");
        }
        current = current->next;
    }
    printf("\n");
}
 */

