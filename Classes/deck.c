#include "deck.h"
#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include <string.h> // For strcmp

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
        // Use %s for printing the string rank and %c for the single char suit
        printf("%s%c ", current->card.rank, current->card.suit);
        current = current->next;
    }
    printf("\n");
}

Node* findCard(List* list, struct Card cardToFind) {
    Node* current = list->head;
    while (current != NULL) {
        // Use strcmp for string comparison and correct access to card fields
        if (strcmp(current->card.rank, cardToFind.rank) == 0 && current->card.suit == cardToFind.suit) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// deck into 7 coloumns



