#include <stdio.h>
#include <stdbool.h> // Include this for bool type if using C99 or later
#include <string.h> // Include this for strcpy and other string functions


// Define a struct to represent a playing card
struct Card {
    char rank[3];     // Enough space for '10' plus a null terminator
    char suit;        // Using chars like 'H', 'D', 'C', 'S' for hearts, diamonds, clubs, spades
    bool isVisible;   // true for face up, false for face down
};

int main() {
    struct Card myCard;

    // Example of setting a card's properties
    // For a two-character rank like '10', we need to copy a string
    strcpy(myCard.rank, "10");  // Use strcpy to safely copy the string into the rank array
    myCard.suit = 'H';          // Hearts
    myCard.isVisible = true;    // The card is face up

    // Print card information
    printf("Card: %s of %c\n", myCard.rank, myCard.suit);
    printf("Visible: %s\n", myCard.isVisible ? "Yes" : "No");

    return 0;
}
