
#ifndef PROJECT2_MACHINEORIENTEDPROGRAMMING__CARD_H
#define PROJECT2_MACHINEORIENTEDPROGRAMMING__CARD_H
#include <stdbool.h>

typedef enum {
    hearts,
    diamonds,
    spades,
    clubs
} SuitType;

typedef struct {
    int value;
    SuitType suit;
    bool visible;
} Card;

Card* createCard(int value, SuitType suit, bool visible);
void destroyCard(Card* card);


#endif //PROJECT2_MACHINEORIENTEDPROGRAMMING__CARD_H
