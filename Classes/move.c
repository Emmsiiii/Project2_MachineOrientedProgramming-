#include <stdbool.h>
#include <string.h>
#include "move.h"
#include "deck.h"

bool isMoveCommand(char* cm){
    int l = strlen(cm);
    if(l != 6 && l != 9){
        return false;
    }
    if(cm[2] != '-' || cm[3] != '>'){
        if(l != 9){
            return false;
        }
        if(cm[5] != '-' || cm[6] != '>'){
            return false;
        }
        if(cm[2] != ':'){
            return false;
        }

    } else {
        if(l != 6){
            return false;
        }
    }

    if(l == 6){
        if(cm[0] ==  cm[4] ){
            return false;
        }
    }
    return true;
}


char* moveCards(char* cm) {
    int l = strlen(cm);

    struct linkedList *sourcePile;
    struct linkedList *targetPile;
    int from = cm[1] - '0';
    int to = (l == 9) ? cm[8] - '0' : cm[5] - '0';

    // Determining the source pile
    if (cm[0] == 'C') {
        sourcePile = (from == 1) ? &C1 : (from == 2) ? &C2 : (from == 3) ? &C3 : (from == 4) ? &C4 : (from == 5) ? &C5 : (from == 6) ? &C6 : &C7;
    } else if (cm[0] == 'F') {
        sourcePile = (from == 1) ? &F1 : (from == 2) ? &F2 : (from == 3) ? &F3 : &F4;
    }

    // Determining the target pile
    if (cm[l == 9 ? 7 : 4] == 'C') {
        targetPile = (to == 1) ? &C1 : (to == 2) ? &C2 : (to == 3) ? &C3 : (to == 4) ? &C4 : (to == 5) ? &C5 : (to == 6) ? &C6 : &C7;
    } else if (cm[l == 9 ? 7 : 4] == 'F') {
        targetPile = (to == 1) ? &F1 : (to == 2) ? &F2 : (to == 3) ? &F3 : &F4;
    }

    enum suitType st;
    int cardValue = 0;
    struct node *fromCard;

    // Parse card value and suit if the command length is 9 (specific card is mentioned)
    if (l == 9) {
        char cardChar = cm[3];
        char suitChar = cm[4];
        cardValue = (cardChar == 'A') ? 1 : (cardChar == 'T') ? 10 : (cardChar == 'J') ? 11 : (cardChar == 'Q') ? 12 : (cardChar == 'K') ? 13 : cardChar - '0';
        st = (suitChar == 'H') ? hearts : (suitChar == 'D') ? diamonds : (suitChar == 'C') ? clubs : spades;
        fromCard = findElement(sourcePile, cardValue, st);
    } else {
        fromCard = findLastElement(sourcePile);
    }

    struct node *toCard = findLastElement(targetPile);

    // Validation of the move
    if (fromCard == NULL || !fromCard->visible) {
        return "No such card in source pile!";
    } else if (toCard != NULL) {
        if ((cm[l == 9 ? 7 : 4] == 'F' && (fromCard->suit != toCard->suit || fromCard->cardValue != toCard->cardValue + 1)) ||
            (cm[l == 9 ? 7 : 4] != 'F' && (fromCard->suit == toCard->suit || fromCard->cardValue != toCard->cardValue - 1))) {
            return "Invalid move!";
        }
    }

    // Execute the card move
    struct node* card = deleteFrom(sourcePile, fromCard->cardValue, fromCard->suit);
    if (targetPile->head == NULL) {
        targetPile->head = card;
    } else {
        struct node *current = targetPile->head;
        while (current->next) {
            current = current->next;
        }
        current->next = card;
    }

    return checkWinCon() ? "You won!!!" : "Moved cards";
}