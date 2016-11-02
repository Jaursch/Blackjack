#include "./hand.h"

/*************************************************************************
 ** Function: hand
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: initialized
 ************************************************************************/
hand::hand(){
	num_cards = 0; 
} 

/*************************************************************************
 ** Function: ~hand
 ** Description: destructor
 ** Parameters: none
 ** Pre-Conditions: cards initiialized
 ** Post-Conditions: hand deleted
 ************************************************************************/
hand::~hand(){
	delete [] cards;
}

/*************************************************************************
 ** Function: hand
 ** Description: copy constructor
 ** Parameters: const hand &
 ** Pre-Conditions: initalized hand
 ** Post-Conditions: hand copied over
 ************************************************************************/
hand::hand(const hand & other){
	num_cards = other.num_cards;
	cards = new card[num_cards];
	for(int i=0; i<num_cards; i++){
		cards[i] = other.cards[i];
	}
};

/*************************************************************************
 ** Function: operator = 
 ** Description: assignment overload operator
 ** Parameters: const hand &
 ** Pre-Conditions: initilized hand
 ** Post-Conditions: operation overloaded
 ************************************************************************/
void hand::operator = (const hand & other){
	num_cards = other.num_cards;
	cards = new card[num_cards];
	for(int i=0; i<num_cards; i++)
      		cards[i] = other.cards[i];
	delete [] other.cards;	
} 

/*************************************************************************
 ** Function: create_hand
 ** Description: creates hand array
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: cards array created
 ************************************************************************/
void hand::create_hand(){
   	num_cards = 0;
	cards = new card[num_cards];
} 

/*************************************************************************
 ** Function: add_card
 ** Description: adds card to hand
 ** Parameters: card
 ** Pre-Conditions: must have num_cards initialized
 ** Post-Conditions: card will be added to hand
 ************************************************************************/
void hand::add_card(card c){
	card *temp;
	num_cards = num_cards+1;
	temp=cards; //temp card array
	cards=new card[num_cards];
	for(int i=0; i<num_cards-1; i++){
		cards[i]=temp[i];
	}delete [] temp;
       	cards[num_cards-1]=c; //adds to end of hand	
}

/*************************************************************************
 ** Function: get_num_cards
 ** Description: returns number of cards in hand
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returned num_cards
 ************************************************************************/
int hand::get_num_cards(){
	return num_cards;
}

/*************************************************************************
 ** Function: get_cards
 ** Description: returns card array
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: cards returned
 ************************************************************************/
card * hand::get_cards() const{
	return cards;
} 

/*************************************************************************
 ** Function: print_cards
 ** Description: prints out card array
 ** Parameters: none
 ** Pre-Conditions: cards initilized
 ** Post-Conditions: cards in hand printed out
 ************************************************************************/
void hand::print_cards(){
	cout << "Current hand:" << endl;
	for(int i=0; i<num_cards; i++){
       		if(cards[i].faced_up != false){
			if(cards[i].face == 'J')
			 	cout << "Jack"; //full names
		     	else if(cards[i].face == 'Q')
		   		cout << "Queen";
     			else if(cards[i].face == 'K')
   				cout << "King";
			else if(cards[i].face == 'A')
   				cout << "Ace";
			else
   				cout << cards[i].value;
			cout << " of " << cards[i].suit << endl;		
		}
	}
}

/*************************************************************************
 ** Function: count_total
 ** Description: counts total value amount of hand
 ** Parameters: hand
 ** Pre-Conditions: hand must be given
 ** Post-Conditions: value will be returned
 ************************************************************************/
int hand::count_total(hand h){
	int total=0;
   	for(int i=0; i<h.get_num_cards(); i++){
		if(h.cards[i].faced_up != false) //as long as its showing
		  	total += h.cards[i].value; 
	}
       	return total;
}

/*************************************************************************
 ** Function: flip_card
 ** Description: toggle to flip over card
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: card will have been flipped
 ************************************************************************/
void hand::flip_card(){ 
	if(cards[num_cards-1].faced_up == true)//toggle up/down 
	   	cards[num_cards-1].faced_up = false;
	else
	   	cards[num_cards-1].faced_up = true;
	   	
}		
