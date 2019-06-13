
#include "tictac.h"

void tictac::run() {

	intro();

	for (;;) {
		int selection = 0;
		resetBoard();

		std::cout << "\nGame modes:\n"
			<< "     1) Human first \n"
			<< "     2) Machine first \n"
			<< "     3) Human vs Human \n"
			<< "     4) Quit \n\n"
			<< "Select a mode: ";
		std::cin >> selection;

		if (selection == 4) break;

		board();

		if (selection == 1) {
			for (;;) {
				enterMove();
				board();
				if (verifyEnd() != 0) break;
				AIdecision();
				board();
				if (verifyEnd() != 0) break;
			}
		}

		if (selection == 2) {
			for (;;) {
				AIdecision();
				board();
				if (verifyEnd() != 0) break;
				enterMove();
				board();
				if (verifyEnd() != 0) break;
			}
		}

		if (selection == 3) {
			for (;;) {
				enterMove();
				board();
				if (verifyEnd_2() != 0) break;
				enterMove_2();
				board();
				if (verifyEnd_2() != 0) break;
			}
		}
	}
}

void tictac::intro() {
	std::cout << "\n  >>>>> Console Tic-Tac-Toe <<<<< \n\n"
			  << "To enter a move, type a number from 1 to 9 according to the picture below. \n";
	board();
}

void tictac::board() {
	std::cout << '\n';
	std::cout << "   " << (char)-55 << (char)-51 << (char)-51 << (char)-51 << (char)-53 << (char)-51 << (char)-51 << (char)-51 << (char)-53 << (char)-51 << (char)-51 << (char)-51 << (char)-69 << '\n';
	std::cout << "   " << (char)-70 << ' ' << pieces[0] << ' ' << (char)-70 << ' ' << pieces[1] << ' ' << (char)-70 << ' ' << pieces[2] << ' ' << (char)-70 << '\n';
	std::cout << "   " << (char)-52 << (char)-51 << (char)-51 << (char)-51 << (char)-50 << (char)-51 << (char)-51 << (char)-51 << (char)-50 << (char)-51 << (char)-51 << (char)-51 << (char)-71 << '\n';
	std::cout << "   " << (char)-70 << ' ' << pieces[3] << ' ' << (char)-70 << ' ' << pieces[4] << ' ' << (char)-70 << ' ' << pieces[5] << ' ' << (char)-70 << '\n';
	std::cout << "   " << (char)-52 << (char)-51 << (char)-51 << (char)-51 << (char)-50 << (char)-51 << (char)-51 << (char)-51 << (char)-50 << (char)-51 << (char)-51 << (char)-51 << (char)-71 << '\n';
	std::cout << "   " << (char)-70 << ' ' << pieces[6] << ' ' << (char)-70 << ' ' << pieces[7] << ' ' << (char)-70 << ' ' << pieces[8] << ' ' << (char)-70 << '\n';
	std::cout << "   " << (char)-56 << (char)-51 << (char)-51 << (char)-51 << (char)-54 << (char)-51 << (char)-51 << (char)-51 << (char)-54 << (char)-51 << (char)-51 << (char)-51 << (char)-68 << '\n';
	std::cout << '\n';
}

void tictac::resetBoard() {
	for (int i = 0; i < 9; ++i) {
		pieces[i] = ' ';
	}
}

void tictac::enterMove() {
	int position = 0;
	for (;;) {
		std::cout << "Enter position: ";
		std::cin >> position;
		position -= 1;
		if ((position < 0 && position >8) || isOccupied(position)) {
			std::cout << " [Invalid position]\n";
			continue;
		}
		break;
	}
	pieces[position] = 'x';
}

bool tictac::isOccupied(int pos) {
	if (pieces[pos] != ' ') {
		return 1;
	}
	else return 0;
}

bool tictac::verifyFull() {
	for (int i = 0; i < 9; ++i) {
		if (pieces[i] == ' ') {
			return 0;
		}
	}
	return 1;
}

int tictac::verifyVictory() {
	if ((pieces[0] == 'x' && pieces[1] == 'x' && pieces[2] == 'x') ||
		(pieces[3] == 'x' && pieces[4] == 'x' && pieces[5] == 'x') ||
		(pieces[6] == 'x' && pieces[7] == 'x' && pieces[8] == 'x') ||
		(pieces[0] == 'x' && pieces[3] == 'x' && pieces[6] == 'x') ||
		(pieces[1] == 'x' && pieces[4] == 'x' && pieces[7] == 'x') ||
		(pieces[2] == 'x' && pieces[5] == 'x' && pieces[8] == 'x') ||
		(pieces[0] == 'x' && pieces[4] == 'x' && pieces[8] == 'x') ||
		(pieces[2] == 'x' && pieces[4] == 'x' && pieces[6] == 'x')) {
		return 1;
	}

	if ((pieces[0] == 'o' && pieces[1] == 'o' && pieces[2] == 'o') ||
		(pieces[3] == 'o' && pieces[4] == 'o' && pieces[5] == 'o') ||
		(pieces[6] == 'o' && pieces[7] == 'o' && pieces[8] == 'o') ||
		(pieces[0] == 'o' && pieces[3] == 'o' && pieces[6] == 'o') ||
		(pieces[1] == 'o' && pieces[4] == 'o' && pieces[7] == 'o') ||
		(pieces[2] == 'o' && pieces[5] == 'o' && pieces[8] == 'o') ||
		(pieces[0] == 'o' && pieces[4] == 'o' && pieces[8] == 'o') ||
		(pieces[2] == 'o' && pieces[4] == 'o' && pieces[6] == 'o')) {
		return 2;
	}

	return 0;
}

int tictac::verifyEnd() {
	int vict = verifyVictory();

	if      (vict == 1) {
		std::cout << "     YOU WIN! :D \n";
		return 1;
	}
	else if (vict == 2) {
		std::cout << "     YOU LOSE... :'( \n";
		return 2;
	}
	else if (verifyFull()) {
		std::cout << "     THIS IS A DRAW :/ \n";
		return 3;
	}
	else return 0;
}

bool tictac::AI_1() {
	if      (pieces[0] == ' ' && pieces[1] == 'o' && pieces[2] == 'o') {
		pieces[0] = 'o';
		return 1;
	}
	else if (pieces[0] == 'o' && pieces[1] == ' ' && pieces[2] == 'o') {
		pieces[1] = 'o';
		return 1;
	} 
	else if (pieces[0] == 'o' && pieces[1] == 'o' && pieces[2] == ' ') {
		pieces[2] = 'o';
		return 1;
	}
	else if (pieces[3] == ' ' && pieces[4] == 'o' && pieces[5] == 'o') {
		pieces[3] = 'o';
		return 1;
	}
	else if (pieces[3] == 'o' && pieces[4] == ' ' && pieces[5] == 'o') {
		pieces[4] = 'o';
		return 1;
	}
	else if (pieces[3] == 'o' && pieces[4] == 'o' && pieces[5] == ' ') {
		pieces[5] = 'o';
		return 1;
	}
	else if (pieces[6] == ' ' && pieces[7] == 'o' && pieces[8] == 'o') {
		pieces[6] = 'o';
		return 1;
	}
	else if (pieces[6] == 'o' && pieces[7] == ' ' && pieces[8] == 'o') {
		pieces[7] = 'o';
		return 1;
	}
	else if (pieces[6] == 'o' && pieces[7] == 'o' && pieces[8] == ' ') {
		pieces[8] = 'o';
		return 1;
	}
	else if (pieces[0] == ' ' && pieces[3] == 'o' && pieces[6] == 'o') {
		pieces[0] = 'o';
		return 1;
	}
	else if (pieces[0] == 'o' && pieces[3] == ' ' && pieces[6] == 'o') {
		pieces[3] = 'o';
		return 1;
	}
	else if (pieces[0] == 'o' && pieces[3] == 'o' && pieces[6] == ' ') {
		pieces[6] = 'o';
		return 1;
	}
	else if (pieces[1] == ' ' && pieces[4] == 'o' && pieces[7] == 'o') {
		pieces[1] = 'o';
		return 1;
	}
	else if (pieces[1] == 'o' && pieces[4] == ' ' && pieces[7] == 'o') {
		pieces[4] = 'o';
		return 1;
	}
	else if (pieces[1] == 'o' && pieces[4] == 'o' && pieces[7] == ' ') {
		pieces[7] = 'o';
		return 1;
	}
	else if (pieces[2] == ' ' && pieces[5] == 'o' && pieces[8] == 'o') {
		pieces[2] = 'o';
		return 1;
	}
	else if (pieces[2] == 'o' && pieces[5] == ' ' && pieces[8] == 'o') {
		pieces[5] = 'o';
		return 1;
	}
	else if (pieces[2] == 'o' && pieces[5] == 'o' && pieces[8] == ' ') {
		pieces[8] = 'o';
		return 1;
	}
	else if (pieces[0] == ' ' && pieces[4] == 'o' && pieces[8] == 'o') {
		pieces[0] = 'o';
		return 1;
	}
	else if (pieces[0] == 'o' && pieces[4] == ' ' && pieces[8] == 'o') {
		pieces[4] = 'o';
		return 1;
	}
	else if (pieces[0] == 'o' && pieces[4] == 'o' && pieces[8] == ' ') {
		pieces[8] = 'o';
		return 1;
	}
	else if (pieces[2] == ' ' && pieces[4] == 'o' && pieces[6] == 'o') {
		pieces[2] = 'o';
		return 1;
	}
	else if (pieces[2] == 'o' && pieces[4] == ' ' && pieces[6] == 'o') {
		pieces[4] = 'o';
		return 1;
	}
	else if (pieces[2] == 'o' && pieces[4] == 'o' && pieces[6] == ' ') {
		pieces[6] = 'o';
		return 1;
	}
	else return 0;
}

bool tictac::AI_2() {
	if (pieces[0] == ' ' && pieces[1] == 'x' && pieces[2] == 'x') {
		pieces[0] = 'o';
		return 1;
	}
	else if (pieces[0] == 'x' && pieces[1] == ' ' && pieces[2] == 'x') {
		pieces[1] = 'o';
		return 1;
	}
	else if (pieces[0] == 'x' && pieces[1] == 'x' && pieces[2] == ' ') {
		pieces[2] = 'o';
		return 1;
	}
	else if (pieces[3] == ' ' && pieces[4] == 'x' && pieces[5] == 'x') {
		pieces[3] = 'o';
		return 1;
	}
	else if (pieces[3] == 'x' && pieces[4] == ' ' && pieces[5] == 'x') {
		pieces[4] = 'o';
		return 1;
	}
	else if (pieces[3] == 'x' && pieces[4] == 'x' && pieces[5] == ' ') {
		pieces[5] = 'o';
		return 1;
	}
	else if (pieces[6] == ' ' && pieces[7] == 'x' && pieces[8] == 'x') {
		pieces[6] = 'o';
		return 1;
	}
	else if (pieces[6] == 'x' && pieces[7] == ' ' && pieces[8] == 'x') {
		pieces[7] = 'o';
		return 1;
	}
	else if (pieces[6] == 'x' && pieces[7] == 'x' && pieces[8] == ' ') {
		pieces[8] = 'o';
		return 1;
	}
	else if (pieces[0] == ' ' && pieces[3] == 'x' && pieces[6] == 'x') {
		pieces[0] = 'o';
		return 1;
	}
	else if (pieces[0] == 'x' && pieces[3] == ' ' && pieces[6] == 'x') {
		pieces[3] = 'o';
		return 1;
	}
	else if (pieces[0] == 'x' && pieces[3] == 'x' && pieces[6] == ' ') {
		pieces[6] = 'o';
		return 1;
	}
	else if (pieces[1] == ' ' && pieces[4] == 'x' && pieces[7] == 'x') {
		pieces[1] = 'o';
		return 1;
	}
	else if (pieces[1] == 'x' && pieces[4] == ' ' && pieces[7] == 'x') {
		pieces[4] = 'o';
		return 1;
	}
	else if (pieces[1] == 'x' && pieces[4] == 'x' && pieces[7] == ' ') {
		pieces[7] = 'o';
		return 1;
	}
	else if (pieces[2] == ' ' && pieces[5] == 'x' && pieces[8] == 'x') {
		pieces[2] = 'o';
		return 1;
	}
	else if (pieces[2] == 'x' && pieces[5] == ' ' && pieces[8] == 'x') {
		pieces[5] = 'o';
		return 1;
	}
	else if (pieces[2] == 'x' && pieces[5] == 'x' && pieces[8] == ' ') {
		pieces[8] = 'o';
		return 1;
	}
	else if (pieces[0] == ' ' && pieces[4] == 'x' && pieces[8] == 'x') {
		pieces[0] = 'o';
		return 1;
	}
	else if (pieces[0] == 'x' && pieces[4] == ' ' && pieces[8] == 'x') {
		pieces[4] = 'o';
		return 1;
	}
	else if (pieces[0] == 'x' && pieces[4] == 'x' && pieces[8] == ' ') {
		pieces[8] = 'o';
		return 1;
	}
	else if (pieces[2] == ' ' && pieces[4] == 'x' && pieces[6] == 'x') {
		pieces[2] = 'o';
		return 1;
	}
	else if (pieces[2] == 'x' && pieces[4] == ' ' && pieces[6] == 'x') {
		pieces[4] = 'o';
		return 1;
	}
	else if (pieces[2] == 'x' && pieces[4] == 'x' && pieces[6] == ' ') {
		pieces[6] = 'o';
		return 1;
	}
	else return 0;
}

bool tictac::AI_3() {
	if (pieces[4] == ' ') {
		pieces[4] = 'o';
		return 1;
	}
	return 0;
}

bool tictac::AI_4() {
	int corner[4] = { 0, 2, 6, 8 };
	for (int i = 0; i < 4; ++i) {
		if (pieces[corner[i]] == ' ') {
			pieces[corner[i]] = 'o';
			return 1;
		}
	}
	return 0;
}

bool tictac::AI_5() {
	int side[4] = { 1, 3, 5, 7 };
	for (int i = 0; i < 4; ++i) {
		if (pieces[side[i]] == ' ') {
			pieces[side[i]] = 'o';
			return 1;
		}
	}
	return 0;
}

bool tictac::AIdecision() {

	std::this_thread::sleep_for(std::chrono::seconds(2));

	if      (AI_1()) return 0;
	else if (AI_2()) return 0;
	else if (AI_3()) return 0;
	else if (AI_4()) return 0;
	else if (AI_5()) return 0;	
}

void tictac::enterMove_2() {
	int position = 0;
	for (;;) {
		std::cout << "Enter position (player 2): ";
		std::cin >> position;
		position -= 1;
		if ((position < 0 && position >8) || isOccupied(position)) {
			std::cout << "Enter a valid position\n";
			continue;
		}
		break;
	}
	pieces[position] = 'o';
}

int tictac::verifyEnd_2() {
	int vict = verifyVictory();

	if      (vict == 1) {
		std::cout << "     PLAYER 1 WINS! :D \n";
		return 1;
	}
	else if (vict == 2) {
		std::cout << "     PLAYER 2 WINS! :D \n";
		return 2;
	}
	else if (verifyFull()) {
		std::cout << "     THIS IS A DRAW :/ \n";
		return 3;
	}
	else return 0;
}
