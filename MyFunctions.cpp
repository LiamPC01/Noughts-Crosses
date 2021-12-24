#include "MyFunctions.h"


bool player1Turn = true;
int turnCounter = 0;


std::vector<char> brd = { ' ', ' ', ' ',
			  ' ', ' ', ' ',
			  ' ', ' ', ' ' };


void greeting() {
	std::cout << "NAUGHTS & CROSSES\n";
	std::cout << "This game requires two human players. The player will choose a tile with the commands:\n\n";
	std::cout << "1 2 3\n4 5 6\n7 8 9\n\n";
	std::cout << "The game will start with player one placing a naught, then player two placing a cross and so on\n\n";
}


//Each brd[] represents a tile
void printBoard() {
	std::cout << '|' << brd[0] << ' ' << brd[1] << ' ' << brd[2] << '|' << "\n";
	std::cout << '|' << brd[3] << ' ' << brd[4] << ' ' << brd[5] << '|' << "\n";
	std::cout << '|' << brd[6] << ' ' << brd[7] << ' ' << brd[8] << '|' << "\n";
}


void playGame() {

	while (turnCounter < 9) {
		playerInput();
		printBoard();
		checkWin();
	}
}


void playerInput() {

	int input;

	//Player 1
	if (player1Turn) {
		std::cout << "Player ones turn:\n";
		std::cin >> input;

		if (brd[input - 1] == ' ') {			//Checks if tile is empty
			brd[input - 1] = '0';			    //places a nought
			player1Turn = false;			    //Ends turn
			turnCounter++;
		}
		else {
			std::cout << "\nThat tile is taken!\n";
		}
	}

	//Player 2
	else if (!player1Turn) {
		std::cout << "Player twos turn:\n";
		std::cin >> input;

		if (brd[input - 1] == ' ') {
			brd[input - 1] = 'X';
			player1Turn = true;
			turnCounter++;
		}
		else {
			std::cout << "\nThat tile is taken!\n";
		}
	}
}


void checkWin() {
	if (brd[0] == brd[1] && brd[1] == brd[2] && brd[0] != ' ') {
		std::cout << "\nWinner!\n\n";
	}
	else if (brd[3] == brd[4] && brd[4] == brd[5] && brd[3] != ' ') {
		std::cout << "\nWinner!\n\n";
	}
	else if (brd[6] == brd[7] && brd[7] == brd[8] && brd[6] != ' ') {
		std::cout << "\nWinner!\n\n";
	}
	else if (brd[0] == brd[3] && brd[3] == brd[6] && brd[0] != ' ') {
		std::cout << "\nWinner!\n\n";
	}
	else if (brd[1] == brd[4] && brd[4] == brd[7] && brd[1] != ' ') {
		std::cout << "\nWinner!\n\n";
	}
	else if (brd[2] == brd[5] && brd[5] == brd[8] && brd[2] != ' ') {
		std::cout << "\nWinner!\n\n";
	}
	else if (brd[0] == brd[4] && brd[4] == brd[8] && brd[0] != ' ') {
		std::cout << "\nWinner!\n\n";
	}
	else if (brd[2] == brd[4] && brd[4] == brd[6] && brd[2] != ' ') {
		std::cout << "\nWinner!\n\n";
	}
}









