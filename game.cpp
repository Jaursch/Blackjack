#include "./game.h" 

using namespace std;

/*************************************************************************
 ** Function: game
 ** Description: constructor
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: game will be started
 ************************************************************************/
game::game(){
	cout << "Welcome to Burt's Casino!" << endl; //will set up players,
	cout << "Let play some BLACKJACK!" << endl;  //and money to start
	set_num_players(); //sets up how many players
	set_starting_total();
       	players = make_players();
	
} 

/*************************************************************************
 ** Function: ~game
 ** Description: game will be ended and deleted
 ** Parameters: none
 ** Pre-Conditions: game initialized 
 ** Post-Conditions: game will be delted
 ************************************************************************/
game::~game(){
   	cout << "Now leaving Burt's Casino\nHere are you totals:" << endl;
	for(int i=0; i<num_players; i++){
		cout << "Player " << i+1 << " total: $"; 
		cout << players[i].get_money() << endl;  //final scores
	}delete [] players; 	
}

/*************************************************************************
 ** Function: game
 ** Description: copy constructor
 ** Parameters: const game &
 ** Pre-Conditions: game intitalized
 ** Post-Conditions: game class copied
 ************************************************************************/
game::game(const game &other){
	d = other.d;
	game_dealer = other.game_dealer;
	num_players = other.num_players;
	starting_total = other.starting_total;
	players = new player[num_players];
	for(int i=0; i<num_players; i++){
		players[i] = other.players[i];
	} 	
} 

/*************************************************************************
 ** Function: operator =
 ** Description: assignment operator overload
 ** Parameters: const game &
 ** Pre-Conditions: game initialized
 ** Post-Conditions: operator overloaded
 ************************************************************************/
void game::operator = (const game & other){ 
	d = other.d;
	game_dealer = other.game_dealer;
	num_players = other.num_players;
	starting_total = other.starting_total;
	players = new player[num_players];
	for(int i=0; i<num_players; i++){
		players[i] = other.players[i];
	}delete [] other.players; 	
}

/*************************************************************************
 ** Function: get_num_players
 ** Description: returns number of players
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: num_players returned
 ************************************************************************/
int game::get_num_players(){ //will I need this?
	return num_players;
} 

/*************************************************************************
 ** Function: set_num_players
 ** Description: will get user input to find number of players
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: number of players made
 ************************************************************************/
void game::set_num_players(){
	cout << "How many players will be with us today?: ";	
	while(!(cin >> num_players) || (num_players<1) || (num_players>5)){
		cin.clear();
		cin.ignore(); //error handling
		cout << "No players more than 5 or less than 1 at the table. ";
		cout << "Sorry, house rules. \nEnter a new number: ";	
	} 
}

/*************************************************************************
 ** Function: get_starting_total
 ** Description: returns starting total
 ** Parameters: none
 ** Pre-Conditions: none 
 ** Post-Conditions: starting total returned
 ************************************************************************/
int game::get_starting_total(){
	return starting_total;
} 

/*************************************************************************
 ** Function: set_starting_total
 ** Description: will set the starting total
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: starting total set
 ************************************************************************/
void game::set_starting_total(){
   	int choice;
	cout << "How much would you like each player to start with?" << endl;
       	cout << " 1 - $100\n 2 - $500\n 3 - $1000\n 4 - $10000\n 5 - $100000\n";
	cout << "Enter your choice: ";
       	while(!(cin>>choice) || (choice<1) || (choice>5)){
		cin.clear();
	       	cin.ignore(); //error handling
		cout << "Please pick a choice, 1-5: "; 	
	}if(choice == 1)
		starting_total=100;
	else if(choice == 2)
	  	starting_total=500;
	else if(choice == 3)
   		starting_total=1000;
	else if(choice == 4)
   		starting_total=10000;
	else if(choice == 5)
   		starting_total=100000;
			
} 

/*************************************************************************
 ** Function: make_players
 ** Description: will make players and set money
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: player array made
 ************************************************************************/
player * game::make_players(){
	player *p = new player [num_players];
	for(int i=0; i<num_players; i++){
		p[i].set_money(starting_total); //also sets money
	}return p;
}

//scrapped because couldn't set players values on the stack
/*void game::set_players(player *p){
   	cout << "set players" << endl; 
	for(int i=0; i<num_players; i++){
		players[i] = p[i];	
	}delete [] p; 
} */

/*************************************************************************
 ** Function: get_inital_hand
 ** Description: gets players inital hand
 ** Parameters: deck &
 ** Pre-Conditions: deck initialized
 ** Post-Conditions: hand given
 ************************************************************************/
void player::get_inital_hand(deck &d){
   	p_hand.create_hand();
	p_hand.add_card(d.remove_card());
	p_hand.add_card(d.remove_card()); 	//two cards
} 

/*************************************************************************
 ** Function: get_dealer_hand
 ** Description: gives the dealer his inital hand
 ** Parameters: deck &
 ** Pre-Conditions: deck initalized
 ** Post-Conditions: hand given
 ************************************************************************/
void dealer::get_dealer_hand(deck &d){
	d_hand.create_hand();
   	cout << endl << "Dealer deals his own hand..." << endl; 
	d_hand.add_card(d.remove_card());
	d_hand.add_card(d.remove_card()); //two cards
	d_hand.flip_card(); 	//one flipped down
} 

/*************************************************************************
 ** Function: hit
 ** Description: will give the player another card 
 ** Parameters: deck &, bool &
 ** Pre-Conditions: deck initalized
 ** Post-Conditions: player hit
 ************************************************************************/
void player::hit(deck &d, bool &stay){
	p_hand.add_card(d.remove_card()); //similar to Parham demo
	int card_total = p_hand.count_total(p_hand);  //see if busted
	//p_hand.print_cards();
	if(card_total>21){
		cout << "You Busted!" << endl;
		stay = true;
	}	   
}

/*************************************************************************
 ** Function: play_game
 ** Description: game is being played once game is set up
 ** Parameters: none
 ** Pre-Conditions: all classes initialized
 ** Post-Conditions: game has been played
 ************************************************************************/
void game::play_game(){
   	d.shuffle_deck(d); 	       	
	for(int i=0; i<num_players; i++){
	   	cout <<"Player " << i+1 << ": " << endl;  
		players[i].make_bet(); //makes bet, make sure it >money 
	}cout << "Dealer deals out hand..." << endl;
	for(int i=0; i<num_players; i++){
	   	cout << endl << "For Player " << i+1 << ": " <<endl;  
		players[i].get_inital_hand(d);
	      	players[i].print_hand(); //get player hand and print	
	}game_dealer.get_dealer_hand(d);
     	game_dealer.print_dhand(); //get dealer hand and print
	for(int i=0; i<num_players; i++){ //each turn
	   	int choice;
		bool stay = false;
		cout << endl << "Player " << i+1 << ": " << endl;
	     	while(stay == false){ //keep playing turn
		  	cout << "Would you like to hit(1), stay(2)";  
			cout << " or see hand(3): ";
			while(!(cin>>choice) && choice!=1 && choice!=2 && choice!=3){
				cin.clear(); //error handling
			      	cin.ignore();
				cout << "Please pick 1, 2, or 3: "; 	
			}if(choice == 1){
				players[i].hit(d, stay); //also can end turn
				if(stay ==false) 
				   	players[i].print_hand(); //show new card
			}else if(choice == 2){
				stay = true; //to end turn 
			}else{ //choice == 3
			  	cout << "Current card worth: ";
		       		cout <<	players[i].get_card_total() << endl;
			}if(stay == true){
				players[i].determine_bust();//will print
			}				    //final hand
		}	
	}game_dealer.show_cards();  //dealer turns over cards
	game_dealer.dhit(d);  //dealer will get hand
	for(int i=0; i<num_players; i++){ //determines winner
		if(players[i].get_card_total() <= 21){ //when player hasnt busted
		   	cout << "Player " << i+1 << ": " << endl;
			if(game_dealer.get_dcard_total() > 21) //if dealer busts
				players[i].won();
		      	else if(game_dealer.get_dcard_total() < players[i].get_card_total()){
				players[i].won();  
			}else if(game_dealer.get_dcard_total() > players[i].get_card_total()){
			   	players[i].lost(); 
			}else if(game_dealer.get_dcard_total() == players[i].get_card_total())
		   		players[i].tie(); 	   
		}cout << endl; 		
	}  	



} 
