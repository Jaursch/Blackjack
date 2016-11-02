#include <time.h>
#include "./deck.h"


/*************************************************************************
 ** Function: deck
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: deck constructed
 ************************************************************************/
deck::deck(){
       	num_cards=52;
	card * d = make_deck();
	set_deck(d); 

} 

/*************************************************************************
 ** Function: ~deck
 ** Description: destructor
 ** Parameters: none
 ** Pre-Conditions: deck initialized
 ** Post-Conditions: deck destroyed
 ************************************************************************/
deck::~deck(){
}


/*************************************************************************
 ** Function: num_cards
 ** Description: returns number of cards in deck
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: num_cards will be returned
 ************************************************************************/
int deck::get_num_cards(){
	return num_cards;
}

/*************************************************************************
 ** Function: make_deck
 ** Description: creates a deck on the heap
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: deck will be created
 ************************************************************************/
card * deck::make_deck(){
   	card *d = new card[52];
	for(int i=0; i<52; i++)
	  	d[i].faced_up = true; //all shown
	for(int i=0; i<13; i++)
      		d[i].suit = "spades";
	for(int i=13; i<26; i++)
   		d[i].suit = "hearts";
	for(int i=26; i<39; i++)
   		d[i].suit = "clubs";
	for(int i=39; i<52; i++)
   		d[i].suit = "diamonds";
	for(int i=0; i<52;){
		for(int k=0; k<4; k++){
			for(int n=1; n<11; n++){
				d[i].value=n; //value 1-10
				i++;
			}for(int n=0; n<3; n++){
				d[i].value=10;
				i++;
			}  
		} 
	}for(int i=0; i<52;){
		for(int k=0; k<4; k++){
			d[i].face='A';
			i+=10;
			d[i].face='J'; i++;
			d[i].face='Q'; i++;
			d[i].face='K'; i++;
		}	
	}return d;  	
};

/*************************************************************************
 ** Function: set_deck
 ** Description: set deck on stack of game function
 ** Parameters: card *
 ** Pre-Conditions: deck must have 52 members
 ** Post-Conditions: deck on stack, heap array deleted
 ************************************************************************/
void deck::set_deck(card *d){
	for(int i=0; i<52; i++){
		cards[i] = d[i]; //now on stack
	}delete [] d; 
} 

/*************************************************************************
 ** Function: shuffle_deck
 ** Description: deck is shuffled
 ** Parameters: deck &
 ** Pre-Conditions: deck must have members
 ** Post-Conditions: deck will be shuffled up
 ************************************************************************/
void deck::shuffle_deck(deck &d){
	cout << "The dealer shuffles the cards..." << endl; 
   	srand(time(0));
       	for(int i=0; i<1000; i++){
		int c1 = rand() % d.get_num_cards(); //used in recitation
	       	int c2 = rand() % d.get_num_cards();
		card temp = d.cards[c1];
		d.cards[c1] = d.cards[c2];
		d.cards[c2] = temp;	
	} 	
}

/*************************************************************************
 ** Function: print_deck
 ** Description: prints out the deck
 ** Parameters: deck
 ** Pre-Conditions: none 
 ** Post-Conditions: deck will be printed
 ************************************************************************/
void deck::print_deck(deck d){
	for(int i=0; i<num_cards; i++){
		cout << d.cards[i].face << " of " << d.cards[i].suit; 
		cout << d.cards[i].value << endl; 
	} 
}

/*************************************************************************
 ** Function: remove_card
 ** Description: removes card from the deck, returns that card
 ** Parameters: none
 ** Pre-Conditions: num_cards > 0
 ** Post-Conditions: num_cards lessened, card returned
 ************************************************************************/
card deck::remove_card(){
	num_cards = num_cards-1;
	return cards[num_cards]; //returns card now not seen on deck
} 
