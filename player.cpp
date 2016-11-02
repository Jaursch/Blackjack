#include "./player.h" 
#include <iostream>

using namespace std;

/*************************************************************************
 ** Function: player
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: none 
 ** Post-Conditions: constructed
 ************************************************************************/
player::player(){
	card_total = 0; //needs to be set because will ++
	bet = 0;
	money = 0;
} 

/*************************************************************************
 ** Function: ~player
 ** Description: destructor
 ** Parameters: none
 ** Pre-Conditions: must be constructed
 ** Post-Conditions: will be destructed
 ************************************************************************/
player::~player(){
}

/*************************************************************************
 ** Function: set_money
 ** Description: sets money to user start total
 ** Parameters: int
 ** Pre-Conditions: none 
 ** Post-Conditions: money of player is start total
 ************************************************************************/
void player::set_money(int start_total){
	money = start_total; //takes the starting total by user and gives
}			     //it to the player

/*************************************************************************
 ** Function: get_money
 ** Description: returns money of player
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: money returned
 ************************************************************************/
int player::get_money(){
	return money;
}

/*************************************************************************
 ** Function: make_bet
 ** Description: gets user input to make bet
 ** Parameters: none
 ** Pre-Conditions: money must have value
 ** Post-Conditions: bet made
 ************************************************************************/
void player::make_bet(){
   	cout << "Current cash: $" << money << endl; 
	cout << "How much would you like to bet?: ";
	while(!(cin >> bet) || (bet > money)){ 
		cin.clear();
	   	cin.ignore(); //error handling
   		cout << "You bet is more than you currently have.\n";
		cout << "Please lower it: ";
		cin >> bet;
	}	
}

/*************************************************************************
 ** Function: get_bet
 ** Description: returns bet
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: bet returned
 ************************************************************************/
int player::get_bet(){
	return bet;
}

/*************************************************************************
 ** Function: get_card_total
 ** Description: returns card total
 ** Parameters: none
 ** Pre-Conditions: none 
 ** Post-Conditions: card total returned
 ************************************************************************/
int player::get_card_total(){
	return card_total;
} 

/*************************************************************************
 ** Function: print_hand
 ** Description: prints out hand and card total
 ** Parameters: none
 ** Pre-Conditions: hand must be initalized
 ** Post-Conditions: hand and total will be printed
 ************************************************************************/
void player::print_hand(){
  	p_hand.print_cards();
	card_total = p_hand.count_total(p_hand); 
	int ace_card_total = card_total;
	bool aces = false;
      	cout << "Current card worth: " << card_total; 
	for(int i=0; i<p_hand.get_num_cards(); i++){
		if(p_hand.get_cards()[i].face =='A'){
		   	aces = true;
			ace_card_total += 10;
			break; //only one ace needed
		}
	}if(aces == true){
		cout << " or " << ace_card_total; 
	}cout << endl;  	
}

/*************************************************************************
 ** Function: determine_bust
 ** Description: determines if player has busted, prints out hand
 ** Parameters: none
 ** Pre-Conditions: hand must be initalized
 ** Post-Conditions: will determine if busted, total printed
 ************************************************************************/
void player::determine_bust(){
	card_total = p_hand.count_total(p_hand); //amount card is worth	
	int ace_card_total = card_total;
	bool aces = false; //are there aces?
      	cout << "Round card worth: " << card_total; //with A=1
	for(int i=0; i<p_hand.get_num_cards(); i++){
		if(p_hand.get_cards()[i].face =='A'){
		   	aces = true;
			ace_card_total += 10;
			break;
		}
	}if(aces == true)
		cout << " or " << ace_card_total;//with A=11
	cout << endl;
	p_hand.print_cards(); 	
	if(aces == true && card_total<=21){ 
	   	int eleven_ace = 0;
		cout << "Would you like an ace to be an 11? yes(1) or no(2): ";
		while(!(cin>>eleven_ace) && eleven_ace!=1 && eleven_ace!=2){
			cin.clear();
			cin.ignore(); //error handling
			cout << "Please pick yes(1) or no(2):"; 
		}if(eleven_ace == 1){
			card_total=ace_card_total; //now A=11
		}  	
	}cout << endl;
       	if(card_total>21){
		cout << "Your total is over 21, your bet has been lost" << endl;
	       	money= money-bet; //end of turn and round	
	} 	
	
}

/*************************************************************************
 ** Function: won
 ** Description: returns bet amount, announces winning
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: money will be set
 ************************************************************************/
void player::won(){
	cout << "You Won!" <<endl;
	if(card_total == 21){
		cout << "Blackjack! Your winnings: $" << bet*1.5 << endl;
		money = money+(bet*1.5); //adding bet with blackjack
	}else{
	   	cout << "Your winnings: $" << bet <<endl;
		money = money+bet; //adding bet
	}bet = 0;
	cout << "New Total: $" << money << endl; 	
}

/*************************************************************************
 ** Function: lost 
 ** Description: take bet amount from money, announces loss
 ** Parameters: none
 ** Pre-Conditions: none 
 ** Post-Conditions: money will be set
 ************************************************************************/
void player::lost(){
	cout << "You Lost!" << endl;
	cout << "Lost bet: $" << bet << endl; 
	money = money-bet;
	cout << "New Total: $" << money << endl; 
       	bet = 0;
}

/*************************************************************************
 ** Function: tied
 ** Description: announces tie
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 ************************************************************************/
void player::tie(){
	cout << "You Tied!" << endl;
       	bet = 0;
	cout << "Total: $" << money << endl; 	
} 
