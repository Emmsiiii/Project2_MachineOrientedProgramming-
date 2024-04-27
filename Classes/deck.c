#include "deck.h"
#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include <string.h> // For strcmp
#include <time.h>

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
        if (current->card.isVisible) {
            printf("%s%c ", current->card.rank, current->card.suit);
        } else {
            printf("[] ");
        }
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

void shuffleInterleave(struct DeckNode **head) {
    if (*head == NULL || (*head)->next == NULL) return;  // No need to shuffle if deck is too small

    struct DeckNode *slow = *head;
    struct DeckNode *fast = (*head)->next;
    // Using the slow and fast pointer technique to find the middle of the list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct DeckNode *second = slow->next;
    slow->next = NULL; // Split the list into two parts
    struct DeckNode *first = *head;

    // Now interleave first and second parts
    while (first != NULL && second != NULL) {
        struct DeckNode *temp1 = first->next;
        struct DeckNode *temp2 = second->next;

        first->next = second; // Link first node of second part after first part
        if (temp1 != NULL) {
            second->next = temp1; // Link next node of first part after second part node
        }

        first = temp1;
        second = temp2;
    }
}


void shuffleRandom(struct DeckNode **head) {
    if (*head == NULL) return; // No need to shuffle if the list is empty

    // First, count the number of nodes in the list
    int count = 0;
    struct DeckNode *current = *head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    if (count < 2) return; // No need to shuffle if there's 0 or 1 node

    // Allocate space for an array of pointers to nodes
    struct DeckNode **array = malloc(count * sizeof(struct DeckNode *));
    if (array == NULL) return; // Handle memory allocation failures

    // Populate the array
    int i = 0;
    current = *head;
    while (current != NULL) {
        array[i++] = current;
        current = current->next;
    }

    // Shuffle using the Fisher-Yates algorithm
    srand(time(NULL)); // Seed the random number generator
    for (int i = count - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        // Swap nodes i and j in the array
        struct DeckNode *temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // Relink the nodes in the list
    for (int i = 0; i < count - 1; i++) {
        array[i]->next = array[i + 1];
    }
    array[count - 1]->next = NULL; // Last node points to NULL

    // Update the head of the list
    *head = array[0];

    // Free the array
    free(array);
}


void saveDeck(struct DeckNode **head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Unable to open file %s for writing.\n", filename);
        return;
    }
    struct DeckNode *current = *head;
    while (current != NULL) {
        fprintf(file, "%s%c\n", current->card.rank, current->card.suit);
        current = current->next;
    }
    fclose(file);
}
