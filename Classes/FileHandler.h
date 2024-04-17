#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include "deck.h"

bool loadDeck(struct DeckNode** head, const char* filename);
bool validateDeck(struct DeckNode* head);

#endif // FILE_HANDLER_H
