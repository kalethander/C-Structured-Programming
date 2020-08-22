/*
Deck of cards
Kyle Lethander
Aug. 14, 2020
*/

// struct defines card with a suit and a pips

#include <stdio.h>
#include <stdlib.h>

#define NUM_CARDS 52
#define EMPTY_STACK -1

typedef enum suits {diamonds, hearts, clubs, spades} suit;
typedef enum pips {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king} pips;

typedef struct card{
    suit suit;
    pips pips;
} card;

typedef struct stack {
    card deck[NUM_CARDS];
    int top;
} stack;

void print_suit( card card)
{
    switch (card.suit) {
	case(1): printf(" of diamonds"); break;
	case(2): printf(" of hearts"); break;
	case(3): printf(" of clubs"); break;
	case(4): printf(" of spades"); break;
	default: printf("Invalid suit"); break;
    }
}

void print_pips( card card)
{
    switch (card.pips) {
	case(1): printf("Ace"); break;
	case(2): printf("two"); break;
	case(3): printf("three"); break;
	case(4): printf("four"); break;
	case(5): printf("five"); break;
	case(6): printf("six"); break;
	case(7): printf("seven"); break;
	case(8): printf("eight"); break;
	case(9): printf("nine"); break;
	case(10): printf("ten"); break;
	case(11): printf("jack"); break;
	case(12): printf("queen"); break;
	case(13): printf("king"); break;
	default: printf("Invalid pips"); break;
    }
}

void deck_shuffle( stack* deck)
{
    deck -> top = EMPTY_STACK;
    for( int i = 0; i < NUM_CARDS; i++) {
	deck -> top++;
	deck -> deck[deck -> top].suit = rand() % 4;
	deck -> deck[deck -> top].pips = rand() % 13;
    }
}

int main(void)
{
    stack* deck = (stack*)malloc(sizeof(stack));
    deck_shuffle( deck);
    printf("The top card is the ");
    print_pips( deck -> deck[deck -> top]);
    print_suit( deck -> deck[deck -> top]);

    return 0;
}