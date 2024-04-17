#ifndef DECK_H
#define DECK_H
#include <stdbool.h>

// Subtask 1.1: Define Card Struct
struct Card {
    char rank[3];       // Enough space for '10' plus a null terminator
    char suit;          // bruger chars som 'H', 'D', 'C', 'S' for hearts, diamonds, clubs, spades
    bool isVisible;     // Visibility of the card (0 for face down, 1 for face up)
};

typedef struct DeckNode {
    struct Card card;
    struct DeckNode* next;
} deckNode;

// Subtask 1.2: Define Node Struct
typedef struct Node {
    struct Card card;          // Card held by the node
    struct Node* next;         // Pointer to the next node
} Node;

// Subtask 1.3: Define List Struct
typedef struct List {
    Node* head;                // Pointer to the head node of the list
    int size;                  // Size of the list (optional)
} List;

// Subtask 2.1: Create and Destroy Functions
List* createList();
Node* createNode(struct Card card);
void destroyList(List* list);

// Subtask 2.2: Insertion and Deletion Functions
void insertAtHead(List* list, struct Card card);
void insertAtTail(List* list, struct Card card);
void removeNode(List* list, Node* nodeToRemove);

// Subtask 2.3: Searching and Traversal Functions
void printList(List* list);
Node* findCard(List* list, struct Card cardToFind);

// End if directive for DECK_H
#endif