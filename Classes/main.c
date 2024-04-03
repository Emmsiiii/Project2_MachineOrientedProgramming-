// Created by Emma Rebner on 03/04/2024.
//

#include <stdio.h>
#include <stdbool.h> // Include this for bool type if using C99 or later

// defining a struct to represent a playing card
typedef struct {
    char rank;       // Using chars like 'A', '2', ..., '10', 'J', 'Q', 'K'
    char suit;       // Using chars like 'H', 'D', 'C', 'S' for hearts, diamonds, clubs, spades
    bool isVisible;  // true for face up, false for face down
};


int main() {
        Card myCard;

        myCard.rank = 'A';       // Ace
        myCard.suit = 'H';       // Hearts
        myCard.isVisible = true; // The card is face up

        printf("Card: %s of %c\n", myCard.rank, myCard.suit);
        printf("Visible: %s\n", myCard.isVisible ? "Yes" : "No");

        return 0;
    }
