/*******************************************************
 ** Program: blackjack
 ** Author: Burton Jaursch
 ** Date: 4/18/2016
 ** Input: user input for blackjack game
 ** Output: game?
 ******************************************************/

#include <iostream>
#include <string> 
#include "./game.h"

using namespace std;

int main(){
	game blackjack;
	//d.shuffle_deck(d); 
	//d.print_deck(d);
	bool play_again = true;
       	while(play_again == true){
		blackjack.play_game(); 
		cout << "Would you like to go again?\n Enter yes or no: ";
	       	while(true){
			string ans;
			cin >> ans;
			if(ans == "yes" || ans == "Yes" || ans == "y")
				break;
			else if(ans == "no" || ans == "No" || ans == "n"){
				play_again = false;
				break;
			}else
			  	cout << "Please enter yes or no: "; 
		}  	
	
	}
}
