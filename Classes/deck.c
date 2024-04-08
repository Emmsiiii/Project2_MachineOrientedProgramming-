//
// Created by Emma Rebner on 03/04/2024.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> // include for malloc


// Subtask 1.1: Define Card Struct
struct Card {
    char rank[10];       // Enough space for '10' plus a null terminator
    char suit;          // Suit of the card (e.g., 'H' for hearts, 'S' for spades)
    bool isVisible;     // Visibility of the card (0 for face down, 1 for face up)
};

// Subtask 1.2: Define Node Struct
typedef struct Node {
    struct Card card;          // Card held by the node
    struct Node* next;  // Pointer to the next node
} Node;

// Subtask 1.3: Define List Struct
typedef struct {
    Node* head;         // Pointer to the head node of the list
    int size;           // Size of the list (optional)
} List;

// Subtask 2.1: Create and Destroy
List* createList() {
    List* newList = (List*)malloc(sizeof(List));
    if (newList != NULL) {
        newList->head = NULL;
        newList->size = 0;
    }
    return newList;
}

Node* createNode(struct Card card) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->card = card;
        newNode->next = NULL;
    }
    return newNode;
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
void insertAtHead(List* list, struct Card card) {
    Node* newNode = createNode(card);
    if (newNode != NULL) {
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
    }
}

void insertAtTail(List* list, struct Card card) {
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
        printf("%c%c ", current->card.rank, current->card.suit);
        current = current->next;
    }
    printf("\n");
}

Node* findCard(List* list, struct Card cardToFind) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->card.rank == cardToFind.rank && current->card.suit == cardToFind.suit) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// deck into 7 coloumns



