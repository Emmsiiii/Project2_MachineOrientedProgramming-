//
// Created by Emma Rebner on 27/04/2024.
//

#ifndef PROJECT2_MACHINEORIENTEDPROGRAMMING__FILEHANDLER_H
#define PROJECT2_MACHINEORIENTEDPROGRAMMING__FILEHANDLER_H

#include "deck.h"

#define FILENAME_MAX_LENGTH 256

bool loadCardDeckFromFile(Deck* deck, const char* filename);
bool saveCardDeckToFile(Deck* deck, const char* filename);

#endif //PROJECT2_MACHINEORIENTEDPROGRAMMING__FILEHANDLER_H
