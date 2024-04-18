
#include <stdio.h>
#include "deck.h"
#include <string.h>

void save_deck_to_a_file(deckNode* head, char* filename) {
    char file_path[100];
    sprintf(file_path, "Files/%s", filename);

    FILE* fp = fopen(file_path, "w");
    if (fp == NULL) {
        printf("Error: unable to open file.\n");
        return;
    }

    deckNode* current = head;
    while (current != NULL) {
        fprintf(fp, "%c%c\n", current->card.rank, current->card.suit);
        current = current->next;
    }

    fclose(fp);
}

