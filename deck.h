#include "./card.h"
#pragma once

class deck{
	private:
	   	card cards[52];
		int num_cards;
	public:
		deck(); //constructor 
	       	~deck(); //destructor
		card * make_deck(); 	
		int get_num_cards(); 
		void shuffle_deck(deck&);
		void print_deck(deck);
		void set_deck(card *);
	      	card remove_card(); 	
		
};  
