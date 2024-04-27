#ifndef DECK_H
#define DECK_H

#include <stdbool.h>

enum suitType { hearts, diamonds, spades, clubs };

struct node {
    int cardValue;
    bool visible;
    enum suitType suit;
    struct node *next;
};

struct linkedList {
    struct node *head;
};

void insert(struct linkedList *list, int cardValue, enum suitType suit, bool visible);
void insertLast(struct linkedList *list, int cardValue, enum suitType suit, bool visible);
void insertRandom(struct linkedList *list, int cardValue, enum suitType suit, bool visible);
struct node* findElement(struct linkedList *list, int cardValue, enum suitType suit);
struct node* findLastElement(struct linkedList *list);
struct node* deleteFrom(struct linkedList *list, int cardValue, enum suitType suit);
char* loadCardDeck(char* name);
char* saveCardDeck(char* filename);
char* splitCards(char* splitLine);
char* shuffleRandom();
void updateCardPiles();

#endif //DECK_H