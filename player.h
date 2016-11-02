#include "./hand.h"
#include "./deck.h" 

class player{
	private:
	   	hand p_hand; //player hand
		int money;
		int card_total; //total value of cards in hand
		int bet;
	public:
		player();
	       	~player();
		void set_money(int);
	       	int get_money();
		void make_bet(); //when dealer asks for bet
		int get_card_total(); 
		int get_bet(); //gives player's bet
		void get_inital_hand(deck &); //gets hand, changes deck
		void print_hand();
		void hit(deck &, bool &); 
		void determine_bust(); 
		void won();
		void lost(); 	
		void tie(); 
};
