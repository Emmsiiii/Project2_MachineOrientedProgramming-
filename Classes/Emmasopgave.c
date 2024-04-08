//
#include <stdio.h>
#include <stdlib.h>

// Subtask 1.1: Define Card Struct
typedef struct {
    char rank;          // Rank of the card (e.g., 'A', '2', 'K')
    char suit;          // Suit of the card (e.g., 'H' for hearts, 'S' for spades)
    int visibility;     // Visibility of the card (0 for face down, 1 for face up)
} Card;

// Subtask 1.2: Define Node Struct
typedef struct Node {
    Card card;          // Card held by the node
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

Node* createNode(Card card) {
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
void insertAtHead(List* list, Card card) {
    Node* newNode = createNode(card);
    if (newNode != NULL) {
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
    }
}

void insertAtTail(List* list, Card card) {
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

Node* findCard(List* list, Card cardToFind) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->card.rank == cardToFind.rank && current->card.suit == cardToFind.suit) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    List* myList = createList();

    Card card1 = {'A', 'H', 1};
    Card card2 = {'2', 'D', 0};
    Card card3 = {'K', 'S', 1};

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
