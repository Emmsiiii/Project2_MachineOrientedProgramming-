#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include "deck.h"
#include <stdbool.h>

void saveDeck(const char *filename, column *deck[]);
void loadDeck(const char *filename, column *deck[]);

#endif


