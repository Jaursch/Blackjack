#include "./deck.h"
#include "./dealer.h"
#include "./player.h"

class game{
	private:
	   	deck d;
		player *players;
		dealer game_dealer;
		int num_players;
		int starting_total;
	public:
		game();
	      	~game();
		game(const game &);
		void operator = (const game &); //assignment operator overload 	
		void play_game();
		int get_starting_total();
	       	void set_starting_total(); 
		void set_num_players(); //gets number of players from user
		int get_num_players(); //retrieves number if for each player
		void print_players(); //does not have function
		player* make_players();
	       	void set_players(player *);  	

};
