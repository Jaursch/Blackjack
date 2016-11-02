#include "./hand.h"
#include "./deck.h" 

class dealer{
	private:
		hand d_hand;
		int num_cards;
		int card_total;

	public:
		dealer();
	       	~dealer(); 
		void get_dealer_hand(deck &);
		void print_dhand();
       		int get_dcard_total();
		void show_cards(); 
		void dhit(deck &); 		
};
