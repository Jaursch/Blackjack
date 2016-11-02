#include "./dealer.h" 

/*************************************************************************
 ** Function: dealer
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: none 
 ** Post-Conditions: constructed
 ************************************************************************/
dealer::dealer(){
	num_cards = 0;
} 

/*************************************************************************
 ** Function: ~dealer
 ** Description: destructor
 ** Parameters: none
 ** Pre-Conditions: must be constructed
 ** Post-Conditions: will be destructed
 ************************************************************************/
dealer::~dealer(){
}

/*************************************************************************
 ** Function: print_dhand
 ** Description: dealer's hand will be printed and card total
 ** Parameters: none
 ** Pre-Conditions: hand must be initialized
 ** Post-Conditions: hand will be printed
 ************************************************************************/
void dealer::print_dhand(){
	cout << "Dealer has one card faced down, the other showing... " <<endl; 
  	d_hand.print_cards(); //shows only one card
	card_total = d_hand.count_total(d_hand); 
	bool aces = false;
	int ace_card_total = card_total; //if aces in group
      	cout << "Current dealer shown card worth: " << card_total;
	for(int i=0; i<d_hand.get_num_cards(); i++){
		if(d_hand.get_cards()[i].face =='A' && d_hand.get_cards()[i].faced_up == true ){
		   	aces = true;
			ace_card_total += 10;
			break; //only one ace needed because 2 == 22!
		}
	}if(aces == true){
		cout << " or " << ace_card_total; 
	}cout << endl;  	
}

/*************************************************************************
 ** Function: get_dcard_total
 ** Description: returns card total of dealer
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: card total returned
 ************************************************************************/
int dealer::get_dcard_total(){
	return card_total;
}

/*************************************************************************
 ** Function: show_cards
 ** Description: dealer shows all cards
 ** Parameters: none
 ** Pre-Conditions: hand must be intialized
 ** Post-Conditions: dealers hand will be shown
 ************************************************************************/
void dealer::show_cards(){
	cout << "Dealer flips over card" << endl;
       	d_hand.flip_card(); //makes cards up	
	d_hand.print_cards();
       	card_total = d_hand.count_total(d_hand);
	cout << "Current dealer card worth: " << card_total << endl << endl;
} 

/*************************************************************************
 ** Function: dhit
 ** Description: will control dealers move and hit
 ** Parameters: deck &
 ** Pre-Conditions: hand & deck must be initialized
 ** Post-Conditions: dealer's hand will be dealt
 ************************************************************************/
void dealer::dhit(deck &d){
   	bool stay = false;
	while(stay == false && card_total<17){ //while under 17 and still in
	  	cout << "Dealer hits..." << endl;  
		d_hand.add_card(d.remove_card()); //gets card
		d_hand.print_cards(); 
		card_total = d_hand.count_total(d_hand); //get amount
		int ace_card_total = card_total;
		bool aces = false;
		for(int i=0; i<d_hand.get_num_cards(); i++){
			if(d_hand.get_cards()[i].face =='A'){
				aces =true; 
			   	ace_card_total += 10;
				break; //stops after one ace
			}	       //2 aces == 22. Bust!
		}cout << "Current dealer worth: " << card_total; 
		if(aces == true)
			cout << " or " << ace_card_total;//with A=11
		cout << endl; 
		if(card_total>=17 || (ace_card_total>=17 && ace_card_total<=21)){
			if(ace_card_total >= 17 && ace_card_total <= 21)
	    			card_total = ace_card_total; //now ace is 11   
		   	stay = true; //will stop hitting
		}if(card_total>21){
			cout << "Dealer busted!" << endl;
			stay = true;
		}cout << endl;
	}		
}

