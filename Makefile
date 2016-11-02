CC = g++
exe_file = blackjack
$(exe_file): driver.o game.o dealer.o player.o hand.o deck.o
	$(CC) driver.o game.o dealer.o player.o hand.o deck.o -o $(exe_file)
deck.o: deck.cpp
	$(CC) -c deck.cpp
hand.o:	hand.cpp deck.cpp
	$(CC) -c hand.cpp deck.cpp
player.o: player.cpp hand.cpp deck.cpp
	$(CC) -c player.cpp hand.cpp deck.cpp
dealer.o: dealer.cpp player.cpp hand.cpp deck.cpp
	$(CC) -c dealer.cpp player.cpp hand.cpp deck.cpp
game.o:	game.cpp dealer.cpp player.cpp hand.cpp deck.cpp
	$(CC) -c game.cpp dealer.cpp player.cpp hand.cpp deck.cpp
driver.o: driver.cpp game.cpp dealer.cpp player.cpp hand.cpp deck.cpp
	$(CC) -c driver.cpp game.cpp dealer.cpp player.cpp hand.cpp deck.cpp 
clean:
	rm -f *.out *.o $(exe_file) 	
