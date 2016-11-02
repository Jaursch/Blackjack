#include "card.h"
#pragma once

class hand{
	private:
	   	card *cards;
		int num_cards;
	public:
		hand();
	       	~hand();
		hand(const hand &);//copy constructor
		void operator = (const hand &); //assignment operator overload 
	       	void create_hand(); 	
		void add_card(card);
		int get_num_cards();
		card * get_cards() const; 
		void print_cards();
		int count_total(hand);
		void flip_card(); 	
};
