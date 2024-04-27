#include <MacTypes.h>
#include "cards.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Implementations of the functions declared in cards.h
// Takes a node struct (card) and changes a str to match the representation of the card.
// str is the pointer to the string. E.g. 7 of spades becomes 7S.
void cardToString(char *str,struct node *card){
    if(card == NULL){
        return;
    }

    if(!card->visible){
        str[0]='[';
        str[1] = ']';
        return;
    }

    switch (card->cardValue) {
        case 1:
            str[0] = 'A';
            break;
        case 10:
            str[0] = 'T';
            break;
        case 11:
            str[0] = 'J';
            break;
        case 12:
            str[0] = 'Q';
            break;
        case 13:
            str[0] = 'K';
            break;
        default:
            str[0] = card->cardValue + '0';
            break;

    }

    char suitNames[4] = {3,4,6,5};
    str[1] = suitNames[card->suit];
}


//Reveals all cards in a column
void showColumn(struct linkedList *col){
    struct node *el = col->head;
    while (el != NULL){
        el->visible = true;
        el = el->next;
    }
}


//Reveals all cards
char *showCards(){
    if(A.head == NULL){
        return "ERROR: No deck loaded";
    }
    showColumn(&C1);
    showColumn(&C2);
    showColumn(&C3);
    showColumn(&C4);
    showColumn(&C5);
    showColumn(&C6);
    showColumn(&C7);
    return "OK";
}