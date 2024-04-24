// main.c
#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "move.h"
#include "FileHandler.h"

int main() {
    column *deck[7];
    for (int i = 0; i < 7; i++) {
        deck[i] = createDeck();
        deck[i]->size = i + 1;
    }
    column *foundations[4];
    for (int i = 0; i < 4; i++) {
        foundations[i] = createDeck();
        foundations[i]->size = 0;
        foundations[i]->capacity = 14;
    }

    char command;
    do {
        displayColumns(deck);
        printf("Enter a command (M = move, S = save, L = load, Q = quit): ");
        scanf(" %c", &command);
        switch (command) {
            case 'M': {
                int fromColumn, toColumn, cardIndex;
                printf("Enter source column (1-7): ");
                scanf("%d", &fromColumn);
                printf("Enter destination column (1-7 or F1-F4 for foundations): ");
                scanf("%d", &toColumn);
                printf("Enter card index (1-20): ");
                scanf("%d", &cardIndex);
                if (toColumn >= 1 && toColumn <= 7) {
                    moveCard(deck[fromColumn - 1], deck[toColumn - 1], cardIndex - 1);
                } else if (toColumn >= 'F' && toColumn <= 'F' + 3) {
                    moveCardToFoundation(deck[fromColumn - 1], foundations[toColumn - 'F']);
                } else {
                    printf("Invalid destination column!\n");
                }
                break;
            }
            case 'S': {
                char filename[100];
                printf("Enter filename to save: ");
                scanf("%s", filename);
                saveDeck(filename, deck);
                break;
            }
            case 'L': {
                char filename[100];
                printf("Enter filename to load: ");
                scanf("%s", filename);
                loadDeck(filename, deck);
                break;
            }
            case 'Q':
                printf("Quitting game...\n");
                break;
            default:
                printf("Invalid command! Please try again.\n");
        }
    } while (command != 'Q');

    for (int i = 0; i < 7; i++) {
        destroyColumn(deck[i]);
    }
    for (int i = 0; i < 4; i++) {
        destroyColumn(foundations[i]);
    }

    return 0;
}


