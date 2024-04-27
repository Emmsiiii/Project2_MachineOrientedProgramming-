#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Implementations of the functions declared in deck.h
//Inserts element in the beginning
void insert(struct linkedList *list, int cardValue, enum suitType suit, bool visible){
    struct node *newNodeLink = (struct node*) malloc(sizeof (struct node));
    newNodeLink->cardValue = cardValue;
    newNodeLink->suit = suit;
    newNodeLink->next = list->head;
    newNodeLink->visible = visible;
    list->head = newNodeLink;
}


void insertLast(struct linkedList *list, int cardValue, enum suitType suit, bool visible){
    struct node *newNodeLink = (struct node*) malloc(sizeof (struct node));
    newNodeLink->cardValue = cardValue;
    newNodeLink->suit = suit;
    newNodeLink->next = NULL;
    newNodeLink->visible = visible;
    if(list->head == NULL){
        list->head = newNodeLink;
    } else{
        struct node *lastElement = list->head;
        while(lastElement->next != NULL){
            lastElement = lastElement->next;
        }
        lastElement->next = newNodeLink;
    }
}


void insertRandom(struct linkedList *list, int cardValue, enum suitType suit, bool visible){
    int post = rand() %52;
    struct node *el= list->head;
    struct node* previous= NULL;
    for (int i = 0; i < post && el != NULL; ++i) {
        previous=el;
        el=el->next;
    }
    struct node *newNodeLink = (struct node*) malloc(sizeof (struct node));
    newNodeLink->cardValue = cardValue;
    newNodeLink->suit = suit;
    newNodeLink->next = NULL;
    newNodeLink->visible = visible;

    newNodeLink->next=el;
    if (previous==NULL){
        list->head=newNodeLink;
    } else{
        previous->next=newNodeLink;
    }
}


//Returns pointer to node(card) that matches card value and suit
struct node* findElement(struct linkedList *list, int cardValue, enum suitType suit){
    struct node* el = list->head;

    if(list->head == NULL){
        return NULL;
    }

    while (el->cardValue != cardValue || el->suit != suit){
        if(el->next == NULL){
            return NULL;
        } else{
            el = el->next;
        }
    }
    return el;
}


struct node* findLastElement(struct linkedList *list){
    struct node* el = list->head;
    if(el == NULL){
        return NULL;
    }

    while (el->next != NULL){
        el = el->next;
    }
    return  el;
}


//Delete from element (the given element and all the following)
struct node* deleteFrom(struct linkedList *list, int cardValue, enum suitType suit){
    struct node* el = list->head;
    struct node* prev = NULL;
    if(list->head == NULL){
        return NULL;
    }
    while (el->cardValue != cardValue || el->suit != suit){
        if(el->next == NULL){
            return NULL;
        } else{
            prev = el;
            el = el->next;
        }
    }
    if(el == list->head){
        list->head = NULL;
    } else{
        prev->next = NULL;
    }
    if(prev != NULL){
        prev->visible = true;
    }
    return el;
}

// Loads a file and puts the cards in the columns. First horizontal from left to right and then vertical from top to bottom.
// Right now they get inserted in reversed order (can be fixed by changing the insert() method)
char* loadCardDeck(char* name){

    FILE *filePointer;

    if (access(name, F_OK) != 0) {
        filePointer = fopen("DefaultDeck.txt", "r");
    } else {
        filePointer = fopen(name, "r");
    }


    char line[256];
    int cardIndex = 1;

    A.head = NULL;
    C1.head = NULL;
    C2.head = NULL;
    C3.head = NULL;
    C4.head = NULL;
    C5.head = NULL;
    C6.head = NULL;
    C7.head = NULL;


    while (fgets(line, sizeof (line), filePointer)){
        struct node *newCard = (struct node*) malloc(sizeof (struct node));
        switch (line[0]) {
            case 'A':
                newCard->cardValue = 1;
                break;
            case 'T':
                newCard->cardValue = 10;
                break;
            case 'J':
                newCard->cardValue = 11;
                break;
            case 'Q':
                newCard->cardValue=12;
                break;
            case 'K':
                newCard->cardValue = 13;
                break;
            default:
                newCard->cardValue = line[0]-'0';
                break;
        }


        switch (line[1]) {
            case 'H':
                newCard->suit = hearts;
                break;
            case 'D':
                newCard->suit = diamonds;
                break;
            case 'S':
                newCard->suit = spades;
                break;
            case 'C':
                newCard->suit = clubs;
                break;
        }

        insertLast(&A, newCard->cardValue,newCard->suit, false);

        switch (cardIndex%7) {
            case 1:
                insertLast(&C1, newCard->cardValue, newCard->suit, false);
                break;
            case 2:
                insertLast(&C2, newCard->cardValue, newCard->suit, false);
                break;
            case 3:
                insertLast(&C3, newCard->cardValue, newCard->suit, false);
                break;
            case 4:
                insertLast(&C4, newCard->cardValue, newCard->suit, false);
                break;
            case 5:
                insertLast(&C5, newCard->cardValue, newCard->suit, false);
                break;
            case 6:
                insertLast(&C6, newCard->cardValue, newCard->suit, false);
                break;
            default:
                insertLast(&C7, newCard->cardValue, newCard->suit, false);
                break;

        }
        cardIndex += 1;

    }
    fclose(filePointer);
    return "OK";
}

// Should save the cards in the columns to a file
char* saveCardDeck(char* filename){

    FILE *fb;

    if (access(filename, F_OK) != 0) {
        fb = fopen("card.txt", "w");
    } else {
        fb = fopen(filename, "w");
    }

    struct node *el = A.head;

    while (el != NULL){
        switch (el->cardValue) {
            case 1:
                putc('A', fb);
                break;
            case 10:
                putc('T', fb);
                break;
            case 11:
                putc('J', fb);
                break;
            case 12:
                putc('Q', fb);
                break;
            case 13:
                putc('K', fb);
                break;
            default:
                fprintf(fb, "%d", el->cardValue);
                break;
        }
        switch (el->suit) {
            case hearts:
                putc('H',fb);
                break;
            case diamonds:
                putc('D',fb);
                break;
            case spades:
                putc('S',fb);
                break;
            case clubs:
                putc('C',fb);
                break;
        }
        putc('\n', fb); // Add a newline character
        el = el->next;
    }
    fclose(fb);
    return "Game saved";
}


char* splitCards(char* splitLine){
    if(A.head == NULL){
        return "Error: No deck loaded";
    }
    int line;

    if(splitLine != NULL){
        sscanf(splitLine, "%d", &line);
    } else{
        srand(time(NULL));
        line = rand() % 52 + 1;
    }

    if(line >= 52 || line <= 0){
        return "Error: The line where to split the deck should be between 1 and 51";
    }


    struct node *el = A.head;
    pile1.head = NULL;
    pile2.head = NULL;
    splitPile.head = NULL;

    for (int i = 0; i < line; ++i) {
        insert(&pile1,el->cardValue,el->suit,el->visible);
        el = el->next;
    }
    while (el != NULL){
        insert(&pile2,el->cardValue,el->suit,el->visible);
        el = el->next;
    }

    struct node *newEl = pile1.head;
    struct node *newEl2 = pile2.head;
    bool pileOne = true;
    while (newEl != NULL && newEl2 != NULL) {
        if (pileOne == true) {
            insert(&splitPile, newEl->cardValue, newEl->suit, newEl->visible);
            newEl = newEl->next;
            if (newEl2 != NULL) {
                pileOne = false;
            }
        } else {
            insert(&splitPile, newEl2->cardValue, newEl2->suit, newEl2->visible);
            newEl2 = newEl2->next;
            if (newEl != NULL) {
                pileOne = true;
            }
        }
    }
    if (newEl != NULL){
        while (newEl != NULL){
            insertLast(&splitPile, newEl->cardValue, newEl->suit, newEl->visible);
            newEl = newEl->next;
        }
    } else if (newEl2 != NULL){
        while (newEl2 != NULL){
            insertLast(&splitPile, newEl2->cardValue, newEl2->suit, newEl2->visible);
            newEl2 = newEl2->next;
        }
    }

    A.head = splitPile.head;
    updateCardPiles();
    return "Ok";
}


char* shuffleRandom(){
    if(A.head == NULL){
        return "Error: No deck loaded";
    }
    struct node *el=A.head;
    shufflePile.head = NULL;
    while(el!= NULL) {
        insertRandom(&shufflePile,el->cardValue,el->suit,el->visible);
        el=el->next;
    }
    A.head=shufflePile.head;
    updateCardPiles();
    return "Ok";
}


char* shuffleRandom(){
    if(A.head == NULL){
        return "Error: No deck loaded";
    }
    struct node *el=A.head;
    shufflePile.head = NULL;
    while(el!= NULL) {
        insertRandom(&shufflePile,el->cardValue,el->suit,el->visible);
        el=el->next;
    }
    A.head=shufflePile.head;
    updateCardPiles();
    return "Ok";
}

void updateCardPiles(){
    C1.head = NULL;
    C2.head = NULL;
    C3.head = NULL;
    C4.head = NULL;
    C5.head = NULL;
    C6.head = NULL;
    C7.head = NULL;

    struct node *el = A.head;
    int cardIndex = 1;
    while (el != NULL){
        switch (cardIndex%7) {
            case 1:
                insertLast(&C1, el->cardValue, el->suit, false);
                break;
            case 2:
                insertLast(&C2, el->cardValue, el->suit, false);
                break;
            case 3:
                insertLast(&C3, el->cardValue, el->suit, false);
                break;
            case 4:
                insertLast(&C4, el->cardValue, el->suit, false);
                break;
            case 5:
                insertLast(&C5, el->cardValue, el->suit, false);
                break;
            case 6:
                insertLast(&C6, el->cardValue, el->suit, false);
                break;
            default:
                insertLast(&C7, el->cardValue, el->suit, false);
                break;
        }
        el = el->next;
        cardIndex += 1;
    }
}
