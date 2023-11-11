/* 
	000000000000000000000
	THE HANDLER
	000000000000000000000

	Program that:
		Implements cards like a stucts.
		Deal a random hand of cards
		Calculate the probability of the hand ocurring by counting at least 1 Million Hands
*/

#define NUMBER_COMBINATIONS 1000000

typedef enum Card_Family { hearts, spades, diamonds, clubs } Card_Family;

typedef struct Card {
	int num;
	Card_Family family;
	
} Card;

int main (void) {
	return 0;
}
